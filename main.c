#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

int main() {

	// Mot a deviner
	char words[TAILLE_TAB][MAX_STR_LENGTH] = { "ROUGE", "BLEU", "VERT", "MAISON", "FRANCE", "BOUTEILLE", "CLAVIER" };

	// Tire un mot aléatoire
	srand(time(NULL)); // Initialisation de la graine de l'aléatoire

	int indexSecretWord = (rand() % TAILLE_TAB); // Tire un index aléatoire entre 0 et 6

	// String du mot secret
	char secretWord[MAX_STR_LENGTH];

	// Copy d'une chaine aléatoire dans la variable secretWord
	strcpy(secretWord, words[indexSecretWord]);

	// Nombre de lettre
	int countLetter = strlen(secretWord);

	// Initalisation du pointer
	int* lettreTrouvee = NULL;

	// Attribution de l'espace mémoire
	lettreTrouvee = malloc(countLetter * sizeof(int));
	initArray(lettreTrouvee, countLetter);

	int nbrCoup = 10;
	char lettre = 0;

	printf("Bienvenue dans le jeu du pendu !\n");


	while (nbrCoup > 0 && !hasWon(lettreTrouvee, countLetter)) {
		printf("\n\nIl vous reste %d coups a jouer\n", nbrCoup);
		printf("Quel est le mot secret ? \n");

		for (int i = 0; i < countLetter; i++) {
			if (lettreTrouvee[i]) {
				printf("%c", secretWord[i]);
			}
			else {
				printf("*");
			}
		}

		printf("\n\nProposez une lettre : ");
		lettre = lireCaractere();

		// Si ce n'était pas la bonne lettre
		if (!rechercheLettre(lettre, secretWord, lettreTrouvee)) {
			nbrCoup--;
		}
	}

	if (hasWon(lettreTrouvee, countLetter)) {
		printf("\n\nGagne ! Le mot secret etait bien : %s", secretWord);
	}
	else {
		printf("\n\Perdu ! Le mot secret etait : %s", secretWord);
	}

	free(lettreTrouvee);

	return 0;
}

void initArray(int* lettreTrouvee, int sizeArray) {
	int i;

	for (i = 0; i < sizeArray; i++) {
		lettreTrouvee[i] = 0;
	}
}

int hasWon(int* lettreTrouvee, int countLetter) {
	int i;
	int joueurGagne = 1;

	for (i = 0; i < countLetter; i++) {
		if (lettreTrouvee[i] == 0) {
			joueurGagne = 0;
		}
	}

	return joueurGagne;
}

char lireCaractere() {
	char caractere = 0;

	caractere = getchar(); // On lit le premier caractère
	caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà

	// On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)
	while (getchar() != '\n');

	return caractere; // On retourne le premier caractère qu'on a lu
}

int rechercheLettre(char lettre, char secretWord[], int* lettreTrouvee) {
	int i;
	int bonneLettre = 0;

	for (i = 0; secretWord[i] != '\0'; i++) {
		// Si la lettre rechercher est dans le mot secret
		if (lettre == secretWord[i]) {
			bonneLettre = 1;
			// On met à 1 toute les lettres qui ont été trouvée
			lettreTrouvee[i] = 1;
		}
	}

	return bonneLettre;
}