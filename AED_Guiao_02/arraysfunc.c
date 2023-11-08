#include <stdio.h>

void DisplayArray(double* a, size_t n){
    for( int i = 0; i < n; i++){
        if(a[i] != 0){
            printf("%f ", a[i]);
        }
    }
}

double* ReadArray(size_t* size_p){
    assert(size_p !=NULL);
    size_t n;
    printf("Array size(>0) : ");
    scanf("%zu", &n);
    assert(n>0);

    double* array =malloc(n*sizeof(*array) );
    if(array==NULL){
        *size_p = 0;
        return NULL;
    }

    for (size_t i = 0; i<n;i++){
        printf("A[%2zu] = ", i);
        scanf("%lf", &array[i]);
    }

    *size_p = n;
    return array;
}

double* Append(double array_1, size_t size_1, double* array_2, size_t size_2){
    
}

int main(void){

    
}