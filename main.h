#define TAILLE_TAB 7
#define MAX_STR_LENGTH 10

void initArray(int* lettreTrouvee, int sizeArray);
int hasWon(int* lettreTrouvee, int countLetter);
char lireCaractere();
int rechercheLettre(char lettre, char secretWord[], int* lettreTrouvee);