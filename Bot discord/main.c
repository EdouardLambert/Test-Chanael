#include "fonctions.h"


int main() {
	bool start = true;
	int lvl = 0;
	int daily = 0;
	bool badge_daily = false;
	char selectAction;
	afficher_menu_principal();
	do {
		selectAction = getc(stdin);
		switch (selectAction)
		{
		case 'L':
		case 'l':
			system("cls");
			choixLVL1();
			break;
		case 'D':
		case 'd':
			system("cls");
			choixDAILY1();
			break;
		case 'T':
		case 't':
			system("cls");
			choixTOTAL();
			break;
		case 'S':
		case 's':
			system("cls");
			shop();
			break;
		}
	system("cls");
	afficher_menu_principal();
	} while (selectAction != 'X' && selectAction != 'x');
	return 0;
}