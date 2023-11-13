#pragma omp barrier

#pragma omp taskwait

#pragma omp atomic

c=a*b;
b=c+b;
a=b/c;

#pragma omp ciritical

myValue++

