/* Autor: Kathrina Arrocha Umpi�rrez
   Contacto: alu0100913293@ull.edu.es
   Pr�ctica: Langton's Ant
   Fecha de entrega: 1 de Febrero de 2018  */
#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include "myMachine.h"
#include "myAntX.h"
#include "myNewAnt.h"
#include "myBoard.h"
#include "colores.hpp"

using namespace std;


void animacion_inicio(void){

	system("clear");

	int contador=1;
	
	do{	
	
		cout <<endl<<endl;
		cout<<FCYN("			LANGTON'S ANTS");
		cout<<endl;
		sleep(2);
		system("clear");
		
	
		cout <<endl<<endl;
		cout<<FGRN("					CARGANDO.");
		cout<<endl;
		sleep(1);
		system("clear");
		
		cout <<endl<<endl;
		cout<<FGRN("				   `O´__  ") <<endl;
		cout<<FGRN("			             !!!!  ");
		cout<<endl;
    	sleep(1);
		system("clear");
	
		cout <<endl<<endl;
		cout<<FGRN("					CARGANDO..");
		cout<<endl;
		sleep(1);
		system("clear");
		
		cout <<endl<<endl;
		cout<<FGRN("				   `O´__  `O´__  ") <<endl;
		cout<<FGRN("			             !!!!   !!!!  ");
		cout<<endl;
    	sleep(1);
		system("clear");
		
		cout <<endl<<endl;
		cout<<FGRN("					CARGANDO...");
		cout<<endl;
    	sleep(1);
		system("clear");
		
		cout <<endl<<endl;
		cout<<FGRN("				   `O´__  `O´__  `O´__  ") <<endl;
		cout<<FGRN("			             !!!!   !!!!   !!!!  ");
		cout<<endl;
    	sleep(1);
		system("clear");
		
		
		contador++;
	
	}while(contador<=1);
}


int main() {
	//animacion_inicio();

	int num_hormigas, num_hormigas2, num_hormigas3, num_hormigas4, num_pasos, cols, rows;
	cout << endl<<endl<<endl<< "------- Bienvenido a la hormiga de Langton: -------"<<endl<<endl;
	cout << "Inserte el numero de hormigas DDII que desea: " << endl;
	cin >> num_hormigas;
		cout << "Inserte el numero de hormigas IIDD que desea: " << endl;
	cin >> num_hormigas2;
	cout << "Inserte el numero de hormigas DIDI que desea: " << endl;
	cin >> num_hormigas3;
		cout << "Inserte el numero de hormigas IDID que desea: " << endl;
	cin >> num_hormigas4;
	cout << "Inserte el numero de pasos maximo que desea: " << endl;
	cin >> num_pasos;
	cout << "Inserte el numero de filas del tablero: " << endl;
	cin >> rows;
	cout << "Inserte el numero de columnas del tablero: " << endl<<endl;
	cin >> cols;

	myMachine mMachine(num_hormigas, num_hormigas2, num_hormigas3, num_hormigas4, num_pasos, rows,cols);
	mMachine.execute();

	return 0;
}