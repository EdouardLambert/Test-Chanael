#include "fonctions.h"


int xpLVL(int lvl, int* xp, int* xp_cumul) {
	if (xp == NULL || xp_cumul == NULL || lvl < 0) {
		return 1;
	}
	*xp_cumul = 0;
	for (int niv = 0; niv <= lvl; niv++) {
		*xp = (3.5 * niv + 150) * (pow(1.05, niv)); // xp pour aller au prochain niveau
		*xp_cumul += *xp;
	}
	return 0;
}


int coinLVL(int lvl, int* coin, int* coins_cumul) {
	if (coin == NULL || coins_cumul == NULL || lvl < 0) {
		return 1;
	}
	for (int niv = 1; niv <= lvl; niv++) {
		if (niv % 5 == 0) {
			if (niv % 10 == 0) {
				*coin = 250 * niv; // palier 10
			}
			else {
				*coin = 100 * niv; // palier 5
			}
		}
		else {
			*coin = 25 * niv; // palier unitaire
		}
		*coins_cumul += *coin;
	}
	
	return 0;
}


int messLVL(int lvl, int* mess, int* mess_cumul) {
	if (mess == NULL || mess_cumul == NULL || lvl < 0) {
		return 1;
	}
	int xp = 0;
	int xp_cumul = 0;
	xpLVL(lvl, &xp, &xp_cumul);
	*mess = xp / XP; // moyenne nombre message pour passer au prochain niveau
	*mess_cumul = xp_cumul / XP; // moyenne nombre message total pour atteindre le prochain niveau
	return 0;
}


int statsLVL(int lvl) {
	if (lvl < 0) {
		return 1;
	}
	int xp = 0;
	int xp_cumul = 0;
	xpLVL(lvl, &xp, &xp_cumul);
	int coin = 0;
	int coins_cumul = 0;
	coinLVL(lvl, &coin, &coins_cumul);
	int mess = 0;
	int mess_cumul = 0;
	messLVL(lvl, &mess, &mess_cumul);
	printf("\n Lvl %2d : %5d xp | %4d messages | %5d coins\n", lvl, xp, mess, coin);
	printf(" cumule : %5d xp | %4d messages | %5d coins\n", xp_cumul, mess_cumul, coins_cumul);
	return 0;
}


int calculDAILY(int daily, int nb_jours, bool badge_daily, bool affichage) {
	daily = 0;
	for (int day = 1; day <= nb_jours; day++) { // 242 jours => nb de jours entre 01/09/22 et 01/05/23
		if (badge_daily == false) {
			daily += DAILY;
		}
		else {
			daily += BADGE_DAILY;
		}
	}
	if (affichage == true) {
		if (badge_daily == false) {
			printf("\n\n SANS badge daily : !daily = %3d coins\n", DAILY);
			printf(" Pendant %d jours : %5d coins\n", nb_jours, daily);
		}
		else {
			printf("\n AVEC badge daily : !daily = %d coins\n", BADGE_DAILY);
			printf(" Pendant %d jours : %d coins\n", nb_jours, daily);
		}
	}
	return daily;
}


void ratioBADGE() {
	printf("\n\n // RATIO BADGE DAILY //\n\n");
	int coins_sans = 0;
	int coins_avec = -PRIX_BADGE;
	int nb_jours = 0;
	int benef = 0;
	
	while (coins_sans >= coins_avec) {
		coins_sans += DAILY;
		coins_avec += BADGE_DAILY;
		nb_jours++;
		printf("%d | %d | %d\n", coins_sans, coins_avec, nb_jours);
	}
	puts("\n");
	while (nb_jours < 242) {
		coins_sans += DAILY;
		coins_avec += BADGE_DAILY;
		nb_jours++;
		printf("%d | %d | %d\n", coins_sans, coins_avec, nb_jours);
	}
	puts("\n");
	printf("%d | %d | %d\n", coins_sans, coins_avec, nb_jours);
	benef = coins_avec - coins_sans;
	printf("\nBenefice : %d\n", benef);
}

int coinsTOTAL(int lvl, bool all) {
	if (all == true) {
		for (int niv = 0; niv <= lvl; niv++) {
			coinsTOTAL(niv, false);
		}
	}
	else {
		int coin = 0;
		int coins_cumul = 0;
		coinLVL(lvl, &coin, &coins_cumul);
		int mess = 0;
		int mess_cumul = 0;
		messLVL(lvl, &mess, &mess_cumul);
		/*int daily = 0;
		daily = calculDAILY(daily, 242, false, false);*/
		int total = coins_cumul + (mess_cumul * COIN) /* + daily*/;
		printf("Au niveau %2d : %5d + %5d = %6d", lvl, coins_cumul, mess_cumul * 10, total);
		printf("\t\tcoins_cumul + (mess_cumul * %d)\n", COIN);
		/*daily = calculDAILY(daily, 242, true, false);
		total = coins_cumul + (mess_cumul * 10) + daily;
		printf("\ncoins_cumul + (mess_cumul * 10) + daily(AVEC badge)\n%d + %d + %d = %d\n", coins_cumul, mess_cumul * 10, daily, total);
		*/
	}
	return 0;
}


void shop() {
	printf("\n\n// SHOP //\n\n");
	printf("Cafe / Chocolat Chaud | 15 000\n");
	printf("Pinte de Biere        | 50 000\n");
	printf("???                   | ???\n");
	printf("???                   | ???\n");
	printf("???                   | ???\n");
	printf("Brazzers              | 300 000\n");
	printf("Emotes                | ???\n");
	printf("Badge Daily           | %d 000\n", PRIX_BADGE/1000);
}