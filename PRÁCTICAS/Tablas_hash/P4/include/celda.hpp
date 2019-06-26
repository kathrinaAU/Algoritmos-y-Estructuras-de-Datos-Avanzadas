#pragma once

template<class Clave>
Celda<Clave>::Celda(int Bloques):
    nBloques(Bloques)
{
    Bloque_=new Clave[nBloques];

    for(int i=0; i<nBloques; i++)
        Bloque_[i]=-1; //Valor de bloques a false
}

template<class Clave>
bool Celda<Clave>::Buscar(Clave X){
  /*retorna el valor booleano ? true si el valor ? X del tipo ? Clave está
guardado en la celda. En otro caso retorna ? false? .*/

    for(int i=0;i<nBloques;i++){
        if(Bloque_[i]==X)
            return true;
    }
    return false;
}

template<class Clave>
bool Celda<Clave>::Insertar(Clave X){
  /*retorna el valor booleano ? true si se añade el valor ? X del tipo
Clave? a la celda. En otro caso retorna ? false? .*/

    for(int i=0;i<nBloques;i++){
        if(Bloque_[i]==-1){ // SI esta A FALSE
            Bloque_[i]=X;
            return true;
        }
    }
    return false;
}

template<class Clave>
void Celda<Clave>::Mostrar_Bloques(){
    for(int i=0;i<nBloques;i++)
        cout<<Bloque_[i]<<" ";
}

