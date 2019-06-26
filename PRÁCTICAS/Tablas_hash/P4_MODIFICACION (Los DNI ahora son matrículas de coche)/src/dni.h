#ifndef DNI_H
#define DNI_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "generador.h"
#include "contador.h"

#pragma once
using namespace std;

class Dni {

    private:
            int num;
            int digits;
            string letra;
            string nombre;// string nombre.
            string apellidos;// string apellidos.

    public:
            Dni();
            Dni(int dni, string l, string n, string a);
            Dni(int dni);
            static Contador Comparaciones;
            static Generador generador;


            //Sobrecarga de operadores
            bool operator==(int dni);
            bool operator==(const Dni& dni);
            bool operator!=(string nombre);
            bool operator!=(int dni);
            Dni& operator = (int dni);
            operator int() const;
            void setDni(int dni);
            friend ostream& operator<<(ostream& os, const Dni& dni);
            friend istream& operator>>(istream& is, Dni& dn1i);
            ostream& toStream(ostream& os) const;
};

#endif // DNI_H
