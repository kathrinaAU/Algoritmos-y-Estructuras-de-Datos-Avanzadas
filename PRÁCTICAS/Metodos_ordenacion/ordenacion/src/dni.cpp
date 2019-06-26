#include "dni.h"

///////////////////////////////////////////////////////////////////////////////
Dni::Dni()
: nombre("Vacio"), apellidos("Vacio"){
    num=generador.generate();
    letra = generador.generate(65,91);
    //nombre = "";
    // for(int i=0; i < 3; i++){
    //     nombre += generador.generate(65,91);
    // }
}

///////////////////////////////////////////////////////////////////////////////
bool Dni::lessDniNum::operator()(const Dni&a, const Dni &b){
    ++Comparaciones;
    return a.num <= b.num;
}

///////////////////////////////////////////////////////////////////////////////
bool Dni::greaterDniNum::operator()(const Dni&a, const Dni &b){
    ++Comparaciones;
    return a.num >= b.num;
}

///////////////////////////////////////////////////////////////////////////////
bool Dni::lessDniLetra::operator()(const Dni&a, const Dni &b){
    ++Comparaciones;
    return a.letra <= b.letra;
}

///////////////////////////////////////////////////////////////////////////////
bool Dni::greaterDniLetra::operator()(const Dni&a, const Dni &b){
    ++Comparaciones;
    return a.letra >= b.letra;
}

///////////////////////////////////////////////////////////////////////////////
bool Dni::lessDniNombre::operator()(const Dni&a, const Dni &b){
    ++Comparaciones;
    return a.nombre <= b.nombre;
}

///////////////////////////////////////////////////////////////////////////////
bool Dni::greaterDniNombre::operator()(const Dni&a, const Dni &b){
    ++Comparaciones;
    return a.nombre >= b.nombre;
}

///////////////////////////////////////////////////////////////////////////////
int Dni::stringToInt(string s) const{
    int resultado = 0;
    int aux;
    for(int i=0; i< s.size(); i++){
        aux = s[i];
        resultado += aux;
    }

    return resultado;
}

///////////////////////////////////////////////////////////////////////////////
bool Dni::lessDniNumAndLetra::operator()(const Dni &a, const Dni &b){
    string la = a.letra;
    string lb = b.letra;
    int suma_a = a.num;
    int suma_b = b.num;

    suma_a += a.stringToInt(la);
    suma_b += b.stringToInt(lb);

    ++Comparaciones;
    return suma_a <= suma_b;
}

///////////////////////////////////////////////////////////////////////////////
bool Dni::greaterDniNumAndLetra::operator()(const Dni &a, const Dni &b){
    string la = a.letra;
    string lb = b.letra;
    int suma_a = a.num;
    int suma_b = b.num;

    suma_a += a.stringToInt(la);
    suma_b += b.stringToInt(lb);

    ++Comparaciones;
    return suma_a >= suma_b;
}

///////////////////////////////////////////////////////////////////////////////
Dni::Dni(int dni, string l, string n, string a)
{
    num=dni;
    letra=l;
    nombre=n;
    apellidos=a;
}

Dni::Dni(int dni)
:letra ("vacio"), nombre("Vacio"), apellidos("Vacio"){
  num = dni;
}
///////////////////////////////////////////////////////////////////////////////
bool Dni::operator==(int dni){
    ++Comparaciones;
    return num==dni;
}

///////////////////////////////////////////////////////////////////////////////
bool Dni::operator<=(const Dni& dni){
  ++Comparaciones;
  return num<=dni.num;
}

///////////////////////////////////////////////////////////////////////////////
bool Dni::operator>=(const Dni& dni){
  ++Comparaciones;
  return num>=dni.num;
}

///////////////////////////////////////////////////////////////////////////////
bool Dni::operator<(const Dni& dni){
  ++Comparaciones;
  return num<dni.num;
}

///////////////////////////////////////////////////////////////////////////////
bool Dni::operator>(const Dni& dni){
  ++Comparaciones;
  return num>dni.num;
}

///////////////////////////////////////////////////////////////////////////////
void Dni::setDni(int dni){
  num = dni;
}

///////////////////////////////////////////////////////////////////////////////
Dni& Dni::operator=(int dni){
    num = dni;
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
Dni& Dni::operator=(const Dni& dni){
    num = dni.num;
    letra = dni.letra;
    nombre = dni.nombre;
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
bool Dni::operator!=(int dni){
  ++Comparaciones;
  return num!=dni;
}

///////////////////////////////////////////////////////////////////////////////
bool Dni::operator==(const Dni& dni){
    ++Comparaciones;
    return num==dni.num;
}

///////////////////////////////////////////////////////////////////////////////
/**
* Define como se tiene que transformar un objeto cuando tu lo declaras como int.
* En este caso.
* Se llama cuando igualas el DNI a un objeto.
* int dni = mDni. mDni es de la clase Dni.
* int dni = int(mDni)
* En la funcion insertar por ejemplo que se pasa una clave x y hay que igualar  int dni = X;
*/

Dni::operator int() const{
    return num;
}

bool Dni::operator!=(string nombre){
  return this->nombre != nombre;
}

///////////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& os, const Dni& dni){
    os<<dni.num;
    os <<dni.letra;
    // os <<dni.nombre << endl;
    //os << dni.apellidos << endl;
    return os;
}

///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
istream& operator>>(istream& is, Dni& dni){
    is>>dni.num;
    return is;
}

///////////////////////////////////////////////////////////////////////////////
ostream& Dni::toStream(ostream& os) const {
        os << num;
        return os;
}

///////////////////////////////////////////////////////////////////////////////
Contador Dni::Comparaciones;
Generador Dni::generador;
