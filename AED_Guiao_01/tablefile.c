#include <stdio.h>
#include <math.h>

int main(void){

    FILE *tabela = fopen("tabela.txt", "w");

    int smaller;
    int greater;
    int interval;
    
    printf ("Ângulo mais pequeno: ");
    scanf("%d", &smaller);

    printf("Ângulo maior: ");
    scanf("%d", &greater);

    printf("Intervalo entre ângulos: ");
    scanf("%d", &interval);

    fprintf (tabela, "%s %10s %13s \n", "Ang", "sin(ang)", "cos(ang)");
    fprintf (tabela, "============================\n");

    int atual = smaller;

    do{
        double radianos = atual * M_PI / 180;
        fprintf(tabela, "%3d %10.6lf %13.6lf \n" , atual, sin(radianos), cos(radianos));
        atual = atual + interval;
        
    }
    while (atual <= greater);

    fclose (tabela);

    return 0;

}