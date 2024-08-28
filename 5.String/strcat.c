#include <stdio.h>
#include <string.h>

int main() {
  char str1[20] = "C programming";
  char str2[20] = " language";
  // strcat(str2, str1);
  strncat(str1, str2, 10);

  printf("Copying string str1 to str2: %s \n", str1);
  return 0;
}