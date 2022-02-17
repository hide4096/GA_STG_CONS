#pragma once
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Define.h"
#include"Struct.h"
#include"Global.h"
#include"BulletPattern.h"

void StartInit();

void ShotMain();
void CharaMove(int);
int CharaDistance();
int BulletCheckIn(int);
void BulletAppend(int);
bool CheckMain();