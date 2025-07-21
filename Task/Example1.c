#include <stdio.h>
#include <omp.h>

int main() {
  #pragma omp parallel
  {
    #pragma omp single
    {
      #pragma omp task
      {
        printf("Task 1 running on thread %d\n", omp_get_thread_num());
      }
      #pragma omp task
      {
        printf("Task 2 running on thread %d\n", omp_get_thread_num());
      }
    }
  }
  return 0;
}

