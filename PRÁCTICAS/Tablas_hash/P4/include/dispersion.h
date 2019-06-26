#ifndef DISPERSION
#define DISPERSION

#include <stdlib.h>

using namespace std;

template<class Clave>
class Dispersion{

  /*Funci�n de dispersi�n (? fDispersion? ): este atributo de la clase implementa la funci�n de
dispersi�n que utiliza la tabla hash. Recibe como par�metro un valor ? X del tipo ? Clave y
retorna un valor en el intervalo ? [0..? nCeldas-1] que indica la posici�n de la celda dentro
de ? vCelda que deber�a contener valor ? X del tipo ? Clave? . El constructor de la tabla hash
recibe un par�metro que le indica la funci�n de dispersi�n a instanciar.*/

    public:
          virtual int operator () (Clave X)=0;
};

///////////////////////////////////////////////////////////////////////////////
template<class Clave>
class Suma: public Dispersion<Clave>{
//Coge cada uno de los digitos y los va sumando. Y hacemos el m�dulo.
  public:

    /**
    * 22334455 -> 5 y 2233445. (5)
    * 2233445 -> 5 y 223344. (10)
    * 223344 -> 4 y 22334. (14)
    * 22334 -> 4 y 2233. (18)
    * 2233 -> 3 y 223. (21)
    * 223 -> 3 y 22. (24)
    * 22 -> 2 y 2. (26)
    * 2 -> 2 y 0. (28)
    * Como clave = 0 -> Para.
    * Devuelve 28.
    */

    int operator () (Clave X){
      int suma = 0;
      int clave = int(X); //Devuelve el dni como un entero por la sobrecarga
      int aux = 0;
      while(clave > 0){
        aux = clave%10; //Devuelve �ltima cifra
        suma += aux;
        clave=clave/10; // Para pasar al siguiente
      }

      return suma;
    }


};

///////////////////////////////////////////////////////////////////////////////
template<class Clave>
class Modulo: public Dispersion<Clave>{

  /**
  * 22334455 % 100
  */ //Como aqui no sabemos el tama�o pues lo hacemos en la tabla
    public:
            int operator () (Clave X){
                return X;
            }
};

///////////////////////////////////////////////////////////////////////////////
template<class Clave>
class PseudoAleatoria: public Dispersion<Clave>{
//Primero aleatorio y luego hacemos el m�dulo
    public:
            int operator () (Clave X){
                int x = X;
                srand(x); //Para que no me salga el mismo aleatorio inicio la semilla

                return rand();
            }
};

#endif // DISPERSION

