#ifndef MYQUEUELIST_H
#define MYQUEUELIST_H

#include "mydoublenode.hpp"
#include "mydoublelist.hpp"
#pragma once
#include <istream>
#include <ostream>
#include <iostream>
#include "mydoublelist.h"
using namespace std;

template <class TDATO>
class myQueueList {
    private:
        myDoubleList<TDATO> list_;

    public:
        myQueueList(void);
        ~myQueueList(void);

        void pop();
        void push(TDATO dato);
        TDATO front(void);
        TDATO back(void);
        
        int size(void);

        bool isEmpty(void);

        ostream& write(ostream& os);
};

#include "myqueuelist.hpp"

#endif // MYQUEUELIST_H
