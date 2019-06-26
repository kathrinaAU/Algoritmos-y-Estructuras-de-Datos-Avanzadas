#pragma once
template <class TDATO>
myVector<TDATO>::myVector()
    :tam(50), num_incluidos(0)
{
    m_vector = new TDATO[tam];
}

template <class TDATO>
myVector<TDATO>::myVector(int newtam)
    :tam(newtam), num_incluidos(0)
{
    m_vector = new TDATO[tam];
}

template <class TDATO>
myVector<TDATO>::myVector(const myVector<TDATO>& v):
    tam (v.tam),
    num_incluidos(v.num_incluidos)
{
    m_vector = new TDATO[tam];
    for (int i = 0; i < tam; i++){
        m_vector[i] = v.m_vector[i];
    }
}

template <class TDATO>
myVector<TDATO>::~myVector(){
    if(!this->isEmpty()){
        delete[] m_vector;
    }
    tam = 0;
    num_incluidos = 0;
}

template <class TDATO>
bool myVector<TDATO>::isEmpty(){
    return num_incluidos == 0;
}

template <class TDATO>
void myVector<TDATO>::pushBack(TDATO newdato){
    if(num_incluidos < tam){
        m_vector[num_incluidos] = newdato;
        num_incluidos++;
    }else{
        resize(tam+INCREASE_TAM);
        pushBack(newdato);
    }
}

template <class TDATO>
int myVector<TDATO>::size(){
    return num_incluidos;
}

template <class TDATO>
int myVector<TDATO>::reserved_size(){
    return tam;
}

template <class TDATO>
void myVector<TDATO>::resize(int newtam){
    TDATO * aux = new TDATO[newtam];

    for(int i=0; i < num_incluidos; i++){
        aux[i] = m_vector[i];
    }

    tam = newtam;
    delete[] m_vector;
    m_vector = aux;

    return;


}

template <class TDATO>
void myVector<TDATO>::popBack(){
    if(!this->isEmpty()){
        num_incluidos--;
    }
}

template <class TDATO>
TDATO myVector<TDATO>::get(int pos){
    if(pos < num_incluidos){
        return m_vector[pos];
    }
}

