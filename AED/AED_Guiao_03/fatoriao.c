#include <stdio.h>

int fatorial[10];

void preFatoriais(){
    fatorial[0] = 1;
    fatorial[1] = 1;
    for(int i = 2; i<10; i++){
        fatorial[i] = fatorial[i-1]*i;
    }
}

int somaFatorial(int n){
    int soma = 0;
    while (n > 0)
    {
        int inteiro = n%10;
        soma += fatorial[inteiro];
        n /= 10;
    }
    return soma;
}

int main(void){

    preFatoriais();
    int fatorioes[1000];
    int count = 0;
    for (int i = 1; i < 10e5; i++){
        int soma = somaFatorial(i);
        if(soma == i){
            fatorioes[count] = i;
            count++;
        }
    }
    for(int i = 0; i < count; i++){
        printf("%d ; ", fatorioes[i]);
    }
    printf("\n done \n");

    return 0;
}

