#ifndef MYNEWANT_IDID_H
#define MYNEWANT_IDID_H

#include "myAnt.h"

using namespace std;

class myNewAnt_IDID : public myAnt{
private:
    vector<pair<char,char> > mColorMap; // key: color, value:I

public:
    myNewAnt_IDID();
    myNewAnt_IDID(myBoard &b);
    ~myNewAnt_IDID();

    char movimiento(char color);
    ostream& ver(ostream &os);

    char setNewDirection(char color);
    void go();
    int findInColorMap(char color);

};

#endif