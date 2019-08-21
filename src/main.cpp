
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
  #define gameFieldIncluded
#endif

#ifndef playerHIncluded
#include "player.h"
#endif

#define POSITIVE 1
#define NEGATIVE 0
/*

bitmapy idu sprava doleva zhora nadol a jednotlive byty idu zespodu hore

todo:




*/


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
//Player* player = new Player(0,0);
//extern GameField field;
const short amountOfGraphicObjects = 2;
//graphicObject* onScreenPtrs[amountOfGraphicObjects] = {gridGO, player.itsGraphicObject};// , grid};

void pressedButtonInterrupt()
{

}

//graphicObject* yeet = new graphicObject(14, 2, skelGO->ownMap);

OnBoard* newEnemy = new OnBoard(1,1,zomGO);
void setup() {
    randomSeed(analogRead(A6));
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
  //nudes->isVisible = false;
  //bowAndArrow->isVisible = true;
  //bowAndArrow->xCoord = 4;
  //bowAndArrow->yCoord = 2;
  gridGO->isVisible = true;
  gridGO->xCoord = 0;
  gridGO->yCoord = 0;
  playerGO->isVisible = true;
  //zomGO->xCoord = 25;
  //zomGO->yCoord = 12;


  //gameField.policka[1][1]-> = ENEMY;

}

#define LEFT 1
#define DOWN 2
#define RIGHT 3
#define UP 4

int checkButtons()
{
  if(digitalRead(A0) == LOW) return LEFT;
  if(digitalRead(A1) == LOW) return UP;
  if(digitalRead(A2) == LOW) return DOWN;
  if(digitalRead(A3) == LOW) return RIGHT;
  else return 0;
}

bool wantToGenerate = true;
short toGenerate = 9;
void calculateNext()
{
  wantToGenerate = true;
  while(wantToGenerate && toGenerate > 0)
  {
    short newnewX = random(0,3);
    short newnewY = random(0,3);
    short newEnemyType = random(0, 3);
    if(field.policka[newnewX][newnewY] == 0)
    {
      field.generateNewTile(newnewX, newnewY, newEnemyType);
      wantToGenerate = false;
      toGenerate--;
    }
  }

  //bowAndArrow->drawSelf(1);
  //zomGO->drawSelf(1);
  Serial.println("printujeme policka");
  for(short x = 0; x < 3; x++)
  {
    /*for(short y = 0; y < 3; y++)
    {
      if(field.policka[x][y] == 0)
      Serial.print(x);
      Serial.print(" ");
      Serial.print(y);
      Serial.println(" is null");
    }*/
  }
   int direction = checkButtons();

  if(direction !=0)
  {
//      player->move(direction);
      //player->drawSelfP(1);
  }
  gridGO->drawSelf(1);
  field.displayGameField();

  //player->drawSelfP(1);

}

void refreshDisplay()
{
  myDisplay.display();
}

unsigned long lastTime = 0;
unsigned long timeStep = 200;

int state = 0;

void loop()
{

      if(millis() > lastTime + timeStep)
      {
        lastTime = millis();
        myDisplay.clearDisplay();
        calculateNext();
        refreshDisplay();
        digitalWrite(5, !digitalRead(5));
        delay(800);

      }
}
