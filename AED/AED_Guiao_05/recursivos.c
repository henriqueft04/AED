#include <stdio.h>
#include <math.h>
#include <assert.h>

int counter = 0;

unsigned long primeiro(int n){

    assert(n>0);
    
    if(n==1){
        return 1;
    }

    counter ++;
    return (n + primeiro(n/2));
}

unsigned long segundo(int n){

    assert(n>0);

    if(n==1){
        return 1;
    }
    counter ++;
    return (n + segundo(n/2) + segundo((n+1)/2));
}

unsigned long terceiro(int n){

    assert(n>0);

    if(n==1){
        return 1;
    }
    counter ++;

    if(n%2 != 0){
        return(terceiro(n/2) + terceiro((n+1)/2) + n); 
    }

    
    return(n + 2 * terceiro(n/2));
}

int main(void){

    printf("|-----|--------------|----------------|--------------|----------------|--------------|----------------|\n");
    printf("| %3s | %s | %s | %s | %s | %s | %s | %s | \n", "N","1ª Função(N)", "Nº de chamadas", "Teste" , "2ª Função(N)", "Nº de chamadas", "3ª Função(N)", "Nº de chamadas");
    printf("|-----|--------------|----------------|--------------|----------------|--------------|----------------|\n");

    for(int i = 1; i < 16; i++){
        counter = 0;
        printf("| %3d ", i);
        printf("| %12lu ", primeiro(i));
        printf("| %15d", counter);
        printf("|%d", 2.5 * lo)
        

        counter = 0;
        printf("| %13lu", segundo(i));
        printf("| %15d", counter);

        counter = 0;
        printf("| %13lu", terceiro(i));
        printf("| %15d", counter);
        printf("|\n");
        
    }
    printf("|-----|--------------|----------------|--------------|----------------|--------------|----------------|\n");

    return 0;
}