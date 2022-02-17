#include"System.h"

int CharaDistance() {
	double x, y, distance,max;
	const double cnt_x = RNG_U + (RNG_D - RNG_U) / 2, cnt_y = RNG_L + (RNG_R - RNG_L) / 2;

	x = chara.x - cnt_x;
	y = chara.y - cnt_y;
	distance = sqrt(x * x + y * y);
	
	return 250 - (int)(distance);
}

void CharaMove(int i) {
	double calc_x=0.0, calc_y=0.0;
	double speed=1.5;

	switch (key[i][stagecount]) {
		case'W':
			calc_y = 1.0;
			break;
		case'S':
			calc_y = -1.0;
			break;
		case'A':
			calc_x = -1.0;
			break;
		case'D':
			calc_x = 1.0;
			break;
		case 'N':
			break;
		default:
			break;
	}

	bool xout = chara.x + calc_x < RNG_L || chara.x + calc_x > RNG_R;
	bool yout = chara.y + calc_y < RNG_U || chara.y + calc_y > RNG_D;
	if (!(xout || yout)) {
		chara.x += calc_x * speed;
		chara.y += calc_y * speed;
	}
}