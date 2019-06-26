#ifndef NUMBER_H
#define NUMBER_H

#include<iostream>
#include <vector>
#include <cmath>

using namespace std;

template< size_t N, size_t B,class T=char>

class number
{
private:
    T v[N];
    int ocupado = 0;
    //size_t b = B;
    //size_t max = N;
    void to_base(int n);

public:
    number(int n=0);
    T* getVector();
    
    int to_decimal();
    int getOcupados();
    ostream& write(ostream& os) const ;
    
    number<N,B,T> operator + (const number<N,B,T> & other) const;
    number<N,B,T> operator - (const number<N,B,T> & other) const;
    number<N,B,T> operator / (const number<N,B,T> & other) const;
    number<N,B,T> operator * (const number<N,B,T> & other) const;
 
    bool operator == (const number<N,B,T> & other);
    bool operator != (const number<N,B,T> & other);
    bool operator < (const number<N,B,T> & other);
    bool operator > (const number<N,B,T> & other);
    bool operator >= (const number<N,B,T> & other);
    bool operator <= (const number<N,B,T> & other);
    
    ostream& write2(ostream& os, int base) const ;
    
    
    
    //int getMax();
    
    
    number<N,B,T> conversor (int numero);
    
    
    
};



template <size_t N, size_t B, class T>
number<N,B,T> number<N,B,T>::conversor(int numero){
    
    number<N,B,T> numero_nuevo(numero);
    return numero_nuevo;
}


template <size_t N, size_t B, class T>
number<N, B,T>::number(int n){
    for(int i=0; i < N; i++){
        v[i] = '0';
    }
    to_base(n);
}

template <size_t N, size_t B, class T>
int number<N,B,T>::getOcupados(){
    return ocupado;
}

// template <size_t N, size_t B, class T>
// int number<N,B,T>::getMax(){
//     return max;
// }

template<size_t N, size_t B, class T>
void number<N, B,T>::to_base(int n){
    int remainder, value;
    remainder = n;
    int pos = N-1;
    

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
        cout << "Error, no se pudo crear el número" << endl;
}


template <size_t N, size_t B, class T>
T* number<N, B,T>::getVector(){
    return v;
}

template<size_t N, size_t B, class T>
int number<N,B,T>::to_decimal(){
    int aux = 0;
    int n = 0;
    int expo = 0;
    
    for(int i = N-1 ; i >= 0 ; i--){
        aux = v[i] - '0';
        n += (pow(B,(expo)))*aux;
        expo++;
    }
    
    return n;
}
// 
// template<size_t N, size_t B, class T>
// template<size_t N2, size_t B2, class T2>
// number<N,B,T> number<N,B,T>::operator + (const number<N2,B2,T2> & other) const{
template<size_t N, size_t B, class T>
number<N,B,T> number<N,B,T>::operator + (const number<N,B,T> & other) const{
    
    int aux = 0;
    vector<int> vector_aux;
    number<N,B,T> aux_n = other;

    int n = aux_n.to_decimal();
    
    
    number<N,B> aux_number(n); //Creo el nuevo numero en la base del primero. Es other.
    
    T *aux_v = aux_number.getVector(); //Nuevo vector que almacena el número en su nueva base
    
    int suma = 0;
    int acarreo = 0;
    int c1,c2;
    
    for(int i=N-1; i >=0 ; i--){
   
        c1 = v[i] - '0'; // Para almacenar solo el número no el caracter que pusimos antes en to_base
        
        c2 = aux_v[i] - '0';
        suma = (c1+c2+acarreo);
        if( suma >= B ){ // Si se pasa y no puede representarse con un solo caracter pues me llevo una
            suma = suma % B;
            acarreo = 1;
        }else{
            acarreo = 0;
        }
        vector_aux.push_back(suma); // Vector resultante de la suma
        
    }
    
    if(acarreo > 0){
        vector_aux.push_back(acarreo);
    }
    
    
    number<N,B> error(0);
    if(  vector_aux.size() > N ){
        cout << "número demasiado grande para ser almacenado con " << N << " posiciones" << endl;
        return error;
    }
    
    
    aux = 0;
    for(int i=0; i < vector_aux.size(); i++){
        aux += pow(B,(i)) * vector_aux[i];
    }
    
    //Resultado a decimal para crear el numero
    number<N,B> salida(aux);
    
    return salida;
}


// RESTA: 32-17. 2,7--> 12-7 --> acc= 1.
template<size_t N,size_t B, class T>
number<N,B,T> number<N,B,T>::operator - (const number<N,B,T> &other)const {
    int aux = 0;
    vector<int> vector_aux;
    number<N,B,T> aux_n = other;

    int n = aux_n.to_decimal();
    number<N,B> aux_number(n); 
    number<N,B>  aux_2 = *this;
    
    if( aux_2 < aux_number){
        return number<N,B>(0);
    }
    
    T *aux_v = aux_number.getVector();
    
    int resta = 0;
    int acc = 0;
    int c1,c2;
    int expo = 0;
    for(int i=N-1; i >= 0; i--){
        c1 = v[i]-'0';
        c2 = aux_v[i]-'0';
        
        
        if((c1-acc) < c2){
            //cout << "hello" << endl;
            c1 = c1+B-acc;
            acc = 1;
            //cout <<"c1: " << (c1-acc) << " c2: " << c2 << endl;
            //cout << "diff" << c1-c2 << endl;
            resta += (c1-c2)*pow(B,expo);
        }else{
            //cout << "no problemo" << endl;
            //cout <<"c1: " << (c1-acc) << " c2: " << c2 << endl;
            c1 = c1-acc;
            //cout << "diff" << c1-c2 << endl;
            resta += (c1-c2)*pow(B,expo);
            acc = 0;
        }
        
        //cout << "resta " << resta << endl;
        expo++;
    }
    
    return number<N,B>(resta);
}



template<size_t N, size_t B, class T>
number<N,B,T> number<N,B,T>::operator * (const number<N,B,T> & other) const{
    
    int n = 0;
  
    vector<int> vector_aux;
    number<N,B,T> aux_n = other;
    
    n = aux_n.to_decimal();
    
    number<N,B> aux_number(n);
    T *aux_v = aux_number.getVector();
    number<N,B> salida(0);
    
    number<N,B> error(0);
    
    for(int i = 0; i < n ; i++){
        salida = salida + *this; //OJO OJO OJO OJO
        // *****0
        if(salida.getVector()[N-1] == '0' and salida.getOcupados() == 1){
            i = n;
            salida = error;
        }
    }
    
    return salida;
}





template<size_t N, size_t B, class T>
number<N,B,T> number<N,B,T>::operator / (const number<N,B,T> & other) const{
    
    int n = 0;
  
    vector<int> vector_aux;
    number<N,B,T> aux_n = other;
    
    n = aux_n.to_decimal();
    
    number<N,B> aux_number(n);
    T *aux_v = aux_number.getVector();
    
    number<N,B> salida(0);
    
    number<N,B> error(0);
    
  
    bool stop = true;
    int count = 0;
    int pos=0;
    salida = *this;
    while(stop==true){
        salida = salida - n;
        //cout <<"He realizado la resta" <<endl;
        if (salida < aux_number){
            //cout << "STOP"<< endl;
            stop = false;
        }
        count++;
        pos++;
    }
    

    number<N,B,T> resta(count);
    return count;
}



template<size_t N, size_t B, class T>
bool number<N,B,T>::operator != (const number<N,B,T> & other){
    return ! (*this == other);
}

template<size_t N, size_t B, class T>
bool number<N,B,T>::operator >= (const number<N,B,T> & other){
    return  (*this == other) or (*this > other);
}

template<size_t N, size_t B, class T>
bool number<N,B,T>::operator <= (const number<N,B,T> & other){
    return  (*this == other) or (*this < other);
}


template<size_t N, size_t B, class T>
bool number<N,B,T>::operator < (const number<N,B,T> & other){

    bool iguales = true;
    
    int n = 0;
  
    vector<int> vector_aux;
    number<N,B,T> aux_n = other;
    
    // Pasamos a decimal
    n = aux_n.to_decimal();
    
    int n2 = this->to_decimal();
        
    return n2 < n;
}

template<size_t N, size_t B, class T>
bool number<N,B,T>::operator > (const number<N,B,T> & other){
    return  !(*this == other) and !(*this < other);
}


template<size_t N, size_t B, class T>
bool number<N,B,T>::operator == (const number<N,B,T> & other){
    bool iguales = true;
    
    int n = 0;

    vector<int> vector_aux;
    number<N,B,T> aux_n = other;
    
    // Pasamos a decimal
    n = aux_n.to_decimal();
   
    number<N,B> aux_number(n);
    T *aux_v = aux_number.getVector();
    
  
    for(int i=N-1; i >= 0 and iguales; i--){
        if(v[i] != aux_v[i])
            iguales = false;
    }


    return iguales;
}



template <size_t N, size_t B, class T>
ostream& number<N, B,T>::write(ostream& os)const{
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



template <size_t N, size_t B, class T>
ostream& number<N, B,T>::write2(ostream& os, int base)const{
    
    // number<N,B,T> aux_n = *this;
    // int n = 0;
    
    // n = aux_n.to_decimal();
    
    // number<N,B> aux(n);
    
    // T *aux_v = aux.getVector();
    // T *aux_v2;
    // int aux2;
    
    
    // if( base > 9 ){
    //     for (int i = 0; i < N; i++){
    //         aux2 = aux_v[i]-'0';
    //         if(aux2 > 9){
        
    //             char aux_c = (aux2-10)+'A';
    //             os << aux_c;
    //         }
    //         else
    //             os << aux_v[i];
    //     }
    // }else{
    //     for(int i = 0; i < N ; i ++)
    //         os << aux_v[i];
    // }
    
    // os << ")"<< base;
    // return os;
}



#endif