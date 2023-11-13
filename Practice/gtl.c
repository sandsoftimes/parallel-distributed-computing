#include<stdio.h>
#include<omp.h>

int main(){
    omp_lock_t locked;
    omp_lock_init(locked);
    char input;
    while(input!='gt'){
        printf("Write gr to move grass");
        // cin>>input;
    }
    if(input='gr'){
        omp_set_lock(&locked);
        printf("Moving goat");
    }
    while(input!='back'){
        printf("Write back to move back");
        // cin>>input;
    }
    if(input='back'){
        omp_set_lock(&locked);
        printf("Moving back");
    while(input!='li'){
        printf("Write li to move lion");
        // cin>>input;
    }
    if(input='lion'){
        omp_set_lock(&locked);
        printf("Moving lion");
    return 0;
    while(input!='gt'){
        printf("Write gt to move goat back");
        // cin>>input;
    }
    if(input='gt'){
        omp_set_lock(&locked);
        printf("Moving goat back");
}
    while(input!='gr'){
        printf("Write grass to move grass");
        // cin>>input;
    }
    if(input='gt'){
        omp_set_lock(&locked);
        printf("Moving grass");
}
    while(input!='back'){
        printf("Write back to move back");
        // cin>>input;
    }
    while(input!='goat'){
        printf("Write goat to move goat");
        // cin>>input;
    if(input='goat'){
        omp_set_lock(&locked);
        printf("Moving goat");
}
    }
}
    }}if(input='goat'){
        omp_set_lock(&locked);
        printf("Moving goat");
}