#include <stdio.h>

int main() {

    int n = 5;
    int a = 2;
    int p = 1;

    for(int i = 0; i<n; i++){
        p *= a;
    }
    
    printf("%d alla %d è uguale a %d \n\n", a, n, p);

}