#include <stdio.h>
#include <omp.h>
int main() {
    //int number = 1;
    #pragma omp parallel
    {
	int number = 1;
        #pragma omp task default(shared)
        {
            //printf("%d.I think the number is %d.\n", omp_get_thread_num(),number);
            number = number + 1;
	    printf("%d.I think the number is %d.\n", omp_get_thread_num(),number);
        }
    }
    return 0;
}
