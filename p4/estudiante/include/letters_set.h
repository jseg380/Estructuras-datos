/**
 * @file letters_set.h
 * @brief  Archivo de especificación del TDA Bag
 */
#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__

#include <iostream>
#include <map>
#include <string>

using namespace std;

/**
 * @brief TDA LetterInfo
 *
 * Contiene información sobre un determinado carácter del juego de las
 * letras. En concreto, almacena información sobre el número de repeticiones de
 * la letra en la partida y de la puntuación que otorga al utilizarse en una
 * palabra
 */

struct LetterInfo {
    int repetitions;
    int score;
};

/**
 * @brief Sobrecarga del operador de salida del TDA LetterInfo
 * 
 * @param os Flujo de salida, donde escribir el LetterInfo
 * @param li LetterInfo que se escribe
 */
ostream & operator << (ostream & os, const LetterInfo & li);

/**
 * @brief Sobrecarga del operador de entrada del TDA LetterInfo
 * 
 * @param is Flujo de entrada, donde leer el LetterInfo
 * @param li LetterInfo en el que se guarda lo leído
 * @post @p li es modificado
 */
istream & operator >> (istream & is, LetterInfo & li);

/**
 * @brief TDA LettersSet
 *
 * Este TDA representa un conjunto de letras, con la información necesaria para
 * jugar una partida al juego de las letras, es decir, el número de repeticiones
 * que tenemos de la letra y la puntuación que dicha letra otorga cuando se
 * utiliza en una palabra
 * 
 * Una instancia del TDA LettersSet almacena parejas de claves y valores
 * donde las claves son una letra (no se repiten) y los valores son
 * la cantidad de repeticiones y puntuación de la letra asociada
 * {l, (r, p)}  donde l es la letra, r las repeticiones y p la puntuación
 * 
 * Función de abstracción: \n
 * Sea r un objeto de tipo LetterSet, entonces las parejas son
 * {r.datos[i].letra, (r.datos[i].repeticiones, r.datos[i].puntuación)}
 * 
 * Invariante de la representación: \n
 * Sea {c, (r, p)} una pareja con clave (letra) c, repeticiones r y puntuación p
 * entonces no existe ninguna otra pareja con la misma clave c en el mismo objeto
 * 
 * Para poder usar el TDA LettersSet se debe incluir el fichero
 * \#include <letters_set.h>
 */

class LettersSet {

private:
    /**
     * @brief El contenedor subyacente del TDA LettersSet es un map de la STL
     */

    map<char, LetterInfo> letters;

public:
    /**
     * @brief Constructor por defecto.
     * 
     * Crea un LettersSet vacio.
     */
    LettersSet();

    /**
     * @brief Constructor de copia.
     * 
     * @param other LettersSet a copiar
     */
    LettersSet(const LettersSet & other);

    /**
     * @brief Inserta un elemento en el LettersSet.
     * 
     * @param val Pareja de letra y LetterInfo asociada a insertar
     * @return booleano que marca si se ha podido insertar la letra en el 
     * LetterSet. La letra sólo se inserta correctamente si no estaba aún 
     * incluída en la colección
     * @post Si no estaba el elemento a insertar, el objeto es modificado
     */
    bool insert(const pair<char, LetterInfo> & val);

    /**
     * @brief Elimina un carácter del LettersSet.
     * 
     * @param key Carácter a eliminar
     * @return Booleano que indica si se ha podido eliminar correctamente la 
     * letra del LettersSet
     * @post Si existía una entrada con la clave @p key , el objeto es modificado
     */
    bool erase(const char & key);

    /**
     * @brief Limpia el contenido del LettersSet.
     * 
     * @post Elimina el contenido del LettersSet
     */
    void clear();

    /**
     * @brief Consulta si el LettersSet está vacío.
     * 
     * @return true Si el LettersSet está vacío
     * @return false Si el LettersSet no está vacío
     */
    bool empty() const;

    /**
     * @brief Tamaño del LettersSet.
     * 
     * @return Número de elementos en el LettersSet
     */
    unsigned int size() const;

    /**
     * @brief Calcula la puntuación dada una palabra.
     * 
     * @param word String con la palabra cuya puntuación queremos calcular
     * @return Puntuación de la palabra, calculada como la suma de las
     * puntuaciones de cada una de sus letras
     */
    int getScore(string word);

    /**
     * @brief Sobrecarga del operador de asignación.
     * 
     * @param cl LettersSet a copiar
     * @return Referencia al objeto this para poder encadenar el operador
     * @post El objeto se modifica
     */
    LettersSet & operator = (const LettersSet & cl);

    /**
     * @brief Sobrecarga del operador de consulta.
     * 
     * Permite acceder a los elementos del map que hay en nuestra clase.
     * 
     * @param val Carácter a consultar
     * @return Estructura de tipo LettersSet con la información del carácter
     * consultado: Número de repeticiones y puntuación
     */
    LetterInfo & operator [] (const char & val);

    /**
     * @brief Sobrecarga del operador de salida.
     * 
     * @param os Flujo de salida, donde escribir el LettersSet
     * @param cl LettersSet que se escribe
     */
    friend ostream & operator << (ostream & os, const LettersSet & cl);

    /**
     * @brief Sobrecarga del operador de entrada.
     * 
     * @param is Flujo de entrada, del que leer el LettersSet
     * @param cl LettersSet en el que almacenar la información leída
     * @post El objeto se modifica
     */
    friend istream & operator >> (istream & is, LettersSet & cl);


    /**
     * @brief Clase para iterar sobre el TDA LettersSet
     */
    class iterator {
    private:
        map<char, LetterInfo>::iterator it;

    public:
        iterator(){}

        iterator (const map<char, LetterInfo>::iterator & other) {
            it = other;
        }

        iterator (const iterator & other) {
            it = other.it;
        }

        iterator & operator++() {
            ++it;
            return (*this);
        }

        iterator & operator--() {
            --it;
            return (*this);
        }

        iterator & operator = (const map<char, LetterInfo>::iterator & other) {
            it = other;
            return (*this);
        }

        iterator & operator = (const iterator & other) {
            it = other.it;
            return (*this);
        }

        pair<const char, LetterInfo> & operator *() const{
            return (*it);
        }

        bool operator == (const iterator & i) {
            return (it == i.it);
        }

        bool operator != (const iterator & i) {
            return (it != i.it);
        }

        friend class LettersSet;
    };  // class iterator

    /**
     * @brief Inicializa un iterator al comienzo del LettersSet
     * 
     * @return Un iterator apuntando al comienzo del LettersSet
     */
    iterator begin() {
        iterator i (letters.begin());
        return i;
    }

    /**
     * @brief Inicializa un iterator al final del LettersSet
     * 
     * @return Un iterator apuntando al final del LettersSet
     */
    iterator end() {
        iterator i (letters.end());
        return i;
    }
    
    /**
     * @brief Clase para iterar sobre el TDA LettersSet sin modificarlo
     */
    class const_iterator {
    private:
        map<char, LetterInfo>::const_iterator it;

    public:
        const_iterator(){}

        const_iterator (const map<char, LetterInfo>::const_iterator & other) {
            it = other;
        }

        const_iterator (const const_iterator & other) {
            it = other.it;
        }

        const_iterator & operator++() {
            ++it;
            return (*this);
        }

        const_iterator & operator--() {
            --it;
            return (*this);
        }

        const_iterator & operator = (const map<char, LetterInfo>::const_iterator & other) {
            it = other;
            return (*this);
        }

        const_iterator & operator = (const const_iterator & other) {
            it = other.it;
            return (*this);
        }

        const pair<const char, LetterInfo> & operator *() const {
            return (*it);
        }

        bool operator == (const const_iterator & i) {
            return (it == i.it);
        }

        bool operator != (const const_iterator & i) {
            return (it != i.it);
        }

        friend class LettersSet;
    };  // class const_iterator

    /**
     * @brief Inicializa un const_iterator al comienzo del LettersSet
     * 
     * @return Un const_iterator apuntando al comienzo del LettersSet
     */
    const_iterator cbegin() const {
        const_iterator i (letters.cbegin());
        return i;
    }

    /**
     * @brief Inicializa un const_iterator al final del LettersSet
     * 
     * @return Un const_iterator apuntando al final del LettersSet
     */
    const_iterator cend() const {
        const_iterator i (letters.cend());
        return i;
    }

};


#endif
