#include "dni.h"

///////////////////////////////////////////////////////////////////////////////
Dni::Dni()
:letra(""), nombre(""), apellidos(""){

    // num=00000000 + rand() %99999999;
    num = generador.generate();
    
}

///////////////////////////////////////////////////////////////////////////////
Dni::Dni(int dni, string l, string n, string a)
{
    num=dni; // En el num se sumaria num + letra
    digits=dni;
    letra=l;
    nombre=n;
    apellidos=a;
}

Dni::Dni(int dni)
:letra (""), nombre(""), apellidos(""){
  int letra_aux;
  if(dni == 0){
    num = generador.generate();
    digits = num; // Esto muestra el dni solo para que no salga con la letra
  }else if(dni == 1){
    num = generador.generate();
    digits = num;
    letra_aux = generador.generate(65,91);
    letra = letra_aux;
    num = num+letra_aux; // Este es el que usaremos para las busquedas
  }else if(dni == 2){
    num = generador.generate();
    digits = num;
    // letra_aux = generador.generate(65,91);
    // letra = letra_aux;
    // num = num+letra_aux;
    nombre = "";
    //num = 0; Para buscar por nombre descomento esta y la 45
    for (int i = 0; i < 3; i++) {
      letra_aux = generador.generate(65,91);
      nombre += letra_aux;
      //num += letra_aux;
    }
  }else{ // Caso de dni manualmente
    digits=dni;
    num = dni;
    // cout << " num: " << num << endl;
  }
}
///////////////////////////////////////////////////////////////////////////////
bool Dni::operator==(int dni){
    ++Comparaciones;
    return num==dni;
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
    os<<dni.digits;
    os <<dni.letra << endl;
    os <<dni.nombre << endl;
    os << dni.apellidos << endl;
    return os;
}

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
