#ifndef MYSTACKLIST_H
#define MYSTACKLIST_H
#pragma once

#include <iostream>
#include <iomanip>
#include <cassert>
#include <iostream>


#include "mydoublelist.h"

template <class TDATO>
class myStackList{
	
private:

	myDoubleList<TDATO>    l_;

public:	
	myStackList(void);
	
	~myStackList(void);

	bool isEmpty(void);
	TDATO top(void);
	void pop(void);
	void push(TDATO dato);
	ostream& write(ostream& os);


};

#include "mystacklist.hpp"

#endif // MYSTACKLIST_H