#include <stdio.h>
#include <stdlib.h>


int main() {

  int *ptr;
  int n, i;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  // Dynamically allocate memory using malloc()
  ptr = (int*) malloc(n * sizeof(int));

  // Check if the memory has been successfully
  if(ptr == NULL) {
    printf("Memory not allocated. \n");
    exit(0);
  }

  // input elements
  for (i = 0; i < n; i++) {
    printf("Enter element %d: ", i+1);
    printf("Enter element %d: ", *ptr);
    scanf("%d", ptr + i);
  }

  // Print elements
  printf("Elements of the array are: ");
  for (i = 0; i < n; i++) {
    printf("%d, ", *(ptr + i));
  }

  // Deallocate memory
  free(ptr);

  return 0;
}