#ifndef MYNEWANT_DIDI_H
#define MYNEWANT_DIDI_H

#include "myAnt.h"

using namespace std;

class myNewAnt_DIDI : public myAnt{
private:
    vector<pair<char,char> > mColorMap; // key: color, value:I

public:
    myNewAnt_DIDI();
    myNewAnt_DIDI(myBoard &b);
    ~myNewAnt_DIDI();

    char movimiento(char color);
    ostream& ver(ostream &os);

    char setNewDirection(char color);
    void go();
    int findInColorMap(char color);

};

#endif