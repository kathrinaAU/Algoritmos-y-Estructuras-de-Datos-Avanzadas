#include "myNewAnt.h"

myNewAnt::myNewAnt(){}

myNewAnt::~myNewAnt(){}

myNewAnt::myNewAnt(myBoard &b)
    :myAnt(b)
{
    muerte_id = '1';
    id = '2';
    mColorMap.push_back(pair<char,char>(' ','I'));
	mColorMap.push_back(pair<char,char>('b','I'));
	mColorMap.push_back(pair<char,char>('p','D'));
	mColorMap.push_back(pair<char,char>('n','D'));
}

ostream& myNewAnt::ver(ostream &os){

    os << "Posicion: " << yPos << ' ' << xPos << endl;
    os << "Nueva dirección: " << getDirection() << endl;   

    for(auto y=board.getRows()-1; y >= 0; y--){
        for(auto x=0; x < board.getCols(); x++){
            if(y ==  yPos and x == xPos)
                os << getID() << ' ' ;
            else if( (y == 0 or y == board.getRows()-1) or (x==0 or x==board.getCols()-1))
                os << '*' << ' ' ;
            else
                os << board.getColor(x,y) << ' ';
            
        }
        os << endl;
    }

    return os;
}

char myNewAnt::movimiento(char color){
    // Obtenemos color al que cambiar y cambiamos la direcci�n.
	char new_color = setNewDirection(color);

	// Nos movemos en la direcci�n que hemos elegido.
	go();
	// Comprobamos que no estamos en el borde del tablero.
	checkBorders();

	return new_color;
}

int myNewAnt::findInColorMap(char color){
	int pos = -1;
	bool encontrado = false;

	for(auto i=0; i <mColorMap.size() and !encontrado; i++){
		if(mColorMap[i].first == color){
			encontrado = true;
			pos = i;
		}
	}

	return pos;
}

char myNewAnt::setNewDirection(char color){
	char new_color;

	int color_pos = findInColorMap(color);

	if(mColorMap[color_pos].second == 'I'){
		setDirection(-1);
	}else{
		setDirection(1);
	}

	new_color = mColorMap[(color_pos+1)%mColorMap.size()].first;

	return new_color;

}

void myNewAnt::go(){

	switch(getDirection()){
		case '^': // (0,1)
			setY(yPos+1);
			v.push_back(pair<int,int>(0,-1));
		break;

		case '>': // (1,0)
			setX(xPos+1);
			v.push_back(pair<int,int>(1,0));
		break;

		case 'v': // (0,-1)
			setY(yPos-1);
			v.push_back(pair<int,int>(0,1));
		break;

		case '<': // (-1,0)
			setX(xPos-1);
			v.push_back(pair<int,int>(-1,0));
		break;
	}

}
