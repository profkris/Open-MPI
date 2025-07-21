#include <stdio.h>
#include <omp.h>

void compute(int* sum, int start, int end) {
  for (int i = start; i < end; i++) {
    *sum += i;
  }
}

int main() {
  int sum = 0;
  omp_set_num_threads(4);
  #pragma omp parallel
  {
    int i = omp_get_thread_num();
    #pragma omp single
    while (i < 10) {
      #pragma omp task shared(sum)
      compute(&sum, i, i + 10);
      i += omp_get_num_threads();
    }
  }
  printf("Sum = %d\n", sum);
  return 0;
}

