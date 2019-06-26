#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>

#include "colores.hpp"
#include "dni.h"
#include "contador.h"

#include "sorter.h"
#include "bubblesort.h"
#include "heapsort.h"
#include "shakesort.h"
#include "seleccion.h"
#include "insercion.h"
#include "shellsort.h"
#include "radixsort.h"
#include "mergesort.h"
#include "quicksort.h"

using namespace std;

int main()
{

    cout << endl;
    cout << FYEL("************************************************************************") << endl;
    cout << FYEL("************************************************************************") << endl;
    cout << FYEL("**                                                                    **") << endl;
    cout << FYEL("**                            ORDENACION                              **") << endl;
    cout << FYEL("**                                                                    **") << endl;
    cout << FYEL("************************************************************************") << endl;
    cout << FYEL("************************************************************************") << endl;

    cout << endl;
    cout << endl;

    int npruebas = 0;
    int tam = 0;
    float alpha;
    // Ordenacion<Dni, Dni::lessDniNumAndLetra> ord_dni;
    // Ordenacion<int, less_equal<int>> ord_entero;
    vector<Dni> v_dni;
    vector<Dni> v_copia_dni;

    int tamanos[] = {100, 1000, 10000};
    int tam_pruebas[] = {10, 100, 200};
    double v_alpha[] = {0.3, 0.5, 0.7};

    Sorter<Dni, Dni::lessDniNumAndLetra> *ordenador;
    int opcion = -1;
    while (opcion != 0)
    {
        cout << endl
             << endl;
        cout << "Opciones: " << endl;
        cout << "0) Modo estadístico (banco de pruebas)." << endl;
        cout << "1) Modo demostración." << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 0:
        {
            cout << endl;
            cout << FCYN("*******************************************************************") << endl;
            cout << FCYN("MODO ESTADISTICO") << endl
                 << endl;

            for (int tam = 0; tam < 1; tam++)
            {
                cout << FYEL("************************************************************************") << endl;
                cout << endl
                     << "\t\t\t\t"
                     << FGRN("Minimo")
                     << "       "
                     << FGRN("  Maximo")
                     << "       "
                     << FGRN("    Media") << endl;
                cout << endl

                     << FCYN("TAMAÑO: ") << tamanos[tam] << endl;
                v_dni.clear();
                v_dni.resize(tamanos[tam]);
                ordenador = new Insercion<Dni, Dni::lessDniNumAndLetra>;
                for (int ind_pruebas = 0; ind_pruebas < 3; ind_pruebas++)
                {
                    cout << FRED("    PRUEBAS: ") << tam_pruebas[ind_pruebas] << endl;
                    Dni::Comparaciones.reset();
                    Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.reset();
                    for (auto j = 0; j < tam_pruebas[ind_pruebas]; j++)
                    {
                        for (auto i = 0; i < tamanos[tam]; i++)
                        {
                            v_dni[i] = *new Dni;
                        }

                        v_copia_dni = v_dni;
                        Dni::Comparaciones.start();
                        Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.start();
                        ordenador->sort(v_copia_dni, tamanos[tam], 0, 0, 0, 0, false);
                        Dni::Comparaciones.stop();
                        Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.stop();
                    }
                    cout << "Intercambios Inserción: " << Sorter<Dni,Dni::lessDniNumAndLetra>::Intercambio << endl;
                    cout << "       - Insercion " << Dni::Comparaciones << endl;
                }

                for (int ind_pruebas = 0; ind_pruebas < 3; ind_pruebas++)
                {
                    cout << FRED("    PRUEBAS: ")  << tam_pruebas[ind_pruebas] << endl;
                    Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.reset();
                    Dni::Comparaciones.reset();
                    for (auto j = 0; j < tam_pruebas[ind_pruebas]; j++)
                    {
                        for (auto i = 0; i < tamanos[tam]; i++)
                        {
                            v_dni[i] = *new Dni;
                        }
                        v_copia_dni = v_dni;
                        Dni::Comparaciones.start();
                        Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.start();
                        ordenador = new Seleccion<Dni, Dni::lessDniNumAndLetra>;
                        ordenador->sort(v_copia_dni, tamanos[tam], 0, 0, 0, false);
                        Dni::Comparaciones.stop();
                        Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.stop();
                    }
                    cout << "Intercambios Seleccion: " << Sorter<Dni,Dni::lessDniNumAndLetra>::Intercambio << endl;
                    cout << "       - Seleccion " << Dni::Comparaciones << endl;
                }

                for (int ind_pruebas = 0; ind_pruebas < 3; ind_pruebas++)
                {
                    cout << FRED("    PRUEBAS: ") << tam_pruebas[ind_pruebas] << endl;
                    Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.reset();
                    Dni::Comparaciones.reset();
                    for (auto j = 0; j < tam_pruebas[ind_pruebas]; j++)
                    {
                        for (auto i = 0; i < tamanos[tam]; i++)
                        {
                            v_dni[i] = *new Dni;
                        }
                        v_copia_dni = v_dni;
                        Dni::Comparaciones.start();
                        Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.start();
                        ordenador = new Shakesort<Dni, Dni::lessDniNumAndLetra>;
                        ordenador->sort(v_copia_dni, tamanos[tam], 0, 0, 0, 0, false);
                        Dni::Comparaciones.stop();
                        Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.stop();
                    }
                    cout << "Intercambios Shakesort: " << Sorter<Dni,Dni::lessDniNumAndLetra>::Intercambio << endl;
                    cout << "       - Shakesort " << Dni::Comparaciones << endl;
                }
                for (int ind_pruebas = 0; ind_pruebas < 3; ind_pruebas++)
                {
                    Dni::Comparaciones.reset();
                    cout << FRED("    PRUEBAS: ")  << tam_pruebas[ind_pruebas] << endl;
                    Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.reset();
                    for (auto j = 0; j < tam_pruebas[ind_pruebas]; j++)
                    {
                        for (auto i = 0; i < tamanos[tam]; i++)
                        {
                            v_dni[i] = *new Dni;
                        }
                        v_copia_dni = v_dni;
                        Dni::Comparaciones.start();
                        Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.start();
                        ordenador = new Bubblesort<Dni, Dni::lessDniNumAndLetra>;
                        ordenador->sort(v_copia_dni, tamanos[tam], 0, 0, 0, 0, false);
                        Dni::Comparaciones.stop();
                        Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.stop();
                    }
                    cout << "Intercambios Bubblesort: " << Sorter<Dni,Dni::lessDniNumAndLetra>::Intercambio << endl;
                    cout << "       - Bubblesort " << Dni::Comparaciones << endl;
                }

                for (int ind_pruebas = 0; ind_pruebas < 3; ind_pruebas++)
                {
                    Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.reset();
                    Dni::Comparaciones.reset();
                    cout << FRED("    PRUEBAS: ")  << tam_pruebas[ind_pruebas] << endl;
                    for (auto j = 0; j < tam_pruebas[ind_pruebas]; j++)
                    {

                        for (auto i = 0; i < tamanos[tam]; i++)
                        {
                            v_dni[i] = *new Dni;
                        }
                        v_copia_dni = v_dni;
                        Dni::Comparaciones.start();
                        Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.start();
                        ordenador = new Heapsort<Dni, Dni::lessDniNumAndLetra>;
                        ordenador->sort(v_copia_dni, tamanos[tam], 0, 0, 0, 0, false);
                        Dni::Comparaciones.stop();
                        Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.stop();
                    }
                    cout << "Intercambios Heapsort: " << Sorter<Dni,Dni::lessDniNumAndLetra>::Intercambio << endl;
                    cout << "       - Heapsort " << Dni::Comparaciones << endl;
                }

                for (int ind_pruebas = 0; ind_pruebas < 3; ind_pruebas++)
                {
                    Dni::Comparaciones.reset();
                    Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.reset();
                    cout << FRED("    PRUEBAS: ")  << tam_pruebas[ind_pruebas] << endl;
                    for (auto j = 0; j < tam_pruebas[ind_pruebas]; j++)
                    {

                        for (auto i = 0; i < tamanos[tam]; i++)
                        {
                            v_dni[i] = *new Dni;
                        }
                        v_copia_dni = v_dni;
                        Dni::Comparaciones.start();
                        Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.start();
                        ordenador = new Quicksort<Dni, Dni::lessDniNumAndLetra>;
                        ordenador->sort(v_copia_dni, tamanos[tam], 0, 0, tamanos[tam] - 1, 0, false);
                        Dni::Comparaciones.stop();
                        Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.stop();
                    }
                    cout << "Intercambios Quicksort: " << Sorter<Dni,Dni::lessDniNumAndLetra>::Intercambio << endl;
                    cout << "       - Quicksort " << Dni::Comparaciones << endl;
                }

                for (int ind_pruebas = 0; ind_pruebas < 3; ind_pruebas++)
                {
                    Dni::Comparaciones.reset();
                    Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.reset();
                    cout << FRED("    PRUEBAS: ")  << tam_pruebas[ind_pruebas] << endl;
                    for (auto j = 0; j < tam_pruebas[ind_pruebas]; j++)
                    {

                        for (auto i = 0; i < tamanos[tam]; i++)
                        {
                            v_dni[i] = *new Dni;
                        }
                        v_copia_dni = v_dni;
                        Dni::Comparaciones.start();
                        Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.start();
                        ordenador = new Mergesort<Dni, Dni::lessDniNumAndLetra>;
                        ordenador->sort(v_copia_dni, tamanos[tam], 0, 0, tamanos[tam] - 1, alpha, false);
                        Dni::Comparaciones.stop();
                        Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.stop();
                    }
                    cout << "Intercambios Mergesort: " << Sorter<Dni,Dni::lessDniNumAndLetra>::Intercambio << endl;
                    cout << "       - Mergesort " << Dni::Comparaciones << endl;
                }

                for (int ind_pruebas = 0; ind_pruebas < 3; ind_pruebas++)
                {
                    
                    cout << FRED("    PRUEBAS: ")  << tam_pruebas[ind_pruebas] << endl;
                    for (int a = 0; a < 3; a++)
                    {
                        Dni::Comparaciones.reset();
                        Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.reset();
                        for (auto j = 0; j < tam_pruebas[ind_pruebas]; j++)
                        {

                            for (auto i = 0; i < tamanos[tam]; i++)
                            {
                                v_dni[i] = *new Dni;
                            }
                            v_copia_dni = v_dni;
                            Dni::Comparaciones.start();
                            Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.start();
                            ordenador = new Radixsort<Dni, Dni::lessDniNumAndLetra>;
                            ordenador->sort(v_copia_dni, tamanos[tam], 0, 0, 0, 0, false);
                            Dni::Comparaciones.stop();
                            Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.stop();
                        }
                        cout << "       - Radixsort " << Dni::Comparaciones << endl;
                    }
                }
                for (int ind_pruebas = 0; ind_pruebas < 3; ind_pruebas++)
                {
                    cout << FRED("    PRUEBAS: ")  << tam_pruebas[ind_pruebas] << endl;
                    for (int a = 0; a < 3; a++)
                    {
                        Dni::Comparaciones.reset();
                        Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.reset();
                        for (auto j = 0; j < tam_pruebas[ind_pruebas]; j++)
                        {

                            for (auto i = 0; i < tamanos[tam]; i++)
                            {
                                v_dni[i] = *new Dni;
                            }
                            v_copia_dni = v_dni;
                            Dni::Comparaciones.start();
                            Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.start();
                            ordenador = new Shellsort<Dni, Dni::lessDniNumAndLetra>;
                            ordenador->sort(v_copia_dni, tamanos[tam], 0, 0, 0, v_alpha[a], false);
                            Dni::Comparaciones.stop();
                            Sorter<Dni, Dni::lessDniNumAndLetra>::Intercambio.stop();
                        }
                        cout << "Intercambios Shellsort: " << Sorter<Dni,Dni::lessDniNumAndLetra>::Intercambio << endl;
                        cout << "       - Shellsort " << Dni::Comparaciones << endl;
                    }
                }
            }
        }
        break;

        case 1:
        {

            cout << endl;
            cout << FCYN("*******************************************************************") << endl;
            cout << FCYN("MODO DEMOSTRACION") << endl
                 << endl;

            cout << endl;
            cout << endl;

            cout << "Ingrese el tamaño del vector de prueba:" << endl;
            cin >> tam;
            v_dni.clear();
            v_dni.resize(tam);

            for (auto i = 0; i < tam; i++)
            {
                v_dni[i] = *new Dni;
            }

            cout << endl
                 << "Ingrese el numero de pruebas a realizar:" << endl;
            cin >> npruebas;

            cout << endl
                 << "Ingrese la constante alpha para el algoritmo shellsort:" << endl;
            cin >> alpha;

            int dni;
            string l;
            string n;
            string a;

            // cout << "Ingrese DNI, letra, nombre y apellidos:" << endl;
            // for (auto i = 0; i < tam; i++)
            // {
            //   cin >> dni;
            //   cin >> l;
            //   cin >> n;
            //   cin >> a;

            //   v_dni[i] = *new Dni(dni, l, n, a);
            // }

            for (auto i = 0; i < tam; i++)
            {
                v_dni[i] = *new Dni;
            }

            v_copia_dni = v_dni;

            cout << "\x1b[94m";
            cout << endl
                 << endl
                 << endl;
            cout << " --- Ordenacion por insercion --- " << endl;
            cout << "\x1b[0m";
            // ordenador = new Seleccion<Dni, Dni::lessDniNumAndLetra>;
            ordenador = new Insercion<Dni, Dni::lessDniNumAndLetra>;
            ordenador->sort(v_copia_dni, tam, 0, 0, 0, 0, true);
            // ord_dni.insercion(v_copia_dni, tam, true);
            cout << "\x1b[95m";
            cout << endl
                 << "SOLUCION: ";
            for (auto i = 0; i < v_copia_dni.size(); i++)
            {
                cout << v_copia_dni[i] << ' ';
            }
            cout << "\x1b[0m";
            v_copia_dni = v_dni;
            cout << "\x1b[94m";
            cout << endl
                 << endl
                 << endl;
            cout << " --- Ordenacion por seleccion --- " << endl;
            cout << "\x1b[0m";
            ordenador = new Seleccion<Dni, Dni::lessDniNumAndLetra>;
            ordenador->sort(v_copia_dni, tam, 0, 0, 0, 0, true);
            // ord_dni.seleccion(v_copia_dni, tam, true);
            cout << "\x1b[95m";
            cout << endl
                 << "SOLUCION: ";
            for (auto i = 0; i < v_copia_dni.size(); i++)
            {
                cout << v_copia_dni[i] << ' ';
            }
            cout << "\x1b[0m";
            v_copia_dni = v_dni;

            cout << "\x1b[94m";
            cout << endl
                 << endl
                 << endl;
            cout << " --- Ordenacion por shakesort --- " << endl;
            cout << "\x1b[0m";
            ordenador = new Shakesort<Dni, Dni::lessDniNumAndLetra>;
            ordenador->sort(v_copia_dni, tam, 0, 0, 0, 0, true);
            // ord_dni.shakesort(v_copia_dni, tam, true);
            cout << "\x1b[95m";
            cout << endl
                 << "SOLUCION: ";
            for (auto i = 0; i < v_copia_dni.size(); i++)
            {
                cout << v_copia_dni[i] << ' ';
            }
            cout << "\x1b[0m";
            v_copia_dni = v_dni;

            cout << "\x1b[94m";
            cout << endl
                 << endl
                 << endl;
            cout << " --- Ordenacion por burbuja --- " << endl;
            cout << "\x1b[0m";
            ordenador = new Bubblesort<Dni, Dni::lessDniNumAndLetra>;
            ordenador->sort(v_copia_dni, tam, 0, 0, 0, 0, true);
            // ord_dni.burbuja(v_copia_dni, tam, true);
            cout << "\x1b[95m";
            cout << endl
                 << "SOLUCION: ";
            for (auto i = 0; i < v_copia_dni.size(); i++)
            {
                cout << v_copia_dni[i] << ' ';
            }
            cout << "\x1b[0m";
            v_copia_dni = v_dni;

            cout << "\x1b[94m";
            cout << endl
                 << endl
                 << endl;

            cout << " --- Ordenacion por heapsort --- " << endl;
            cout << "\x1b[0m";
            ordenador = new Heapsort<Dni, Dni::lessDniNumAndLetra>;
            ordenador->sort(v_copia_dni, tam, 0, 0, 0, 0, true);
            // ord_dni.heapsort(v_copia_dni, tam, true);
            cout << "\x1b[95m";
            cout << endl
                 << "SOLUCION: ";
            for (auto i = 0; i < v_copia_dni.size(); i++)
            {
                cout << v_copia_dni[i] << ' ';
            }
            cout << "\x1b[0m";
            v_copia_dni = v_dni;

            cout << "\x1b[94m";
            cout << endl
                 << endl
                 << endl;

            cout << " --- Ordenacion por quicksort --- " << endl;
            cout << "\x1b[0m";
            ordenador = new Quicksort<Dni, Dni::lessDniNumAndLetra>;
            ordenador->sort(v_copia_dni, tam, 0, 0, tam - 1, 0, true);
            // ord_dni.quicksort(v_copia_dni, tam, 0, tam - 1, true);
            cout << "\x1b[95m";
            cout << endl
                 << "SOLUCION: ";
            for (auto i = 0; i < v_copia_dni.size(); i++)
            {
                cout << v_copia_dni[i] << ' ';
            }
            cout << "\x1b[0m";

            v_copia_dni = v_dni;
            cout << "\x1b[94m";
            cout << endl
                 << endl
                 << endl;

            cout << " --- Ordenacion por shellsort --- " << endl;
            cout << "\x1b[0m";
            ordenador = new Shellsort<Dni, Dni::lessDniNumAndLetra>;
            ordenador->sort(v_copia_dni, tam, 0, 0, 0, alpha, true);
            // ord_dni.shellsort(v_copia_dni, tam, alpha, true);
            cout << "\x1b[95m";
            cout << endl
                 << "SOLUCION: ";
            for (auto i = 0; i < v_copia_dni.size(); i++)
            {
                cout << v_copia_dni[i] << ' ';
            }

            cout << "\x1b[0m";

            v_copia_dni = v_dni;

            cout << "\x1b[94m";
            cout << endl
                 << endl
                 << endl;

            cout << " --- Ordenacion por MergeSort --- " << endl;
            cout << "\x1b[0m";
            ordenador = new Mergesort<Dni, Dni::lessDniNumAndLetra>;
            ordenador->sort(v_copia_dni, tam, 0, 0, tam - 1, alpha, true);
            // ord_dni.msort(v_copia_dni, tam, 0, tam - 1, true);
            cout << "\x1b[95m";
            cout << endl
                 << "SOLUCION: ";
            for (auto i = 0; i < v_copia_dni.size(); i++)
            {
                cout << v_copia_dni[i] << ' ';
            }
            cout << "\x1b[0m";

            v_copia_dni = v_dni;

            cout << "\x1b[94m";
            cout << endl
                 << endl
                 << endl;

            cout << " --- Ordenacion por Radixsort --- " << endl;
            cout << "\x1b[0m";
            ordenador = new Radixsort<Dni, Dni::lessDniNumAndLetra>;
            ordenador->sort(v_copia_dni, tam, 0, 0, 0, alpha, true);
            cout << "\x1b[95m";
            cout << endl
                 << "SOLUCION: ";
            for (auto i = 0; i < v_copia_dni.size(); i++)
            {
                cout << v_copia_dni[i] << ' ';
            }
            cout << "\x1b[0m";

            cout << endl
                 << endl;
            cout << FCYN("*******************************************************************") << endl;
            cout << endl;
        }
        break;

        default:
        {
            cout << endl
                 << FRED("------> ERROR <------") << " Opción incorrecta, saliendo del programa." << endl;
            opcion = 0;
        }

        break;
        }
    }
}
