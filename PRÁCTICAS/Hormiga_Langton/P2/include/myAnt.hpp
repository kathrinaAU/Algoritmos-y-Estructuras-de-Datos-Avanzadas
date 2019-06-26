/* Autor: Kathrina Arrocha Umpiérrez
   Contacto: alu0100913293@ull.edu.es
   Práctica: Langton's Ant
   Fecha de entrega: 1 de Febrero de 2018  */

#ifndef MYANT
#define MYANT

using namespace std;

class myAnt{
    
    private:
        int xPos;   
        int yPos;
        char direction[4] = {'^','>','v','<'};
        int pos_dir = 0;
    
	public:
        myAnt();
        ~myAnt();
        
        char getDirection();
        void setDirection(int dir);
        void setColor(int x, int y);
        int getX();
        int getY();
        void setX(int x);
        void setY(int y);
        
};

#endif
