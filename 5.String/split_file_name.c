#include <stdio.h>
#include <string.h>

int main() {
    char filename[100];
    printf("Enter the file name (e.g., file.c): ");
    scanf("%99s", filename);  // Read the filename from the user

    // Find the last occurrence of '.' in the filename
    char *dot = strrchr(filename, '.');
    if (dot == NULL) {
        printf("No extension found in the file name.\n");
        return 1;
    }

    // Create a new filename by replacing the extension with ".exe"
    char new_filename[100];
    strncpy(new_filename, filename, dot - filename);  // Copy the base name
    new_filename[dot - filename] = '\0';  // Null-terminate the string
    strcat(new_filename, ".exe");  // Add the new extension

    printf("Original filename: %s\n", filename);
    printf("New filename: %s\n", new_filename);

    // Optional: Rename the file on the filesystem (if the file exists)
    // if (rename(filename, new_filename) != 0) {
    //     perror("File rename failed");
    //     return 1;
    // }

    printf("File renamed successfully.\n");

    return 0;
}
