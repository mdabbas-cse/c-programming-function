#include <stdio.h>
#include <string.h>

int main() {
  char str1[20] = "C programming";
  char str2[20];
  strncpy(str2, str1, 10);

  printf("Copying string str1 to str2: %s \n", str2);
  return 0;
}