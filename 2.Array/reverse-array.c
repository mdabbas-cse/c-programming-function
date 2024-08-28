#include <stdio.h>

void reverse(int arr[], int n);
void display(int arr[], int n);

int main() {
  int n = 5;
  int arr[5] = {1, 2, 3, 4, 5};
  reverse(arr, n);
  display(arr, n);
}

void reverse(int arr[], int n) {
  for (int i = 0; i < n / 2; i++)
  {
    int temp = arr[i];
    arr[i] = arr[n-i-1];
    arr[n-i-1] = temp;
  }
}

void display(int arr[], int n) {
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}