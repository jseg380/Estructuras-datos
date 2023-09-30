/**
 * @file dictionary.h
 * @brief  Archivo de especificación del TDA Dictionary
 */
#ifndef __DICTIONARY_ED_H__
#define __DICTIONARY_ED_H__

#include <set>
#include <string>
#include <vector>


using namespace std;

/**
 * @brief TDA Dictionary
 * 
 * Esta TDA abstracto nos permite almacenar un conjunto de palabras sin
 * repeticiones y que estén ordenadas por orden alfabético
 * 
 * Una instancide del TDA Dictionary almacena datos de tipo string de tal
 * forma que no existen repeticiones, es decir, no hay dos strings iguales,
 * y estos están ordenados por orden alfabético
 * 
 * Función de abstracción: \n 
 * Sea r un objeto de tipo Dictionary, entonces los elementos son {r.datos[i]}
 * donde r.datos[i] es de tipo string
 * 
 * Invariante de la representación: \n 
 * Sea un elemento {r.datos[i]}, entonces:
 * - r.datos[i] = r.datos[j]  <==>   i = j
 * - para todo j < i, r.datos[i] > r.datos[j] siguiendo el criterio de orden
 *   lexicográfico. Para más información acerca de cómo ordenar según este 
 *   orden, veáse la página de manual de la función strncmp, que sigue este
 *   mismo criterio.
 * 
 * Para poder usar el TDA abstracto Dictionary se debe incluir el fichero
 * \#include <dictionary_ed.h>
 */

class Dictionary {
private:
    /**
     * @brief El contender subyacente del TDA Dictionary es un set de la STL
     */
    set <string> words;

public:
    /**
     * @brief Constructor por defecto
     * 
     * Crea un Dictionary vacío
     */
    Dictionary();

    /**
     * @brief Constructor de copia
     * 
     * @param other Dictionary del que se quiere copiar
     */
    Dictionary (const Dictionary & other);

    /**
     * @brief Indica si una palabra está en el diccionario o no
     * 
     * @param val palabra que se quiere buscar
     * @return true si la palabra existe en el diccionario
     * @return false en caso contrario
     */
    bool exists (const string & val) const;

    /**
     * @brief Inserta una palabra en el diccionario
     * 
     * @param val Palabra a insertar en el diccionario
     * @return true si la palabra se ha insertado con éxito, es decir, si no se encontraba antes en el diccionario
     * @return false en caso contrario
     */
    bool insert (const string & val);

    /**
     * @brief Elimina una palabra del diccionario
     * 
     * @param val Palabra a borrar del diccionario
     * @return true si la palabra se ha borrado del diccionario
     * @return false en caso contrario
     */
    bool erase (const string & val);

    /**
     * @brief Elimina todas las palabras contenidas en el Diccionario
     * 
     */
    void clear();

    /**
     * @brief Comprueba si el diccionario está vacío
     * 
     * @return true si el diccionario está vacío
     * @return false en caso contrario
     */
    bool empty();

    /**
     * @brief Tamaño del diccionario
     * 
     * @return unsigned int Número de palabras guardadas en el diccionario
     */
    unsigned int size() const;

    /**
     * @brief Indica el número de apariciones de una letra
     * 
     * @param c letra a buscar
     * @return int Entero que indica el número de apariciones
     */
    int getOcurrences (const char c);

    /**
     * @brief Cuenta el total de letras de un diccionario
     * 
     * @return int Entero con el total de letra
     */
    int getTotalLetters();

    /**
     * @brief Devuelve las palabras del diccionario con una longitud dada
     * 
     * @param lenght Longitud de las palabras buscadas
     * @return vector <string> Vector de palabaras con la longitud deseada
     */
    vector <string> wordsOfLength (int lenght);

    /**
     * @brief Sobrecarga del operador de salida.
     * 
     * @param os Flujo de salida, donde escribir el Dictionary
     * @param dic Dictionary que se escribe
     */
    friend ostream & operator << (ostream & os, const Dictionary & dic);

    /**
     * @brief Sobrecarga del operador de entrada.
     * 
     * @param is Flujo de entrada, del que leer el Dictionary
     * @param dic Dictionary en el que almacenar la información leída
     */
    friend istream & operator >> (istream & is, Dictionary & dic);

    /**
     * @brief Clase para iterar sobre el TDA Dictionary
     */
    class iterator {
    private:
        set<string>::iterator it;

    public:
        iterator(){}

        iterator (const set<string>::iterator & otro) {
            it = otro;
        }
        
        iterator (const iterator & otro) {
            it = otro.it;
        }

        iterator & operator = (const set<string>::iterator & otro) {
            it = otro;
            return *this;
        }
        
        iterator & operator = (const iterator & otro) {
            it = otro.it; 
            return *this;
        }

        string operator *() const {
            return *it;
        }

        iterator & operator ++() {
            ++it;
            return *this;
        }

        iterator & operator --() {
            --it;
            return *this;
        }

        bool operator == (const iterator & otro) {
            return it==otro.it;
        }

        bool operator != (const iterator & otro) {
            return it!=otro.it;
        }

        friend class Dictionary;
    };      // class iterator

    iterator begin() {
        iterator i (words.begin());
        return i;
    }

    iterator end() {
        iterator i (words.end());
        return i;
    }

    /**
     * @brief Clase para iterar sobre el TDA Dictionary sin modificarlo
     */
    class const_iterator {
    private:
        set<string>::const_iterator it;

    public:
        const_iterator(){}

        const_iterator (const set<string>::const_iterator & otro) {
            it = otro;
        }
        
        const_iterator (const const_iterator & otro) {
            it = otro.it;
        }

        const_iterator & operator = (const set<string>::const_iterator & otro) {
            it = otro; 
            return *this;
        }
        
        const_iterator & operator = (const const_iterator & otro) {
            it = otro.it; 
            return *this;
        }

        string operator *() const {
            return *it;
        }

        const_iterator & operator ++() {
            ++it; 
            return *this;
        }

        const_iterator & operator --() {
            --it; 
            return *this;
        }

        
        bool operator == (const const_iterator & otro) {
            return it==otro.it;
        }

        bool operator != (const const_iterator & otro) {
            return it!=otro.it;
        }

        friend class Dictionary;
    };      // class const_iterator

    const_iterator cbegin() const {
        const_iterator i (words.cbegin());
        return i;
    }

    const_iterator cend() const {
        const_iterator i (words.cend());
        return i;
    }
 };

#endif
