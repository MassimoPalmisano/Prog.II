#include <stdio.h>
#include <stdlib.h>

/*funzione che dati due array di valori interi ordinati, generi un terzo array che 
contenga tutti i valori dei precedenti array in modo ordinato*/
void merge(int **r, const int *a1, unsigned s1, const int *a2, unsigned s2);

int main(){
    int a1[] = {1, 2, 5, 6, 9};
    int a2[] = {0, 2, 4, 8, 10};
    int *merged = NULL;
    unsigned s1 = sizeof(a1)/sizeof(a1[0]);
    unsigned s2 = sizeof(a2)/sizeof(a2[0]);

    merge(&merged, a1, s1, a2, s2);

    printf("Stampa dei valori nell'array Merged: \n");
    for(unsigned i = 0; i < s1+s2; i++){
        printf("%d ", merged[i]);
    }

}

void merge(int **r, const int *a1, unsigned s1, const int *a2, unsigned s2){

    unsigned i = 0, j = 0, k = 0;
    unsigned size = s1 + s2;

    *r = (int *)malloc(size * sizeof(int));

    //merge dei due array
    while(i<s1 && j<s2){
        if(a1[i] <= a2[j]){
            (*r)[k++] = a1[i++];
        }
        else{
            (*r)[k++] = a2[j++];
        }

    }

    //accodare i valori in più di a1
    while(i<s1){
        (*r)[k++] = a1[i++];
    }

    //accodare i valori in più di a2
    while(j<s2){
        (*r)[k++] = a2[j++];
    }
}