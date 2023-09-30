/**
 * @file letters_bag.cpp
 * @brief  Archivo de implementación del TDA Letters_bag
 */

#include "letters_bag.h"

// Constructor por defecto
LettersBag::LettersBag(){}

// Constructor de copia a partir de un LettersSet
LettersBag::LettersBag (const LettersSet & lettersSet){
    LettersSet::const_iterator pos;
    for (pos = lettersSet.cbegin(); pos!=lettersSet.cend(); ++pos)
        for (int i=0; i < (*pos).second.repetitions; i++)
            letters.add((*pos).first);
}

// Inserta una nueva letra en la bolsa
void LettersBag::insertLetter (const char & l){
    letters.add(l);
}

// Extrae una letra aleatoria de la bolsa, eliminándola del conjunto
char LettersBag::extractLetter(){
    return letters.get();
}

// Extrae un conjunto de letras de la LettersBag, eliminándolas del conjunto
vector<char> LettersBag::extractLetters (int num){
    vector<char> letras;
    for (int i=0; i < num; i++)
        letras.push_back(letters.get());
    
    return letras;
}

// Elimina todo el contenido de la LettersBag
void LettersBag::clear(){
    letters.clear();
}

// Tamaño de la bolsa
unsigned int LettersBag::size(){
    return letters.size();
}

// Sobrecarga del operador de asignación
LettersBag & LettersBag::operator = (const LettersBag & other){
    if (this != &other)
        letters = other.letters;

    return *this;
}
