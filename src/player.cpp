
#ifndef playerCIncluded


#ifndef LEFT
#define LEFT 0
#endif

#ifndef DOWN
#define DOWN 1
#endif

#ifndef RIGHT
#define RIGHT 2
#endif

#ifndef UP
#define UP 3
#endif

#ifndef graphicObjectHIncluded
  #include "graphicObject.h"
#endif

#ifndef onBoardIncluded
  #include "onBoard.h"
#endif

#ifndef playerHIncluded
#include "player.h"
#endif

#ifndef gameFieldIncluded
#include "gameField.h"
#endif

#ifndef smery
#include "smery.h"
#endif



#ifndef POSITIVE
#define POSITIVE 1
#endif

#ifndef NEGATIVE
#define NEGATIVE 0
#endif


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


  Player::Player():
    (OnBoard(0,0, playerGO))
  {
    score = 0;
    hasWeapon = false;
    HP = 10;
    attackVal = 1;
    defenseVal = 1;
    itsGraphicObject = playerGO;

  }

Player::Player(short XCOO, short YCOO):
(
  OnBoard(XCOO,YCOO, playerGO)
)
{
  score = 0;
  hasWeapon = false;
  HP = 10;
  attackVal = 1;
  defenseVal = 1;
  itsGraphicObject = playerGO;
  field.policka[XCOO][YCOO]->tileType = PLAYER;
  field.policka[XCOO][YCOO] = this;

}
  Player::~Player() {}


  bool Player::canMove(short smer)
  {
    if (field.isItIn(Xcoordinate+dX[smer], Ycoordinate+dY[smer]) == false)
    {
      return false;
    }
    /*
    if( (smer == UP) && (Ycoordinate <= 0)){return false;}
    if( (smer == DOWN) && (Ycoordinate >= 2)) {return false;}
    if( (smer == LEFT) && (Xcoordinate <= 0)) {return false;}
    if( (smer == RIGHT) && (Xcoordinate >= 2)) {return false;}  //crude IsItIn
    */
    short newX = Xcoordinate + dX[smer];
    short newY = Ycoordinate + dY[smer];
    if (field.policka[newX][newY] == 0)
    {
      return true;
    }
    if (field.policka[newX][newY]->tileType == ENEMY)
    {
        attack(newX, newY);
        return false;
    }
    return true;
  }
  void Player::move(short smer)
  {
    if(canMove(smer))
    {

      field.policka[Xcoordinate][Ycoordinate] = 0;
      Ycoordinate+=dY[smer];
      Xcoordinate+=dX[smer];
      field.policka[Xcoordinate][Ycoordinate] = this;
      field.policka[Xcoordinate][Ycoordinate]->tileType = PLAYER;
      //drawSelfP(1);
    }
    else
    Player::refuseMove();

  }

    void Player::refuseMove()
    {
        drawSelf(POSITIVE);
        delay(100);
        drawSelf(NEGATIVE);
        playerGO->xCoord--;
        playerGO->xCoord--;
        playerGO->drawSelf(POSITIVE);
        delay(50*2);
        playerGO->drawSelf(NEGATIVE);
        playerGO->xCoord++;
        playerGO->xCoord++;
        playerGO->drawSelf(POSITIVE);
        delay(50*2);
        playerGO->drawSelf(NEGATIVE);
        playerGO->xCoord++;
        playerGO->xCoord++;
        playerGO->drawSelf(POSITIVE);
        delay(50*2);
        playerGO->drawSelf(NEGATIVE);
        playerGO->xCoord--;
        playerGO->xCoord--;
        playerGO->drawSelf(POSITIVE);

    }


  void Player::drawSelf(bool positive)
  {
      playerGO->xCoord = Xcoordinate*20+4;
      playerGO->yCoord = Ycoordinate*16;
      playerGO->isVisible = true;
      playerGO->drawSelf(positive);
  }

  void Player::attack(short newX, short newY)
  {
    score++;
    field.attackPosition(newX, newY);
    return;
  }

//item Playeritems[];
#define playerCIncluded
#endif
