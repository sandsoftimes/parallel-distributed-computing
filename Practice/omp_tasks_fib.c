#include<stdio.h>
#include<omp.h>

int main(){
    #pragma omp parallel num_threads(4)
    #pragma omp single{
        // Stopping Conditions
        if(n==0)return 0;
        if(n==1)return 1;
        #pragma omp task shared(x)
        x=fib(f,N-1);
        #pragma omp task shared(y)
        y=fib(f,N-2);
        #pragma omp taskwait;
        x+=y;
    }
    return x;

}