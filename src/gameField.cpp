
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

void GameField::generateNewTile(short newX, short newY)
{
  OnBoard* newTile = new OnBoard(newX, newY, zomGO);
  newTile->itsGraphicObject->xCoord = Xcoordinate*20+4;
  newTile->itsGraphicObject->yCoord = Ycoordinate*16;
  newTile->tileType = ENEMY;
  policka[newX][newY] = newTile;


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
    }
  }

}

GameField field;
