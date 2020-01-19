
#ifndef onBoardCIncluded


#ifndef onBoardHIncluded
#include "onBoard.h"
#endif

#ifndef graphicObjectHIncluded
#include "graphicObject.h"
#endif

#ifndef LEFT
#define LEFT 1
#endif

#ifndef DOWN
#define DOWN 2
#endif

#ifndef RIGHT
#define RIGHT 3
#endif

#ifndef UP
#define UP 4
#endif

//  virtual void action();
//  virtual void move(int smer);
//  virtual void drawSelf();




OnBoard::OnBoard()
{
    Xcoordinate = 0;
    Ycoordinate = 0;
    HP = 4;
    itsGraphicObject = 0;
    

}

OnBoard::OnBoard(graphicObject* itsGObject):

  Xcoordinate(0),
  Ycoordinate(0),
  HP(4),
  itsGraphicObject(itsGObject)

{

}


OnBoard::OnBoard(int XCOORD, int YCOORD, graphicObject* itsGObject):

  Xcoordinate(XCOORD),
  Ycoordinate(YCOORD),
  HP(4),
  itsGraphicObject(itsGObject)

{}

OnBoard::~OnBoard()
{
  itsGraphicObject = 0;
}

void OnBoard::drawSelf(bool positive)
{
  itsGraphicObject->xCoord = Xcoordinate*20+1;
  itsGraphicObject->yCoord = Ycoordinate*16;
  itsGraphicObject->isVisible = true;
  itsGraphicObject->drawSelf(positive);
}

//OnBoard::takeDamage(short damage)



#define onBoardCIncluded
#endif
