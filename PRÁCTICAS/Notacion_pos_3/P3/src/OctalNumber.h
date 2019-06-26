#ifndef OCTALNUMBER_H
#define OCTALNUMBER_H

#include "NumberBase.hpp"

class OctalNumber : public number<8,8>{
public:
    OctalNumber(int n);
};

OctalNumber::OctalNumber(int n)
:number(n){}

#endif