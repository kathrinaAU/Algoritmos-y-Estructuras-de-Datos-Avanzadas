#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "tablahash.h"
#include "celda.h"
#include "dispersion.h"
#include "exploracion.h"
#include "dni.h"
#include "colores.hpp"

using namespace std;

void prueba_ejecucion(int fd, int fe, int tam, double carga, int nPruebas = 10)
{
     string exploracion[] = {"Lineal", "Cuadratica", "Dispersion doble", "Redispersion"};
     string dispersion[] = {"Modulo", "Pseudo Aleatoria", "Suma"};
     int celdas = tam;
     int bloques = tam;
     // 100*100-->tabla
     // 0.7*100*100*2
     vector<Dni *> dni(2 * carga * celdas * bloques);

     for (int i = 0; i < dni.size(); i++)
     {
          dni[i] = new Dni(0);
          // cout << *dni[i] << endl;
     }

     Tablahash<Dni> tabla(celdas, bloques, fd, fe);
     cout << endl
          << FCYN("*************************************************************") << endl;
     cout << endl
          << "------------------------------------------------------------------" << endl;
     //cout <<  "Tabla creada" << endl;

     // No puedo meter todo de golpe
     int aux = 0; // índice
     cout << "Tamaño del vector: " << dni.size() << endl;
     for (int i = 0; i < (dni.size() / 2); i++)
     {
          tabla.Insertar(*dni[aux]);
          aux++;
     }

     //cout << "Terminando de insertar" << endl;

     //tabla.Mostrar_Celda();

     Dni::Comparaciones.reset();

     //cout<<"Busco:";

     for (int i = 0; i < nPruebas; i++)
     {
          int aux = rand() % ((dni.size() / 2)); //Indice entre 0  y la mitad del vector
          //cout << "aux " << aux << endl;
          Dni::Comparaciones.start();
          //cout<<" ", dni[aux]->toStream(cout),cout<<" | ";
          tabla.Buscar(*dni[aux]); //dni que va a buscar en la tabla
          Dni::Comparaciones.stop();
     }

     cout << endl;
     cout << endl
          << "Celdas  Bloques  Dispersion  Exploracion   FCarga   Pruebas" << endl;
     cout << celdas << "  " << bloques << "    " << dispersion[fd] << "           " << exploracion[fe] << "       " << carga << "    " << nPruebas << endl;
     cout << endl
          << endl;
     cout << "------------------------------------------------------------------" << endl;
     cout << "             Mínimo          Máximo          Media     " << endl;
     cout << "Busquedas    ";
     cout << Dni::Comparaciones;
     cout << endl
          << endl
          << "------------------------------------------------------------------" << endl;

     Dni::Comparaciones.reset();

     for (int i = 0; i < nPruebas; i++)
     {
          int aux = ((dni.size() / 2)) + (rand() % ((dni.size() / 2)));
          //cout << "aux " << aux << endl;
          Dni::Comparaciones.start();
          tabla.Buscar(*dni[aux]);
          Dni::Comparaciones.stop();
     }

     cout << endl;
     cout << "             Mi­nimo             Maximo           Media" << endl;
     cout << "Insercion     ";
     cout << Dni::Comparaciones;
     cout << endl
          << "------------------------------------------------------------------" << endl;
     cout << endl
          << endl;
}

int main()
{
     vector<Dni> Vnombres;
     string sLetra;
     string sNombre;
     string sApellido;
     int celdas, bloques, fd, fe, nPruebas, dni, nNombre;
     int opcion_generador;
     float carga;
     string exploracion[] = {"Lineal", "Cuadratica", "Dispersion doble", "Redispersion"};
     string dispersion[] = {"Modulo", "Pseudo Aleatoria", "Suma"};

     int tamanos[] = {100, 1000, 10000};
     double f_carga[] = {0.3, 0.5, 0.7, 0.8, 0.9};
     int f_disp[] = {0, 1, 2};
     int f_exp[] = {0, 1, 2, 3};

     cout << endl;
     cout << FCYN("*************************************************************") << endl;
     cout << FCYN("*************************************************************") << endl;
     cout << FCYN("**                                                         **") << endl;
     cout << FCYN("**         Bienvenido a la práctica de Tabla Hash         **") << endl;
     cout << FCYN("**                                                         **") << endl;
     cout << FCYN("*************************************************************") << endl;
     cout << FCYN("*************************************************************") << endl;

     int opcion = -1;
     while (opcion != 0)
     {
          cout << endl
               << endl;
          cout << "Opciones: " << endl;
          cout << "0) Modo banco de pruebas." << endl;
          cout << "1) Introducir opciones." << endl;
          cout << "2) Introducir dni y otros parámetros manualmente." << endl;
          cin >> opcion;
          cout << endl;
          cout << endl;
          switch (opcion)
          {
          case 0:
          {
               for (int tam = 0; tam < 3; tam++)
               {
                    for (int ind_carga = 0; ind_carga < 5; ind_carga++)
                    {
                         for (int ind_d = 0; ind_d < 3; ind_d++)
                         {
                              for (int ind_e = 0; ind_e < 4; ind_e++)
                                   prueba_ejecucion(f_disp[ind_d],
                                                    f_exp[ind_e], tamanos[tam], f_carga[ind_carga]);
                         }
                    }
               }
               break;
          }

          case 1:
          {

               cout << "Inserte los siguientes datos, por favor:" << endl
                    << endl;

               cout << "   Inserte el numero de celdas: ";
               cin >> celdas;
               cout << endl;
               cout << "   Inserte el numero de bloques: ";
               cin >> bloques;

               cout << endl;
               cout << endl;
               cout << endl;
               cout << FCYN("*************************************************************") << endl;
               cout << "   Seleccione tipo de dispersión: " << endl;
               cout << "       0) Modulo" << endl;
               cout << "       1) Pseudo Aleatoria" << endl;
               cout << "       2) Suma" << endl;
               cout << "   Opcion: ";
               cin >> fd;
               cout << "   Ha selecionado " << dispersion[fd] << "." << endl;

               cout << endl;
               cout << FCYN("*************************************************************") << endl;
               cout << "   Seleccione tipo de exploracion: " << endl;
               cout << "       0) Lineal" << endl;
               cout << "       1) Cuadrática" << endl;
               cout << "       2) Dispersión Doble" << endl;
               cout << "       3) Redispersión" << endl;
               cout << "   Opción: ";
               cin >> fe;
               cout << "   Ha selecionado " << exploracion[fe] << "." << endl;
               cout << endl;
               cout << FCYN("*************************************************************") << endl;
               cout << endl;
               cout << "   Introduzca el factor de carga: ";
               cin >> carga;
               cout << endl;

               cout << "   Introduzca el numero de pruebas: ";
               cin >> nPruebas;
               cout << endl;

               cout << " Introduzca opción para generar DNI" << endl;
               cout << "       0) Generar DNI solo" << endl;
               cout << "       1) Generar DNI+letra" << endl;
               cout << "       2) Generar 3 primeras letras del nombre" << endl;
               cout << "   Opción: ";
               cin >> opcion_generador;

               vector<Dni *> dni(2 * carga * celdas * bloques);

               for (int i = 0; i < dni.size(); i++)
               {
                    dni[i] = new Dni(opcion_generador);
                    cout << *dni[i] << endl;
               }

               Tablahash<Dni> tabla(celdas, bloques, fd, fe);
               cout << endl
                    << FCYN("*************************************************************") << endl;
               cout << endl
                    << "------------------------------------------------------------------" << endl;
               //cout <<  "Tabla creada" << endl;

               int aux = 0;
               cout << "Tamanio del vector: " << dni.size() << endl;
               for (int i = 0; i < (dni.size() / 2); i++)
               {
                    tabla.Insertar(*dni[aux]);
                    aux++;
               }

               //cout << "Terminando de insertar" << endl;

               //tabla.Mostrar_Celda();

               Dni::Comparaciones.reset();

               //cout<<"Busco:";

               for (int i = 0; i < nPruebas; i++)
               {
                    int aux = rand() % ((dni.size() / 2)); //Indice entre 0  y la mitad del vector
                    //cout << "aux " << aux << endl;
                    Dni::Comparaciones.start();
                    //cout<<" ", dni[aux]->toStream(cout),cout<<" | ";
                    tabla.Buscar(*dni[aux]); //dni que va a buscar en la tabla
                    Dni::Comparaciones.stop();
               }

               cout << endl;
               cout << endl
                    << "Celdas  Bloques  Dispersion  Exploracion   FCarga   Pruebas" << endl;
               cout << celdas << "  " << bloques << "    " << dispersion[fd] << "           " << exploracion[fe] << "       " << carga << "    " << nPruebas << endl;
               cout << endl
                    << endl;
               cout << "------------------------------------------------------------------" << endl;
               cout << "             Mínimo          Máximo          Media     " << endl;
               cout << "Búsquedas    ";
               cout << Dni::Comparaciones;
               cout << endl
                    << endl
                    << "------------------------------------------------------------------" << endl;

               Dni::Comparaciones.reset();

               for (int i = 0; i < nPruebas; i++)
               {
                    int aux = ((dni.size() / 2)) + (rand() % ((dni.size() / 2)));
                    //cout << "aux " << aux << endl;
                    Dni::Comparaciones.start();
                    tabla.Buscar(*dni[aux]);
                    Dni::Comparaciones.stop();
               }

               cout << endl;
               cout << "             Mínimo             Máximo           Media" << endl;
               cout << "Inserción     ";
               cout << Dni::Comparaciones;
               cout << endl
                    << "------------------------------------------------------------------" << endl;
               cout << endl
                    << endl;
               break;
          }
          case 2:
          {
               cout << endl;
               cout << endl;
               cout << "Inserte los siguientes datos, por favor:" << endl
                    << endl;
               cout << "   Inserte el número de celdas: ";
               cin >> celdas;

               cout << endl;
               cout << "   Inserte el número de bloques: ";
               cin >> bloques;

               cout << "Inserte el número de nombres que desea introducir:" << endl;
               cin >> nNombre;
               for (int i = 0; i < nNombre; i++)
               {
                    cout << "Introduzca nombre, apellido y dni:" << endl;
                    cin >> sNombre;
                    cin >> sApellido;
                    cin >> dni;
                    cin >> sLetra;
                    Vnombres.push_back(Dni(dni, sLetra, sNombre, sApellido));
                    cout << endl;
               }

               cout << endl;
               cout << endl;
               cout << FCYN("*************************************************************") << endl;
               cout << "   Seleccione tipo de dispersion: " << endl;
               cout << "       0) Módulo" << endl;
               cout << "       1) Pseudo Aleatoria" << endl;
               cout << "       2) Suma" << endl;
               cout << "   Opción: ";
               cin >> fd;
               cout << "   Ha selecionado " << dispersion[fd] << "." << endl;

               cout << endl;
               cout << FCYN("*************************************************************") << endl;
               cout << "   Seleccione tipo de exploracion: " << endl;
               cout << "       0) Lineal" << endl;
               cout << "       1) Cuadrática" << endl;
               cout << "       2) Dispersión Doble" << endl;
               cout << "       3) Redispersión" << endl;
               cout << "   Opci�n: ";
               cin >> fe;
               cout << "   Ha selecionado " << exploracion[fe] << "." << endl;
               cout << endl;
               cout << FCYN("*************************************************************") << endl;
               cout << endl;

               Tablahash<Dni> tabla(celdas, bloques, fd, fe);
               cout << endl
                    << FCYN("*************************************************************") << endl;
               cout << endl
                    << "------------------------------------------------------------------" << endl;

               cout << "Introduciendo datos" << endl;
               for (auto i = 0; i < nNombre; i++)
               {
                    tabla.Insertar(Vnombres[i]);
               }

               cout << "Datos insertados" << endl;

               //tabla.Mostrar_Celda();

               for (auto i = 0; i < 1; i++)
               {
                    cout << endl
                         << "¿Qué DNI desea buscar?" << endl;
                    cout << "DNI:";
                    cin >> dni;
                    /*dame la letra:
                    cin de la letra
                    voy_a_buscar= dni+letra
                    */

                    Dni mDni = tabla.Buscar(Dni(dni));
                    cout << endl
                         << "El dni seleccionado pertenece a los siguientes datos insertados:" << mDni << endl;
               }
               break;
          }

          default:

               cout << endl
                    << FRED("------> ERROR <------") << " Opción incorrecta, saliendo del programa." << endl;
               opcion = 0;
               break;
          }
     }
}