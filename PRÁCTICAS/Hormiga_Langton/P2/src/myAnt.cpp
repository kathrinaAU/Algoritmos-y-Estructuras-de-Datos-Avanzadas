/* Autor: Kathrina Arrocha Umpiérrez
   Contacto: alu0100913293@ull.edu.es
   Práctica: Langton's Ant
   Fecha de entrega: 1 de Febrero de 2018  */

#include <iostream>
#include <cstdlib>
#include "myAnt.hpp"

using namespace std;

myAnt::myAnt(){
}

myAnt::~myAnt(){
}

char myAnt::getDirection(){
    return direction[pos_dir];
}

void myAnt::setDirection(int dir){
   pos_dir = (pos_dir+dir+4)%4;
}

int myAnt::getX() {
    return xPos;
}

int myAnt::getY() {
    return yPos;
}

void myAnt::setX(int x) {
    xPos = x;
}

void myAnt::setY(int y) {
    yPos = y;
}


