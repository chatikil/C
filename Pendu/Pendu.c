#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 6
#define MAX_WORD_LEN 20

void afficherPendu(int essais);
void afficherMot(char mot[], int devine[]);
int verifierLettre(char mot[], char lettre, int devine[]);

int main() {
    char mot[MAX_WORD_LEN];
    char lettre;
    int devine[MAX_WORD_LEN] = {0}; // Initialise un tableau pour garder trace des lettres devinées
    int essais = 0;
    int longueurMot, i;

    // Saisie du mot à deviner
    printf("Entrez le mot à deviner : ");
    scanf("%s", mot);
    longueurMot = strlen(mot);

    // Convertit le mot en minuscules
    for (i = 0; i < longueurMot; i++) {
        mot[i] = tolower(mot[i]);
    }

    // Boucle de jeu
    while (essais < MAX_TRIES) {
        printf("\n\n");
        afficherPendu(essais);
        printf("\n\n");
        afficherMot(mot, devine);

        printf("\n\nEntrez une lettre (ou le mot): ");
        scanf(" %c", &lettre);

        lettre = tolower(lettre);

        if (verifierLettre(mot, lettre, devine)) {
            printf("\nCorrect !\n");
        } else {
            printf("\nIncorrect !\n");
            essais++;
        }

        // Vérifie si le mot est deviné
        for (i = 0; i < longueurMot; i++) {
            if (!devine[i]) {
                break;
            }
        }

        if (i == longueurMot) {
            printf("\nFélicitations ! Vous avez deviné le mot: %s\n", mot);
            return 0;
        }
    }

    printf("\nPerdu ! Le mot était : %s\n", mot);

    return 0;
}

// Fonction pour afficher le pendu
void afficherPendu(int essais) {
    switch (essais) {
        case 0:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 1:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 2:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 3:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 4:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 5:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" /    |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 6:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" / \\  |\n");
            printf("      |\n");
            printf("=========\n");
            break;
    }
}

// Fonction pour afficher le mot avec des underscores pour les lettres non devinées
void afficherMot(char mot[], int devine[]) {
    int i;
    int longueurMot = strlen(mot);

    for (i = 0; i < longueurMot; i++) {
        if (devine[i]) {
            printf("%c ", mot[i]);
        } else {
            printf("_ ");
        }
    }
}

// Fonction pour vérifier si une lettre devinée est correcte
int verifierLettre(char mot[], char lettre, int devine[]) {
    int i;
    int longueurMot = strlen(mot);
    int correct = 0;

    for (i = 0; i < longueurMot; i++) {
        if (mot[i] == lettre) {
            devine[i] = 1;
            correct = 1;
        }
    }

    return correct;
}
