#pragma once
template <class TDATO>
myList<TDATO>::myList()
    : root(0), num_nodos(0)
{

}

template <class TDATO>
myList<TDATO>::~myList(){
    root = 0;
    num_nodos = 0;
}

template <class TDATO>
bool myList<TDATO>::isEmpty(){
    return (num_nodos == 0);
}

template <class TDATO>
int myList<TDATO>::size(){
    return num_nodos;
}

template<class TDATO>
TDATO myList<TDATO>::get(int pos)
{
    if(pos < num_nodos){
        myNode<TDATO> *aux=root;
        for(int i=0; i < pos; i++){
            aux=aux->get_next();
        }

        return aux->get_dato();
    }

}


template <class TDATO>
void myList<TDATO>::insert(TDATO dato, int pos){
    if(pos == 0){
        pushFront(dato);
    }else{
        myNode<TDATO> *pre;
        myNode<TDATO> *current;
        myNode<TDATO> *newnode = new myNode<TDATO>(dato);

        current = root;

        for(int i=0; i < pos; i++){
            pre = current;
            current = current->get_next();
        }

        newnode->set_next(current);
        pre->set_next(newnode);

        num_nodos++;
    }

}


template <class TDATO>
myNode<TDATO> myList<TDATO>::extract(int pos){
    if(pos == 0){
        popFront();
    }else{
        myNode<TDATO> *pre;
        myNode<TDATO> *current;

        current = root;

        for(int i=0; i < pos; i++){
            pre = current;
            current = current->get_next();
        }

        pre->set_next(current->get_next());
        current->set_next(0);

        num_nodos--;
        return current->get_dato();
    }
}

template <class TDATO>
void myList<TDATO>::pushFront(TDATO dato){
    myNode <TDATO> *nodo = new myNode<TDATO>(dato);
    nodo->set_next(root);
    root = nodo;
    num_nodos++;
}

template <class TDATO>
void myList<TDATO>:: popFront(){
    myNode <TDATO> *nodo = root;
    root = root->get_next();
    delete nodo;
    num_nodos--;
}
