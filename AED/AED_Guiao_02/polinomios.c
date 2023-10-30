#include <stdio.h>
#include <assert.h>
#include <math.h>

void DisplayPol(double* coef, size_t degree){
    assert(coef != NULL && degree >= 0);

    for(size_t i = 0; i <= degree; i++){
        
        if(degree - i != 0){
            printf("%lf * x^ %d ", coef[i], degree-i);
            if(i<degree){
                printf(" + ");
            }
        }
        else{
            printf("%lf", coef[i]);
        }
        

    }

    printf(" \n ");
        
}

double ComputePol(double* coef, size_t degree, double x){
    assert(coef != NULL && degree >= 0);
    double result = 0;
    for(size_t i = 0; i <= degree; i++){

        result += coef[i] * pow(x,(degree-i));

    }

    return result;
}

unsigned int GetRealRoots(double* coef, size_t degree, double* root_1, double* root_2){
    assert(coef != NULL && degree ==2 && coef[0] != 0);
    assert(root_1 != NULL && root_2 != NULL);

    double raiz = pow(coef[1],2) - 4*coef[0]*coef[2];

    if(raiz < 0){
        return 0;
    }
    else if(raiz == 0){
        *root_1 = (-coef[1] + sqrt(raiz))/(2*coef[0]);
        return 1;
    }
    else{
        *root_1 = (-coef[1] + sqrt(raiz))/(2*coef[0]);
        *root_2 = (-coef[1] - sqrt(raiz))/(2*coef[0]);

        if(*root_1 == *root_2){
            return 1;
        }
        else{
            return 2;
        }
    }

}


int main(){
    double coef[5] = {1,4,1};
    printf("---------POLINOMIO--------\n");
    DisplayPol(coef, 2);

    printf("---------COMPUTED VALUE--------\n");
    printf("%lf \n", ComputePol(coef, 2, 2));

    printf("---------REAL ROOTS--------\n");
    double root_1, root_2;
    unsigned int roots  = GetRealRoots(coef, 2, &root_1, &root_2);
    printf("%d", roots);
    return 0;
}

