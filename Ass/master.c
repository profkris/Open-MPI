#include <stdio.h>
#include <omp.h>

int main(void) {
    int x = 0;
    int y = 0;

    #pragma omp parallel
    {
        #pragma omp master
        {
            x = 1;
          
            y = 1;
        }

        #pragma omp barrier
        #pragma omp single
        {
            printf("x = %d, y = %d\n", x, y);
        }
    }

    return 0;
}

