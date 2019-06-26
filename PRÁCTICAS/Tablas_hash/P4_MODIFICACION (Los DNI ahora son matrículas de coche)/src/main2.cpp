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

    vector<Dni> Vnombres;
    string sLetra;
    string sNombre;
    string sApellido;
    int celdas,bloques,fd,fe,nPruebas,dni, nNombre;
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

    cout << "Inserte el número de nombres que desea introducir:" <<endl;
    cin >> nNombre;
    for (int i=0; i < nNombre; i++){
        cout << "Introduzca nombre, apellido y dni:" <<endl;
        cin >> sNombre;
        cin >> sApellido;
        cin >> dni;
        cin >> sLetra;
        Vnombres.push_back(Dni(dni,sLetra, sNombre,sApellido));
        cout<<endl;
    }

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

    Tablahash<Dni> tabla(celdas,bloques,fd,fe);
    cout << endl <<FCYN("*************************************************************") << endl;
    cout << endl << "------------------------------------------------------------------" <<endl;

    cout << "Introduciendo nombres" << endl;
    for(auto i=0; i < nNombre; i++){
      tabla.Insertar(Vnombres[i]);
    }

    cout << "Datos insertados" << endl;

    //tabla.Mostrar_Celda();

    for(auto i=0; i < 1; i++){
      cout <<endl << "¿Qué DNI desea buscar?"<<endl;
      cout << "DNI:";
      cin >> dni;
      Dni mDni = tabla.Buscar(Dni(dni));
      cout <<endl<< "El dni seleccionado pertenece a los siguientes datos insertados:" << mDni <<endl;
    }

}

