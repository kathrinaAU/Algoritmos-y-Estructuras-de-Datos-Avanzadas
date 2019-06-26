#include <unistd.h>
#include <iostream>

#include "number.h"
//#include "colores.hpp"

using namespace std;


// void animacion_inicio(void){

// 	//system("clear");

// 	int contador=1;
	
// 	do{	
	
// 		cout <<endl<<endl;
// 		cout<<FCYN("			CONVERSIÓN DE NÚMEROS:");
// 		cout<<endl;
// 		cout <<FYEL( "                     Kathrina Arrocha Umpiérrez") <<endl;
// 		cout <<FYEL( "                  ALGORITMOS Y ESTRUCTURAS DE DATOS") <<endl;
// 		sleep(3);
// 		system("clear");
		
	
// 		cout <<endl<<endl;
// 		cout<<FGRN("					CARGANDO.");
// 		cout<<endl;
// 		sleep(1);
// 		system("clear");
		
	
// 		cout <<endl<<endl;
// 		cout<<FGRN("					CARGANDO..");
// 		cout<<endl;
// 		sleep(1);
// 		system("clear");
		
// 		cout <<endl<<endl;
// 		cout<<FGRN("					CARGANDO...");
// 		cout<<endl;
//     	sleep(1);
// 		system("clear");
		
		
// 		contador++;
	
// 	}while(contador<=1);
// }

int main(){

	// animacion_inicio();

    int num1;
    int num2;
    int num3;
    

	cout <<endl;
	cout << "	¡Bienvenido!"<< endl;
	cout << "	Introduzca el primer número: " <<endl; 
	cin >> num1;
    cout << "Crean el primer número..." <<endl;
	number<12,2> numero1;
    
    try {
		numero1 = number<12,2>(num1);
		numero1.write(cout);
		cout << endl;
		cout << endl;
	}catch( exception & e ){
		cout << "Cannot create number" << endl;
	}
      
    cout << "	Introduzca el segundo número: " <<endl; 
	cin >> num2;
    cout << "Crean el segundo número..." <<endl;
    
	
    number<12,8> numero2(num2);
    numero2.write(cout);

    int opcion = -1;
    while(opcion!=0){
   		
   			cout <<endl <<endl;
   			cout<< BOLD("        *********************** OPCIONES ************************") <<endl;
   			cout << "\t" << "*---------------------------------------------------------*" <<endl;
			cout << "\t" << "*----->	1. Sumar numero1 y numero2. -------------------*" <<endl;
            cout << "\t" << "*----->	2. Multiplicar numero1 y numero2. --------------*" <<endl;
            cout << "\t" << "*----->	3. Restar numero1 y numero2. -------------------*" <<endl;
            cout << "\t" << "*----->	4. Dividir numero1 y numero2. --------------*" <<endl;
            cout << "\t" << "*----->	5. Comparar si numero1 < numero2. --------------*" <<endl;
            cout << "\t" << "*----->	6. Comparar si numero1 > numero2. --------------*" <<endl;
			cout << "\t" << "*----->	7. Comparar si numero1 = numero2. --------------*" <<endl;
            cout << "\t" << "*----->	8. Comparar si numero1 != numero2. -------------*" <<endl;
            cout << "\t" << "*----->	9. Comparar si numero1 >= numero2. --------------*" <<endl;
            cout << "\t" << "*----->	10. Comparar si numero1 <= numero2. -------------*" <<endl;
           	cout << "\t" << "*----->	0. Salir.---------------------------------------*" <<endl;
			
			cout << BOLD ( "	*-----> Introduce la opción deseada: -------------------*") <<endl;
			cout << "\t" << "*-------------------------------------------------------*" <<endl;
			cout << "\t" << "*********************************************************" <<endl <<endl;;
			cin >> opcion;
			
			number<13,10> resultado;

			bool comparacion;
			int nuevo;
			int n;
			
			switch (opcion){
				
				case 0:
					opcion = 0;
				break;
				
				   
				case 1: 
					try{
						resultado = numero1 + numero2;
					}catch(overflow_set_exception & e){
						cout << e.what() << endl;
					}
					
		        	
		        break;
		        
		        case 2:
					try{
						resultado = numero1*numero2;
					}catch(overflow_set_exception & e){
						cout << e.what() << endl;
					}
				    
			       
		        break;
		        
		        case 3:
		        	resultado = (numero1-numero2);
		        break;
		        
		        case 4:
					try{
						resultado = (numero1/numero2);
					}catch(divide_exception & e){
						cout << e.what() << endl;
					}
		        	
			        
		        break;
		        
		        case 5:
		            comparacion = numero1 < numero2;
		            cout << endl;
				    cout << "¿Es cierto que numero1 < numero2? " << std::boolalpha << comparacion << endl;
			        cout << endl;
			        
		        break;
		        
		        case 6:
		        
		            comparacion = numero1 > numero2;
		            cout << endl;
				    cout << "¿Es cierto que numero1 > numero2? " << std::boolalpha << comparacion << endl;
			        cout << endl;
			        
		        break;
		        
		        case 7:
		            comparacion = numero1 == numero2;
		            cout << endl;
				    cout << "¿Es cierto que numero1 = numero2? " << std::boolalpha << comparacion << endl;
			        cout << endl;
			        
		        break;
		        
		        case 8:
		            comparacion = numero1 != numero2;
		            cout << endl;
				    cout << "¿Es cierto que numero1 != numero2? " << std::boolalpha << comparacion << endl;
			        cout << endl;
			        
		        break;
		        
		        case 9:
		            comparacion = numero1 >= numero2;
		            cout << endl;
				    cout << "¿Es cierto que numero1 >= numero2? " << std::boolalpha << comparacion << endl;
			        cout << endl;
			        
		        break;
		        
		        case 10:
		            comparacion = numero1 <= numero2;
		            cout << endl;
				    cout << "¿Es cierto que numero1 <= numero2? " << std::boolalpha << comparacion << endl;
			        cout << endl;
			        
		        break;
	
				default:
					cout <<endl << FRED("------> ERROR <------")<< " Opción incorrecta, saliendo del programa." << endl;
					opcion = 0;
				break;
					
			}
			cout << endl<< "El resultado es : ";
			resultado.write(cout);

		}
		return 0;

}
	   		


