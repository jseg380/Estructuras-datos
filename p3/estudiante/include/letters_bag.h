/**
 * @file letters_bag.h
 * @brief  Archivo de especificación del TDA Bag
 */
#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include "bag.h"
#include "letters_set.h"
#include <vector>

/**
 * @brief TDA LettersBag
 *
 * Este TDA almacena un conjunto de chars utilizado en el juego de letras.
 * La estructura de datos subyacente es una lista de chars.
 * 
 * Una instancia del TDA LettersBag almacena un TDA Bag utilizando como 
 * tipo de dato char (carácter)
 * 
 * Función de abstracción: \n 
 * Sea r un objeto de tipo LettersBag, entonces los elementos son {r.datos[i]}
 * donde r.datos[i] es un char
 * 
 * Invariante de la representación: \n
 * Sea un elemento {r.datos[i]}, entonces no se puede saber con certeza cuándo
 * será extraido
 * 
 * Para poder usar el TDA LettersBag se debe incluir el fichero
 * \#include <letters_bag.h>
 */


class LettersBag {

private:
    Bag <char> letters;

public:

    /**
     * @brief Constructor por defecto
     * 
     * Crea un LettersBag vacío
     */
    LettersBag();

    /**
     * @brief Constructor de copia a partir de un LettersSet
     * 
     * @param un letterSet a copiar
     */
    LettersBag (const LettersSet & letterSet);

    /**
     * @brief Inserta una nueva letra en la bolsa
     * 
     * @param l letra a añadir a la LettersBag
     */
    void insertLetter (const char & l);

    /**
     * @brief Extrae una letra aleatoria de la bolsa, eliminándola del conjunto
     * 
     * @return char representa la letra extraída
     */
    char extractLetter();

    /**
     * @brief Extrae un ocnjunto de letras de la LettersBag, eliminándolas del conjunto
     * 
     * @param num Número de letras a extraer
     * @return vector<char> Lista con las letras extraídas aleatoriamente
     */
    vector<char> extractLetters (int num);

    /**
     * @brief Elimina todo el contenido de la LettersBag
     * 
     */
    void clear();

    /**
     * @brief Tamaño de la bolsa
     * 
     * @return unsigned int con el tamaño de la bolsa
     */
    unsigned int size();

    /**
     * @brief Sobrecarga del operador de asignación
     * 
     * @return LettersBag& Referencia a this. De esta forma el operador puede ser encadenado
     */
    LettersBag & operator = (const LettersBag & other);
};



#endif
