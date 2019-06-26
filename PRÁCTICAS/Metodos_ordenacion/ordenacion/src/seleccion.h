#ifndef _SELECCION_H
#define _SELECCION_H

#include "sorter.h"
template <class Clave, class Comparar = std::less_equal<Clave> >
class Seleccion : public Sorter<Clave,Comparar>{
    public:
        void sort(vector<Clave> &v, int tam, int ini,int cen, int fin, float alpha, bool show);

};

#include "seleccion.hpp"

#endif