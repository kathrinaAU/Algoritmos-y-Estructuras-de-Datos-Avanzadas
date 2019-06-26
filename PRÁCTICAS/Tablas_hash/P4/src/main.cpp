#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>

#include "tablahash.h"
#include "celda.h"
#include "dispersion.h"
#include "exploracion.h"
#include "dni.h"
#include "colores.hpp"

using namespace std;


int main(){

    int celdas,bloques,fd,fe,nPruebas;
    float carga;
    string exploracion[]={"Lineal","Cuadratica","Dispersion doble","Redispersion"};
    string dispersion[]={"Modulo", "Pseudo Aleatoria", "Suma"};

    cout << endl;
    cout<<FCYN("*************************************************************") << endl;
    cout<<FCYN("*************************************************************") << endl;
    cout<<FCYN("**                                                         **") << endl;
    cout<<FCYN("**         Bienvenido a la práctica de Tabla Hash          **") << endl;
    cout<<FCYN("**                                                         **") << endl;
    cout<<FCYN("*************************************************************") << endl;
    cout<<FCYN("*************************************************************") << endl;

    cout << endl;
    cout << endl;
    cout << "Inserte los siguientes datos, por favor:" << endl << endl;
    cout<<"   Inserte el numero de celdas: ";
    cin>>celdas;
    cout<< endl;
    cout<<"   Inserte el numero de bloques: ";
    cin>>bloques;
    cout<<endl;
    cout<< endl;
    cout<<endl;
    cout<<FCYN("*************************************************************") << endl;
    cout<<"   Seleccione tipo de dispersion: "<<endl;
    cout<<"       0) Modulo"<<endl;
    cout<<"       1) Pseudo Aleatoria"<<endl;
    cout<<"       2) Suma" <<endl;
    cout<<"   Opción: ";
    cin>>fd;
    cout<<"   Ha selecionado " << dispersion[fd] << "." << endl;

    cout<<endl;
    cout<<FCYN("*************************************************************") << endl;
    cout<<"   Seleccione tipo de exploracion: "<<endl;
    cout<<"       0) Lineal"<<endl;
    cout<<"       1) Cuadratica"<<endl;
    cout<<"       2) Dispersion Doble"<<endl;
    cout<<"       3) Redispersion"<<endl;
    cout<<"   Opción: ";
    cin>>fe;
    cout<<"   Ha selecionado " << exploracion[fe] << "." << endl;
    cout<<endl;
    cout<<FCYN("*************************************************************") << endl;
    cout<<endl;
    cout<<"   Introduzca el factor de carga: ";
    cin>>carga;
    cout<<endl;

    cout<<"   Introduzca el numero de pruebas: ";
    cin>>nPruebas;
    cout<<endl;


    vector<Dni*> dni(2*carga*celdas*bloques);

    for(int i=0;i<dni.size();i++){
            dni[i]=new Dni;
    }

    Tablahash<Dni> tabla(celdas,bloques,fd,fe);
    cout << endl <<FCYN("*************************************************************") << endl;
    cout << endl << "------------------------------------------------------------------" <<endl;
    //cout <<  "Tabla creada" << endl;


    int aux=0;
    cout << "Tamaño del vector: " << dni.size() << endl;
    for(int i=0;i<(dni.size()/2);i++){
            tabla.Insertar(*dni[aux]);
            aux++;
    }

    //cout << "Terminando de insertar" << endl;

    //tabla.Mostrar_Celda();

    Dni::Comparaciones.reset();

    //cout<<"Busco:";

    for(int i=0;i<nPruebas;i++){
        int aux=rand()%((dni.size()/2)); //Indice entre 0  y la mitad del vector
        //cout << "aux " << aux << endl;
        Dni::Comparaciones.start();
        //cout<<" ", dni[aux]->toStream(cout),cout<<" | ";
        tabla.Buscar(*dni[aux]); //dni que va a buscar en la tabla
        Dni::Comparaciones.stop();

    }

    cout << endl;
    cout << endl << "Celdas	 Bloques  Dispersion  Exploracion	FCarga	 Pruebas" << endl;
    cout << celdas << "	 " << bloques << "	  " <<  dispersion[fd] << "           " << exploracion[fe] << "    	  " << carga << "	 " << nPruebas << endl;
    cout << endl <<endl;
    cout << "------------------------------------------------------------------" <<endl;
    cout << "             Mínimo          Máximo          Media     " << endl;
    cout << "Busquedas    ";
    cout << Dni::Comparaciones;
    cout << endl <<endl << "------------------------------------------------------------------" <<endl;


    Dni::Comparaciones.reset();

    for(int i=0;i<nPruebas;i++){
            int aux=((dni.size()/2))+(rand()%((dni.size()/2)));
            //cout << "aux " << aux << endl;
            Dni::Comparaciones.start();
            tabla.Buscar(*dni[aux]);
            Dni::Comparaciones.stop();
    }

    cout << endl ;
    cout << "             Mínimo             Máximo           Media" << endl;
    cout<<"Insercion     ";
    cout<<Dni::Comparaciones;
    cout << endl << "------------------------------------------------------------------" <<endl;
    cout << endl <<endl;



}

