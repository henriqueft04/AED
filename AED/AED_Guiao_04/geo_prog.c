#include <stdio.h>
#include <assert.h>

int comparations = 0;

int check(int a[], int n){
    assert(n > 2);

    comparations = 0;
    double r = a[1]/a[0];

    for(int i = 1; i < n; i++){
        
        if(a[i] != a[i-1]*r){
            
            return 0;     
        }
        comparations++;
    }

    return 1;
}

int main(void){

    int arrays[][10] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 4, 4, 5, 6, 7, 8, 9, 10}, 
        {1, 2, 4, 8, 5, 6, 7, 8, 9, 10},   
        {1, 2, 4, 8, 16, 6, 7, 8, 9, 10},
        {1, 2, 4, 8, 16, 32, 7, 8, 9, 10},
        {1, 2, 4, 8, 16, 32, 64, 8, 9, 10},
        {1, 2, 4, 8, 16, 32, 64, 128, 9, 10},
        {1, 2, 4, 8, 16, 32, 64, 128, 256, 10},
        {1, 2, 4, 8, 16, 32, 64, 128, 256, 512},
    };

    for(int i = 0; i < 9; i++){

        int count = check(arrays[i], sizeof(arrays[i])/sizeof(arrays[i][0]));

        for(int j = 0; j < sizeof(arrays[i])/sizeof(arrays[i][0]); j++){
            printf("%3d | ", arrays[i][j]);
        }
        printf("Resultado | %d  |", count);
        printf("Nº comparacoes | %d \n", comparations);
        
    }

    return 0;
}