
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
    int HP;
    int attackVal;
    int defenseVal;


    Player();
    Player(int newX, int newY);
    ~Player();

    void move(int smer);
    bool canMove(int smer);
    void playerMove(int smer);// inherits
    void refuseMove();
    void attack(int smer);
    void action();
    void drawSelfP(bool positive);
  private:
    int dummy;
};

#define playerHIncluded
#endif
