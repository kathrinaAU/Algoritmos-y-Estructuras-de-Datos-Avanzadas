#ifndef TABLAHASH
#define TABLAHASH

#pragma once

#include "celda.h"
#include "dispersion.h"
#include "exploracion.h"

template<class Clave>
class Tablahash{
        private:
                Celda<Clave>** Celda_; //Vector de celdas
                int nCeldas, nBloques; // Numero de celdas y de bloques
                Dispersion<Clave>* FD; // Objeto de tipo dispersion
                Exploracion<Clave>* FE; //Objeto de tipo exploracion


        public:
              Tablahash(int Celdas, int Bloques, int Fd,int Fe); // COnstructor para crear la tabla hash
              bool Buscar(Clave X);
              bool Insertar(Clave X);
              void Mostrar_Celda();
};

#include "tablahash.hpp"
#endif // TABLAHASH

