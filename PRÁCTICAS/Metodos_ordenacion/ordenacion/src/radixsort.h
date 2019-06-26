#ifndef _RADIXSORT_H
#define _RADIXSORT_H

#include "sorter.h"
template <class Clave, class Comparar = std::less_equal<Clave> >
class Radixsort : public Sorter<Clave,Comparar>{
    public:
        void sort(vector<Clave> &v, int tam, int ini,int cen, int fin, float alpha, bool show);
        int getMaxElement(vector<Clave> &v);
        void sortByExpIndex(vector<Clave> &v,int exp);

};

#include "radixsort.hpp"

#endif