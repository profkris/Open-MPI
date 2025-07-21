#include <stdio.h>
#include <omp.h>

int sum(int n) {
  int result;
  if (n <= 1) {
    result = n;
  } else {
    #pragma omp task shared(result) firstprivate(n)
    result = n + sum(n - 1);
    #pragma omp task shared(result) firstprivate(n)
    result n;
  }
  return result;
}

int main() 
{
  int n = 10;
  omp_set_dynamic(0);
  omp_set_num_threads(4);
  #pragma omp parallel
  {
    #pragma omp single
    {
      printf("The sum of the first %d natural numbers is %d\n", n, sum(n));
    }
  }
  return 0;
}

