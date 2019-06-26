/* Autor: Kathrina Arrocha Umpiérrez
   Contacto: alu0100913293@ull.edu.es
   Práctica: Langton's Ant
   Fecha de entrega: 1 de Febrero de 2018  */
   
#ifndef MYMACHINE
#define MYMACHINE

#include <utility>
#include <vector>
#include "myAnt.hpp"
#include "myBoard.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class myMachine{

private:

	vector<vector<pair<int,int> > > v;
	vector<myAnt> v_ant;
	myBoard board;

	int pasos;
	int max_pasos;


public:
	myMachine();
	myMachine(int num_hormigas, int num_pasos=10, int rows=21, int cols=31); //Por defecto
	~myMachine();

	int getRandom(int ini, int fin);

	void antMove(int posAnt);
	// void bordersColor();
	vector<vector<pair<int,int> > > execute();
	void makeMove();

};

#endif
