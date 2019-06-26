#ifndef  __BIN_NUMBER_H
#define __BIN_NUMBER_H
#include <iostream>
#include <vector>
#include <cmath>
#include "number.h"

using namespace std;


template<size_t N, class T>
class number<N,2,T>{
private:
    T* v;
    int ocupado = 0;
    size_t B=2;
    size_t max = N;
    int signo = 0;
    void to_base(int n);
    int nd; //number of digits
    void build();
    void destroy();

public:
    number(int n=0);
    number(const number<N,2,T> &other);
    ~number();


    void complemento_1() const;
    number<N,2,T> complemento_2 (int n) const;
    

    int to_decimal() const;
    int getOcupados() const;
    T* getVector() const;
    int ndigit(int number, int base) const;
    int getSigno() const;
    void setSigno(int sig);

    number<N,2,T> operator + (const number<N,2,T> & other) const;
    number<N,2,T> operator - (const number<N,2,T> & other) const;
    number<N,2,T> operator / (const number<N,2,T> & other) const;
    number<N,2,T> operator * (const number<N,2,T> & other) const;
 
    number<N,2,T> & operator = (const number<N,2,T> & other);
    bool operator == (const number<N,2,T> & other) const;
    bool operator != (const number<N,2,T> & other) const;
    bool operator < (const number<N,2,T> & other) const;
    bool operator > (const number<N,2,T> & other) const;
    bool operator >= (const number<N,2,T> & other) const;
    bool operator <= (const number<N,2,T> & other) const;

    ostream& write(ostream& os) const ;
};


// Construye el nuevo vector en base a N
template<size_t N, class T>
void number<N,2,T>::build(){
    v = new T[N];
}

//Destruye el vector
template<size_t N, class T>
void number<N,2,T>::destroy(){
    if(v){
        delete[] v;
    }  
}

// Método que calcula el número de bits necesario para representar un número según una base.
template<size_t N, class T>
int number<N,2,T>::ndigit(int number, int base) const{
	return floor(log10(number)/log10(base))+1;
}


// Método que ayuda a crear un número en función de la base
template <size_t N, class T>
void number<N,2,T>::to_base(int n){
    int remainder, value;
    remainder = n;
    int pos = N-1;

    int numberofdigits ;
        
    if(n >= 0){ // Para números positivos
        numberofdigits = ndigit(n,2);

        while(remainder >= B and pos > 0){
            value = remainder % B;
            remainder /= B;
            v[pos] = value + '0';
            pos--;
            ocupado ++;
        }
        
        v[pos] = remainder+'0';
        ocupado++;

        if(remainder >= B)
            throw overflow_set_exception();
            
    }else{ // Para números negativos
        numberofdigits = ndigit(-n,2);
        nd = numberofdigits;
        // Como el número es negativo pues le hago complemento a 2 y ahora su signo es 1 que indica negativo.
        *this = complemento_2(-n); 
        signo = 1;
        // cout << signo << endl;
    }
    
}

// Constructor
template <size_t N, class T>
number<N,2,T>::number(int n){
    v = new T[N];
    for(int i=0; i < N; i++){
        v[i] = '0';
    }
    to_base(n);
}

// Constructor de copia
template<size_t N, class T>
number<N,2,T>::number(const number<N,2,T> & other)
    :v(NULL){

    build(); // Creo vector
    max = N;
    signo = other.signo; 
    int n = other.to_decimal();

    for(int i=0; i < N; i++){
        v[i] = '0'; 
    }
    to_base(n);
  
}

// Destructor
template<size_t N, class T>
number<N,2,T>::~number(){

}

// Método que realiza el complemento a 1
template <size_t N, class T>
void number<N,2,T>::complemento_1() const{
    int c = 0; 
    for(int i=0; i < N; i++){
        c = v[i]-'0'; // Quito los char al vector
        c = (c+1) % 2; // Cambio los 0 por 1 y los 1 por 0. 
                        // Si era 0%2=0 ahora es 1%2=1
        v[i] = c + '0';
        
    }
}


// Método que devuelve el number con el complemento a 2 hecho
template <size_t N, class T>
number<N,2,T> number<N,2,T>::complemento_2 (int n) const{
    number<N,2,T> aux(n);
    aux.complemento_1();
    // Como ya está convertido a complemento a 1 pues solo me falta sumarle 1
    number<N,2,T> uno(1);

    return aux+uno;
}

// Método que convierte un number a decimal
template<size_t N, class T>
int number<N,2,T>::to_decimal() const{
    int aux = 0;
    int n = 0;
    int expo = 0;
    T* aux_v = getVector();
    int fin = 0;
    // if(signo == 1){
    //     fin = N-nd-1;
    // }
    for(int i = N-1 ; i >= fin ; i--){
        aux = aux_v[i] - '0';
        n += (pow(B,(expo)))*aux;
        expo++;
    }
    
    return n;
}

// Método que devuelve el número de bits ocupados del total
template <size_t N, class T>
int number<N,2,T>::getOcupados() const{
    return ocupado;
}

// Método que devuelve al vector
template <size_t N, class T>
T* number<N,2,T>::getVector() const{
    return v;
}

// Método que devuelve el signo del número
template<size_t N, class T>
int number<N,2,T>::getSigno() const{
    return signo;
}

// Método que cambia el signo
template<size_t N, class T>
void number<N,2,T>::setSigno(int sig){
    signo = sig;
}


template<size_t N, class T>
number<N,2,T> number<N,2,T>::operator + (const number<N,2,T> & other) const{
    
    int aux = 0;
    vector<int> vector_aux; // Vector donde meto el resultado
    
    T *aux_v = other.getVector(); //Nuevo vector que almacena el número en su nueva base
    
    int suma = 0;
    int acarreo = 0;
    int c1,c2;
    
    for(int i=N-1; i >=0 ; i--){
        c1 = v[i] - '0'; // elemento del primer vector
        c2 = aux_v[i] - '0'; // elemento del segundo vector
        suma = (c1+c2+acarreo);

        if( suma >= B ){ // Si se pasa y no puede representarse con un solo caracter pues me llevo una
            suma = suma % B;
            acarreo = 1;
        }else{
            acarreo = 0;
        }
        vector_aux.push_back(suma); // Vector resultante de la suma
        
    }

    // Situación normal
    if (acarreo > 0 and signo == 0 and other.signo == 0){
        //cout << "Aquí entro " << signo << endl;
        vector_aux.push_back(acarreo);
    }
    if (vector_aux.size() > N ){
        throw overflow_set_exception();
    }
    
    aux = 0;
    for (int i=0; i < vector_aux.size(); i++){
        aux += pow(B,(i)) * vector_aux[i];
    }
    
    //Resultado a decimal para crear el number
    return number<N,2>(aux);
}



// RESTA: 32-17. 2,7--> 12-7 --> acc= 1.
// Método que realiza la resta entre dos números.
template<size_t N, class T>
number<N,2,T> number<N,2,T>::operator - (const number<N,2,T> &other) const {
    
    number<N,2,T> resta(*this);
    
    if (other == 0){
        return *this;
    }

    number<N,2,T> comp2 = other.complemento_2(other.to_decimal());


    if(other.getSigno() == 0 ){
        comp2.setSigno(1);
    }else{
        comp2.setSigno(0);
    }
    
    return resta+comp2;
}



template<size_t N, class T>
number<N,2,T> number<N,2,T>::operator * (const number<N,2,T> & other) const{
    
    int n = 0;
  
    vector<int> vector_aux;
    number<N,2,T> aux_n = other;
    
    n = aux_n.to_decimal();
    
    number<N,2> aux_number(n);
    T *aux_v = aux_number.getVector();
    number<N,2> salida(0);
    
    for(int i = 0; i < n ; i++){
        salida = salida + *this; //OJO OJO OJO OJO
        // *****0
        if(salida.getVector()[N-1] == '0' and salida.getOcupados() == 1){
            throw overflow_set_exception();
        }
    }
    
    return salida;
}


// Método que devuelve el resultado de dividir dos number
template<size_t N, class T>
number<N,2,T> number<N,2,T>::operator / (const number<N,2,T> & other) const{
    
    number<N,2,T> exit(0);
    int n = 0;
    //vector<int> vector_aux;

    number<N,2,T> aux_n = other;
    number<N,2,T> pri_n = *this;
    n = aux_n.to_decimal();
    number<N,2> aux_number(n); // Debería ya estar en binario desde el principio

    //T *aux_v = aux_number.getVector();
    
    number<N,2> salida(0);


    if(other == salida){
        throw divide_exception();
    }
    
    bool stop = true;
    int count = 0;

    salida = *this;

// Casos drásticos
    if ((salida.getSigno() == 0 ) and (aux_n.getSigno() == 0) and (salida < aux_n)){
        cout << "Resultado decimal: Caso no contemplado" <<endl;
        return exit;
    }
    if ((salida.getSigno() == 1 ) and (aux_n.getSigno() == 1) and (salida > aux_n)){
        cout << "Resultado decimal: Caso no contemplado 2" <<endl;
        return exit;
    }
    if ((salida.getSigno() == 1 ) and (aux_n.getSigno() == 0) and (salida < aux_n)){
        cout << "Resultado decimal: Caso no contemplado 2" <<endl;
        return exit;
    }

    if ((salida.getSigno() == 0 ) and (aux_n.getSigno() == 1) and (salida > aux_n)){
        cout << "Resultado decimal: Caso no contemplado 2" <<endl;
        return exit;
    }

 

    while(stop==true){
        salida = salida - aux_number;
        if (salida < aux_number){
            stop = false;
        }
        count++;
    }

    number<N,2,T> resta(count);
    return resta;
}


// Método para asignar/igualar un number de misma base a otro de misma base
template <size_t N, class T>
number<N,2,T> & number<N,2,T>::operator = (const number<N,2,T> & other){
    destroy();
    build();

    number<N,2,T> a = other;
    signo = other.signo;
    max = N;

    int n = a.to_decimal();

    for(int i=0; i < N; i++){
        this->v[i] = '0';
    }

    to_base(n);
   
    return *this;
}


// Método que compara numbers con ==
template<size_t N, class T>
bool number<N,2,T>::operator == (const number<N,2,T> & other) const{
    bool iguales = true;
    
    int n = 0;

    vector<int> vector_aux;
    number<N,2,T> aux_n = other;
    
    // Pasamos a decimal
    n = aux_n.to_decimal();
   
    number<N,2> aux_number(n);
    T *aux_v = aux_number.getVector();
    
  
    for(int i=N-1; i >= 0 and iguales; i--){
        if(v[i] != aux_v[i])
            iguales = false;
    }


    return iguales;
}


// Método que compara numbers con !=
template<size_t N, class T>
bool number<N,2,T>::operator != (const number<N,2,T> & other) const{
    return ! (*this == other);
}



// Método que compara numbers con <
template<size_t N, class T>
bool number<N,2,T>::operator < (const number<N,2,T> & other) const{

    bool iguales = true;
    int n = 0;
    vector<int> vector_aux; // Vector resultante

    number<N,2,T> aux_n = other; // aux_n es una copia de other number
    n = aux_n.to_decimal();   // n es el decimal del segundo number

    number<N,2,T> copy(*this); // copy es una copia de this number
    int n2 = this->to_decimal(); // n2 es el decimal del primer number
    
    
    
    // Es para hacer limpieza porque to_decimal me pasa el 11110011 a decimal y no el 011 
    if(copy.signo == 1){
        copy.complemento_1();
        copy = copy + number<N,2,T>(1);
        copy.setSigno(0);
        n2 = copy.to_decimal(); // Obtengo el verdadero número 
        n2 = -n2; // Lo paso a negativo
        
    }
    
    if(aux_n.signo == 1){
        aux_n.complemento_1();
        aux_n = aux_n + number<N,2,T>(1);
        aux_n.setSigno(0);
        n = aux_n.to_decimal();
        n = -n;
    }
    
    return n2 < n;
}


// Método que compara numbers con >
template<size_t N, class T>
bool number<N,2,T>::operator > (const number<N,2,T> & other) const{
    return  !(*this == other) and !(*this < other);
}


// Método que compara numbers con >=
template<size_t N, class T>
bool number<N,2,T>::operator >= (const number<N,2,T> & other) const{
    return  (*this == other) or (*this > other);
}

// Método que compara numbers con <=
template<size_t N, class T>
bool number<N,2,T>::operator <= (const number<N,2,T> & other) const{
    return  (*this == other) or (*this < other);
}

// Método que escribe la representación de un number según su base.
template <size_t N, class T>
ostream& number<N,2,T>::write(ostream& os) const{
    int aux;
    
    if( B > 9 ){
        for (int i = 0; i < N; i++){
            aux = v[i]-'0';
            if(aux > 9){
                char aux_c = (aux-10)+'A';
                os << aux_c;
            }
            else
                os << v[i];
        }
    }else{
        for(int i = 0; i < N ; i ++)
            os << v[i];
    }
    
    os << ")"<< B;
    return os;
}

#endif