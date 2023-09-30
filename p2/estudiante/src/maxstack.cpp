/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 */

#include <iostream>
#include <queue>
#include <maxstack.h>

using namespace std;

ostream & operator << (ostream & p, const element & elemento) {
  p << elemento.value << "," << elemento.maximum;

  return p;
}

/********************************
       FUNCIONES PÚBLICAS
********************************/

// Constructor por defecto
MaxStack::MaxStack() {}

// Consulta el último elemento
element MaxStack::top() {
  return cola.front();
}

// Extrae el último elemento introducido (no devuelve nada)
void MaxStack::pop() {
  cola.pop();
}

// Inserta un elemento
void MaxStack::push (int num) {
  element nuevo;
  nuevo.value = num;

  if (!empty() && top().maximum > num)
    nuevo.maximum = top().maximum;
  else
    nuevo.maximum = num;

  queue<element> a_reemplazar;
  a_reemplazar.push(nuevo);

  while (!empty()){
    a_reemplazar.push(top());
    pop();
  }

  cola.swap (a_reemplazar);
}


// Tamaño de la pila
int MaxStack::size () {
  return cola.size();
}

// Devuelve true si la pila está vacía, false en caso contrario
bool MaxStack::empty () {
  return cola.empty(); 
}
