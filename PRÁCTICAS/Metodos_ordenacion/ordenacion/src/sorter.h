#ifndef _SORTER_H
#define _SORTER_H
#include <vector>
#include <iostream>
#include "contador.h"
using namespace std;
template <class Clave, class Comparar = std::less_equal<Clave> >
class Sorter{
    protected:
        Comparar cmp;
    public:
        static Contador Intercambio;
        virtual void sort(vector<Clave> &v, int tam, int ini,int cen, int fin, float alpha, bool show=false) = 0;
};

template<class Clave, class Comparar>
Contador Sorter<Clave,Comparar>::Intercambio;

#endif