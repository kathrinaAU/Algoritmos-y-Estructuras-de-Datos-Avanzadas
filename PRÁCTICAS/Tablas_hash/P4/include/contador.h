#ifndef CONTADOR_H
#define CONTADOR_H

#include <iostream>

using namespace std;


/*Contador de comparaciones, que se inicializa a cero antes de cada b�squeda en la tabla hash
y se incrementa con cada ejecuci�n de una operaci�n de comparaci�n de claves.*/

class Contador {

    private:
        int Cuenta;
        int Min;
        int Max;
        int Acumulado;
        int Pruebas;

    public:
        Contador();
        void reset();
        void start();
        int stop();
        /*Al finalizar cada b�squeda en la tabla hash el valor contenido en el contador se utiliza
        para actualizar una estad�stica que registra los valores m�nimo, m�ximo y media del n�mero
        de comparaciones obtenidos.*/
        const Contador& operator++();
        friend ostream& operator<<(ostream& sout, const Contador& cont);
};


#endif // CONTADOR_H

