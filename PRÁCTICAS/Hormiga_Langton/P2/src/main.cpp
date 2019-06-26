/* Autor: Kathrina Arrocha Umpiérrez
   Contacto: alu0100913293@ull.edu.es
   Práctica: Langton's Ant
   Fecha de entrega: 1 de Febrero de 2018  */

#include <iostream>
#include "myMachine.hpp"

using namespace std;


int main() {
	int num_hormigas, num_pasos, cols, rows;
	cout << endl<<endl<<endl<< "------- Bienvenido a la hormiga de Langton: -------"<<endl<<endl;
	cout << "Inserte el numero de hormigas que desea: " << endl;
	cin >> num_hormigas;
	cout << "Inserte el numero de pasos maximo que desea: " << endl;
	cin >> num_pasos;
	cout << "Inserte el numero de filas del tablero: " << endl;
	cin >> rows;
	cout << "Inserte el numero de columnas del tablero: " << endl<<endl;
	cin >> cols;

	myMachine mMachine(num_hormigas, num_pasos, rows,cols);
	mMachine.execute();

	
	return 0;
}
