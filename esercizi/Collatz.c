#include <stdio.h>

/*
- Sviluppare il seguente algoritmo:
        – Si prenda numero intero positivo n.
        – Se n = 1 l’algoritmo termina.
        – Finché n > 1, se n è pari, lo si divida per 2; se n dispari lo si moltiplichi per 3 e si aggiunga 1.
- La congettura di Collatz asserisce che questo algoritmo giunge sempre a termine,
    indipendentemente dal valore di partenza.
- Assegnare 2 valori ad a e b e, per tutti i numeri compresi tra a e b, stampare quanti cicli compie
    l’algoritmo
*/

void collatz(int n){

    int conta = 1;

    while(n > 1){

        if((n%2) == 0){
            n = n/2;
        }
        else{
            n = (n*3)+1; 
        } 

        conta++;

    }
    printf("L'algoritmo è terminato. \n Il numero totale di cicli compiuti è %d\n\n", conta);

}

int main(){

    int a = 3;
    int b = 6;

    for(int i = a; i <= b; i++){
        collatz(i);
    } 


}