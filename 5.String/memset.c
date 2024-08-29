#include <stdio.h>
#include <string.h>

int main() {
    char str[50] = "Hello, World!";
    memset(str, '*', 0);
    printf("Modified string: %s\n", str);
    return 0;
}
