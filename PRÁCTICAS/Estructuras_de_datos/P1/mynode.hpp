#pragma once
template <class TDATO>
myNode<TDATO>::myNode():
    next_(0),
    dato_(0)
{}


template <class TDATO>
myNode<TDATO>::myNode(TDATO dato):
    next_(0),
    dato_(dato)
{}


template <class TDATO>
myNode<TDATO>::~myNode()
{
    next_ = 0;
}

template<class TDATO>
myNode<TDATO> *myNode<TDATO>::get_next()
{
    return next_;
}


template <class TDATO>
TDATO myNode<TDATO>::get_dato(){
    return dato_;
}

template <class TDATO>
void myNode<TDATO>::set_next(myNode* next){
    next_ = next;
}

template <class TDATO>
void myNode<TDATO>::set_dato(TDATO dato){
    dato_ = dato;
}
