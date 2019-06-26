#pragma once
template <class TDATO>
myQueue<TDATO>::myQueue(int max_sz):
        v_(max_sz),
        front_(0),
        back_(-1) {}

template <class TDATO>
myQueue<TDATO>::myQueue(void):
        v_(MAX_STACK_SIZE),
        front_(0),
        back_(-1) {}

template <class TDATO>
myQueue<TDATO>::~myQueue(void) {}

template <class TDATO>
bool myQueue<TDATO>::isEmpty(void){
    return (back_ < front_);
}

template <class TDATO>
bool myQueue<TDATO>::full(void){
    return (size() >= v_.size() - 1);
}

template <class TDATO>
int myQueue<TDATO>::size(void)
{
    return back_-front_+1 ;
}

template <class TDATO>
TDATO myQueue<TDATO>::front(void){
    assert(!isEmpty());
    return v_.get(front_);
}

template <class TDATO>
TDATO myQueue<TDATO>::back(void){
    assert(!isEmpty());
    return v_.get(back_);
}


template <class TDATO>
void myQueue<TDATO>::pop(void){
    assert(!isEmpty());
    front_++;
}

template <class TDATO>
void myQueue<TDATO>::push(TDATO dato){
    assert(!full());

    back_++;
    v_.set(back_,dato);
}

template <class TDATO>
ostream& myQueue<TDATO>::write(ostream& os){

    for(int i = front_; i <= back_; ++i)
        os << setw(4) << v_.get(i);

    os << endl;


    return os;
}
