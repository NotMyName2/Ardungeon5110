
#include <Arduino.h>
#include "gameField.h"

#ifndef onBoardHIncluded
#include "onBoard.h"
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

void GameField::generateNewTile(short newX, short newY, int enemyType)
{

  OnBoard* newTile = new OnBoard(newX, newY, zomGO);
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
    }
  }


  newTile->itsGraphicObject->xCoord = Xcoordinate*20+4;
  newTile->itsGraphicObject->yCoord = Ycoordinate*16;
  newTile->tileType = ENEMY;
  //newTile->isVisible = true;
  policka[newX][newY] = newTile;


  if(policka[newX][newY] == 0)
  {
  Serial.println("New address is null");
  }
  else
  {
    Serial.println("New address is not null");
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
    }
  }

}

GameField field;
