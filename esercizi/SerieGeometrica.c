#include <stdio.h>

//serie Geometrica Troncata con due cicli for

int main(){

    int n = 10;         //limite superiore della sommatoria
    float somma = 0;    //valore della sommatoria
    float r = 0.5;      //valore a cui applicare la potenza
    float a = 3;        //valore da moltiplicare
    
    for(int i = 0; i<=n; i++){      //for che incrementa il valore della sommatoria
        
        float p = 1;
        for(int j = 0; j<i; j++){   //for per fare la potenza
            
            p *= r;

        }
        somma +=  (a * p);

    }

    printf("\n La serie geometrica troncata di %f ha valore %f \n", a, somma);

}