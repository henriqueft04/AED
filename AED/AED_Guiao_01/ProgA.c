#include <stdio.h>

void printArray(char s[], int a[], int lenght);
void cumSum(int a[], int b[], int lenght);

int main(){

    int a[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    int length = sizeof(a) / sizeof(a[0]);
    printArray("a", a, length);

    int b[12];
    cumSum(a, b, length);
    printArray("b", b, length);

    return 0;
}

void printArray(char s[], int a[], int length ){

    printf("%s: \n" ,s );
    for(int i=0; i<length; i++){

        printf("%d ", a[i]);
    }
    printf("\n");

}

void cumSum(int a[], int b[], int length){

    int c = 0;
    for(int i=0; i< length;i++){
        c = c + a[i];
        b[i] = c;
    }
}