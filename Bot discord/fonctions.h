#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define DAILY 125
#define BADGE_DAILY 350
#define PRIX_BADGE 20000

int xpLVL(int lvl, int* xp, int* xp_cumul);

int coinLVL(int lvl, int* coin, int* coins_cumul);

int messLVL(int lvl, int* mess, int* mess_cumul);

int statsLVL(int lvl);

int calculDAILY(int daily, int nb_jours, bool badge_daily, bool affichage);

void ratioBADGE();

int coinsTOTAL(int lvl, bool all);

void shop();