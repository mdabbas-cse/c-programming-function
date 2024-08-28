#include <stdio.h>
#include <stdlib.h>

int main() {

  int *ptr, i, n;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  ptr = (int*) malloc(n * sizeof(int));

  ptr = (int*) realloc(ptr, 2 * n * sizeof(int));
}