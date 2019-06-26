#include <unistd.h>
#include <iostream>

#include "NumberBase.hpp"
#include "BinaryNumber.h"
#include "OctalNumber.h"
#include "DecimalNumber.h"
#include "HexadecimalNumber.h"
#include "Vigesimal3Number.h"
#include "Vigesimal4Number.h"

using namespace std;

int main (){
    cout << endl << "-----------------------------------------------------------------------------" << endl<< endl;
    cout << endl << "Se comprueba la excepción de base menor o igual a 1: " << endl;

    try{
        NumberBase *prueba = new number<1,1>(0);
    }catch(wrong_number_exception e){
        cout << e.what() << endl;
    }

    cout << endl << "Usando puntero NumberBase para BinaryNumber" << endl;
    try{
        NumberBase *p_b;
        BinaryNumber b(2);
        p_b = &b;

        BinaryNumber b2(3);
        NumberBase *p_b2;
        p_b2 = &b2;

        cout << "- Suma en base 2:" << endl;
        NumberBase * resultado1;
        resultado1 = *p_b + *p_b2;
        resultado1->write(cout);
    
        cout << endl << "- Resta en base 2:" << endl;
        resultado1 = *p_b - *p_b2;
        resultado1->write(cout);

    }catch(wrong_number_exception e){
        cout << e.what() << endl;
    }
   
    
    cout << endl << endl  << "Usando puntero NumberBase para base 8" << endl;

    try{
        NumberBase *p_o;
        OctalNumber o(2);
        p_o = &o;

        OctalNumber o2(2);
        NumberBase *p_o2;
        p_o2 = &o2;

        cout << "- Suma en base 8:" << endl;
        NumberBase * resultado3;
        resultado3 = *p_o + *p_o2;
        resultado3->write(cout);

        cout << endl << "- Resta en base 8:" << endl;
        resultado3 = *p_o - *p_o2;
        resultado3->write(cout);

    }catch(wrong_number_exception e){
        cout << e.what() << endl;
    }

    
    cout << endl << endl  << "Usando puntero NumberBase para base 23 y base 24" << endl;

    try{
        Vigesimal3Number v3(23);
        Vigesimal3Number v4(24);

        NumberBase *sumaV = v3 + v4;
        sumaV->write(cout);
    }catch(wrong_number_exception e){
        cout << e.what() << endl;
    }

    cout << endl << endl  << "Usando puntero NumberBase para base 10" << endl;
    try{
        NumberBase *p_d;
        DecimalNumber d(2);
        p_d = &d;

        DecimalNumber d2(2);
        NumberBase *p_d2;
        p_d2 = &d2;

        cout << "- Suma en base 10:" << endl;
        NumberBase * resultado4;
        resultado4 = *p_d + *p_d2;
        resultado4->write(cout);

        cout << endl << "- Resta en base 10:" << endl;
        resultado4 = *p_d - *p_d2;
        resultado4->write(cout);
    

    }catch(wrong_number_exception e){
        cout << e.what() << endl;
    }

    
    cout << endl << endl  << "Usando puntero NumberBase para base 16" << endl;

    try{
        NumberBase *p_h;
        HexadecimalNumber h(2);
        p_h = &h;

        HexadecimalNumber h2(2);
        NumberBase *p_h2;
        p_h2 = &h2;

        cout << "- Suma en base 16:" << endl;
        NumberBase * resultado5;
        resultado5 = *p_h + *p_h2;
        resultado5->write(cout);

        cout << endl << "- Resta en base 16:" << endl;
        resultado5 = *p_h - *p_h2;
        resultado5->write(cout);
        
    }catch(wrong_number_exception e){
        cout << e.what() << endl;
    }

   
    // cout << endl << endl  << "Usando puntero NumberBase para base 23 y base 24. USANDO CLASE" << endl;

    // try{
    //     NumberBase *p_vi;
    //     Vigesimal3Number vi(23);
    //     p_vi = &vi;

    //     Vigesimal4Number vi2(24);
    //     NumberBase *p_vi2;
    //     p_vi2 = &vi2;

    //     cout << "- Suma en base 23 y base 24:" << endl;
    //     NumberBase * resultado6;
    //     resultado6 = *p_vi + *p_vi2;
    //     resultado6->write(cout);

    //     // cout << endl << "- Resta en base 23:" << endl;
    //     // resultado6 = *p_vi - *p_vi2;
    //     // resultado6->write(cout);
        
    // }catch(wrong_number_exception e){
    //     cout << e.what() << endl;
    // }

    cout << endl << endl;

  
}