#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World!";
    char *ptr = strstr(str, "World");
    if (ptr != NULL) {
        printf("Found 'World' at position: %ld\n", ptr - str);
    } else {
        printf("'World' not found.\n");
    }
    return 0;
}
