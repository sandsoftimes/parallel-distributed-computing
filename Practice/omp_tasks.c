#include <stdio.h>
#include<omp.h>

int main(){
    #pragma omp parallel
    #pragma omp single
    {
        #pragma omp task shared(x)
        x=summation(array,half);
        #pragma omp task shared(y)
        y=summation(array+half,N-half);

        #pragma omp taskwait
        
        x+=y;
    }
    return x;
}