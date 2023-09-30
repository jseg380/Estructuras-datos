/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 */
#ifndef _MAXSTACK_H
#define _MAXSTACK_H

#include <queue>

using namespace std;

/**
 * @brief Tipo de dato que almacena un valor arbitrario y otro que contiene el
 * valor más grande de todo el contenedor hasta ese momento.
 */
struct element {
  int value;      // Current value to store
  int maximum;    // Current max value in the structure
};

/**
 * @brief Sobrecarga del operador << para imprimir por pantalla un struct element
 * 
 * @param p Flujo de salida por el que sale la información
 * @param elemento struct element a mostrar por pantalla
 * @return Una referencia a ostream
 * @post @p elemento No es modificado 
 */
ostream & operator << (ostream & p, const element & elemento);


/**
  @brief T.D.A. MaxStack

  Una instancia del tipo de dato abstracto MaxStack nos permite almacenar 
  struct element.

  Función de abstracción
  f(r) = {element, element, ..., n}  n es un Número Natural

  Invariante de la representación
  a) r.top() no modifica el tamaño (no se sacan elementos)

  Para poder usar el TDA MaxStack se debe incluir el fichero

  \#include <maxstack.h>

**/

class MaxStack {

/**
   @page page_repMaxStack Representación del TDA MaxStack

    El TDA MaxStack utiliza como contenedor subyacente la cola de la STL (queue).
    **/
private:

  /**
    @brief Contenedor subyacente de la pila, una cola de la STL (queue)
  **/
  queue<element> cola;


public:

  /**
   * @brief Constructor sin parámetros para un objeto de tipo MaxStack
   * 
   */
  MaxStack();

  /**
   * @brief Devuelve el último elemento almacenado en la pila
   * 
   * @return El último struct element, el menos antiguo
   */
  element top();

  /**
   * @brief Elimina el último elemento introducido en la pila.
   * 
   * @pre La pila ha de tener al menos un elemento
   * @post Se elimina un elemento
   * @exception Si la pila estaba vacía no se modifica
   */
  void pop();

  /**
   * @brief Introduce en la pila un número, convirtiéndolo en un struct element
   * 
   * @param num El valor a almacenar en la pila
   * @post Se añade un elemento
   */
  void push(int num);

  /**
   * @brief Devuelve el tamaño actual de la pila
   * 
   * @return Número de elementos que posee la pila actualmente
   */
  int size();

  /**
   * @brief Nos indica si la pila se encuentra vacía o no
   * 
   * @return true si la pila no tiene elementos, false en otro caso
   */
  bool empty();
};


#endif
