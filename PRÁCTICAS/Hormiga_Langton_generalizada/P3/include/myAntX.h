#ifndef MYANTX_H
#define MYANTX_H

#include "myAnt.h"

using namespace std;

class myAntX : public myAnt{
private:
    vector<pair<char,char> > mColorMap; // key: color, value:I

public:
    myAntX();
    myAntX(myBoard &b);
    ~myAntX();

    char movimiento(char color);
    ostream& ver(ostream &os);
//Hola
    char setNewDirection(char color);
    void go();
    int findInColorMap(char color);

};

#endif