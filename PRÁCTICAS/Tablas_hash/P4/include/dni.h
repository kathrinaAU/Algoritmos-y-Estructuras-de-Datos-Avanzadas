#ifndef DNI_H
#define DNI_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "contador.h"
#include "generador.h"

#pragma once
using namespace std;

class Dni {

    private:
            int num;

    public:
            Dni();
            Dni(int dni);
            static Contador Comparaciones;
            static Generador gen;

            bool operator==(int dni);
            bool operator==(const Dni& dni);
            bool operator!=(int dni);
            operator int() const;
            friend ostream& operator<<(ostream& os, const Dni& dni);
            friend istream& operator>>(istream& is, Dni& dni);
            ostream& toStream(ostream& os) const;
};

#endif // DNI_H

