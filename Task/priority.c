#include <stdio.h>
#include <omp.h>

int main() {
  #pragma omp parallel
  {
    #pragma omp single
    {
      #pragma omp task priority(300)
      {
        printf("%d.Task 1\n",omp_get_thread_num());
      }
      #pragma omp task priority(200)
      {
        printf("%d.Task 2\n",omp_get_thread_num());
      }
      #pragma omp task priority(100)
      {
        printf("%d.Task 3\n",omp_get_thread_num());
      }
    }
  }
  return 0;
}

