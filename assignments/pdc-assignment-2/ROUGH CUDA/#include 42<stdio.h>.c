#include <stdio.h>
#include <stdlib.h>

__global__ void add(int *a,int *b,int *c,int N){
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    int index = row* blockDim.x* gridDim.x + col;

    //Performing matrix addition
    c[index]=a[index]+b[index];
}

int main(){
    int *a,*b,*c,*da,*db,*dc,N=16,i,j;
    a=(int*)malloc(sizeof(int)*N);
    b=(int*)malloc(sizeof(int)*N);
    c=(int*)malloc(sizeof(int)*N);
    
    //Initializing matrices a and b to 1's
    for (i=0;i<N;i++){
        a[i]=1;
        b[i]=1;
    }

    cudaMalloc((void **)&da, sizeof(int) *N);
    cudaMalloc((void **)&db, sizeof(int) *N);
    cudaMalloc((void **)&dc, sizeof(int) *N);

    cudaMemcpy(da,a,sizeof(int) *N, cudaMemcpyHostToDevice);
    cudaMemcpy(da,b,sizeof(int) *N, cudaMemcpyHostToDevice);

    dim3 dimGrid(N/8,N/8,1);
    dim3 dimBlock(N/8,N/8,1);

    add<<<dimGrid, dimBlock>>>(da, db, dc, N);
    cudaMemcpy(c, dc, sizeof(int)*N, cudaMemcpyDeviceToHost);

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
    // cudaMemcpy(c, &dc, sizeof(int)*N, cudaMemcpyDeviceToHost);
}