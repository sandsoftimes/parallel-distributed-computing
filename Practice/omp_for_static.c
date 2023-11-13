// #include <stdio.h>
// #include <omp.h>

// int main() {
//     int tid; // Declare tid as an integer to store the thread ID
//     // #pragma omp parallel num_threads(2)
//     #pragma omp parallel num_threads(4) private(tid)
//     {
//         tid = omp_get_thread_num();
//         // #pragma omp for schedule(static,3)
//         #pragma omp for schedule(static,5)
//         for (int i = 0; i < 20; i++) {
//             printf("%3d by %3d\n", i, tid);
//         }
//     }

//     return 0;
// }


#include<stdio.h>
#include<omp.h>

int main(){
    int tid;
    #pragma omp parallel num_threads(4) private(tid)
    {
        tid=omp_get_thread_num();
        #pragma omp for schedule(static,5)
        for ( int i = 0; i < 20; i++)
        {
            printf("%3d by %3d\n",i,tid);
        }
        
    }
}