/* Autor: Kathrina Arrocha Umpiérrez
   Contacto: alu0100913293@ull.edu.es
   Práctica: Langton's Ant
   Fecha de entrega: 1 de Febrero de 2018  */
   
#ifndef MYBOARD_H
#define MYBOARD_H

#include "myAnt.hpp"
#include <vector>
using namespace std;

class myBoard {

public:
 	char colorA;
 	
 	myBoard(); 
	myBoard(int rows, int cols);
	~myBoard();
	
	char getColor(int x, int y);
	void setColor(int x, int y);
	const int getWidth();
	const int getHeight();
	void Bordes();
	void drawBoard(vector<myAnt> &ants);
	
	void setColorChar(char newColor);
  
private:
	int width;
	int height;
	char **m_board;
  
};

#endif
