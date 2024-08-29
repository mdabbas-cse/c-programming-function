#include <stdio.h>
#include <string.h>


int main () {

  char str[] = "Hello, World!";
  char *token = strtok(str, ", ");

  printf("%s\n", token);

  while (token != NULL) {
    printf("%s\n", token);
    token = strtok(NULL, ", ");
  }

  return 0;
}