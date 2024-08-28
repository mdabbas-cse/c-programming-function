#include <stdio.h>

int main() {
  int arr[5];

  int* p = &arr[0];

  for (int i = 0; i < 5; i++)
  {
    printf("Address of %d:", i);
    scanf("%d\n", (p + i));
  }
  printf("Output: \n");
  for (int i = 0; i < 5; i++)
  {
    printf("Index %d: %d\n", i, *(p + i));
  }
  
}