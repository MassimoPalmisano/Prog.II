#include <stdio.h>

int main(){

    int n = 10; 
    float sommatoria = 0; //somma
    float Gauss = 0;


    for(int i = 1; i<= n; i++){
        sommatoria += i;
    }

    Gauss = (n*(n+1)/2);

    if(Gauss == sommatoria) printf("I due numeri equivalgono \n");
    else printf("I due numeri non equivalgono \n");



}