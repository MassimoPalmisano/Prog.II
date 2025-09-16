#include <stdio.h>
#include <stdlib.h>
//libreria necessaria per avere valori random
#include <time.h> 

int** allocateMatrix(int rows, int cols);                       //allocazione memoria matrice
void fillMatrix(int** matrix, int rows, int cols);              //riempimento con valori random
void sumMatrix(int** matrix, int rows, int cols, int* sum);     //somma di tutti i valori della matrice
void printMatrix(int** matrix, int rows, int cols);             //stampa della matrice
void freeMatrix(int** matrix, int rows);                        //deallocazione della memoria


int main(){
    int rig = 5;
    int col = 5;
    int** matrice = NULL;
    int somma = 0;

    matrice = allocateMatrix(rig, col);
    
    fillMatrix(matrice, rig, col);
    sumMatrix(matrice, rig, col, &somma);
    printMatrix(matrice, rig, col);
    printf("\nLa somma degli elementi della matrice é %d\n\n", somma);
    freeMatrix(matrice, rig);

}

int** allocateMatrix(int rows, int cols){

    int **matrice = (int**)malloc(rows *sizeof(int*));
    if(matrice == NULL){
        printf("Errore di allocazione \n");
        return NULL;
    }

    for(unsigned i = 0; i< rows; i++){
        matrice[i] = (int*)malloc(cols * sizeof(int));
        if(matrice[i] == NULL){
            printf("Errore di allocazione \n");
            return NULL;
        }   
    }

    return matrice;

}

void fillMatrix(int** matrix, int rows, int cols){

    for(unsigned i = 0; i<rows; i++){

        for(unsigned j = 0; j<cols; j++){
            matrix[i][j] = rand() %100;
        }

    }

}

void sumMatrix(int** matrix, int rows, int cols, int* sum){

    *sum = 0;

    for(unsigned i = 0; i<rows; i++){

        for(unsigned j = 0; j<cols; j++){
            *sum = *sum + matrix[i][j];
        }

    }

}

void printMatrix(int** matrix, int rows, int cols){

    printf("Stampa della matrice: \n");
    for(unsigned i = 0; i<rows; i++){

        for(unsigned j = 0; j<cols; j++){
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

}

 void freeMatrix(int** matrix, int rows){

    for(unsigned i = 0; i< rows; i++){
        free(matrix[i]);
    }

    free(matrix);

 }