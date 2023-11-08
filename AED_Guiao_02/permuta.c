#include <stdio.h>

void Permute(int* a, int* b, int* c);

int main(){

    int a = 24;
    int b = 16;
    int c =3;

    printf("Before Permute: %d %d % d\n", a,b,c);

    Permute(&a, &b, &c);

    printf("After Permute: %d %d %d\n", a, b, c);

    return 0;

}

void Permute(int* a, int* b, int* c){

    int aOG = *a;

    *a = *c;
    *c = *b;
    *b = aOG;
}