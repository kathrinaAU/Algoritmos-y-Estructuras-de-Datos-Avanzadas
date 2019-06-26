#pragma once
template <class TDATO>
myRoundVector<TDATO>::myRoundVector():
    v_(NULL),
    sz_(0)
{}


template <class TDATO>
myRoundVector<TDATO>::myRoundVector(int tam):
    v_(NULL),
    sz_(tam)
{
    crea_vector();
}

template <class TDATO>
myRoundVector<TDATO>::~myRoundVector(){
    destruye_vector();
}


template <class TDATO>
bool myRoundVector<TDATO>::isEmpty(){
    return sz_ == 0;
}

template <class TDATO>
void myRoundVector<TDATO>::pushBack(TDATO newdato){
    v_[sz_] = newdato;
    sz_++;
}

template <class TDATO>
void myRoundVector<TDATO>::popBack(){
    if(!this->isEmpty()){
        sz_--;
    }
}



template <class TDATO>
void myRoundVector<TDATO>::resize(int tam){
    TDATO * aux = new TDATO[tam];

    for(int i=0; i < sz_; i++){
        aux[i] = v_[i];
    }

    sz_ = tam;
    delete[] v_;
    v_ = aux;
}

template <class TDATO>
void myRoundVector<TDATO>::crea_vector(void){
    v_ = new TDATO[sz_];
    assert(v_!= NULL);
}

template <class TDATO>
void myRoundVector<TDATO>::destruye_vector(void){
    if (v_ != NULL){
        delete[] v_;
        v_ = NULL;
    }
}

template <class TDATO>
int myRoundVector<TDATO>::size(){
    return sz_;
}

template <class TDATO>
TDATO myRoundVector<TDATO>::get(int pos){
    assert (pos >=0);
    return v_[(pos % sz_)];
}

template <class TDATO>
TDATO myRoundVector<TDATO>::set(int pos,TDATO dato){
    assert(pos>=0);
    v_[pos % sz_] = dato;
}
