#ifndef MYANT_H
#define MYANT_H

#define NDIR 4

#include "myBoard.h"
#include <ostream>
#include <vector>
#include <utility>
using namespace std;

class myAnt{
protected:
    int xPos, yPos;
    char direction[4] = {'^','>','v','<'};
    int pos_dir = 0;
    vector<pair<int,int> > v;

    myBoard board;
    void checkBorders();

    char id = 'A';
    char muerte_id='_';

public:
    myAnt();
    myAnt(myBoard &b);
    ~myAnt();

    char getDirection();
    void setDirection(int dir);
    void setColor(int x, int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);

    char getID();
    char getMuerteID();

    virtual char movimiento(char color)=0;
    virtual ostream& ver(ostream& os)=0;    

};

#endif