#ifndef EXPLORACION
#define EXPLORACION

template<class Clave>
class Exploracion{

/*Función de exploración (? fExploracion? ): este atributo de la clase implementa la
estrategia de exploración que utiliza la tabla hash. Recibe como parámetros un valor ? X del
tipo ? Clave y el número del intento de exploración ? (i>0)? , que se incrementa en cada
llamada a esta función. En el i-ésimo intento de exploración la función retorna el
desplazamiento, respecto a la posición dada por la función de dispersión, de la celda
dentro de ? vCelda? que debería contener valor ? X ? del tipo ? Clave.*/
    public:
        virtual int operator () (Clave x, int intento)=0;
};

///////////////////////////////////////////////////////////////////////////////
//Lineal
template<class Clave>
class Lineal: public Exploracion<Clave>{

    /**
    *  fd me devuelve :pos = y. fe me devuelve intento = 2.
    *  nueva posición. pos = pos + 2 %nCeldas.
    */
    public:
            int operator () (Clave x, int intento){
                return intento;
            }
};

///////////////////////////////////////////////////////////////////////////////
//Cuadratica
template<class Clave>
class Cuadratica: public Exploracion<Clave>{

  /**
  *  pos = y. intento = 2.
  *  nueva posición. pos = pos + 4 (2^2) (x^2) %nCeldas.
  */
    public:
            int operator () (Clave x, int intento){
                return intento*intento;
            }
};

///////////////////////////////////////////////////////////////////////////////
//Dispersion Doble
template<class Clave>
class DispersionDoble: public Exploracion<Clave>{

  /**
  *  pos = y. intento = 2. rand() = 9.
  *  inicializar una semilla con la clave.
  *  el número aletorio que devuelve rand() lo multiplica por el intento que lleva.
  *  nueva posición. pos = pos + 18 (9*2) %nCeldas.
  */
    public:
            int operator () (Clave x, int intento){
                int k=x;
                srand(k);
                return rand()*intento;
            }

};

///////////////////////////////////////////////////////////////////////////////
//Re-dispersion
template<class Clave>
class Redispersion: public Exploracion<Clave>{

  /**
  *  pos = y. intento = 2. rand() que ha salido en el intento 2 (i llega a intento - 1) = 9.
  *  inicializar una semilla con la clave.
  *  el número aletorio que devuelve rand() lo multiplica por el intento que lleva.
  *  nueva posición. pos = pos + 9 %nCeldas.
  */
    public:
            int operator () (Clave x, int intento){
                int k=x;
                srand(k);

                for(int i=0;i<intento-1;i++){
                        rand();
                }

                int r=rand();
                return r;
            }
};

#endif // EXPLORACION

