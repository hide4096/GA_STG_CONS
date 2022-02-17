#pragma once

#ifdef MAIN
#define GLOBAL
#else
#define GLOBAL extern 
#endif

//•Ï”‚ÌéŒ¾
GLOBAL int mainstate;
GLOBAL unsigned int stateKey[256];
GLOBAL int stagecount;
GLOBAL char key[SEED][FRAME*TIMEOUT];

GLOBAL chara_state chara;
GLOBAL enemy_shot shotdata[MAX_SHOT];

