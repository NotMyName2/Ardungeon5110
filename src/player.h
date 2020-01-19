
#ifndef graphicObjectHIncluded
  #include "graphicObject.h"
#endif

#ifndef onBoardIncluded
  #include "onBoard.h"
#endif




#ifndef playerHIncluded




class Player:public OnBoard
{
  public:
    int score;
    bool hasWeapon;
    short HP;
    short attackVal;
    short defenseVal;



    Player();
    Player(short newX, short newY);
    ~Player();

    void move(short smer);
    bool canMove(short smer);
    void playerMove(short smer);// inherits
    void refuseMove();
    void attack(short newX, short newY);
    void action();
    virtual void drawSelf(bool positive);
  private:
    short dummyThicc;
};

#define playerHIncluded
#endif
