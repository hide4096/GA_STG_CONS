#include"System.h"

void BulletPattern1(int n) {
	if (shotdata[n].count % 30 == 0) {
		for (int i = 0; i < 3; i++) {
			int j = BulletCheckIn(n);
			if (j != -1) {
				shotdata[n].bullet[j].flg = true;
				shotdata[n].bullet[j].count = 0;
				shotdata[n].bullet[j].save = 300;
				shotdata[n].bullet[j].x = 320;
				shotdata[n].bullet[j].y = 100;
				double face2chara = atan2(chara.y - shotdata[n].bullet[j].y, chara.x - shotdata[n].bullet[j].x);
				shotdata[n].bullet[j].angle = face2chara + (PI / 30)*(i - 1);
				shotdata[n].bullet[j].speed = 4.0;
				shotdata[n].bullet[j].range = 3.0;
				shotdata[n].bullet[j].img = 0;
			}
		}
	}
}

void BulletPattern2(int n) {
	if (shotdata[n].count % 60 == 0) {
		for (int i = 0; i < 12; i++) {
			int j = BulletCheckIn(n);
			if (j != -1) {
				shotdata[n].bullet[j].flg = true;
				shotdata[n].bullet[j].count = 0;
				shotdata[n].bullet[j].save = 300;
				shotdata[n].bullet[j].x = 320;
				shotdata[n].bullet[j].y = 100;
				shotdata[n].bullet[j].angle = PI / 6 * i;
				shotdata[n].bullet[j].speed = 2;
				shotdata[n].bullet[j].range = 3.0;
				shotdata[n].bullet[j].img = 0;
			}
		}
	}
}

void BulletPattern3(int n) {
	if (shotdata[n].count % 10 == 0) {
		for (int i = 0; i < 5; i++) {
			int j = BulletCheckIn(n);
			if (j != -1) {
				shotdata[n].bullet[j].flg = true;
				shotdata[n].bullet[j].count = 0;
				shotdata[n].bullet[j].save = 300;
				shotdata[n].bullet[j].x = 320;
				shotdata[n].bullet[j].y = 100;
				shotdata[n].bullet[j].angle = (PI / 2) + (PI / 210)*(shotdata[n].count % 100 - 50) + (PI / 20)*(i - 2);
				shotdata[n].bullet[j].speed = 4.0;
				shotdata[n].bullet[j].range = 3.0;
				shotdata[n].bullet[j].img = 0;
			}
		}
	}
}

void BulletPattern4(int n) {
	if (shotdata[n].count % 20 == 0) {
		for (int i = 0; i < 5; i++) {
			int j = BulletCheckIn(n);
			if (j != -1) {
				shotdata[n].bullet[j].flg = true;
				shotdata[n].bullet[j].count = 0;
				shotdata[n].bullet[j].save = 300;
				shotdata[n].bullet[j].x = 160;
				shotdata[n].bullet[j].y = 480;
				double face2chara = atan2(chara.y - shotdata[n].bullet[j].y, chara.x - shotdata[n].bullet[j].x);
				shotdata[n].bullet[j].angle = face2chara + (PI / 8)*(i - 2);
				shotdata[n].bullet[j].speed = 6.0;
				shotdata[n].bullet[j].range = 3.0;
				shotdata[n].bullet[j].img = 0;
			}
		}
		for (int i = 0; i < 5; i++) {
			int j = BulletCheckIn(n);
			if (j != -1) {
				shotdata[n].bullet[j].flg = true;
				shotdata[n].bullet[j].count = 0;
				shotdata[n].bullet[j].save = 300;
				shotdata[n].bullet[j].x = 320;
				shotdata[n].bullet[j].y = 100;
				double face2chara = atan2(chara.y - shotdata[n].bullet[j].y, chara.x - shotdata[n].bullet[j].x);
				shotdata[n].bullet[j].angle = face2chara + (PI / 8)*(i - 2);
				shotdata[n].bullet[j].speed = 6.0;
				shotdata[n].bullet[j].range = 3.0;
				shotdata[n].bullet[j].img = 0;
			}
		}
		for (int i = 0; i < 5; i++) {
			int j = BulletCheckIn(n);
			if (j != -1) {
				shotdata[n].bullet[j].flg = true;
				shotdata[n].bullet[j].count = 0;
				shotdata[n].bullet[j].save = 300;
				shotdata[n].bullet[j].x = 480;
				shotdata[n].bullet[j].y = 480;
				double face2chara = atan2(chara.y - shotdata[n].bullet[j].y, chara.x - shotdata[n].bullet[j].x);
				shotdata[n].bullet[j].angle = face2chara + (PI / 8)*(i - 2);
				shotdata[n].bullet[j].speed = 6.0;
				shotdata[n].bullet[j].range = 3.0;
				shotdata[n].bullet[j].img = 0;
			}
		}
	}
}

void BulletPattern5(int n) {
	const int numammo = 15;
	if (shotdata[n].count % 60 == 0) {
		for (int i = 0; i < numammo; i++) {
			int j = BulletCheckIn(n);
			if (j != -1) {
				shotdata[n].bullet[j].flg = true;
				shotdata[n].bullet[j].count = 0;
				shotdata[n].bullet[j].save = 300;
				shotdata[n].bullet[j].x = 320;
				shotdata[n].bullet[j].y = 100;
				shotdata[n].bullet[j].angle = (PI / 2) + (PI / 10)*(i - ((numammo - 1) / 2));
				shotdata[n].bullet[j].speed = 2.0;
				shotdata[n].bullet[j].range = 3.0;
				shotdata[n].bullet[j].img = 0;
			}
		}
	}
	for (int i = 0; i < MAX_BULLET; i++) {
		if (shotdata[n].bullet[i].flg) {
			if (shotdata[n].bullet[i].count == 60) {
				double face2chara = atan2(chara.y - shotdata[n].bullet[i].y, chara.x - shotdata[n].bullet[i].x);
				shotdata[n].bullet[i].angle = face2chara;
				shotdata[n].bullet[i].speed = 6.0;
			}
		}
	}
}

void BulletPattern6(int n) {
	if (shotdata[n].count % 6 == 0) {
		for (int i = 0; i < 6; i++) {
			int j = BulletCheckIn(n);
			if (j != -1) {
				shotdata[n].bullet[j].flg = true;
				shotdata[n].bullet[j].count = 0;
				shotdata[n].bullet[j].save = 0;
				shotdata[n].bullet[j].x = 320;
				shotdata[n].bullet[j].y = 50;
				shotdata[n].bullet[j].angle = (PI / 3)*i + (PI / 180)*shotdata[n].count;
				shotdata[n].bullet[j].speed = 4.0;
				shotdata[n].bullet[j].range = 3.0;
				shotdata[n].bullet[j].img = 0;
			}
		}
	}
	for (int i = 0; i < MAX_BULLET; i++) {
		if (shotdata[n].bullet[i].flg) {
			if (shotdata[n].bullet[i].speed > 2.0) {
				shotdata[n].bullet[i].speed -= 0.2;
			}
			if (shotdata[n].bullet[i].speed = 2.0) {
				shotdata[n].bullet[i].angle -= PI / 360;
			}
		}
	}
}
void BulletPattern7(int n) {}
void BulletPattern8(int n) {}
void BulletPattern9(int n) {}
void BulletPattern10(int n) {}