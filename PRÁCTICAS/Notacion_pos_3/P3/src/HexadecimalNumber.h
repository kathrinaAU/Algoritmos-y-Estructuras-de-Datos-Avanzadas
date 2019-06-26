#ifndef HEXADECIMALNUMBER_H
#define HEXADECIMALNUMBER_H

#include "NumberBase.hpp"

class HexadecimalNumber : public number<8,16>{
public:
    HexadecimalNumber(int n);
};

HexadecimalNumber::HexadecimalNumber(int n)
:number(n){}

#endif