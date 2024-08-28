#include <stdio.h>

int main() {
  // pointer
  int age = 20;
  int *p = &age;
  printf("pointer value: %d\n", p);
  *p++;
  printf("pointer value: %d\n", p);
  int *second_point;
  second_point = p;
  printf("pointer address: %d\n", &second_point);
  printf("pointer value: %d\n", second_point);
  printf("pointer value: %d\n", *second_point);
}