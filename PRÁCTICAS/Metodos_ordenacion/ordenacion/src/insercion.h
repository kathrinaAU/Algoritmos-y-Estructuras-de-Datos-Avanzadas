#ifndef _INSERCION_H
#define _INSERSION_H

#include "sorter.h"
template <class Clave, class Comparar = std::less_equal<Clave> >
class Insercion : public Sorter<Clave,Comparar>{
    public:
        void sort(vector<Clave> &v, int tam, int ini,int cen, int fin, float alpha, bool show);

};

#include "insercion.hpp"

#endif