#include"System.h"

//‰Šú‰»
void StartInit() {
	stagecount = 0;
	memset(&chara,0,sizeof(chara_state));
	chara.x = 320;
	chara.y = 400;
	memset(&shotdata, 0, sizeof(enemy_shot)*MAX_SHOT);
}
