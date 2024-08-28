#include <stdio.h>

int main() {
  // pointer 
  int *p;
  int a = 10; // assign value to a
  p = &a; // assign address of a to p

  // print value of a, p, and *p
  printf("Value of a: %d, %d, %d\n", a, p, *p);
  return 0;
}