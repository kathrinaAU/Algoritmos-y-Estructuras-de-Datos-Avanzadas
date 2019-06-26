#ifndef VIGESIMAL3NUMBER_H
#define VIGESIMAL3NUMBER_H

#include "number.h"

class Vigesimal3Number : public number<8,23>{
public:
    Vigesimal3Number(int n=0);
};

Vigesimal3Number::Vigesimal3Number(int n)
:number(n){}

#endif