// #include<stdio.h>
// #include<omp.h>

// int main(){
//     #pragma omp parallel num_threads(3)
//     #pragma omp single
//     {
//         // stopping conditions
//         if(n-->next==NULL)return;
//         #pragma omp task shared(x)
//         x=llist(n,n->next);
//     }
// }

#include<stdio.h>
#include<omp.h>

int main(){
    #pragma omp parallel 
    #pragma omp single
    {
        n=llist->head;
        while(n->next!=NULL){
            #pragma omp shared task(x)
            x=omp_get_thread_num();
            n=n->next;
        }
        #pragma omp taskwait;
    }
    return x;
}