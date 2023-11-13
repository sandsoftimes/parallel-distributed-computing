#include<stdio.h>
#include<omp.h>
int main(){
    int tid;
    int N=1000;
    int array[N];
    int sum=0;
    for(int i=0;i<N;i++){
        array[i]=1;
    }
    #pragma omp parallel num_threads(N) private(tid) reduction(+:sum)
    {
    tid=omp_get_thread_num();
    sum+=array[tid];
    }
    printf("Sum:%d\n",sum);
}

// #include <stdio.h>
// #include <omp.h>

// int main() {
//     int tid;
//     int N = 1000;
//     int array[N];
//     int sum = 0; // Initialize sum

//     // Populate the array with values (for example, all 1s for demonstration)
//     for (int i = 0; i < N; i++) {
//         array[i] = 1;
//     }

//     #pragma omp parallel num_threads(N) private(tid) reduction(+:sum)
//     {
//         tid = omp_get_thread_num();
//         sum += array[tid];
//     }

//     printf("Sum:%d\n", sum);

//     return 0;
// }
