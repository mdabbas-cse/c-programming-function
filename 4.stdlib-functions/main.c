#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  char string[] = "12334";
  int number = atoi(string);
  printf("%d\n", number);  
  // print type of number variable
  // atof, atol, atoll

  /* abort function */
   printf("Starting the program...\n");

    // Simulate a critical error
    int criticalError = 0;
    if (criticalError) {
        printf("Critical error encountered! Terminating the program.\n");
        abort();  // Terminate the program immediately
    }

    // This code will not be executed
    printf("This will not be printed.\n");
  /* abort function */

  srand(time(0));  // Seed the random number generator
  int random_num = rand();  // Generate a random number
  printf("Random number: %d\n", random_num);

  system("ls");
  system("ls -l");
  system("pwd");
  system("echo Hello World");

  int num = 12, den = 3;
  div_t result = div(num, den);  // Compute quotient and remainder
  printf("Quotient: %d, Remainder: %d\n", result.quot, result.rem);

  char *path = getenv("PATH");  // Get the PATH environment variable

  if (path != NULL) {
      printf("PATH: %s\n", path);
  } else {
      printf("PATH not found.\n");
  }


  return 0;
}