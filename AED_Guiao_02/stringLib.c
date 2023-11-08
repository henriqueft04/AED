#include <stdio.h>
#include <strings.h>

int main(){

    printf("Insira uma string: ");
    char str1[100];
    fgets(str1, 100, stdin);

    printf("Insira uma outra string: ");
    char str2[100];
    fgets(str2, 100, stdin);

    int letras = 0;
    int tamanho1 = strlen(str1);

    for(int i = 0; i < tamanho1 ; i++){
        // if is alpha(str1[i]){
        // count++;
        // } (outra maneira de fazer mais eficiente
        if(str1[i] >= 'A' && str1[i] <= 'Z' || str1[i] >= 'a' && str1[i] <= 'z'){
            letras++;
        }
    }

    printf("A string %s tem %d letras \n", str1, letras);

    int maisculas = 0;
    int tamanho2 = strlen(str2);

    for(int i = 0; i< tamanho2; i++){
        if(str2[i] >= 'A' && str2[i] <= 'Z'){
            maisculas++;
        }
    }

    printf("A string %s tem %d letras maisculas \n", str2, maisculas);

    char str1big[50]; 

    for(int i = 0; i < tamanho1; i++){
        if(str1[i] >= 'a' && str1[i] <= 'z'){
            str1big[i] = str1[i] - 32;
        }
    }

    char str2big[50];

    for(int i = 0; i < tamanho2; i++){
        if(str2[i] >= 'a' && str2[i] <= 'z'){
            str2big[i] = str2[i] - 32;
        }
    }

    printf("A primeira string em maiusculas é %s \n", str1big);
    printf("A segunda string em maiusculas é %s \n", str2big);

    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    int compare = strcmp(str1, str2);

    if (compare == 0) {
        printf("As strings são iguais");
    } else if (compare < 0) {
        printf("A string: %s é menor que a string: %s", str1, str2);
    } else {
        printf("A string: %s é menor que a string: %s", str2, str1);
    }

    char copia[50];

    strcpy(copia, str2);

    printf(strcat(str2, copia));

    return 0;

}


    

