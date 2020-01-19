
#include <Arduino.h>
#include "gameField.h"

#ifndef onBoardHIncluded
#include "onBoard.h"
#endif

#ifndef myBitmapsHIncluded
#include "myBitmaps.h"
#endif

GameField::GameField()
{
  for(short x = 0; x < 3; x++)
    for(short y = 0; y < 3; y++)
      policka[x][y]=0;
}

GameField::~GameField()
{
  for(short x = 0; x < 3; x++)
  {
    for(short y = 0; y < 3; y++)
    {
      if(policka[x][y] != 0)
      {
        delete policka[x][y];
      }
    }
  }
}

int GameField::generateNewTile(short newX, short newY)
{
  if (policka[newX][newY] != 0)
  {
    return 1;
  }
  OnBoard* newTile = new OnBoard(newX, newY, zomGO);
  if(newTile == 0)
  {
    return 1;
  }
  short enemyType = random(0,3);
  const short newFD = random(0,9);
  const short newSD = random(0,9);
  switch (enemyType)
  {
    case 0:
    {
      break;
    }
    case 1:
    {
      newTile->itsGraphicObject = weakSkelGO;
      break;
    }
    case 2:
    {
      newTile->itsGraphicObject = slimGO;
      break;
    }
    default:
    {
      newTile->itsGraphicObject = 0;
      break;
    }

  }
  newTile->itsGraphicObject->xCoord = Xcoordinate*20+4;
  newTile->itsGraphicObject->yCoord = Ycoordinate*16+1;
  newTile->tileType = ENEMY;
  newTile->HP = newFD;
  //newTile->isVisible = true;
  policka[newX][newY] = newTile;
  policka[newX][newY]->tileType = ENEMY;
  firstDigit[newX][newY] = new graphicObject(3,1, numbers[newFD], newX*20+15, newY*16+1);
  //secondDigit[newX][newY] = new graphicObject(3,1, numbers[newSD], newX*20+15, newY*16+8);
  return 0;
}

bool GameField::isItIn(short row, short col)
{
  if (row < 3 and row > -1 and col < 3 and col > -1)
    return true;
  else
    return false;
}


//onBoard* GameField dajPointerPozicie(short )
void GameField::attackPosition(short newX, short newY, short damage=5)
{
  if (isItIn(newX, newY) == false)
      return;
  if (policka[newX][newY] == 0)
  {
    return;
  }
  if (policka[newX][newY]->tileType == ENEMY)
  {
    policka[newX][newY]->HP-=damage;
    if (policka[newX][newY]->HP < 1)
    {
      policka[newX][newY]->itsGraphicObject=0;
      delete policka[newX][newY];
      policka[newX][newY] = 0;
    }
  }
}
void GameField::displayGameField()
{
  for(short x = 0; x < 3; x++)
  {
    for(short y = 0; y < 3; y++)
    {
      if(policka[x][y] != 0)
      {
        policka[x][y]->drawSelf(1);
      }
      else
      {
        emptyGO->xCoord = x*20+4;
        emptyGO->yCoord = y*16;
        emptyGO->drawSelf(1);
      }
      if (firstDigit[x][y] !=0)
      {
        firstDigit[x][y]->drawSelf(1);
      }
      if (secondDigit[x][y])
      {
         secondDigit[x][y]->drawSelf(1);
      }
    }
  }


}

GameField field;
