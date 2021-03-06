#ifndef MYDOUBLELIST_H
#define MYDOUBLELIST_H

#pragma once
#include "mydoublenode.h"
#include <cassert>
#include <iostream>


#include <cstdio>

using namespace std;

template <class TDATO> /** < Template TDATO. */
class myDoubleList
{

private: /** < Métodos privados. */

    myDoubleNode<TDATO>* head_; /** < Nodo TDATO que indica la cabeza de la lista. */
    myDoubleNode<TDATO>* tail_; /** < Nodo TDATO que indica la cola de la lista. */

    int sz_; /** < Tamaño de la lista. */

public: /** < Métodos públicos. */

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/**    
            @autor   	Kathrina Arrocha UmpiÃ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles   Constructor de la clase.
	

*/
    myDoubleList();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/**    
            @autor   	Kathrina Arrocha UmpiÃ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles   Destructor de la clase.
	

*/
    ~myDoubleList();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/**    
            @autor   	Kathrina Arrocha UmpiÃ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Método que nos sirve para insertar un elemento por la cola de la lista.
	@param TDATO dato que vamos a introducir en la lista.

*/
    void insert_tail(TDATO dato);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/**    
            @autor   	Kathrina Arrocha UmpiÃ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Método que nos sirve para insertar un elemento por la cabeza de la lista.
	@param TDATO dato que vamos a introducir en la lista.

*/
    void insert_head(TDATO dato);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/**    
            @autor   	Kathrina Arrocha UmpiÃ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Método que nos sirve para extraer la cola de la lista.
	

*/
    myDoubleNode<TDATO>* extract_tail(void);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/**    
            @autor   	Kathrina Arrocha UmpiÃ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Método que nos sirve para extraer la cabeza de la lista.
	

*/
    myDoubleNode<TDATO>* extract_head(void);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/**    
            @autor   	Kathrina Arrocha UmpiÃ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Método que nos sirve para conocer la cola de la lista.
	

*/
    myDoubleNode<TDATO>* get_tail(void);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/**    
            @autor   	Kathrina Arrocha UmpiÃ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Método que nos sirve para conocer la cabeza de la lista.
	

*/
    myDoubleNode<TDATO>* get_head(void);
     
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/**    
            @autor   	Kathrina Arrocha UmpiÃ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Método que nos sirve para conocer si la lista está vacía.
	
	* @return Resultado de comprobar si está vacía.
	* @retval TRUE  Indica que el vector está vacía.
	* @retval FALSE  Indica que el vector no está vacía.
	

*/
    bool isEmpty(void);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
/**    
            @autor   	Kathrina Arrocha UmpiÃ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Método que nos sirve para eliminar el dato de la lista.
	@param  TDATO dato que queremos eliminar.
	
*/
    void remove(TDATO dato);
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
/**    
            @autor   	Kathrina Arrocha UmpiÃ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Método que nos sirve para escribir por pantalla la pila.

*/
    ostream& write(ostream& os);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
/**    
            @autor   	Kathrina Arrocha UmpiÃ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Método que nos sirve para conocer el tamaño ocupado de la lista.
	
*/
    int size(void);
};


#include "mydoublelist.hpp"

#endif // MYDOUBLELIST_H
