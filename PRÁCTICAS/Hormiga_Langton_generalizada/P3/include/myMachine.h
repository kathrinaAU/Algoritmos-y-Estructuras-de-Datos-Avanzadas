#ifndef MYMACHINE_H
#define MYMACHINE_H

#include "myAntX.h"
#include "myBoard.h"
#include "myNewAnt.h"
#include "myNewAnt_DIDI.h"
#include "myNewAnt_IDID.h"
#include <cstdlib>
#include <iostream>
using namespace std;


class myMachine{
private:
    vector<myAntX> v_ant;
    vector<myNewAnt> v_new_ant;
    vector<myNewAnt_DIDI> v_new_ant_DIDI;
    vector<myNewAnt_IDID> v_new_ant_IDID;
    myBoard board;
    int pasos;
    int max_pasos;

public:
    myMachine();
    myMachine(int num_hormigas, int hum_hormigas2, int num_hormigas3, int hum_hormigas4, int max_pasos=10,int rows=21, int cols=21);
    
    int getRandom(int ini, int fin);
    void antMove(int posAnt);
    void antMove2(int posAnt);
    void antMove3(int posAnt);
    void antMove4(int posAnt);
    void makeMove();
    void execute();
    bool checkMuerte(int x, int y, int pos, char ant_id); // Comprobar si nos matan cuando avancemos.
	int checkMatar(int x, int y, int pos, char muerte_id); // Comprobar si matamos cuando avanzamos.
	void matarHormiga(const int pos); // Borramos a la hormiga en la posici�n v_ant.begin()+pos .
    
};

#endif