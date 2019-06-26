#pragma once
template <class TDATO>
myQueueList<TDATO>::myQueueList():
    list_()
{}

template <class TDATO>
myQueueList<TDATO>::~myQueueList()

{}

template <class TDATO>
bool myQueueList<TDATO>::isEmpty(void){
	return list_.isEmpty();
}

template <class TDATO>
int myQueueList<TDATO>::size(void){
	return list_.size();		
}


template <class TDATO>
void myQueueList<TDATO>::push(TDATO dato){
    list_.insert_head(dato);
}


template <class TDATO>
void myQueueList<TDATO>::pop(void){
			assert(!isEmpty());			

			myDoubleNode<TDATO>* node = list_.extract_tail();
			delete node;
		}

template <class TDATO>
TDATO myQueueList<TDATO>::front(){
    assert (!isEmpty());
    
    myDoubleNode<TDATO>* node = list_.get_tail();
	TDATO dato = node->get_dato();
	return (dato);
}


template <class TDATO>
TDATO myQueueList<TDATO>::back(void){

	assert(!isEmpty());
	
	myDoubleNode<TDATO>* node = list_.get_head();
	TDATO dato = node->get_dato();
	return (dato);
}


template <class TDATO>
ostream& myQueueList<TDATO>::write(ostream& os){
	

	myDoubleNode<TDATO>* aux = list_.get_head();

	while(aux != NULL){
		os << setw(4)<< aux->get_dato();
		aux = aux->get_next();
	}

	os << endl;			

	return os;
}