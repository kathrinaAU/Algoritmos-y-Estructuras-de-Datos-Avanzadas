#ifndef _SHELLSORT_H
#define _SHELLSORT_H

#include "sorter.h"
template <class Clave, class Comparar = std::less_equal<Clave> >
class Shellsort : public Sorter<Clave,Comparar>{
    public:
        void sort(vector<Clave> &v, int tam, int ini, int cen, int fin, float alpha, bool show);

};

#include "shellsort.hpp"

#endif