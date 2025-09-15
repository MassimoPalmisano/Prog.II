#include <stdio.h>

//funzione che inverte l’ordine dei valori di un array di dati interi
void reversei(int *r, const int *values, unsigned size);

//funzione che individua la posizione di un valore all’interno di un array di interi
long fini(int t, const int *values, unsigned size); 

/*funzione che dati due array di valori interi ordinati, generi un terzo array che 
contenga tutti i valori dei precedenti array in modo ordinato*/
void merge(int *r, const int *a1, unsigned s1, const int *a2, unsigned s2);

/*funzione per il calcolo della serie di Fibonacci, in cui si calcolano i primi N valori e 
li si salvano in un array*/
void fibonacci(unsigned *r, unsigned n);


int main(){

int values[] = {11,3,23,8,7};
unsigned size = sizeof(values)/sizeof(values[0]);
int reverse[size];
int t = 7;
long posizione;
int a1[] = {1, 2, 5, 6, 9};
int a2[] = {0, 2, 4, 8, 10};
unsigned s1 = sizeof(a1)/sizeof(a1[0]);
unsigned s2 = sizeof(a2)/sizeof(a2[0]);
int merged[s1 + s2];
int n = 8;
int fibonacciR[n];



/*----------------- Reversei ------------------*/

/*reversei(reverse, values, size);

printf("Stampa di Values :\n");
for(unsigned i = 0; i<size; i++){
    printf("%d ", values[i]);
}

printf("\n\n");

printf("Stampa di Reverse :\n");
for(unsigned i = 0; i<size; i++){
    printf("%d ", reverse[i]);
}*/



/*----------------- Findi ------------------*/

/*posizione = fini(t, values, size);

if(posizione == -1){
    printf("Il valore %d non si trova all'interno dell'array \n", t);
}
else{
    printf("Il valore %d si trova in posizione %d dell'array \n", t, posizione + 1);
}*/



/*----------------- Merge ------------------*/

/*merge(merged, a1, s1, a2, s2);

printf("Stampa dei valori nell'array Merged: \n");
for(unsigned i = 0; i < s1+s2; i++){
    printf("%d ", merged[i]);
}*/



/*----------------- Fibonacci ------------------*/

fibonacci(fibonacciR, n);

printf("Stampa dei valori di Fibonacci fino al numero %d \n", n);
for(unsigned i = 0; i < n; i++){
    printf("%d ", fibonacciR[i]);
}
}



/*----------------- Reversei ------------------*/

void reversei(int *r, const int *values, unsigned size){

    for(unsigned i = 0; i<size; i++){

        r[i] = values[size - 1 - i];

    }

}

/*----------------- Findi ------------------*/

long fini(int t, const int *values, unsigned size){

    for(long i = 0; i<size; i++){
        if(values[i] == t){
            return i;
        }
    }

    return -1;

}

/*----------------- Merge ------------------*/

void merge(int *r, const int *a1, unsigned s1, const int *a2, unsigned s2){

    unsigned i = 0, j = 0, k = 0;

    //merge dei due array
    while(i<s1 && j<s2){
        if(a1[i] <= a2[j]){
            r[k++] = a1[i++];
        }
        else{
            r[k++] = a2[j++];
        }

    }

    //accodare i valori in più di a1
    while(i<s1){
        r[k++] = a1[i++];
    }

    //accodare i valori in più di a2
    while(j<s2){
        r[k++] = a2[j++];
    }
}

/*----------------- Fibonacci ------------------*/

void fibonacci(unsigned *r, unsigned n){

    int somma = 1;
    r[0] = 0;
    r[1] = 1;

    for(unsigned i = 1;i < n; i++){
        somma = somma + r[i - 1];
        r[i + 1] = somma;
    }
    
}
