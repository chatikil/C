#include <stdio.h>
#include <stdlib.h>

void fibonacci(int n) {
    int a = 0, b = 1, c, i;

    printf("Suite de Fibonacci jusqu'à %d :\n", n);
    printf("%d, %d, ", a, b);

    for (i = 2; i < n; i++) {
        c = a + b;
        printf("%d, ", c);
        a = b;
        b = c;
    }

    printf("\n");
}

int main() {
    int nombre;
    printf("Entrez le nombre de chiffre de la suite de Fibonacci que vous souhaitez générer : ");
    scanf("%d", &nombre);
    
    if(nombre <= 0) {
        printf("Veuillez ntrez un nombre positif.\n");
        return 1; 
    }
    
    fibonacci(nombre);

    return 0;
}
