#include <stdio.h>

int main(){

    int m = 10;
    float s = 0;

    for(float i = 1; i<= m; i++){
        s += (1/i);
    }

    printf("Il valore della serie armonica di %d è %f \n\n", m, s);

}