


#ifndef ArduinoIncluded
#include <Arduino.h>
#endif

#ifndef AGFX
#define AGFX
#include <Adafruit_GFX.h>
#endif

#ifndef PCD
#include <Adafruit_PCD8544.h>
#define PCD
#endif


//#include <myBitmaps.h>
//#include "graphicObject.cpp"

#include "onBoard.h"
#include "gameTile.h"

#ifndef gameFieldIncluded
  #include "gameField.h"
#endif

#ifndef playerHIncluded
#include "player.h"
#endif

#ifndef myMemScript
  #include "memoryFree.h"
#endif

#define POSITIVE 1
#define NEGATIVE 0
/*

bitmapy idu sprava doleva zhora nadol a jednotlive byty idu zespodu hore

todo:




*/

#ifndef smery
#include "smery.h"
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



//graphicObject myObjects[amountOfGraphicObjects] = {*cross}
Adafruit_PCD8544 myDisplay = Adafruit_PCD8544(9, 8, 7);
Player* player = new Player(0,0);
extern GameField field;
const short amountOfGraphicObjects = 2;
//graphicObject* onScreenPtrs[amountOfGraphicObjects] = {gridGO, player.itsGraphicObject};// , grid};

void pressedButtonInterrupt()
{

}

//graphicObject* yeet = new graphicObject(14, 2, skelGO->ownMap);

//OnBoard* newEnemy = new OnBoard(1,1,zomGO);
void setup() {
    randomSeed(analogRead(A7));
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  //attachInterrupt(digitalPinToInterrupt(2), pressedButtonInterrupt, FALLING);
  myDisplay.begin();
  //smallNudes->isVisible = false;
  //bowAndArrow->isVisible = true;
  //bowAndArrow->xCoord = 4;
  //bowAndArrow->yCoord = 2;
  //gridGO->isVisible = true;
  //gridGO->xCoord = 0;
  //gridGO->yCoord = 0;
  playerGO->isVisible = true;
  //zomGO->xCoord = 25;
  //zomGO->yCoord = 12;


  //gameField.policka[1][1]-> = ENEMY;

}

#define LEFT 0
#define DOWN 1
#define RIGHT 2
#define UP 3
#define NOMOVE 4

short checkButtons()
{
  if(digitalRead(A0) == LOW) return LEFT;
  if(digitalRead(A1) == LOW) return UP;
  if(digitalRead(A2) == LOW) return DOWN;
  if(digitalRead(A3) == LOW) return RIGHT;
  else return NOMOVE;
}

bool wantToGenerate = true;
short toGenerate = 8;
void calculateNext()
{
  int direction = checkButtons();

  if(direction !=NOMOVE)
  {
    player->move(direction);
    player->drawSelf(1);
  }

  wantToGenerate = true;
  short maxPokusov = 50;
  short terazPokusov = 0;
  short newnewX;
  short newnewY;
  while(wantToGenerate && toGenerate > 0 && (maxPokusov > terazPokusov))
  {
    newnewX = random(0,3);
    newnewY = random(0,3);
    short newEnemyType = random(0, 3);

    terazPokusov+=1;

    if(field.policka[newnewX][newnewY] == 0)
    {
      int error = field.generateNewTile(newnewX, newnewY);
      if (error == 1)
      {
        Serial.print("error pri ");
        Serial.print(newnewX);
        Serial.println(newnewY);
      }
      wantToGenerate = false;
      toGenerate--;
    }
    else
    {
      Serial.print(newnewX);
      Serial.print(" ");
      Serial.print(newnewY);
      Serial.print(" ");
      Serial.println("OPPA");
    }

  }
  Serial.print("generujeme");
  Serial.print(newnewX);
  Serial.print(newnewY);
  Serial.println();
  //bowAndArrow->drawSelf(1);
  //zomGO->drawSelf(1);

  for(short x = 0; x < 3; x++)
  {
    for(short y = 0; y < 3; y++)
    {
      Serial.print(x);
      Serial.print(" ");
      Serial.print(y);
      if(field.policka[x][y] == 0)
        Serial.println(" is null");
      else
      {
        Serial.println(" OCCUPIED");
      }
      }



  }
  //gridGO->drawSelf(1);
  field.displayGameField();
  GUIGO->drawSelf(1);
  player->drawSelf(1);

}

void refreshDisplay()
{
  myDisplay.display();
}

unsigned long lastTime = 0;
unsigned long timeStep = 600;

int state = 0;

void loop()
{
      if(millis() > lastTime + timeStep)
      {
        lastTime = millis();
        myDisplay.clearDisplay();
        calculateNext();
        refreshDisplay();
        Serial.println(freeMemory());
      }
}
