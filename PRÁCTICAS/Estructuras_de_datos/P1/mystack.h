#ifndef MYSTACK_H
#define MYSTACK_H
#pragma once
#include "myvector.h"
#include <cassert>

#define MAX_STACK_SIZE 20 /** < Definimos un tamaño máximo a la pila */

template <class TDATO> /** < Template TDATO */
class myStack
{

private: /** < Métodos privados. */
    myVector<TDATO> v_; /** < Vector TDATO */
    TDATO top_; /** < Top de la pila */

public:  /** < Métodos públicos. */

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
/**    
            @autor   	Kathrina Arrocha UmpiÃ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Constructor de la clase.
	
*/
    myStack();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
/**    
            @autor   	Kathrina Arrocha UmpiÃ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Constructor de la clase con parámetros.
	@param Entero max_sz que indica el tamaño del vector.
	
*/
    myStack(int max_sz);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
/**    
            @autor   	Kathrina Arrocha UmpiÃ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Destructor de la clase.
	
*/
    ~myStack();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/**    
            @autor   	Kathrina Arrocha UmpiÃ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Método que nos sirve para conocer si el vector está vacío.
	
	* @return Resultado de comprobar si está vacío.
	* @retval TRUE  Indica que el vector está vacío.
	* @retval FALSE  Indica que el vector no está vacío.
	

*/
    bool isEmpty();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/**    
            @autor   	Kathrina Arrocha UmpiÃ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Método que nos sirve para conocer si el vector está vacío.
	
	* @return Resultado de comprobar si está lleno.
	* @retval TRUE  Indica que el vector está lleno.
	* @retval FALSE  Indica que el vector no está lleno.
	

*/
    bool isFull();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
/**    
            @autor   	Kathrina Arrocha UmpiÃ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Método que nos sirve para introducir datos en el vector.
	@param dato es un tipo de dato definido por el template, el cual será el elemento que insertaremos en el vector.

	
*/
    void push(TDATO dato);
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
/**    
            @autor   	Kathrina Arrocha UmpiÃ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Método que nos sirve para eliminar el ultimo elemento del vector.
	

*/
    void pop();
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
/**    
            @autor   	Kathrina Arrocha UmpiÃ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Método que nos sirve para conocer valor del top  del vector.
	

*/
    TDATO top();

};

#include "mystack.hpp"

#endif // MYSTACK_H
