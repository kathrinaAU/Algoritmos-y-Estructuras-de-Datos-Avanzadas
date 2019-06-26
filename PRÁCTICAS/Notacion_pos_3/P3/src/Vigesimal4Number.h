#ifndef VIGESIMAL4NUMBER_H
#define VIGESIMAL4NUMBER_H

#include "number.h"

class Vigesimal4Number : public number<8,24>{
public:
    Vigesimal4Number(int n=0);
};

Vigesimal4Number::Vigesimal4Number(int n)
:number(n){}

#endif