#include <cstdlib>
#include "myvector.h"
#include "mynode.h"
#include "mylist.h"
#include "mystack.h"
#include "myroundvector.h"
#include "myqueue.h"
#include "mydoublelist.h"
#include "mydoublenode.h"
#include "mystacklist.h"
#include "myqueuelist.h"
#include <iostream>

#define N_CHARS 26

using namespace std;

int main(int argc, char *argv[])
{
    int opcion = 0;
    myVector<int> vector;
    myList<string> lista;
    myDoubleList<char> lista_doble;
    myStack<double> pila;
    myQueue<int> cola;
    myRoundVector<int> vector_circular;
    myStackList<int> pila_lista;
    myQueueList<int> cola_lista;
 
    //Comento lo de abajo que es la modificación
    // int dato_m;
    // myStack<int> dato_m2;
    
    // cout << endl << "Empezamos:::::::::::::::" <<endl;
    // myList< myStack <int> > lista_nodos;
    // myNode< myStack <int> > nodo_pila;
    // for (int i=0; i <=10; i++){
    //     cout << "Introduce un dato:" <<endl;
    //     cin >> dato_m;
    //     myNode<myStack <int> >* nodo = new myNode<myStack<int> > (dato_m);
        
    //     lista_nodos.pushFront(dato_m);
       
        
    //     for(int j=0; j <i; j++){
    //         if(i%j==0){
    //             //nodo_pila.push(j);
    //             lista_nodos.insert(j, i);
    //         }
    //     }
    // } 
    //Comento lo de arriba que es la modificación
    
    int opcion_vector=0;
    int tam_vector = 0;
    
    int dato;
    string dato_lista;
    char dato_lista_doble;
    double dato_pila;
    
    int pos_1 = 0;
    int nuevo_tam = 0;
    char dato_lista_doble_r;
    int tam_round;

    
   
    do{
        cout <<endl;
        cout << "-------------- BIENVENIDO --------------"<<endl;
        cout << "MENU:" <<endl;
        cout << "1) Vectores." <<endl;
        cout << "2) Listas simples." <<endl;
        cout << "3) Listas dobles." <<endl;
        cout << "4) Pila. " <<endl;
        cout << "5) Cola con vectores. " <<endl;
        cout << "6) Pila con listas dobles." <<endl;
        cout << "7) Cola con listas." <<endl;
        cout << "0) Salir." <<endl<<endl;
        cout << "Por favor introduzca una opcion." <<endl;
        cin >> opcion;
        cout << "------------------------------------------"<<endl;
        
        
        
        switch(opcion){
            case 1:
                
                cout << endl;
                cout << "_________ Menu del vector:_________"<<endl;
                
                do{
                    cout<<endl;
                    cout << "0) Salir del programa."<<endl;
                    cout << "1) Insertar elementos al vector."<<endl;
                    cout << "2) Extraer elementos del vector."<<endl;
                    cout << "3) Mostrar tamaÃ±o del vector."<<endl;
                    cout << "4) Mostrar contenido del vector."<<endl;
                    cout << "5) Mostrar dato de una determinada posicion."<<endl;
                    cout << "6) Redimensionar vector."<<endl;
                    cout << "7) Vector de copia." <<endl;
                    cout << "Elija la opcion que desea realizar: "<<endl;
                    cin >> opcion_vector;
                    myVector<int> vector2(vector);
                    
                    cout <<endl;
                    switch(opcion_vector){
                        case 1:
                            cout<< endl;
                            cout << "Introduzca numero de elementos del vector ";
                            int tam;
                            cin >> tam;
                            for(auto i=0; i < tam; i++){
                                cin >> dato;
                                vector.pushBack(dato);
                            }
                            cout<< endl;
                        break;
                        
                        case 2:
                            vector.popBack();
                            cout <<endl;
                        break;
                        
                        case 3:
                          
                            cout << "El tamaño del vector es: " << vector.size() <<endl;
                        break;
                        
                        case 4:
                            for(int i=0; i < vector.size(); i++)
                            cout << vector.get(i) << ' ';
                            cout << endl;
                        break;
                        
                        case 5:
                             
                            cout << "Indique la posicion a la que quiere acceder: "<<endl;
                            cin >> pos_1;
                            cout << endl << "En dicha posicion se encuentra el elemento: " << vector.get(pos_1);
                            cout <<endl;
                        break;
                        
                        case 6:
                           
                            cout << "Indique el nuevo tamaño del vector: "<<endl;
                            cin >> nuevo_tam;
                            vector.resize(nuevo_tam);
                            cout<<endl;
                            
                        break;
                        
                        case 7:
                            cout << "Vector de copia" <<endl;
                            for(int i=0; i < vector2.size(); i++)
                            cout << vector2.get(i) << ' ';
                            cout << endl;
                            cout << "Vector normal" <<endl;
                            for(int i=0; i < vector.size(); i++)
                            cout << vector.get(i) << ' ';
                            cout << endl;
                        
                        break;
                        
                        case 0:
                            cout << "Saliendo..." <<endl;
                        break;
                    }
                    
                }while(opcion_vector!=0);
                
            break;
            
            case 2:
            do{
                    cout << endl;
                    cout << "_________ Menu de la lista: _________"<<endl;
                    cout<<endl;
                    cout << "0) Salir del programa."<<endl;
                    cout << "1) Insertar elementos en la lista."<<endl;
                    cout << "2) Extraer ultimo elemento de la lista."<<endl;
                    cout << "3) Mostrar tamaÃ±o de la lista."<<endl;
                    cout << "4) Mostrar contenido de la lista."<<endl;
                    cout << "5) Mostrar dato de una determinada posicion."<<endl;
                    cout << "6) Insertar elementos en la lista dada una determinada posicion."<<endl;
                    cout << "7) Extraer elemento de la lista dada una determinada posicion."<<endl;
                    cout << "Elija la opcion que desea realizar: "<<endl;
                    cin >> opcion_vector;
                    
                    cout <<endl;
                    switch(opcion_vector){
                        case 1:
                            cout<< endl;
                            cout << "Introduzca numero de elementos de la lista: ";
                            int tam;
                            cin >> tam;
                            for(auto i=0; i < tam; i++){
                                cin >> dato_lista;
                                lista.pushFront(dato_lista);
                            }
                            cout<< endl;
                        break;
                        
                        case 2:
                            lista.popFront();
                            cout <<endl;
                        break;
                        
                        case 3:
                          
                            cout << "El tamano del vector es: " << lista.size() <<endl;
                            
                        break;
                        
                        case 4:
                            for(int i=0; i < lista.size(); i++)
                                cout << lista.get(i) << ' ';
                            cout << endl;
                        break;
                        
                        case 5:
                             
                            cout << "Indique la posicion a la que quiere acceder: "<<endl;
                            cin >> pos_1;
                            cout << endl << "En dicha posicion se encuentra el elemento: " << lista.get(pos_1);
                            cout <<endl;
                        break;
                        
                        case 6:
                            cout << "Indique la posicion del nodo en la que quiere insertar: " <<endl;
                            cin >> pos_1;
                            cout << "Valor del nodo:" <<endl;
                            cin>>dato_lista;
                            lista.insert(dato_lista, pos_1);
                            cout<<endl;
                        break;
                        
                        case 7:
                            cout << "Indique la posicion del nodo que quiere extraer: " <<endl;
                            cin >> pos_1;
                            lista.extract(pos_1);
                            cout<<endl;
                        break;
                        
                        
                        case 0:
                            cout << "Saliendo..." <<endl;
                        break;
                    }
                    
                }while(opcion_vector!=0);
                
            break;
            
            case 3:
                 do{
                    cout<<endl;
                    cout << "_________ Menu de la lista doblemente enlazada: _________"<<endl;
                    cout<<endl;
                    cout << "0) Salir del programa."<<endl;
                    cout << "1) Insertar elementos en la lista por la cola."<<endl;
                    cout << "2) Insertar elementos en la lista por la cabeza."<<endl;
                    cout << "3) Extraer elemento de la lista por la cola."<<endl;
                    cout << "4) Extraer elemento de la lista por la cabeza."<<endl;
                    cout << "5) Mostrar dato guardado en la cola."<<endl;
                    cout << "6) Mostrar dato guardado en la cabeza."<<endl;
                    cout << "7) Eliminar todos los elementos de la lista."<<endl;
                    cout << "8) Mostrar tamaÃ±o de la lista."<<endl;
                    cout << "9) Mostrar contenido de la lista."<<endl;
                    cout << "Elija la opcion que desea realizar: "<<endl;
                    cin >> opcion_vector;
                    
                    cout <<endl;
                    switch(opcion_vector){
                        case 1:
                            cout<< endl;
                            cout << "Introduzca numero de elementos de la lista: ";
                            int tam;
                            cin >> tam;
                            for(auto i=0; i < tam; i++){
                                cin >> dato_lista_doble;
                                lista_doble.insert_tail(dato_lista_doble);
                            }
                            cout<< endl;
                        break;
                        
                        case 2:
                            cout<< endl;
                            cout << "Introduzca numero de elementos de la lista: ";
                            cin >> tam;
                            for(auto i=0; i < tam; i++){
                                cin >> dato_lista_doble;
                                lista_doble.insert_head(dato_lista_doble);
                            }
                            cout<< endl;
                            
                        break;
                        
                        case 3:
                            cout << "Extrayendo elemento de la cola." <<endl;
                            lista_doble.extract_tail();
                            cout << "Nodo extraido."<<endl;
                            
                        break;
                        
                        case 4 :
                            cout << "Extrayendo elemento de la cabeza." <<endl;
                            lista_doble.extract_head();
                            cout << "Nodo extraido."<<endl;
                            
                        break;
                        
                        case 5:
                             
                            cout << "Accediendo a la posicionn de la cola. "<<endl;
                            cout << endl << "En dicha posicion se encuentra el elemento: " << lista_doble.get_tail();
                            cout <<endl;
                        break;
                        
                        case 6:
                             
                            cout << "Accediendo a la posicionn de la cabeza. "<<endl;
                            cout << endl << "En dicha posicion se encuentra el elemento: " << lista_doble.get_head();
                            cout <<endl;
                        break;
                        
                        case 7:
                            cout << "Pulse una tecla para remover." <<endl;
                            cin >> dato_lista_doble_r;
                            lista_doble.remove(dato_lista_doble_r);
                            cout << "Datos removido."<<endl;
                        break;
                        
                        case 8:
                            cout << "El tamaano de la lista es: " << lista_doble.size() <<endl;
                        
                        break;
                        
                        case 9:
                            cout << "El contenido de la lista es el siguiente:" <<endl;
                             lista_doble.write(cout);
                            cout << endl;
                        break;
                        
                        case 0:
                            cout << "Saliendo..." <<endl;
                        break;
                    }
                    
                }while(opcion_vector!=0);
                
            break;
            
            case 4: 
                cout << endl;
                cout << "_________ Menu de la pila: _________"<<endl;
                
                do{
                    cout<<endl;
                    cout << "0) Salir del programa."<<endl;
                    cout << "1) Insertar elementos en la pila."<<endl;
                    cout << "2) Extraer elementos de la pila."<<endl;
                    cout << "3) Mostrar el contenido del top."<<endl;
                    cout << "4) Comprobar si la pila esta llena."<<endl;
                    cout << "5) Comprobar si la pila esta vacia."<<endl;
                    cout << "Elija la opcion que desea realizar: "<<endl;
                    cin >> opcion_vector;
                    cout <<endl;
                    
                    switch(opcion_vector){
                        case 1:
                            cout<< endl;
                            cout << "Introduzca numero de elementos de la pila: ";
                            int tam;
                            cin >> tam;
                            for(auto i=0; i < tam; i++){
                                cin >> dato_pila;
                                pila.push(dato_pila);
                            }
                            cout<< endl;
                        break;
                        
                        case 2:
                            cout << "Extrayendo elemento de la pila."<<endl;
                            pila.pop();
                            cout << "Elemento extraido."<<endl;
                            cout <<endl;
                        break;
                        
                        case 3:
                            
                            cout << "El contenido del top de la pila es: " << pila.top()<<endl<<endl;
                        break;
                        
                        case 4:
                            cout << "Comprobando si la pila esta llena: "<<endl;
                             if (pila.isFull()){
                                cout << "La pila esta llena."<<endl;
                            }else{
                                cout << "La pila no esta llena."<<endl;
                            }
                            cout <<endl;
                        break;
                        
                        case 5:
                             
                            cout << "Comprobando si la pila esta vacÃ­a: "<<endl;
                            if (pila.isEmpty()){
                                cout << "La pila esta vacia."<<endl;
                            }else{
                                cout << "La pila no esta vacia."<<endl;
                            }
                            cout <<endl;
                        break;
                        
                        case 0:
                            cout << "Saliendo..." <<endl;
                        break;
                    }
                    
                }while(opcion_vector!=0);
                
            break;
            
            case 5:
                cout << endl;
                cout << "_________ Menu de la cola: _________"<<endl;
                
                do{
                    cout<<endl;
                    cout << "0) Salir del programa."<<endl;
                    cout << "1) Mostrando elemento del front."<<endl;
                    cout << "2) Mostrando elemento del back."<<endl;
                    cout << "3) Insertar elementos en la cola con push."<<endl;
                    cout << "4) Extraer elementos de la cola con pop."<<endl;
                    cout << "5) Mostrar el contenido de la cola."<<endl;
                    cout << "6) Mostrar el tamaÃ±o de la cola."<<endl;
                    cout << "7) Comprobar si la cola esta llena."<<endl;
                    cout << "8) Comprobar si la cola esta vacia."<<endl;
                    cout << "Elija la opcion que desea realizar: "<<endl;
                    cin >> opcion_vector;
                    cout <<endl;
                    
                    switch(opcion_vector){
                        case 1:
                            cout << endl;
                            cout << "Mostrando elemento del front de la cola: " << cola.front();
                            cout << endl;
                        break;
                        
                        case 2:
                            cout << endl;
                            cout << "Mostrando elemento del back de la cola: " << cola.back();
                            cout << endl;
                        break;
                        
                        case 3:
                            cout<< endl;
                            cout << "Introduzca numero de elementos de la cola: ";
                            int tam;
                            cin >> tam;
                            for(auto i=0; i < tam; i++){
                                cin >> dato;
                                cola.push(dato);
                            }
                        break;
                        
                        case 4:
                            cout<< endl;
                            cout << "Extrayendo elemento de la cola."<<endl;
                            cola.pop();
                            cout << "Elemento extraido."<<endl;
                            cout <<endl;
                        
                        break;
                        
                        case 5:
                            cout <<endl<<  "El contenido de la cola es el siguiente: "<<endl;
                            cola.write(cout);
                            
                        break;
                        
                        case 6:
                            cout << endl << "El tamano de la cola es: " << cola.size() << endl;
                            
                        break;
                        
                        case 7:
                            
                            cout << "Comprobando si la cola esta llena: "<<endl;
                             if (cola.full()){
                                cout << "La cola esta llena."<<endl;
                            }else{
                                cout << "La cola no esta llena."<<endl;
                            }
                            cout <<endl;
                        break;
                        
                        case 8:
                            
                            cout << "Comprobando si la cola esta vacia: "<<endl;
                             if (cola.isEmpty()){
                                cout << "La cola esta vacia."<<endl;
                            }else{
                                cout << "La cola no esta vacia."<<endl;
                            }
                            cout <<endl;
                        break;
                        
                        case 0:
                            cout << "Saliendo..." <<endl;
                        break;
                    }
                    
                }while(opcion_vector!=0);
                
            break;
                
           
            case 6:
                cout << endl;
                cout << "_________ Menu de la pila con listas: _________"<<endl;
                
                do{
                    cout<<endl;
                    cout << "0) Salir del programa."<<endl;
                    cout << "1) Insertar elementos en la pila."<<endl;
                    cout << "2) Extraer elementos de la pila."<<endl;
                    cout << "3) Mostrar el contenido del top."<<endl;
                    cout << "4) Comprobar si la pila esta vacia."<<endl;
                    cout << "Elija la opciÃ³n que desea realizar: "<<endl;
                    cin >> opcion_vector;
                    cout <<endl;
                    
                    switch(opcion_vector){
                        case 1:
                            cout<< endl;
                            cout << "Introduzca numero de elementos de la pila: ";
                            int tam;
                            cin >> tam;
                            for(auto i=0; i < tam; i++){
                                cin >> dato;
                                pila_lista.push(dato);
                            }
                            cout<< endl;
                        break;
                        
                        case 2:
                            cout << "Extrayendo elemento de la pila."<<endl;
                            pila_lista.pop();
                            cout << "Elemento extraido."<<endl;
                            cout <<endl;
                        break;
                        
                        case 3:
                            
                            cout << "El contenido del top de la pila es: " << pila_lista.top()<<endl<<endl;
                        break;
                        
                        case 4:
                             
                            cout << "Comprobando si la pila estÃ¡ vacÃ­a: "<<endl;
                            if (pila_lista.isEmpty()){
                                cout << "La pila estÃ¡ vacÃ­a."<<endl;
                            }else{
                                cout << "La pila no estÃ¡ vacÃ­a."<<endl;
                            }
                            cout <<endl;
                        break;
                        
                        case 0:
                            cout << "Saliendo..." <<endl;
                        break;
                    }
                    
                }while(opcion_vector!=0);
                
            break;
            
            case 7:
                cout << endl;
                cout << "_________ Menu de la cola: _________"<<endl;
                
                do{
                    cout<<endl;
                    cout << "0) Salir del programa."<<endl;
                    cout << "1) Mostrando elemento del front."<<endl;
                    cout << "2) Mostrando elemento del back."<<endl;
                    cout << "3) Insertar elementos en la cola con push."<<endl;
                    cout << "4) Extraer elementos de la cola con pop."<<endl;
                    cout << "5) Mostrar el contenido de la cola."<<endl;
                    cout << "6) Mostrar el tamaÃ±o de la cola."<<endl;
                    cout << "7) Comprobar si la cola estÃ¡ vacÃ­a."<<endl;
                    cout << "Elija la opciÃ³n que desea realizar: "<<endl;
                    cin >> opcion_vector;
                    cout <<endl;
                    
                    switch(opcion_vector){
                        case 1:
                            cout << endl;
                            cout << "Mostrando elemento del front de la cola: " << cola_lista.front();
                            cout << endl;
                        break;
                        
                        case 2:
                            cout << endl;
                            cout << " Mostrando elemento del back de la cola: " << cola_lista.back();
                            cout << endl;
                        break;
                        
                        case 3:
                            cout<< endl;
                            cout << "Introduzca numero de elementos de la cola: ";
                            int tam;
                            cin >> tam;
                            for(auto i=0; i < tam; i++){
                                cin >> dato;
                                cola_lista.push(dato);
                            }
                        break;
                        
                        case 4:
                            cout<< endl;
                            cout << "Extrayendo elemento de la cola."<<endl;
                            cola_lista.pop();
                            cout << "Elemento extraÃ­do."<<endl;
                            cout <<endl;
                        
                        break;
                        
                        case 5:
                            cout <<endl<<  "El contenido de la cola es el siguiente: "<<endl;
                            cola_lista.write(cout);
                            
                        break;
                        
                        case 6:
                            cout << endl << "El tamaÃ±o de la cola es: " << cola_lista.size() << endl;
                            
                        break;
                        
                        case 7:
                            
                            cout << "Comprobando si la cola estÃ¡ vacÃ­a: "<<endl;
                             if (cola_lista.isEmpty()){
                                cout << "La cola estÃ¡ vacÃ­a."<<endl;
                            }else{
                                cout << "La cola no estÃ¡ vacÃ­a."<<endl;
                            }
                            cout <<endl;
                        break;
                        
                        case 0:
                            cout << "Saliendo..." <<endl;
                        break;
                    }
                    
                }while(opcion_vector!=0);
            
            break;
            
            
            case 0:
                cout << "Saliendo..." <<endl;
                return -1;
                
            break;
        }
    }while(opcion!=7);
}



