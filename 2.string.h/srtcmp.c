#include <stdio.h>
#include <string.h>

int main() {
  char str2[20] = "C programming";
  char str1[20] = " language";
  int result = strcmp(str1, str2);
  
  if( result == 0) {
    printf("str1 is equal to str2");
  }  else if(result < 0) {
    printf("str1 is less than str2 %d" , result);
  } else {
    printf("str1 is greater than str2 %d", result);
  }
  return 0;
}