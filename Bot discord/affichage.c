#include "affichage.h"
#include "fonctions.h"


void afficher_menu_principal() {
	printf("\n\n Stats et Test de Chanael :");
	printf("\n\n\t(L) Affiche les stats d'un niveau");
	printf("\n\t(D) Affiche les stats de daily");
	printf("\n\t(T) Affiche les pièces totales");
	printf("\n\t(S) Affiche le shop");
	printf("\n\n\t\t(X) Fermer\n");
}

int choixLVL1() {
	printf("\n\n\t (A) Afficher les niveau [1 - 50]");
	printf("\n\n\t (Z) Choisir un niveau en particulier");
	printf("\n\n\t (X) Retour\n");
	char selectAction;
	do {
		selectAction = getc(stdin);
		switch (selectAction) {
			case 'A':
			case 'a':
				system("cls");
				for (int lvl = 0; lvl <= 50; lvl++) {
					statsLVL(lvl);
				}
				printf("\n\n\t (X) Retour\n");
				break;
			case 'Z':
			case 'z':
				system("cls");
				choixLVL2();
				printf("\n\n\t (X) Retour\n");
				break;
		}
	} while (selectAction != 'X' && selectAction != 'x');
	system("cls");
	return 0;
}

int choixLVL2() {
	printf("\n\n\t Choisir le niveau :");
	printf("\n\n\t (XX) Retour\n");
	char selectAction;
	int lvl;
	int res;
	do {
		selectAction = getc(stdin);
		res = scanf_s("%d", &lvl);
		system("cls");
		statsLVL(lvl);
		printf("\n\n\t (XX) Retour\n");
	} while (selectAction != 'X' && selectAction != 'x');
	system("cls");
	return 0;
}

int choixDAILY1() {
	printf("\n\n\t Choisir le nombre de jours :");
	printf("\n\n\t (XXX) Retour\n");
	char selectAction;
	int nb_jours;
	int res;
	do {
		selectAction = getc(stdin);
		res = scanf_s("%d", &nb_jours);
		system("cls");
		choixDAILY2(nb_jours);
		printf("\n\n\t (XXX) Retour\n");
	} while (selectAction != 'X' && selectAction != 'x');
	system("cls");
	return 0;
}

int choixDAILY2(int nb_jours) {
	printf("\n\n\t (N) SANS badge daily");
	printf("\n\n\t (B) AVEC badge daily");
	printf("\n\n\t (XXX) Retour\n");
	char selectAction;
	int daily = 0;
	do {
		selectAction = getc(stdin);
		switch (selectAction) {
		case 'N':
		case 'n':
			system("cls");
			calculDAILY(daily, nb_jours, false, true);
			printf("\n\n\t (XXX) Retour\n");
			break;
		case 'B':
		case 'b':
			system("cls");
			calculDAILY(daily, nb_jours, true, true);
			printf("\n\n\t (XXX) Retour\n");
			break;
		}
	} while (selectAction != 'X' && selectAction != 'x');
	system("cls");
	return 0;
}

int choixTOTAL() {
	printf("\n\n\t Choisir le niveau :");
	printf("\n\n\t (X) Retour\n");
	char selectAction;
	int lvl;
	int res;
	do {
		selectAction = getc(stdin);
		res = scanf_s("%d", &lvl);
		system("cls");
		coinsTOTAL(lvl);
		printf("\n\n\t (X) Retour\n");
	} while (selectAction != 'X' && selectAction != 'x');
	system("cls");
	return 0;
}