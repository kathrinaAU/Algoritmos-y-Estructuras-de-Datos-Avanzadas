#pragma once

///////////////////////////////////////////////////////////////////////////////
template<class Clave>
Celda<Clave>::Celda(int Bloques):
    nBloques(Bloques)
{
    Bloque_=new Clave[nBloques];

    for(int i=0; i<nBloques; i++)
        Bloque_[i]=-1; //Valor de bloques a false
}

///////////////////////////////////////////////////////////////////////////////
template<class Clave>
Clave Celda<Clave>::Buscar(Clave X){
  /*retorna el valor booleano ​ true si el valor ​ X del tipo ​ Clave está
guardado en la celda. En otro caso retorna ​ false​ .*/

    for(int i=0;i<nBloques;i++){
        if(Bloque_[i]==X){
            return Bloque_[i];
        }
    }
    return X;
}

///////////////////////////////////////////////////////////////////////////////
template<class Clave>
bool Celda<Clave>::Insertar(Clave X){
  /*Retorna el valor booleano ​ true si se añade el valor ​ X del tipo
Clave​ a la celda. En otro caso retorna ​ false​ .*/

    for(int i=0;i<nBloques;i++){
        if(Bloque_[i]==-1){ // SI esta A FALSE
            //cout << "encontrado hueco libre" << endl;
            Bloque_[i]=X;
            return true;
        }else{
          //cout << Bloque_[i];
        }
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////
template<class Clave>
void Celda<Clave>::Mostrar_Bloques(){
    for(int i=0;i<nBloques;i++)
        cout<<Bloque_[i]<<" ";
}
