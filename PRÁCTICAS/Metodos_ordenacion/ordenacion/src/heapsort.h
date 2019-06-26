#ifndef _HEAPSORT_
#define _HEAPSORT_

#include "sorter.h"
template <class Clave, class Comparar = std::less_equal<Clave> >
class Heapsort : public Sorter<Clave,Comparar>{
    public:
        void sort(vector<Clave> &v, int tam, int ini,int cen, int fin, float alpha, bool show);
        void heapify(vector<Clave> &v, int tam, int i,  bool show=false);
};

#include "heapsort.hpp"

#endif