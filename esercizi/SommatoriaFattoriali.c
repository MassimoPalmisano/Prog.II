#include <stdio.h>

int main(){

    int n = 5;
    int somma = 0;
    
    for(int i = 0; i<=n; i++){
        
        int f = 1;
        int j = i;

        while(j > 1){

        f *= j;

        j--;

        }

        somma += f;

    }

    printf("La sommatoria dei fattoriali da 1 a %d è %d \n", n, somma);

}