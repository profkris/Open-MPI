#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    #pragma omp single nowait
    {
        for (int i = 0; i < 10; i++) {
            #pragma omp task
            printf("I am thread no. %d.\n", omp_get_thread_num());
        }
    }
    return 0;
}
