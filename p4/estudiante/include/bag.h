/**
 * @file bag.h
 * @brief  Archivo de especificación del TDA Bag
 */
#ifndef __BAG_H__
#define __BAG_H__

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

/**
 * @brief TDA abstracto Bag
 *
 * Este TDA abstracto nos permite trabajar con una colección de elementos que
 * permite la extracción de elementos de forma aleatoria sin reemplazamiento
 * 
 * Una instancia del TDA Bag almacena datos de tipo T (template)
 * y permite la extracción de estos tipos de datos de forma aleatoria
 * (esto es, sin seguir un orden específico)
 * 
 * Función de abstracción: \n
 * Sea r un objeto de tipo Bag, entonces los elementos son {r.datos[i]} donde
 * el tipo de datos es un vector de datos de tipo T
 * 
 * Invariante de la representación: \n
 * Sea un elemento {r.datos[i]}, entonces no se puede saber con certeza cuándo
 * será extraido
 *  
 * Para poder usar el TDA abstacto Bag se debe incluir el fichero
 * \#include <bag.h>
 */

template <class T>
class Bag {

private:
    vector<T> v;

public:
    /**
     * @brief Constructor por defecto
     * 
     * Crea un Bag vacío
     */
    Bag();

    /**
     * @brief Constructor de copia
     * 
     * @param Objeto de tipo Bag<T> del que se va a realizar la copia
     */
    Bag (const Bag<T> & other);

    /**
     * @brief Añade un elemento a la bolsa
     * 
     * @param element elemento del tipo T a añadir a la bolsa
     */
    void add (const T & element);

    /**
     * @brief Extrae un elemento aleatoria de la bolsa y lo elimina de la misma
     * 
     * @return T Elemento de tipo T extraído de la bolsa
     * @pre La bolsa no está vacíá
     * @post El elemento devuelto se ha eliminado de la bolsa
     */
    T get();

    /**
     * @brief Elimina todos los elementos de la bolsa
     * 
     */
    void clear();
    
    /**
     * @brief Tamaño de la bolsa
     * 
     * @return unsigned int Número de elementos que hay en la bolsa
     */
    unsigned int size() const;

    /**
     * @brief Compruba si la bolsa está vacía
     * 
     * @return true si la bolsa está vacía
     * @return false en caso contrario
     */
    bool empty();

    /**
     * @brief Sobrecarga del operador de asignación
     * 
     * @param other 
     * @return const Bag<T>& 
     */
    const Bag<T> & operator = (const Bag<T> & other);
 };

#endif


// Constructor por defecto
template<class T>
Bag<T> :: Bag(){}

// Constructor de copia
template<class T>
Bag<T> :: Bag (const Bag<T> & other){
    v = other.v;
}

// Añade un elemento a la bolsa
template<class T>
void Bag<T> :: add (const T & element){
    v.push_back(element);
}

// Extrae un elemento aleatoria de la bolsa y lo elimina de la misma
template<class T>
T Bag<T> :: get(){
    srand(time(NULL));
    int num = rand()%v.size();

    T a_devolver = v[num];
    v[num] = v.back();
 
    v.pop_back();

    return a_devolver;
}

// Elimina todos los elementos de la bolsa
template<class T>
void Bag<T> :: clear(){
    v.clear();
}

// Tamaño de la bolsa
template<class T>
unsigned int Bag<T> :: size() const{
    return v.size();
}

// Compruba si la bolsa está vacía
template<class T>
bool Bag<T> :: empty(){
    return v.empty();
}

// Sobrecarga del operador de asignación
template<class T>
const Bag<T> & Bag<T> :: operator = (const Bag<T> & other){
    if (this != &other)
        this->v = other.v;

    return *this;
}
