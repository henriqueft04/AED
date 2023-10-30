#include <stdio.h>
#include <math.h>

int main(void){
    int smaller;
    int greater;
    int interval;
    
    printf ("Ângulo mais pequeno: ");
    scanf("%d", &smaller);

    printf("Ângulo maior: ");
    scanf("%d", &greater);

    printf("Intervalo entre ângulos: ");
    scanf("%d", &interval);

    printf ("%s %10s %13s \n", "Ang", "sin(ang)", "cos(ang)");
    printf ("============================\n");

    int atual = smaller;

    do{
        double radianos = atual * M_PI / 180;
        printf("%3d %10.6lf %13.6lf \n" , atual, sin(radianos), cos(radianos));
        atual = atual + interval;
        
    }
    while (atual <= greater);

    return 0;

}