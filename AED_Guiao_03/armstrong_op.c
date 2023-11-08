#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int ciclos = 0;

void conta_ciclos(){
    ciclos++;
}

int countDigits(int i){
    int count = 0;
    while (i > 0)
    {
        count++;
        i /= 10;
        conta_ciclos();
    }
    return count;
}

int ArmsStrongChecker(int num){

    int ogNum = num;
    int numDigits = countDigits(num);
    int soma = 0;

    while(num > 0){

        int digito = num % 10;
        num /= 10;
        soma += pow(digito, numDigits);
    }

    if(soma == ogNum && ogNum != 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(void){
    int n = 99999;

    for( int i = 0; i < n; i++ ){
        if (ArmsStrongChecker(i)){
            printf("%d ; ", i);
        }
    }

    printf(" \n Done in %d cicles!", ciclos);

    return 0;
}