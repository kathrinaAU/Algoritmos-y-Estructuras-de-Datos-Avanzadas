#ifndef BINARYNUMBER_H
#define BINARYNUMBER_H

#include "number.h"

class BinaryNumber : public number<8,2>{
public:
    BinaryNumber(int n=0);
};

BinaryNumber::BinaryNumber(int n)
:number(n){}

#endif