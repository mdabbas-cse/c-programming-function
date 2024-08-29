#include <stdio.h>
#include <unistd.h>

int main() {
    // Change directory to /path/to/directory
    printf("Enter your path to directory: ");
    char path[100];  // Use a character array to store the path
    scanf("%99s", path);  // Use %99s to avoid buffer overflow

    if (chdir(path) != 0) {
        perror("chdir failed");
        return 1;
    }

    printf("Directory changed to %s\n", path);

    // Get the file name to execute
    printf("Enter your file name which you want to execute: ");
    char file[100];  // Use a character array to store the file name
    scanf("%99s", file);  // Use %99s to avoid buffer overflow

    // Execute a file in the new directory
    const char *args[] = {file, NULL};  // Use the file name directly
    if (execvp(args[0], args) == -1) {
        perror("execvp failed");
        return 1;
    }

    // This line will not be reached if execvp is successful
    printf("This will only print if execvp fails\n");

    return 0;
}
