
#ifndef LDCWIDTH
#define LDCWIDTH 84
#endif

#ifndef LCDHEIGHT
#define LCDHEIGHT 48
#endif

#ifndef AGFX
#define AGFX
#include <Adafruit_GFX.h>
#endif

#ifndef PCD
#include <Adafruit_PCD8544.h>
#define PCD
#endif

extern Adafruit_PCD8544 myDisplay;

#ifndef graphicObjectIncluded

#ifndef myBitmapsHIncluded
#include "myBitmaps.h"
#endif

#ifndef graphicObjectHIncluded
#include "graphicObject.h"
#endif


  graphicObject::graphicObject()
  {
    XSize = 0;
    YSize = 0;
    ownMap = 0;
    isVisible = true;
    xCoord = 0;
    yCoord = 0;
  }
  graphicObject::graphicObject(short newXSize, short newYSize, uint8_t* itsMap)
  {
    XSize = newXSize;
    YSize = newYSize;
    ownMap = itsMap;
    isVisible = true;
    xCoord = 0;
    yCoord = 0;
  }




//graphicObject* cross = new graphicObject(5,1,crossOofMap);
//graphicObject* nudes = new graphicObject(29,2,nudesMap);
//graphicObject xicht(8, 2, xichtmap, 1, 4, 4);
//graphicObject veryBig(100, 7, veryBigMap);
graphicObject* bowAndArrow = new graphicObject(16, 2, bowAndArrowMap);
graphicObject* playerGO = new graphicObject(14, 2, playerMap);
//graphicObject full(8,4,fullmap);
graphicObject* gridGO = new graphicObject(64, 6, gridMap);

graphicObject* zomGO = new graphicObject(14, 2, zomMap);
graphicObject* skelGO = new graphicObject(14, 2, skelMap);
graphicObject* slimGO = new graphicObject(14, 2, slimMap);
graphicObject* emptyGO = new graphicObject(4, 1, emptyMap);


void graphicObject::drawSelf(bool positive)
{
  {
    short itsWidth =XSize;
    short itsHeight = YSize;
    byte* theBitmap = ownMap;
/*
    if(xCoord > LCDWIDTH) return;
    if(yCoord > LCDHEIGHT) return;
    if(xCoord + itsWidth < 0) return;
    if(yCoord + itsHeight < 0) return;
*/
    //xRunner = max(0, -xCoord);  // runner pro bitmapu, jestli zacne mimo, tak xRunner preskoci cast co je mimo
    //yRunner = max(0, -yCoord/8);// to iste // jestli bitmapa zacne nad displejem, tak sa posuneme do casti, kde zacina displejem
    //xdisrunner, yDisRunner/ runnery pro display
    int offset = yCoord%8;
    if (offset < 0) offset +=8;//aby byl kladny offset aj pri yCoord < 0

    for(int yDisRunner = max(0, yCoord/8), yRunner = 0; ((yDisRunner < 6) && (yRunner < itsHeight+1)); (yDisRunner++,yRunner++))
    {
      for(int xDisRunner = max(0, xCoord), xRunner = 0; (xDisRunner < LCDWIDTH) && (xRunner < itsWidth); xDisRunner++, xRunner++)
      {
        if((yRunner == 0) && (xDisRunner < 84)) //prvy radek bitmapy, nema presahy zminula
        {
              if (positive)
              myDisplay.pcd8544_buffer[xDisRunner+(yDisRunner)*LCDWIDTH] |= (*(theBitmap+xRunner) << offset);
              else
              myDisplay.pcd8544_buffer[xDisRunner+(yDisRunner)*LCDWIDTH] ^= (*(theBitmap+xRunner) << offset);
        }
        if((yRunner == itsHeight)) // posledny radek bitmapy, ma iba presah z minula
        {
          if(xDisRunner < 84)
          {
              if (positive)
              myDisplay.pcd8544_buffer[xDisRunner+(yDisRunner)*LCDWIDTH] |= (*(theBitmap+xRunner+(yRunner-1)*itsWidth) >> (8-offset));
              else
              myDisplay.pcd8544_buffer[xDisRunner+(yDisRunner)*LCDWIDTH] ^= (*(theBitmap+xRunner+(yRunner-1)*itsWidth) >> (8-offset));
          }
          continue;
        }

        if(yRunner !=0  && (xDisRunner < 84)) //ostatne radky
        {
          if(positive)
          {
            myDisplay.pcd8544_buffer[xDisRunner+(yDisRunner)*LCDWIDTH] |= (*(theBitmap+xRunner+(yRunner-1)*itsWidth) >> (8-offset));
            myDisplay.pcd8544_buffer[xDisRunner+(yDisRunner)*LCDWIDTH] |= (*(theBitmap+xRunner+(yRunner)*itsWidth) << offset);
          }
          else
          {
            myDisplay.pcd8544_buffer[xDisRunner+(yDisRunner)*LCDWIDTH] ^= (*(theBitmap+xRunner+(yRunner-1)*itsWidth) >> (8-offset));
            myDisplay.pcd8544_buffer[xDisRunner+(yDisRunner)*LCDWIDTH] ^= (*(theBitmap+xRunner+(yRunner)*itsWidth) << offset);
          }
        }
      }
    }
  }
myDisplay.display();
}
#define graphicObjectIncluded
#endif
