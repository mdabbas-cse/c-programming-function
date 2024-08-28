#include <stdio.h>
#include <stdlib.h>


int main() {
  int *ptr, i, n;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  ptr = (int*) malloc(n * sizeof(int));

  if(ptr == NULL) {
    printf("Memory not allocated.\n");
    exit(0);
  }

  for(i = 0; i < n; i++) {
    printf("Enter element %d: ", i+1);
    scanf("%d", ptr + i);
  }

  printf("Elements in the array are: \n");
  printf("Address of the first element: %p\n", ptr);
  // printf("Address of the last element: %p\n", ptr + 1);
  for (i = 0; i < n; i++) {
    printf("Address of element %d: %p\n", i+1, ptr + i);
    printf("Element %d: %d\n", i+1, *(ptr + i));
  }
}