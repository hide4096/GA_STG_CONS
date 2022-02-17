#include"System.h"

//ŠÖ”ƒ|ƒCƒ“ƒ^
void(*GetBulletPattern[PAT_BULLET])(int) = {
	//’e–‹ƒpƒ^[ƒ“‚ğ‹Lq
	BulletPattern1,BulletPattern2,BulletPattern3,BulletPattern4,BulletPattern5
	,BulletPattern6,BulletPattern7,BulletPattern8,BulletPattern9,BulletPattern10
};

//’eî•ñ‚Ì“o˜^êŠ‚ÌŠm”F
int BulletCheckIn(int n) {
	for (int i = 0; i < MAX_BULLET; i++) {
		if (!(shotdata[n].bullet[i].flg)) return i;
	}
	return -1;
}

void ShotCalc(int n) {
	for (int i = 0; i < MAX_BULLET; i++) {
		if (shotdata[n].bullet[i].flg) {
			//’e‚ÌÀ•WŒvZ
			shotdata[n].bullet[i].x += cos(shotdata[n].bullet[i].angle)*shotdata[n].bullet[i].speed;
			shotdata[n].bullet[i].y += sin(shotdata[n].bullet[i].angle)*shotdata[n].bullet[i].speed;
			shotdata[n].bullet[i].count++;
			//‰æ–ÊŠO‚È‚çÁ‚·
			bool xout	 =	shotdata[n].bullet[i].x < 0 || shotdata[n].bullet[i].x > X_SCREEN;
			bool yout	 =	shotdata[n].bullet[i].y < 0 || shotdata[n].bullet[i].y > Y_SCREEN;
			bool timeout =	shotdata[n].bullet[i].save < shotdata[n].bullet[i].count;
			if (xout || yout && timeout) {
				memset(&shotdata[n].bullet[i], 0, sizeof(bullet_state));
				shotdata[n].bullet[i].flg = false;
			}
		}
	}
}

void ShotMain() {
	for (int i = 0; i < MAX_SHOT; i++) {
		if (shotdata[i].flg) {
			GetBulletPattern[shotdata[i].pattern](i);
			ShotCalc(i);
		}
		shotdata[i].count++;
	}
}

//’e‚Ì“–‚½‚è”»’è
bool CheckHitBlt(double bltX, double bltY, double bltrange, double bltangle, double bltspeed, double bltcount, double range, double chX, double chY) {
	if (bltcount > 0) {
		double x = bltX - chX;
		double y = bltY - chY;
		double rng = bltrange + range;
		if (x*x + y * y < rng*rng) return true;
		if (bltspeed > rng) {
			double pre_x = bltX + cos(bltangle + PI)*bltspeed;
			double pre_y = bltY + sin(bltangle + PI)*bltspeed;
			double px, py;
			for (int k = 0; k < bltspeed / rng; k++) {
				px = pre_x - chX;
				py = pre_y - chY;
				if (px*px + py * py < rng*rng) return true;
				pre_x += cos(bltangle)*rng;
				pre_y += sin(bltangle)*rng;
			}
		}
	}
	return false;
}

//’e–‹“o˜^
void BulletAppend(int i) {
	for (int j = 0; j < MAX_SHOT; j++) {
		if (!(shotdata[j].flg)) {
			memset(&shotdata[j], 0, sizeof(enemy_shot));
			shotdata[j].flg = true;
			shotdata[j].pattern = i;
			shotdata[j].count = 0;
			break;
		}
	}
}

bool CheckMain() {
	bool hitflg = false;
	for (int i = 0; i < MAX_SHOT; i++) {
		if (shotdata[i].flg) {
			for (int j = 0; j < MAX_BULLET; j++) {
				if (shotdata[i].bullet[j].flg) {
					hitflg = CheckHitBlt(shotdata[i].bullet[j].x, shotdata[i].bullet[j].y, shotdata[i].bullet[j].range,
						shotdata[i].bullet[j].angle, shotdata[i].bullet[j].speed, shotdata[i].bullet[j].count, RNG_CHARA, chara.x, chara.y);
					if (hitflg) goto PASS;
				}
			}
		}
	}
PASS:
	return hitflg;
}