#include <stdio.h>
#include <math.h>

int main(void){
    int number;
    int menos = 0;

    printf ("Number of lines: ");
    scanf("%d", &number);

    printf ("%s %s %s \n", "Número", "Quadrado", "Raiz Quadrada");
    printf ("============================\n");

    do{
        menos++;
        printf("%d %10.0lf %13.4lf \n" , menos, pow(menos, 2), sqrt(menos));
        
    }
    while (menos <= number);

    return 0;

}