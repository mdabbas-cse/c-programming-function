#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World!";
    char *ptr = strchr(str, 'W');
    if (ptr != NULL) {
        printf("Found 'W' at position: %ld\n", ptr - str);
    } else {
        printf("'W' not found.\n");
    }
    return 0;
}
