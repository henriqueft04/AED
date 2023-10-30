#include <stdio.h>

long count = 0;

unsigned long delannoy(int m, int n){
    
    count++;
    if((m == 0) || (n == 0)){
        return 1;
    }

    return(delannoy(m-1,n)+delannoy(m-1,n-1)+delannoy(m,n-1));
}

unsigned long iterative_delannoy(int m, int n){

    count++;
    long unsigned int it_delannoy[m+1][n+1];
    long r= 0;

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i == 0 || j == 0){
                r = 1;
            }
            else{
                r = it_delannoy[i-1][j] + it_delannoy[i-1][j-1] + it_delannoy[i][j-1];
            }
            it_delannoy[i][j] = r ;
        }
    }

    return it_delannoy[m][n];
}

#define SIZE_N 100
#define SIZE_M 100


long long memo[SIZE_M +1][SIZE_N +1];

void start_memo(){
    for(int i=0; i<SIZE_M; i++){
        for(int j = 0; j<SIZE_N; j++){
            memo[i][j] = -1;
        }
    }
}

unsigned long memoization_delannoy(int m, int n){

    count ++;
    if((m == 0) || (n == 0)){

        return 1;
    }

    if (memo[n][m] != -1){
        return memo[m][n];
    }

    memo[m][n] = memoization_delannoy(m - 1, n) + memoization_delannoy(m - 1, n - 1) + memoization_delannoy(m, n - 1);

    return memo[m][n];

}

int main(){


    int m = 11;
    int n = 10;
    printf("Número de Delannoy recursivo para (%d, %d) é %lu com %lu chamadas\n", m, n, delannoy(m, n), count);

    for (int i = 0; i < 12; i++) {
        printf("%12d", i);
    }
    printf("\n");

    for (int i = 0; i < 11; i++) {

        count = 0;
        printf("%12d", i);

        for (int j = 0; j < 11; j++) {
            printf("%12lu", delannoy(i, j));
        }
  
        printf("%6s = %d","     Chamadas", count);
        printf("\n");
    }

    count = 0;
    printf("Número de Delannoy iterativo para (%d, %d) é %lu com %lu chamadas\n", m, n, iterative_delannoy(m, n), count);

    start_memo();
    for (int i = 0; i < 12; i++) {
        printf("%12d", i);
    }
    printf("\n");

    for (int i = 0; i < 11; i++) {

        count = 0;
        printf("%12d", i);

        for (int j = 0; j < 11; j++) {
            printf("%12lu", memoization_delannoy(i, j));
        }
  
        printf("%6s = %d","     Chamadas", count);
        printf("\n");
    }

    printf("Número de Delannoy iterativo para (%d, %d) é %lu com %lu chamadas\n", m, n, iterative_delannoy(m, n), count);


    return 0;
}