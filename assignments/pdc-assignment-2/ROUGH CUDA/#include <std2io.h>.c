#include <stdio.h>
#include <stdlib.h>

_global_ void add(int *a, int *b, int *c, int N) {
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    int row = blockIdx.y * blockDim.y + threadIdx.y;

    if (col < N && row < N) {
        int index = row * N + col;
        c[index] = a[index] + b[index];
    }
}

int main() {
    int *a, *b, *c, *da, *db, *dc, N = 16, i, j;

    a = (int*)malloc(sizeof(int)*N*N); // allocate host mem
    b = (int*)malloc(sizeof(int)*N*N); // and assign random memory
    c = (int*)malloc(sizeof(int)*N*N); // for the result

    // Write code to initialize both a and b to 1’s.
    for (i = 0; i < N*N; i++) {
        a[i] = 1;
        b[i] = 1;
    }

    cudaMalloc((void **)&da, sizeof(int)*N*N);
    cudaMalloc((void **)&db, sizeof(int)*N*N);
    cudaMalloc((void **)&dc, sizeof(int)*N*N);

    cudaMemcpy(da, a, sizeof(int)*N*N, cudaMemcpyHostToDevice);
    cudaMemcpy(db, b, sizeof(int)*N*N, cudaMemcpyHostToDevice);

    dim3 dimGrid(N/8, N/8, 1);
    dim3 dimBlock(N/8, N/8, 1);

    add<<<dimGrid, dimBlock>>>(da, db, dc, N);

    cudaMemcpy(c, dc, sizeof(int)*N*N, cudaMemcpyDeviceToHost);

    for (j = 0; j < N; j++) {
        for (i = 0; i < N; i++) {
            printf("a[%d] + b[%d] = %d\n", j*N+i, j*N+i, c[j*N+i]);
        }
        printf("\n");
    }

    // Free allocated memory
    free(a);
    free(b);
    free(c);
    cudaFree(da);
    cudaFree(db);
    cudaFree(dc);

    return 0;
}