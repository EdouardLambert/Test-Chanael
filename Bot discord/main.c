#include "fonctions.h"


int main() {
	bool start = true;
	int lvl = 0;
	int xp = 0;
	int xp_cumul = 0;
	int daily = 0;
	bool badge_daily = false;

	printf("\n\n// STATS LVL //\n\n");
	for (lvl = 0; lvl <= 50; lvl++) {
		statsLVL(lvl);
	}

	calculDAILY(daily, 242, false, true);
	calculDAILY(daily, 242, true, true);

	ratioBADGE();

	printf("\n\n// TOTAL COINS //\n\n");
	coinsTOTAL(20, true);
	

	shop();
	
	return 0;
}