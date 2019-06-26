#pragma once
template <class TDATO>
myDoubleNode<TDATO>::myDoubleNode():
    next_(0),
    prev_(0),
    dato_()
{}

template <class TDATO>
myDoubleNode<TDATO>::myDoubleNode(TDATO& dato):
    next_(0),
    prev_(0),
    dato_(dato)
{}

template <class TDATO>
myDoubleNode<TDATO>::~myDoubleNode() {
prev_ = 0;
next_ = 0;
}

template <class TDATO>
void myDoubleNode<TDATO>::set_next(myDoubleNode<TDATO>* next){
    next_ = next;
}

template <class TDATO>
void myDoubleNode<TDATO>::set_prev(myDoubleNode<TDATO>* prev){
    prev_ = prev;
}

template <class TDATO>
void myDoubleNode<TDATO>::set_dato(TDATO& dato){
    dato_ = dato;
}

template <class TDATO>
myDoubleNode<TDATO>* myDoubleNode<TDATO>::get_prev(){
    return prev_;
}

template <class TDATO>
myDoubleNode<TDATO>* myDoubleNode<TDATO>::get_next(){
    return next_;
}

template <class TDATO>
TDATO myDoubleNode<TDATO>::get_dato(){
    return dato_;
}

template <class TDATO>
ostream& myDoubleNode<TDATO>::write(ostream &os) const{

    os << dato_ << ' ';

    return os;
}
