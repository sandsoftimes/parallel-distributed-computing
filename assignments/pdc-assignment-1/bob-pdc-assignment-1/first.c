#include <stdio.h>
#include <omp.h>

int main() {
    int array1[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int array2[16] = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int result[16];

    // Set the number of threads to half of the available threads
    int num_threads = omp_get_max_threads() / 2;
    omp_set_num_threads(num_threads);

    #pragma omp parallel for
    for (int i = 0; i < 16; i++) {
        result[i] = array1[i] + array2[i];
    }

    // Display loop (only executed by thread 0)
    #pragma omp parallel
    {
        #pragma omp master
        {
            for (int i = 0; i < 16; i++) {
                printf("%d ", result[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
