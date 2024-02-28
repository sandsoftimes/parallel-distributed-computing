#include <stdio.h>
#include <cuda_runtime.h>

//Kernel Function for element-wise addition
__global__ void elementWiseAddition(int *a, int *b, int *result, int N) {
    int tid=blockIdx.x*blockDim.x+threadIdx.x;
    if(tid<N){
        result[tid]=a[tid]+b[tid];
    }
}

int main() {
    const int N=16;
    cudaEvent_t start,stop;
    float elapsed;

    //Host arrays
    int h_a[N],h_b[N],h_result[N];
    //Initialize host arrays
    for(int i=0;i<N;i++){
        h_a[i]=i;
        h_b[i]=2*i;
    }
    //Device arrays
    int *d_a,*d_b,*d_result;

    cudaMalloc((void **)&d_a,N*sizeof(int));
    cudaMalloc((void **)&d_b,N*sizeof(int));
    cudaMalloc((void **)&d_result,N*sizeof(int));

    //Copy data from host to device
    cudaMemcpy(d_a,h_a,N*sizeof(int),cudaMemcpyHostToDevice);
    cudaMemcpy(d_b,h_b,N*sizeof(int),cudaMemcpyHostToDevice);
    printf("Grid X\tGrid Y\tGrid Z\tBlock X\tBlock Y\tBlock Z\tMicroseconds \tMilliseconds\tSeconds\n");
    for(int gridX=1;gridX <= N;gridX*=2){
        for(int gridY=1;gridY<=N/gridX;gridY*=2){
            int gridZ=N/(gridX*gridY);
            
            for(int blockX=1;blockX<=N;blockX*=2){
                for(int blockY=1;blockY<=N/blockX;blockY*=2){
                    int blockZ=N/(blockX*blockY);

                    dim3 gridSize(gridX,gridY,gridZ);
                    dim3 blockSize(blockX,blockY,blockZ);

                    cudaEventCreate(&start);
                    cudaEventCreate(&stop);

                    cudaEventRecord(start,0);

                    //call the Kernel
                    elementWiseAddition<<<gridSize,blockSize>>>(d_a,d_b,d_result,N);
                }
            }
        }
    }
}

    