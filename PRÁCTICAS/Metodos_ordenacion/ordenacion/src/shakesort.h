#ifndef _SHAKESORT_H
#define _SHAKESORT_H

#include "sorter.h"
template <class Clave, class Comparar = std::less_equal<Clave> >
class Shakesort : public Sorter<Clave,Comparar>{
    public:
        void sort(vector<Clave> &v, int tam, int ini,int cen, int fin, float alpha, bool show);

};

#include "shakesort.hpp"

#endif