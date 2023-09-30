/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 */

#include <iostream>
#include <stack>
#include <maxqueue.h>

using namespace std;

ostream & operator << (ostream & p, const element & elemento) {
  p << elemento.value << "," << elemento.maximum;

  return p;
}

/********************************
       FUNCIONES PÚBLICAS
********************************/

// Constructor por defecto
MaxQueue::MaxQueue() {}

// Consulta el elemento más antiguo
element MaxQueue::front() {
  return pila.top();
}

// Extrae el elemento más antiguo (no devuelve nada)
void MaxQueue::pop() {
  pila.pop();
}

// Inserta un elemento
void MaxQueue::push (int num) {

  element nuevo;
  nuevo.value = num;
  nuevo.maximum = num;

  stack<element> a_reemplazar;

  while(!pila.empty()){
    a_reemplazar.push (pila.top());
    pila.pop();
  }

  a_reemplazar.push (nuevo);

  while (!a_reemplazar.empty()){
    pila.push(a_reemplazar.top());

    if (pila.top().maximum < nuevo.maximum)
      pila.top().maximum = nuevo.maximum;

    a_reemplazar.pop();

  }
}

// Tamaño de la cola
int MaxQueue::size() {
  return pila.size();
}

// Devuelve true si la cola está vacía, false en caso contrario
bool MaxQueue::empty() {
  return pila.empty();
}
