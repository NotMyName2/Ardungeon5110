
#ifndef playerCIncluded

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
    if( (smer == UP) && (Ycoordinate <= 0)){return false;}
    if( (smer == DOWN) && (Ycoordinate >= 2)) {return false;}
    if( (smer == LEFT) && (Xcoordinate <= 0)) {return false;}
    if( (smer == RIGHT) && (Xcoordinate >= 2)) {return false;}

    if(smer == UP && field.policka[Xcoordinate][Ycoordinate-1]->tileType == ENEMY) {return false;}
    if(smer == DOWN && field.policka[Xcoordinate][Ycoordinate+1]->tileType == ENEMY) {return false;}
    if(smer == LEFT && field.policka[Xcoordinate][Xcoordinate-1]->tileType == ENEMY) {return false;}
    if(smer == RIGHT && field.policka[Xcoordinate][Xcoordinate+1]->tileType == ENEMY) {return false;}

    return true;
  }
  void Player::move(short smer)
  {
    if(canMove(smer))
    {

      field.policka[Xcoordinate][Ycoordinate] = 0;

      if(smer == UP) {Ycoordinate--;}
      if(smer == DOWN) {Ycoordinate++;}
      if(smer == LEFT) {Xcoordinate--;}
      if(smer == RIGHT) {Xcoordinate++;}
      field.policka[Xcoordinate][Ycoordinate] = this;
      field.policka[Xcoordinate][Ycoordinate]->tileType = PLAYER;
      drawSelfP(1);
    }
    else
    Player::refuseMove();

  }

    void Player::refuseMove()
    {
        drawSelfP(POSITIVE);
        delay(100);
        drawSelfP(NEGATIVE);
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


  void Player::drawSelfP(bool positive)
  {
      playerGO->xCoord = Xcoordinate*20+4;
      playerGO->yCoord = Ycoordinate*16;
      playerGO->isVisible = true;
      playerGO->drawSelf(positive);
  }

  void Player::attack(short smer)
  {
    score++;
    return;
  }

//item Playeritems[];
#define playerCIncluded
#endif
