#include <stdio.h>
#include <omp.h>

void foo() {
  printf("My name is Parikshit and my id is = %d\n",omp_get_thread_num());
}

void bar(){
	printf("My dep. is HPC-Tech = %d\n",omp_get_thread_num());
}

int main()
{
  omp_set_dynamic(0);
  omp_set_num_threads(4);
  #pragma omp parallel
  {
    #pragma omp single
	{
	#pragma omp taskyield
    	{
      	foo();
     	#pragma omp task untied
     	bar();
	}
    }
  }
  return 0;
}
