#include <stdio.h>
#include <omp.h>

int main() {
    int num_threads = 4;
    int chunk_size = 4;
    int total_iterations = 16;
    int i;

    printf("Static Scheduling:\n");
    #pragma omp parallel num_threads(num_threads) shared(chunk_size)
    {
        int tid = omp_get_thread_num();
        int start, end;

        #pragma omp for schedule(static, chunk_size)
        for (i = 0; i < total_iterations; i++) {
            start = i;
            end = i + chunk_size - 1;
            if (end >= total_iterations) {
                end = total_iterations - 1;
            }

            // Visualize chunk execution
            printf("Thread %d: ", tid);
            for (int j = 0; j < total_iterations; j++) {
                if (j >= start && j <= end) {
                    printf("X");
                } else {
                    printf("-");
                }
            }
            printf("\n");
        }
    }

    printf("\nDynamic Scheduling:\n");
    #pragma omp parallel num_threads(num_threads) shared(chunk_size)
    {
        int tid = omp_get_thread_num();
        int start, end;

        #pragma omp for schedule(dynamic, chunk_size)
        for (i = 0; i < total_iterations; i++) {
            start = i;
            end = i + chunk_size - 1;
            if (end >= total_iterations) {
                end = total_iterations - 1;
            }

            // Visualize chunk execution
            printf("Thread %d: ", tid);
            for (int j = 0; j < total_iterations; j++) {
                if (j >= start && j <= end) {
                    printf("X");
                } else {
                    printf("-");
                }
            }
            printf("\n");
        }
    }

    return 0;
}
