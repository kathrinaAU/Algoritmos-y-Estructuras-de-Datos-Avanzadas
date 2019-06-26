#ifndef MYVECTOR_H
#define MYVECTOR_H
#pragma once

#define INCREASE_TAM 50 /**< Definimos el tamaÃ±o del vector. */

template <class TDATO> /**< Template. */


class myVector /**< Clase myVector que contiene los mÃ©todos propios de la clase del vector. */
{
private: /**< MÃ©todos privados. */
    

    TDATO * m_vector; /**< Tipo de dato del template, serÃ¡ nuestro vector.*/
    int tam; /**< TamaÃ±o del vector. */
    int num_incluidos; /**< NÃºmero de elementos incluidos en el vector. */
    
public: /**< MÃ©todos pÃºblicos. 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/**    
            @autor   	Kathrina Arrocha UmpiÃƒÂ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Constructor de la clase sin parÃ¡metros.

*/
    myVector();
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/**    
            @autor   	Kathrina Arrocha UmpiÃƒÂ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Constructor de la clase con parÃ¡metros.
	@param newtam Entero con el que indicaremos el tamaÃ±o con el que creamos el vector.

*/
    myVector(int newtam);
  
    myVector(const myVector<TDATO>& v);
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/**    
            @autor   	Kathrina Arrocha UmpiÃƒÂ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	Destructor de la clase.

*/
    ~myVector();
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/**    
            @autor   	Kathrina Arrocha UmpiÃƒÂ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	MÃ©todo que nos sirve para conocer si el vector estÃ¡ vacÃ­o.
	
	* @return Resultado de comprobar si estÃ¡ vacÃ­o.
	* @retval TRUE  Indica que el vector estÃ¡ vacÃ­o.
	* @retval FALSE  Indica que el vector no estÃ¡ vacÃ­o.
	

*/
    bool isEmpty();
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
/**    
            @autor   	Kathrina Arrocha UmpiÃƒÂ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	MÃ©todo que nos sirve para introducir datos en el vector.
	@param newdato es un tipo de dato definido por el template, el cual serÃ¡ el elemento que insertaremos en el vector.
	

*/
    void pushBack(TDATO newdato);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
/**    
            @autor   	Kathrina Arrocha UmpiÃƒÂ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	MÃ©todo que nos sirve para eliminar el ultimo elemento del vector.
	

*/
    void popBack();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
/**    
            @autor   	Kathrina Arrocha UmpiÃƒÂ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	MÃ©todo que nos sirve para redimensionar el tamaÃ±o del vector.
	@param Entero newtam que serÃ¡ el nuevo tamaÃ±o con el que redimensionaremos el vector.

*/
    void resize(int newtam);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
/**    
            @autor   	Kathrina Arrocha UmpiÃƒÂ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	MÃ©todo que nos sirve para conocer el tamaÃ±o ocupado del vector.
	
*/
    int size();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
/**    
            @autor   	Kathrina Arrocha UmpiÃƒÂ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	MÃ©todo que nos sirve para conocer valor de una determinada posiciÃ³n del vector.
	
	* @param Entero pos que nos indica la posiciÃ³n que miraremos del vector.
	

*/
    TDATO get(int pos);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
/**    
            @autor   	Kathrina Arrocha UmpiÃƒÂ©rrez (alu0100913293@ull.edu.es)
        
        @fecha 	    Jueves 15 de Febrero de 2018

	@detalles 	MÃ©todo que nos sirve para reservar espacio al vector.
	

*/
    int reserved_size();
};

#include "myvector.hpp" /**< IncluÃ­mos el fichero en el que se desarrollan los mÃ©todos definidos en la clase. */

#endif // MYVECTOR_H
