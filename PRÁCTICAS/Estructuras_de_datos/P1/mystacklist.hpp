#pragma once
template <class TDATO>
myStackList<TDATO>::myStackList(void):
		l_() 
{}

template <class TDATO>
myStackList<TDATO>::~myStackList()
{}

template <class TDATO>
bool myStackList<TDATO>::isEmpty(void){
	return l_.isEmpty();
}

template <class TDATO>
TDATO myStackList<TDATO>::top(void){
	assert(!isEmpty());
			
	myDoubleNode<TDATO>* node = l_.get_head();
	TDATO dato = node->get_dato();
	return (dato);
}
	
template <class TDATO>
void myStackList<TDATO>::pop(void){
	assert(!isEmpty());			

	myDoubleNode<TDATO>* node = l_.extract_head();
	delete node;
}

template <class TDATO>
void myStackList<TDATO>::push(TDATO dato){
	
	myDoubleNode<TDATO>* node = new myDoubleNode<TDATO>(dato);
	l_.insert_head(node->get_dato());
}

	
template <class TDATO>
ostream& myStackList<TDATO>::write(ostream& os){
	myDoubleNode<TDATO>* aux = l_.get_head();
	
	while(aux != NULL){
		cout << " ”‚ " << setw(2)<< aux->get_dato() << "  ”‚" << endl;
		aux = aux->get_next();
	}

	cout << " ”˜" << endl; 
}	

