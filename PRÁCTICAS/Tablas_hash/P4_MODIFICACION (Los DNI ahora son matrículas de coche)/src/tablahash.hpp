#include "tablahash.h"

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////

template<class Clave>
Tablahash<Clave>::Tablahash(int Celdas, int Bloques, int Fd, int Fe):
    nCeldas(Celdas),
    nBloques(Bloques)
{
    Celda_ = new Celda<Clave>* [nCeldas];
    //Recorremos para crear las celdas con los bloques
    for(int i=0; i<nCeldas;i++){
        Celda_[i]=new Celda<Clave>(nBloques);
    }

    // Punteros
    switch(Fd){
        case 0:
            FD = new Modulo<Clave>;
        break;

        case 1:
            FD = new PseudoAleatoria<Clave>;
        break;

        case 2:
            FD = new Suma<Clave>;
        break;
    }

    switch(Fe){
        case 0:
            FE = new Lineal<Clave>;
        break;

        case 1:
            FE = new Cuadratica<Clave>;
        break;

        case 2:
            FE = new DispersionDoble<Clave>;
        break;

        case 3:
            FE = new Redispersion<Clave>;
        break;
    }
}

////////////////////////////////////////////////////////////////////////////////

/*Retorna el valor booleano ​true si el valor ​ X del tipo  Clave está
guardado en la tabla hash. En otro caso retorna ​ false​*/

template<class Clave>
Clave Tablahash<Clave>::Buscar(Clave X){

    Clave salida;
    int intento=0;
    int pos = ( (*FD)(X) +  (*FE)(X,intento)) % nCeldas;
    pos = (pos + nCeldas)%nCeldas;
    //cout << pos << endl;

    bool visitado[nCeldas] = {false};
    string empty = "Vacio";

    salida = Celda_[pos]->Buscar(X);
    if( salida != empty ){
        return salida;
    }
    else{
        for(int i=0;intento<10;i++){
            visitado[pos] = true;
            intento++;
            pos = ( (*FD)(X) +  (*FE)(X,intento) ) % nCeldas;
            pos = (pos + nCeldas)%nCeldas;
            salida = Celda_[pos]->Buscar(X);

            if((!visitado[pos]) && (salida != empty))
                return salida;
        }
    }
    return X;
}

///////////////////////////////////////////////////////////////////////////////
template<class Clave>
bool Tablahash<Clave>::Insertar(Clave X){
  /*Retorna el valor booleano ​true si se añade el valor ​ X del tipo
Clave​ a la tabla hash. En otro caso retorna ​ false​ .*/

    int intento=0;
    int dni = X;
    //cout << "Dni a insertar: " << dni << endl;
    //cout << "Numero nCeldas: " << nCeldas << endl;
    //cout << "Dispersion: " << (*FD)(X) << endl;
    //cout << "Exploracion: " << (*FE)(X,intento) << endl;
    int pos = ( (*FD)(X) +  (*FE)(X,intento)) % nCeldas;
    pos = (pos + nCeldas)%nCeldas;
    //cout << "pos: " << pos << endl;

    bool visitado[nCeldas] = {false};

    if(Celda_[pos]->Insertar(X))
            return true;
    else{

      for(int i=0;intento<10;i++){
          visitado[pos] = true;
          intento++;
          pos = ( (*FD)(X) +  (*FE)(X,intento) ) % nCeldas;
          pos = (pos + nCeldas)%nCeldas;

          if((!visitado[pos]) && (Celda_[pos]->Insertar(X)))
          // Si no se ha visitado y tiene un false dentro de cuando se creo inicialemte pues se inserta
              return true;
      }
    }
}

///////////////////////////////////////////////////////////////////////////////
template<class Clave>
void Tablahash<Clave>::Mostrar_Celda(){
        for(int i=0;i<nCeldas;i++){
                cout<<endl<<"Celda "<<i<<" "<<endl;
                Celda_[i]->Mostrar_Bloques();
                cout<<endl;
        }
}
