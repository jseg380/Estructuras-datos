/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 */
#ifndef _MAXQUEUE_H
#define _MAXQUEUE_H

#include <stack>

using namespace std;

struct element {
  int value;      // Current value to store
  int maximum;    // Current max value in the structure
};


ostream & operator << (ostream & p, const element & elemento);


/**
  @brief T.D.A. MaxQueue

  Una instancia del tipo de dato abstracto MaxQueue nos permite almacenar 
  struct element.

  Función de abstracción
  f(r) = {element, element, ..., n}  n es un Número Natural

  Invariante de la representación
  a) r.front() no modifica el tamaño (no se sacan elementos)

  Para poder usar el TDA MaxQueue se debe incluir el fichero

  \#include <maxqueue.h>

**/

class MaxQueue {

/**
   @page page_repMaxQueue Representación del TDA MaxQueue

    El TDA MaxQueue utiliza como contenedor subyacente la pila de la STL (stack).
    **/
private:

  /**
    @brief Contenedor subyacente de la cola, una pila de la STL (stack)
  **/
  stack<element> pila;


public:

  /**
   * @brief Constructor sin parámetros para un objeto de tipo MaxQueue
   * 
   */
  MaxQueue();

  /**
   * @brief Devuelve el elemento más antiguo de la cola
   * 
   * @return El struct element más antiguo
   */
  element front();

  /**
   * @brief Elimina el elemento más antiguo introducido en la cola.
   * 
   * @pre La cola ha de tener al menos un elemento
   * @post Se elimina un elemento
   * @exception Si la cola estaba vacía no se modifica
   */
  void pop();
  
  /**
   * @brief Introduce en la cola un número, convirtiéndolo en un struct element
   * 
   * @param num El valor a almacenar en la cola
   * @post Se añade un elemento
   */
  void push(int num);

  /**
   * @brief Devuelve el tamaño actual de la cola
   * 
   * @return Número de elementos que posee la cola actualmente
   */
  int size();

  /**
   * @brief Nos indica si la cola se encuentra vacía o no
   * 
   * @return true si la cola no tiene elementos, false en otro caso
   */
  bool empty();

};

#endif
