#include "myMachine.h"

myMachine::myMachine(){}

myMachine::myMachine(int num_hormigas, int num_hormigas2, int num_hormigas3, int num_hormigas4, int max_pasos,int rows, int cols)
:max_pasos(max_pasos),board(rows,cols), pasos(0)
{
	// Inicializamos la semilla.
	srand(time(NULL));
	
	int x, y;

	// Posiciones de las hormigas aleatorias.
	for(int i=0; i < num_hormigas; i++){
		myAntX aux_ant(board);

		x = getRandom(1,board.getCols()-2);
		y = getRandom(1,board.getRows()-2);
		
		aux_ant.setY(y);
		aux_ant.setX(x);

		v_ant.push_back(aux_ant);
	}

    cout << "size 1: " <<  v_ant.size() << endl;
    
	
	for(int i=0; i < num_hormigas2; i++){
		myNewAnt aux_ant2(board);

		x = getRandom(1,board.getCols()-2);
		y = getRandom(1,board.getRows()-2);
		
		aux_ant2.setY(y);
		aux_ant2.setX(x);

		v_new_ant.push_back(aux_ant2);
	}

    cout << "size 2: " <<  v_new_ant.size() << endl<<endl;
    
	    
    for(int i=0; i < num_hormigas3; i++){
		myNewAnt_DIDI aux_ant3(board);

		x = getRandom(1,board.getCols()-2);
		y = getRandom(1,board.getRows()-2);
		
		aux_ant3.setY(y);
		aux_ant3.setX(x);

		v_new_ant_DIDI.push_back(aux_ant3);
	}

    cout << "size 3::: " <<  v_new_ant.size() << endl<<endl;
    
	    
    for(int i=0; i < num_hormigas4; i++){
		myNewAnt_IDID aux_ant4(board);

		x = getRandom(1,board.getCols()-2);
		y = getRandom(1,board.getRows()-2);
		
		aux_ant4.setY(y);
		aux_ant4.setX(x);

		v_new_ant_IDID.push_back(aux_ant4);
	}

    cout << "size 4: " <<  v_new_ant.size() << endl<<endl;

}

////////////////////////////////////////////////////////////////////////////////	
////////////////////////////////////////////////////////////////////////////////	
int myMachine::getRandom(int ini, int fin){
	return rand()%fin+ini;
}

////////////////////////////////////////////////////////////////////////////////	
////////////////////////////////////////////////////////////////////////////////	
void myMachine::matarHormiga(const int pos){
	cout << "matando a hormiga " << pos << endl;
	auto it = v_ant.begin()+pos;
	v_ant.erase(it);
}

////////////////////////////////////////////////////////////////////////////////	
////////////////////////////////////////////////////////////////////////////////	
int myMachine::checkMatar(int x, int y, int pos, char muerte_id){
	bool puede_matar = false;
	int pos_matar = -1;

	for(int i=0; i < v_ant.size() and !puede_matar; i++){
		if(v_ant[i].getX() == x and v_ant[i].getY() == y and muerte_id == v_ant[i].getID() and i != pos){
			puede_matar = true;
			pos_matar = i;

			cout << "hormiga " << pos << " va a matar a hormiga " << pos_matar << endl;
		}
	}

	return pos_matar;
}

////////////////////////////////////////////////////////////////////////////////	
////////////////////////////////////////////////////////////////////////////////	
bool myMachine::checkMuerte(int x, int y, int pos, char ant_id){
	bool muere = false;

	for(int i=0; i < v_ant.size() and !muere; i++){
		if(v_ant[i].getX() == x and v_ant[i].getY() == y and pos != i and v_ant[i].getMuerteID() == ant_id){
			muere = true;
			cout << "hormiga " << i << " me va a matar." << v_ant[i].getY() << ' ' << v_ant[i].getX() << endl;
		}
	}

	return muere;
}

////////////////////////////////////////////////////////////////////////////////	
////////////////////////////////////////////////////////////////////////////////	
void myMachine::execute(){
	for(int i=0; i < max_pasos; i++){
		cout <<endl<< "--------- PASO: " << i+1 << " ----------" << endl << endl;
		makeMove();
	}
	
}


////////////////////////////////////////////////////////////////////////////////	
////////////////////////////////////////////////////////////////////////////////	
void myMachine::makeMove(){
	cout << "size:" << v_ant.size() << endl;
	for(int i=0; i < v_ant.size(); i++){
		cout << "Moviendo hormiga DDII: " << i << endl;
		antMove(i);
	}
	for (int j=0; j < v_new_ant.size(); j++){
		cout << "Moviendo hormiga IIDD: " << j << endl;
		antMove2(j);
	}
	for (int k=0; k < v_new_ant_DIDI.size(); k++){
		cout << "Moviendo hormiga DIDI: " << k << endl;
		antMove3(k);
	}
	for (int l=0; l < v_new_ant_IDID.size(); l++){
		cout << "Moviendo hormiga IDID: " << l << endl;
		antMove4(l);
	}
	cout << "SIZE TOTAL: " <<  (v_new_ant.size()+v_ant.size()+v_new_ant_IDID.size()+v_new_ant_DIDI.size()) << endl;
	
}

////////////////////////////////////////////////////////////////////////////////	
////////////////////////////////////////////////////////////////////////////////	
void myMachine::antMove(int posAnt){
	
	myAntX ant = v_ant[posAnt];
	
	int x,y;
	//cout << "obteniendo posición de la hormiga" << endl;
	x = ant.getX();
	y = ant.getY();

	char color = board.getColor(x,y); //Casillas de la hormiga
	//cout << "obteniendo nuevo color" << endl;
	char nuevo_color = ant.movimiento(color);
	
	//cout << "cambiando el color del tablero" << endl;
	// Cambiamos el color.
	board.setColor(x, y, nuevo_color);

	ant.ver(cout);

	v_ant[posAnt] = ant;

	
	int matar = checkMatar(ant.getX(), ant.getY(), posAnt, ant.getMuerteID() );

	if(checkMuerte(ant.getX(),ant.getY(),posAnt,ant.getID()) ){
		matarHormiga(posAnt);
	}
	else if( matar != -1 )
		matarHormiga(matar);

}

////////////////////////////////////////////////////////////////////////////////	
////////////////////////////////////////////////////////////////////////////////	
void myMachine::antMove2(int posAnt){
	
	myNewAnt ant2 = v_new_ant[posAnt];
	
	int x,y;
	//cout << "obteniendo posición de la hormiga" << endl;
	x = ant2.getX(); //Cojo las coordenadas de la hormiga del vector
	y = ant2.getY();

	char color = board.getColor(x,y); //Casillas de la hormiga actual
	//cout << "obteniendo nuevo color" << endl;
	char nuevo_color = ant2.movimiento(color); //Vemos que color se tiene que poner con movimiento
	
	//cout << "cambiando el color del tablero" << endl;
	// Cambiamos el color.
	board.setColor(x, y, nuevo_color);

	ant2.ver(cout);

	v_new_ant[posAnt] = ant2;

	
	int matar = checkMatar(ant2.getX(), ant2.getY(), posAnt, ant2.getMuerteID() );

	if(checkMuerte(ant2.getX(),ant2.getY(),posAnt,ant2.getID()) ){
		matarHormiga(posAnt);
	}
	else if( matar != -1 )
		matarHormiga(matar);

}

////////////////////////////////////////////////////////////////////////////////	
////////////////////////////////////////////////////////////////////////////////	
void myMachine::antMove3(int posAnt){
	
	myNewAnt_DIDI ant3 = v_new_ant_DIDI[posAnt];
	
	int x,y;
	//cout << "obteniendo posición de la hormiga" << endl;
	x = ant3.getX();
	y = ant3.getY();

	char color = board.getColor(x,y); //Casillas de la hormiga
	//cout << "obteniendo nuevo color" << endl;
	char nuevo_color = ant3.movimiento(color);
	
	//cout << "cambiando el color del tablero" << endl;
	// Cambiamos el color.
	board.setColor(x, y, nuevo_color);

	ant3.ver(cout);

	v_new_ant_DIDI[posAnt] = ant3;


	int matar = checkMatar(ant3.getX(), ant3.getY(), posAnt, ant3.getMuerteID() );

	if(checkMuerte(ant3.getX(),ant3.getY(),posAnt,ant3.getID()) ){
		matarHormiga(posAnt);
	}
	else if( matar != -1 )
		matarHormiga(matar);
}

////////////////////////////////////////////////////////////////////////////////	
////////////////////////////////////////////////////////////////////////////////	
void myMachine::antMove4(int posAnt){
	
	myNewAnt_IDID ant4 = v_new_ant_IDID[posAnt];
	
	int x,y;
	//cout << "obteniendo posición de la hormiga" << endl;
	x = ant4.getX();
	y = ant4.getY();

	char color = board.getColor(x,y); //Casillas de la hormiga
	//cout << "obteniendo nuevo color" << endl;
	char nuevo_color = ant4.movimiento(color);
	
	//cout << "cambiando el color del tablero" << endl;
	// Cambiamos el color.
	board.setColor(x, y, nuevo_color);

	ant4.ver(cout);

	v_new_ant_IDID[posAnt] = ant4;
	
	
	int matar = checkMatar(ant4.getX(), ant4.getY(), posAnt, ant4.getMuerteID() );

	if(checkMuerte(ant4.getX(),ant4.getY(),posAnt,ant4.getID()) ){
		matarHormiga(posAnt);
	}
	else if( matar != -1 )
		matarHormiga(matar);

}


