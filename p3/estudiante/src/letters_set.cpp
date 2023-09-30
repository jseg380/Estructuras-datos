/**
 * @file letters_set.cpp
 * @brief  Archivo de implementación del TDA Letters_set
 */

#include "letters_set.h"
#include <iostream>
#include <iomanip>

// Sobrecarga del operador de salida para el TDA LetterInfo
ostream & operator << (ostream & os, const LetterInfo & li) {
    os << left << li.repetitions << setw(8) << li.score;

    return os;
}

// Sobrecarga del operador de entrada para el TDA LetterInfo
istream & operator >> (istream & is, LetterInfo & li) {
    is >> li.repetitions >> li.score;

    return is;
}



// Constructor por defecto
LettersSet::LettersSet() {}

// Constructor de copia
LettersSet::LettersSet (const LettersSet & other) {
    letters = other.letters;   // Ya implementado en map
}

// Inserta in elemento en el LettersSet
bool LettersSet::insert (const pair<char, LetterInfo> & val) {
    return letters.insert(val).second;
}

// Elimina un carácter del LettersSet
bool LettersSet::erase (const char & key) {
    return (letters.erase(key) > 0);
}

// Elimina el contenido de LettersSet
void LettersSet::clear() {
    letters.clear();
}

// Consulta si el LettersSet está vacío
bool LettersSet::empty() const {
    return letters.empty();
}

// Tamaño del LettersSet
unsigned int LettersSet::size() const {
    return letters.size();
}

// Calcula la puntuación de una palabra
int LettersSet::getScore (string word) {
    int puntuacion = 0;
    LettersSet::const_iterator pos;

    for (int i = 0; i < word.size(); i++) 
        for (pos = LettersSet::cbegin(); pos != LettersSet::cend(); ++pos)
            if ( toupper((*pos).first) == toupper (word[i]))
                puntuacion += (*pos).second.score;
    
    return puntuacion;
}

// Sobrecarga del operador de asignación
LettersSet & LettersSet::operator = (const LettersSet & cl) {
    letters = cl.letters;
    return (*this);
}

// Sobrecarga del operador de acceso
LetterInfo & LettersSet::operator [] (const char & val) {
    return letters[val];
}

// Sobrecarga del operador de salida
ostream & operator << (ostream & os, const LettersSet & cl) {
    os << left << setw(7) << "Letra" << setw(10) << "Cantidad" << setw(8) << "Puntos\n";

    for (auto it = cl.letters.cbegin(); it != cl.letters.cend(); ++it)
        os << left << setw(7) << it->first << setw(10) << it->second << endl;
    
    return os;
}

// Sobrecarga del operador de entrada
istream & operator >> (istream & is, LettersSet & cl) {
    // Eliminar el contenido actual de LettersSet
    cl.clear();

    string word;
    LetterInfo li;
    pair<char, LetterInfo> aInsertar;

    // Obtener la primera línea que no contiene elementos del mapa
    // (Letra  Cantidad  Puntos)
    getline(is, word);

    while (is >> word) {
        is >> li;
        aInsertar.first = (char) word[0];
        aInsertar.second = li;
        
        cl.insert(aInsertar);
    }

    return is;
}
