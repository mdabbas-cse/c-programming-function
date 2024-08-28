#include <stdio.h>

void swap(int *a, int *b) {

  printf("a: %d, b: %d\n", a, b);
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int a = 10;
  int b = 20;
  printf("a: %d, b: %d\n", a, b);
  swap(&a, &b);
  printf("a: %d, b: %d\n", a, b);

}