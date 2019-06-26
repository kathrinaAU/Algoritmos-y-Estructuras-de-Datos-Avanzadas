#include "generador.h"
#include <iostream>
using namespace std;

Generador::Generador(){
    srand(0);
}

int Generador::generate(int ini, int fin){
    int otro = rand()%(fin-ini);
    int resultado = otro + ini;
    return resultado;
}