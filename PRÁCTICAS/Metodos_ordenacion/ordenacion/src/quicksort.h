#ifndef _QUICKSORT_H
#define _QUICKSORT_H

#include "sorter.h"
template <class Clave, class Comparar = std::less_equal<Clave> >
class Quicksort : public Sorter<Clave,Comparar>{
    public:
        void sort(vector<Clave> &v, int tam, int ini, int cen, int fin, float alpha, bool show);
        int partition(vector<Clave> &v, int tam, int i, bool show=false);
};

#include "quicksort.hpp"

#endif