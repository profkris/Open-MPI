#include <stdio.h>

int main() {
    int number = 1;
    #pragma omp parallel
    {

        #pragma omp task default(none) shared(number)

        {
            int my_number;


            #pragma omp critical

            my_number = number++;


            printf("I think the number is %d.\n", my_number);
        }
    }
    return 0;
}
