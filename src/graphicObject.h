using namespace std;
#include <Arduino.h>

#ifndef AGFX
#define AGFX
#include <Adafruit_GFX.h>
#endif

#ifndef PCD
#include <Adafruit_PCD8544.h>
#define PCD
#endif

#ifndef graphicObjectHIncluded

class graphicObject
{
public:
  short XSize;
  short YSize;
  uint8_t* ownMap;
  bool isVisible;
  short xCoord;
  short yCoord;

//  graphicObject(short newXSize, short newYSize, uint8_t* itsMap, bool newVisible, short newxCoord, short newyCoord);
  graphicObject(short newXSize, short newYSize, uint8_t* itsMap, short newXCoord, short newYCoord);
  graphicObject(short newXSize, short newYSize, uint8_t* itsMap);
  graphicObject();
  //graphicObject(const graphicObject&);
  void drawSelf(bool positive);
private:
  int dummy;
};

  /*graphicObject::graphicObject(short newXSize, short newYSize, uint8_t* itsMap, bool newVisible, short newxCoord, short newyCoord)
  {
    XSize = newXSize;
    YSize = newYSize;
    ownMap = itsMap;
    xCoord = newxCoord;
    yCoord = newyCoord;
  }
*/


//extern graphicObject* cross;
//extern graphicObject* nudes;
extern graphicObject* smallNudes;
//graphicObject xicht(8, 2, xichtmap, 1, 4, 4);
//extern graphicObject veryBig;
//extern graphicObject* bowAndArrow;
extern graphicObject* emptyGO;
extern graphicObject* playerGO;
extern graphicObject* gridGO;

extern graphicObject* zomGO;
extern graphicObject* weakSkelGO;
extern graphicObject* slimGO;
extern graphicObject* GUIGO;
#define graphicObjectHIncluded
#endif
