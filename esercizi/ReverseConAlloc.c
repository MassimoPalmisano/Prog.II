#include <stdio.h>
#include <stdlib.h>

int* reversei(const int *values, unsigned size);


int main(){

int values[] = {1,2,3,4,5};
unsigned size = sizeof(values)/sizeof(values[0]);

int *reverse = reversei(values, size);

printf("Stampa dell'array invertito: \n");
for(unsigned i = 0; i < size; i++){
        printf("%d ", reverse[i]);
    }

}

int* reversei(const int *values, unsigned size){

    if(values == NULL || size == 0){
        return NULL;
    }

    int *reverse = (int *)malloc(size * sizeof(int));
    if(reverse == NULL){
        return NULL;
    }

    for(unsigned i = 0; i < size; i++){
        reverse[i] = values[size - 1 - i];
    }

    return reverse;

}
