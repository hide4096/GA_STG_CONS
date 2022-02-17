#define MAIN
#include"System.h"

int survive[SEED];
int distance[SEED];
int score[SEED];

void Evaluate(int i) {
	mainstate = 0;
	//��`�q�̕]��
	while (mainstate != 100) {

		//�����̕���
		switch (mainstate) {

		case 0:
			StartInit();
			distance[i] = 0;
			BulletAppend(4);
			mainstate = 50;
			break;

			//���s��
		case 50:
			CharaMove(i);
			ShotMain();
			if (CheckMain() || stagecount >= FRAME * TIMEOUT) mainstate = 100;
			distance[i] += CharaDistance();
			stagecount++;
			break;

			//�l�����������ꍇ
		default:
			break;
		}
	}
	distance[i] = (int)(distance[i] / stagecount);
	survive[i] = stagecount;
}

char RandomKey() {
	char outkey = 'N';
	switch (rand()%5) {
		case 0:
			outkey = 'W';
			break;
		case 1:
			outkey = 'A';
			break;
		case 2:
			outkey = 'S';
			break;
		case 3:
			outkey = 'D';
			break;
		case 4:
			outkey = 'N';
			break;
	}
	return outkey;
}

int main(){
	srand(time(NULL));
	int gen = 1;
	int tmpmax=0, count = 0;
	for (int i = 0; i < SEED; i++) {
		for (int j = 0; j < FRAME*TIMEOUT; j++) {
			key[i][j] = RandomKey();
		}
	}

	char sorttemp[SEED][FRAME*TIMEOUT];

	while (true) {
		int max = 0,min = FRAME*TIMEOUT,maxid;
		for (int i = 0; i < SEED; i++) {
			Evaluate(i);
			if (max < survive[i]) {
				max = survive[i];
				maxid = i;
			}
			if (min > survive[i]) min = survive[i];
		}
		//�G���[�g�̏o��
		FILE *fp;
		fopen_s(&fp, "../elite.txt", "w");
		for (int i = 0; i < FRAME*TIMEOUT;i++) {
			//�G���[�g�ۑ�
			sorttemp[0][i] = key[maxid][i];
			fputc(key[maxid][i], fp);
		}
		fclose(fp);

		//��z
		int timesum = 0, scoresum = 0;
		for (int i = 0; i < SEED; i++) {
			timesum += survive[i];
			//�����ŏd�݌���
			scoresum += survive[i] + (int)(distance[i]/10);
			//scoresum += survive[i];
			score[i] = scoresum;
		}
		for (int i = 1; i <= SEED-1; i++) {
			int a = 0, b = 0;

			//���[���b�g�I��
			int roulette = rand() % scoresum;
			for (int i = 0; i < SEED; i++) {
				roulette -= score[i];
				if (roulette < 0) {
					a = i;
					b = i;
					break;
				}
			}
			while (a == b) {
				roulette = rand() % scoresum;
				for (int i = 0; i < SEED; i++) {
					roulette -= score[i];
					if (roulette < 0) {
						b = i;
						break;
					}
				}
			}

			//��l����
			for (int j = 0; j < FRAME*TIMEOUT; j++) {
				if (rand() % 2) sorttemp[i][j] = key[a][j];
				else sorttemp[i][j] = key[b][j];
				if (rand() % 10000 <= MUTATION) sorttemp[i][j] = RandomKey();
			}
		}

		//�R�s�[
		for (int i = 0; i < SEED;i++) {
			for (int j = 0; j < FRAME*TIMEOUT;j++) {
				key[i][j] = sorttemp[i][j];
			}
		}

		printf("��%d���� \t�ō�:%d \t�Œ�:%d \t����:%d \t�J�E���g:%d\n",gen,max,min,(int)(timesum/SEED),count);
		gen++;
		if (tmpmax == max) count++;
		else count = 0;
		tmpmax = max;
	}
}