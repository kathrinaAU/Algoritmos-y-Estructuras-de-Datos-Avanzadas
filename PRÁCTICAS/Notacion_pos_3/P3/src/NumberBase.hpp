#ifndef NUMBERBASE
#define NUMBERBASE

#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <typeinfo>

#include "exceptions.h"

using namespace std;

class NumberBase
{
private:
    size_t base;
    size_t n_digits;

protected:
    virtual void to_base(int b)=0;
    virtual NumberBase* duplicate() const=0;

public:
    NumberBase(const size_t n, const size_t b);
    ~NumberBase();
    virtual ostream& write(ostream&)const=0;
    virtual NumberBase* operator+(const NumberBase & num)const=0;
    virtual NumberBase* operator-(const NumberBase & num)const=0;
};

NumberBase::NumberBase(const size_t n, const size_t b)
:n_digits(n), base(b){
    if(n <= 1 or b <= 1){
        throw wrong_number_exception();
    }
}

NumberBase::~NumberBase(){
}



   
#endif