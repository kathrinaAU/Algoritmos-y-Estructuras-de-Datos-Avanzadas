#ifndef CELDA
#define CELDA

#include <iostream>
using namespace std;

template<class Clave>
class Celda{
        private:
                Clave *Bloque_;
                int nBloques;
        public:
                Celda(int Bloques);
                Clave Buscar(Clave X);
                bool Insertar(Clave X);
                void Mostrar_Bloques();
};

#include "celda.hpp"
#endif // CELDA
