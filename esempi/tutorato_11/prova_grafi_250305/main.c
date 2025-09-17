#include <stdio.h>
#include <stdlib.h>

#include "tipo.h";


tipo_inf* creaNodi(int *n) {
    FILE *f = fopen("nodi.txt", "r");
    if (!f) {
        perror("Errore apertura nodi.txt");
        exit(1);
    }

    fscanf(f, "%d", n);
    tipo_inf *nodes = malloc((*n) * sizeof(tipo_inf));
    if (!nodes) {
        perror("Errore malloc nodi");
        exit(1);
    }

    for (int i = 0; i < *n; i++) {
        fscanf(f, "%s", nodes[i].descrizione); // nome utente o prodotto
        fscanf(f, " %c", &nodes[i].tipo);       // tipo 'U' o 'P'
    }

    fclose(f);
    return nodes;
}

int main(){

    

}