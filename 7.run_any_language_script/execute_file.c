#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>  // Include this for chdir() on Windows

char *file_rename(char *filename, char *new_extension) {
    char *dot = strrchr(filename, '.');
    if (dot == NULL) {
        printf("No extension found in the file name.\n");
        return NULL;
    }

    char *new_filename = malloc(strlen(filename) + strlen(new_extension) + 1);
    if (new_filename == NULL) {
        perror("malloc failed");
        return NULL;
    }

    strncpy(new_filename, filename, dot - filename);
    new_filename[dot - filename] = '\0';
    strcat(new_filename, new_extension);

    return new_filename;
}

int main() {
    char path[100];
    char file[100];
    int choice;

    printf("Enter your path to directory: ");
    scanf("%99s", path);
    if (chdir(path) != 0) {  // Use chdir() on Windows
        perror("chdir failed");
        return 1;
    }
    printf("Directory changed to %s\n", path);

    printf("Available Language for build and compile.\n");
    printf("1. Python\n");
    printf("2. C\n");
    printf("Choose the language you want to execute: ");
    scanf("%d", &choice);


    if (choice == 1) {
        printf("Enter your file name which you want to execute: ");
        scanf("%99s", file);
        char command[200];
        snprintf(command, sizeof(command), "python %s", file);
        system(command);  // Run the Python script and wait for it to finish
    } else if (choice == 2) {
        printf("Enter your file name which you want to build and execute: ");
        scanf("%99s", file);
        char *new_filename = file_rename(file, ".exe");

        if (new_filename == NULL) {
            return 1;  // Exit if file_rename failed
        }

        char command[200];
        snprintf(command, sizeof(command), "gcc %s -o %s", file, new_filename);
        system(command);  // Compile the C file and wait for it to finish

        snprintf(command, sizeof(command), "%s", new_filename);
        system(command);  // Run the compiled executable and wait for it to finish

        free(new_filename);  // Free allocated memory
    }

    return 0;
}
