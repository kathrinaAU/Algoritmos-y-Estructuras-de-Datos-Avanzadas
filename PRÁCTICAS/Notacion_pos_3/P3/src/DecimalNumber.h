#ifndef DECIMALNUMBER_H
#define DECIMALNUMBER_H

#include "NumberBase.hpp"

class DecimalNumber : public number<8,10>{
public:
    DecimalNumber(int n);
};

DecimalNumber::DecimalNumber(int n)
:number(n){}

#endif