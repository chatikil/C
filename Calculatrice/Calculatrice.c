#include <stdio.h>
#include <stdlib.h>

int main() {
    float x;
    float y;
    char a;
    float resultat = 0.0;
    
    printf("Veuillez taper votre opération à 2 facteurs:\n");
    scanf("%f%c%f", &x, &a, &y);
    while (a != '+' && a != '-' && a != '*' && !(a == '/' && y != 0)) {
        printf("Cet opérateur n'est pas disponible ou vous essayez de diviser par ZÉRO!\nSaisissez à nouveau votre opération: ");
        scanf("%f%c%f", &x, &a, &y);
    }
    
    if (a == '+') {
        resultat = x + y;
        printf("Le résultat de ce calcul est: %.2f\n", resultat);
    }
    
    if (a == '-') {
        resultat = x - y;
        printf("Le résultat de ce calcul est: %.2f\n", resultat);
    }
    
    if (a == '*') {
        resultat = x * y;
        printf("Le résultat de ce calcul est: %.2f\n", resultat);
    }
    
    if (a == '/') {
        resultat = x / y;
        printf("Le résultat de ce calcul est: %.2f\n", resultat);
    }
    return 0;
}
