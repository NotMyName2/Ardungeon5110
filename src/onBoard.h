
#ifndef onBoardIncluded

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

#ifndef graphicObjectHIncluded
#include "graphicObject.h"
#endif


class OnBoard
{
public:
  int Xcoordinate;
  int Ycoordinate;
  int HP;
  graphicObject* itsGraphicObject;
  int tileType;



  OnBoard();
  OnBoard(graphicObject* itsObject);
  OnBoard(int XCOORD, int YCOORD, graphicObject* itsGObject);
   ~OnBoard();
   void action();

   //void move(int smer);
   //bool canMove(int smer);
   virtual void drawSelf(bool positive);


};


#define onBoardIncluded
#endif
