#include <stdio.h>
#include <stdlib.h>

int main(){

    int col = 3;
    int rig = 3;
    int h = 0;
    int **matrice = (int **)malloc(rig * sizeof(int*));

    for(unsigned i = 0; i< rig; i++){
        matrice[i] = (int *)malloc(col * sizeof(int));
    }

    for(unsigned i = 0; i< rig; i++){
        for(unsigned j = 0; j< col; j++){
            matrice[i][j] = h;
            h++;
        }
    }

    printf("Stampa della matrice : \n\t");
    for(unsigned i = 0; i< rig; i++){
        for(unsigned j = 0; j< col; j++){
            printf("%d ", matrice[i][j]);
        }
        printf("\n\t");
    }

    for(unsigned i = 0; i< rig; i++){
        free(matrice[i]);
    }

    free(matrice);

}