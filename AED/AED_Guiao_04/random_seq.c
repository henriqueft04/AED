#include <stdio.h>
#include <assert.h>

int comparations = 0;

int check(int array[], int n){

    comparations = 0;

    assert(n > 2);
    int count = 0;

    for(int k = 2; k < n; k++){
        for (int j = 1; j<k; j++){
            for (int i = 0; i<j; i++){
                if(array[k] == array[i] + array[j]){
                    count++;
                }
                comparations++;
            }
        }
    }

    return count;
}

int main(void){

    int arrays[][40] = {
        //array com 5 elementos
        {1,2,3,4,5},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 1, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 1, 3, 2, 6, 7, 8, 9, 10},
        {0, 2, 2, 0, 3, 3, 0, 4, 4, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        //array com 20 elementos
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,12,13,14,15,16,17,18,19,20},
        //1 array com 30 elementos
        {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15, 16,17,18,19,20,21,22,23,24,25,26,27,28,29,30},
        //1 array com 40 elementos
        {1,2,3,4,5,6,7,8,9,10,11,12,13,14, 15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,
         31,32,33,34,35,36,37,38,39,40},
    
    };
    int array_sizes[] = {5, 10, 10, 10, 10, 10, 20, 30, 40};

    for(int i = 0; i < 9; i++){

        int count = check(arrays[i], array_sizes[i]);

        for(int j = 0; j < array_sizes[i]; j++){
            if(array_sizes[i] <= 6 && array_sizes[i] > 0){
                if(j == array_sizes[i]-1){
                    printf("%2d | %34s | %3d | %15s | %5d \n", arrays[i][j], "| Resultado", count, "Nº comparacoes", comparations);
                }
                else{
                    printf("%2d | ", arrays[i][j]);
                }
                
            }
            else if(array_sizes[i] > 5 && array_sizes[i] <= 10 ){
                if(j == array_sizes[i]-1){
                    printf("%2d | %s | %3d | %15s | %5d \n", arrays[i][j], "Resultado", count, "Nº comparacoes", comparations);
                }
                else{
                    printf("%2d | ", arrays[i][j]);
                }
            }
            else{
                printf("%s %d | %41s | %3d | %s | %5d \n","Elementos = ", array_sizes[i]  , "| Resultado", count, "Nº comparacoes", comparations);
                break;
            }
        }

        
    }

    return 0;
}
