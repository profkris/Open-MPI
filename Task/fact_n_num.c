#include <stdio.h>
#include <omp.h>

int factorial(int n) {
  int result;
  if (n <= 1) {
    result = 1;
  } else {
    #pragma omp task shared(result)
    result = factorial(n - 1);
    #pragma omp task shared(result)
    result *= n;
  }
  return result;
}

int main() {
  int n = 5;
  omp_set_num_threads(4);
  #pragma omp parallel
  {
    #pragma omp single
    {
      int result = factorial(n);
      printf("The factorial of %d is %d\n", n, result);
    }
  }
  return 0;
}

