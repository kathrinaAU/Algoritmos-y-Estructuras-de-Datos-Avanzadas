# include "generador.h"

Generador::Generador(){
    srand(0);
}

int Generador::generate(){
    return 00000000 + rand() %99999999;
}