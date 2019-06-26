/* Autor: Kathrina Arrocha Umpiérrez
   Contacto: alu0100913293@ull.edu.es
   Práctica: Langton's Ant
   Fecha de entrega: 1 de Febrero de 2018  */

#include "myBoard.hpp"

#include <iostream>
using namespace std;

myBoard::myBoard()
:height(21),width(31){
    m_board = new char*[height];
	for (int i = 0; i < myBoard::height; i++) {
        m_board[i] = new char[width];
        for (int j = 0; j < myBoard::width; j++) {
        	m_board[i][j] = ' ';
        }
    }
}

myBoard::myBoard(int rows, int cols)
:height(rows+1),width(cols+1){
    m_board = new char*[height];
    for(int i=0; i < height; i++){
        m_board[i] = new char[width];
        for(int j=0; j < width; j++)
            m_board[i][j] = ' ';
    }
}

void myBoard::drawBoard(vector<myAnt> &ants){
    bool ant_draw = false;
    for(auto i=height-1; i >= 0; i--){
        for(auto j=width-1; j >= 0; j--){
            ant_draw = false;
            for(auto ant = 0; ant < ants.size(); ant++){
                if(ants[ant].getX() == j and ants[ant].getY() == i){
                    cout << "A" << ' ';
                    ant_draw = true;
                }
            }
            if((i==0) || (i == height-1) || (j == 0) || (j == width-1)){
                cout << '*' << ' ';
            }
            else if(!ant_draw){
                cout << m_board[i][j] << ' '; 
            }
            
        }
        cout << endl;
    }
}


myBoard::~myBoard(){}


const int myBoard::getWidth(){
    return width;
}

const int myBoard::getHeight(){
    return height;
}

char myBoard::getColor(int x, int y){
    return m_board[y][x];
}

void myBoard::setColor(int x, int y){
    if(m_board[y][x] == 'x')
        m_board[y][x] = ' ';
    else
        m_board[y][x] = 'x';
}

void myBoard::Bordes(){
    for(int i = 0; i <= height; i++){
        m_board[i][0] = '*';
    }
    for(int j = 0; j <= width; j++){
        m_board[0][j] = '*';
    }
}

void myBoard::setColorChar(char newColor) {
  colorA = newColor;
}
