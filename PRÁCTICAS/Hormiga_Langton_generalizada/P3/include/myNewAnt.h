#ifndef MYNEWANTX_H
#define MYNEWANTX_H

#include "myAnt.h"

using namespace std;

class myNewAnt : public myAnt{
private:
    vector<pair<char,char> > mColorMap; // key: color, value:I

public:
    myNewAnt();
    myNewAnt(myBoard &b);
    ~myNewAnt();

    char movimiento(char color);
    ostream& ver(ostream &os);

    char setNewDirection(char color);
    void go();
    int findInColorMap(char color);

};

#endif