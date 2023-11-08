#include <stdio.h>
#include <assert.h>

int comparations = 0;

int check(int array[],int n){

    comparations = 0;

    assert(n > 2);
    int count = 0;

    for(int i = 1 ; i < n-1 ; i++){
        if(array[i] == array[i-1] + array[i+1]){
            count++;
        }

        comparations++;
    }

    return count;
}


int main(void){

    int arrays[][10] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 1, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 1, 3, 2, 6, 7, 8, 9, 10},
        {0, 2, 2, 0, 3, 3, 0, 4, 4, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    for(int i = 0; i < 5; i++){

        int count = check(arrays[i], sizeof(arrays[i])/sizeof(arrays[i][0]));

        for(int j = 0; j < sizeof(arrays[i])/sizeof(arrays[i][0]); j++){
            printf("%2d | ", arrays[i][j]);
        }
        printf("Resultado | %d  |", count);
        printf("Nº comparacoes | %d \n", comparations);
        
        
    }

    return 0;
}