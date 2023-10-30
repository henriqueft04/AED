#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int* digits(int i, int* size){
    int* digitos = malloc(10 * sizeof(int));
    if(digitos == NULL){
        printf("Erro na alocacao de memoria");
        return NULL;
    }

    int count = 0;
    while (i > 0)
    {
        int inteiro = i%10;
        digitos[count] = inteiro;
        count++;
        i /= 10;

        if(count >= *size){
            *size *= 2;
            int* novoDigitos = realloc(digitos,( *size) * sizeof(int));
            if (novoDigitos == NULL) {
                free(digitos);
                printf("Erro no realloc");
                return NULL;
            }
            digitos = novoDigitos;
        }
    }
    return digitos;
}


int main(void){

    int size = 100;
    int n = 1000;
    int armstrong[size];
    int count = 0;
    for(int i = 0; i < n; i++){
        int soma = 0;
        int dig_size = size;
        int* digitos = digits(i,&dig_size);
        for (int j = 0; j < dig_size; j++) {
            soma += pow((double)digitos[j], (double)(dig_size - 1));
        }

        if(soma == i){
            armstrong[count] = i;
            count++;
        }
        
    }
    for(int k = 0; k < count; k++ ){
        printf("%d ; ", armstrong[k]);
    }
    printf("\n done \n");

    return 0;
}