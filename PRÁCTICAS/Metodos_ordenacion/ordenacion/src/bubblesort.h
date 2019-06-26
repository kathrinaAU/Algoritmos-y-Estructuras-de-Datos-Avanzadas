#ifndef _BUBBLESORT_H
#define _BUBBLESORT_H

#include "sorter.h"
template <class Clave, class Comparar = std::less_equal<Clave> >
class Bubblesort : public Sorter<Clave,Comparar>{
    public:
        void sort(vector<Clave> &v, int tam, int ini,int cen, int fin, float alpha, bool show);

};

#include "bubblesort.hpp"

#endif