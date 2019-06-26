#ifndef _MERGESORT_H
#define _MERGESORT_H

#include "sorter.h"
template <class Clave, class Comparar = std::less_equal<Clave> >
class Mergesort : public Sorter<Clave,Comparar>{
    public:
        void sort(vector<Clave> &v, int tam, int ini, int cen, int fin, float alpha, bool show);
        void mezcla(vector<Clave> &v, int tam, int ini, int cen, int fin, bool show);
};

#include "mergesort.hpp"

#endif