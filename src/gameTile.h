#ifndef PLAYER
#define PLAYER 1
#endif

#ifndef ENEMY
#define ENEMY 2
#endif


#ifndef onBoardIncluded
#include "onBoard.h"
#endif


#ifndef gameTileIncluded


class GameTile:public OnBoard
{
    int contains;
};


#define gameTileIncluded
#endif
