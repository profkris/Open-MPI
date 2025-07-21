#include <stdio.h>
#include <omp.h>

int main() {
  int sum = 0;
  #pragma omp parallel
  {
    #pragma omp single
    {
      #pragma omp task in_reduction(+:sum)
      {
        sum += 1;
      }
      #pragma omp task in_reduction(+:sum)
      {
        sum += 2;
      }
      #pragma omp task in_reduction(+:sum)
      {
        sum += 3;
      }
    }
  }
  printf("Sum = %d\n", sum);
  return 0;
}

