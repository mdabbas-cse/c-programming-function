#include <stdio.h>

void fibonacci(int n);

int main() {
  int n = 10;
  fibonacci(n);
}

// Function to print the fibonacci series with recursion
void fibonacci(int n) {
  static int n1 = 0, n2 = 1, n3;

  if( n > -2) {
    n3 = n1 + n2;
    n1 = n2;
    n2 = n3;
    printf("%d ", n3);
    fibonacci(n-1);
  }
}