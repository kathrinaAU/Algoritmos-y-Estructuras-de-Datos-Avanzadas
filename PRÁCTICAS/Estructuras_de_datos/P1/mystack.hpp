#pragma once
template <class TDATO>
myStack<TDATO>::myStack():
    v_(MAX_STACK_SIZE),
    top_(-1)
{}

template <class TDATO>
myStack<TDATO>::myStack(int max_sz):
    v_(max_sz),
    top_(-1)
{}

template <class TDATO>
myStack<TDATO>::~myStack()
{}

template <class TDATO>
bool myStack<TDATO>::isEmpty(){
    return (top_ < 0);
}


template <class TDATO>
bool myStack<TDATO>::isFull(){
    return (top_ == v_.size() -1);
}


template <class TDATO>
void myStack<TDATO>::push(TDATO dato){
    //assert(top_ < v_.size() - 1);
    top_++;
    v_.pushBack(dato); //= dato;
}

template <class TDATO>
void myStack<TDATO>::pop(){
    assert(!isEmpty());
    top_--;
}

template <class TDATO>
TDATO myStack<TDATO>::top(){
    assert(!isEmpty());
    return v_.get(top_);
}