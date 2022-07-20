#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define DAILY 125

int main() {

	int xp = 0;
	int coin = 0;
	int lvl = 0;
	int nbmess = 0;
	int nbmess_cumul = 0;
	int coins_cumul = 0;
	int daily_cumul = 0;
	
	// XP //
	printf("// XP //\n\n");
	for (lvl = 0; lvl <= 50; lvl++) {
		xp = (3 * lvl + 150) * (pow(1.05, lvl)); // calcul de l'xp a avoir pour chaque niveau
		nbmess = xp / 7; // moyenne du nombre de message a envoyer pour passer au niveau suivant
		nbmess_cumul += nbmess; // moyenne du nombre de message a envoyer en tout pour atteindre ce niveau
		printf("Lvl %2d : %4d xp | nb mess : %3d | nb de mess total : %4d\n", lvl, xp, nbmess, nbmess_cumul);	
	}

	// COINS //
	printf("\n\n// COINS //\n\n");
	for (lvl = 1; lvl <= 50; lvl++) {
		// calcul du nombre de pièces données pour chaque niveau
		if (lvl % 5 == 0) {
			if (lvl % 10 == 0) {
				coin = 250 * lvl; // palier 10
			}
			else {
				coin = 100 * lvl; // palier 5
			}
		}
		else {
			coin = 25 * lvl; // palier unitaire
		}
		coins_cumul += coin;
		printf("Lvl %2d : %5d coins | %5d coins cumul\n", lvl, coin, coins_cumul);
	}


	// DAILY //
	printf("\n\n// DAILY //\n\n");
	for (int day = 0; day <= 242; day++) { // 242 jours => nb de jours entre 01/09/22 et 01/05/23
		daily_cumul += DAILY;
	}
	printf("1j !daily = %5d coins\n", DAILY);
	printf("1y !daily = %5d coins\n", daily_cumul);


	// TOTAL COINS (pièces gagnés pour chaques messages + par palier + par daily) //
	int total = coins_cumul + (nbmess_cumul * 10) + daily_cumul;
	printf("\n\nTOTAL : %d coins\n", total);


	// SHOP //
	printf("\n\n// SHOP //\n\n");
	printf("Cafe / Chocolat Chaud | 15 000\n");
	printf("Pinte de Bierre       | 50 000\n");
	printf("                      | \n");
	printf("                      | \n");
	printf("                      | \n");
	printf("Brazzers              | 300 000\n");
	printf("Emotes                | ???\n");
	printf("Badge Daily           | ???\n");
}