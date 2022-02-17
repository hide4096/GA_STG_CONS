#pragma once

//©‹@ƒLƒƒƒ‰î•ñ
typedef struct {
	double x, y;
}chara_state;

//’e‚Ìî•ñ
typedef struct {
	bool flg;
	int count, img, save;
	double x, y, speed, angle, range;
}bullet_state;

//’e–‹î•ñ
typedef struct {
	bool flg;
	int pattern, count;
	bullet_state bullet[MAX_BULLET];
}enemy_shot;