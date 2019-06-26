#pragma once
template <class TDATO>
myDoubleList<TDATO>::myDoubleList() :
    head_(NULL),
    tail_(NULL),
    sz_(0)
{}

template <class TDATO>
myDoubleList<TDATO>::~myDoubleList(){
    myDoubleNode<TDATO>* aux = NULL;

    while (head_ != NULL) {
               aux = head_;
               head_ = head_->get_next();
               delete aux;
               aux = NULL;
           }
           sz_ = 0;
           head_ = NULL;
           tail_ = NULL;
}

template <class TDATO>
bool myDoubleList<TDATO>::isEmpty(){
    if (head_ == NULL){
        assert(tail_ == NULL);
        assert(sz_ == 0);
        return true;
 } else
    return false;
}

template <class TDATO>
void myDoubleList<TDATO>::insert_head(TDATO dato) {


    myDoubleNode<TDATO>* nodo = new myDoubleNode<TDATO>(dato);

    if (isEmpty()) {

        head_ = nodo;
        tail_ = head_;
    } else {

        head_->set_prev(nodo);
        nodo->set_next(head_);
        head_ = nodo;
    }
    sz_++;
}

template <class TDATO>
void myDoubleList<TDATO>::insert_tail(TDATO dato) {
    myDoubleNode<TDATO>* nodo = new myDoubleNode<TDATO>(dato);


   if (isEmpty()) {
       head_ = nodo;
       tail_ = head_;
   } else {
       tail_->set_next(nodo);
       nodo->set_prev(tail_);
       tail_ = nodo;
   }
   sz_++;
}

template <class TDATO>
myDoubleNode<TDATO>* myDoubleList<TDATO>::extract_tail(void) {
    assert(!isEmpty());

    myDoubleNode<TDATO>* aux = tail_;
    tail_ = tail_->get_prev();

    if (tail_ != NULL)
       tail_->set_next(NULL);
    else
       head_ = NULL;

    sz_--;
    aux->set_next(NULL);
    aux->set_prev(NULL);

    return aux;
}


template <class TDATO>
myDoubleNode<TDATO>* myDoubleList<TDATO>::extract_head(void) {
    assert(!isEmpty());

    myDoubleNode<TDATO>* aux = head_;
    head_ = head_->get_next();

    if (head_)
       head_->set_prev(NULL);
    else
       tail_ = NULL;

    sz_--;
    aux->set_next(NULL);
    aux->set_prev(NULL);

    return aux;
    }

template <class TDATO>
myDoubleNode<TDATO>* myDoubleList<TDATO>::get_head(void) {
    myDoubleNode<TDATO>* aux = head_;
    return aux;
}

template <class TDATO>
myDoubleNode<TDATO>* myDoubleList<TDATO>::get_tail(void) {
    myDoubleNode<TDATO>* aux = tail_;
    return aux;
}

template <class TDATO>
void myDoubleList<TDATO>::remove(TDATO dato) {
    
     myDoubleNode<TDATO>* nodo = new myDoubleNode<TDATO>(dato);

    if (nodo->get_prev() != NULL)
       nodo->get_prev()->set_next(nodo->get_next());
    else
       head_ = nodo->get_next();

    if (nodo->get_next() != NULL)
       nodo->get_next()->set_prev(nodo->get_prev());
    else
       tail_ = nodo->get_prev();

    delete nodo;
    sz_--;

   }

template <class TDATO>
int myDoubleList<TDATO>::size(void) {
    return sz_;
}

template <class TDATO>
ostream& myDoubleList<TDATO>::write(ostream& os) {


    myDoubleNode<TDATO>* aux = head_;

    while (aux != NULL) {
       aux->write(os);

       aux = aux->get_next();
    }
    os << endl;
    return os;
}

