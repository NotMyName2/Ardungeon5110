#ifndef gameTileIncluded
  #include"gameTile.h"
#endif

#ifndef onBoardIncluded
#include "onBoard.h"
#endif

#ifndef gameFieldIncluded


#ifndef EMPTY
#define EMPTY 0
#endif

#ifndef PLAYER
#define PLAYER 1
#endif

#ifndef ENEMY
#define ENEMY 2
#endif

#ifndef MONEY
#define MONEY 3
#endif

class GameField:public OnBoard
{
  //void removeWalls
  //void generateNewTile()
public:
  GameField();
  ~GameField();
  OnBoard* policka[3][3];
  graphicObject* firstDigit[3][3];
  graphicObject* secondDigit[3][3];

  int generateNewTile(short newX, short newY);
  //void moveRow(int cislo, int smer);
  void displayGameField();
  bool isItIn(short row, short col);
  void attackPosition(short newX, short newY, short damage=5);
  //void moveColumn(int cislo, int smer);    //technicky rovnake jak
};

extern GameField field;
#define gameFieldIncluded
#endif
