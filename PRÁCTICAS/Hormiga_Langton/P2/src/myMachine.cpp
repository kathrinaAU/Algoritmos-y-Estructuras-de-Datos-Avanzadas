/* Autor: Kathrina Arrocha Umpiérrez
   Contacto: alu0100913293@ull.edu.es
   Práctica: Langton's Ant
   Fecha de entrega: 1 de Febrero de 2018  */
   
#include <iostream>
#include <cstdlib>
#include "myMachine.hpp"

using namespace std;

myMachine::myMachine(int num_hormigas, int num_pasos, int rows, int cols)
:v(num_hormigas),max_pasos(num_pasos),board(rows,cols)
{
	// Inicializamos la semilla.
	srand(time(NULL));

	myAnt aux_ant;
	int x, y;

// Posiciones de las hormigas aleatorias.
	for(int i=0; i < num_hormigas; i++){
		x = getRandom(1,board.getWidth()-2);
		y = getRandom(1,board.getHeight()-2);

		aux_ant.setY(y);
		aux_ant.setX(x);

		v_ant.push_back(aux_ant);
	}

}

int myMachine::getRandom(int ini, int fin){
	return rand()%fin+ini;
}

myMachine::myMachine():
	pasos(0),max_pasos(10)
{
	
}

myMachine::~myMachine(){}

vector<vector<pair<int, int> > > myMachine::execute(){
	for(int i=0; i < max_pasos; i++){
		cout <<endl<< "--------- PASO: " << i+1 << " ----------" << endl << endl;
		makeMove();
	}
	return v;
}


void myMachine::makeMove(){
	for(int i=0; i < v_ant.size(); i++){
		cout << "Moviendo hormiga: " << i << endl;
		antMove(i);
	}
	board.drawBoard(v_ant);
}

void myMachine::antMove(int posAnt){
	//cout << "obteniendo hormiga" << endl;
	myAnt ant = v_ant[posAnt];
	//cout << "hormiga: hello" << endl;

	int x,y;
	x = ant.getX();
	y = ant.getY();

	char color = board.getColor(x,y);
	char ant_direction;

	cout << "mirando color del tablero." << endl;
	// Cambiamos la direcciÃ³n depediendo del color.
	if(color == 'x'){
		ant.setDirection(1);

	}else{
		ant.setDirection(-1);
	}

	cout << "cambiando el color del tablero" << endl;
	// Cambiamos el color.
	board.setColor(x,y);

	cout << "Cambiando direccion de la hormiga " << endl;
	// Avanzamos segÃºn la direcciÃ³n de la hormiga.
	ant_direction = ant.getDirection();
	switch(ant_direction){
		case '^': // (0,1)
			ant.setY(y+1);
			v[posAnt].push_back(pair<int,int>(0,-1));
		break;

		case '>': // (1,0)
			ant.setX(x-1);
			v[posAnt].push_back(pair<int,int>(1,0));
		break;

		case 'v': // (0,-1)
			ant.setY(y-1);
			v[posAnt].push_back(pair<int,int>(0,1));
			
		break;

		case '<': // (-1,0)
			ant.setX(x+1);
			v[posAnt].push_back(pair<int,int>(-1,0));
		break;
	}

	//cout << "comprobando que no este en el borde" << endl;
	if((ant.getY() == board.getHeight()-1) || (ant.getX() == board.getWidth()-1) || (ant.getY() == 0) || (ant.getX() == 0)){
		ant.setY((board.getHeight()-1)/2);
		ant.setX((board.getWidth()-1)/2);
	}

	cout << "Movimiento hecho en: " << y << " " << x << endl;
	cout << "Nuevo color: " << board.getColor(x,y) << endl;
	cout << "Avanzado a: " << ant.getY() << ' ' << ant.getX() << endl;
	cout << "Nuevo direccion de la hormiga: " << ant.getDirection() << endl << endl;

	v_ant[posAnt] = ant;


}
