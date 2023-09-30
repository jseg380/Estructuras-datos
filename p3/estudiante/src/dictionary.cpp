/**
 * @file dictionary.cpp
 * @brief  Archivo de implementación del TDA Letters_bag
 */

#include "dictionary_ed.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Constructor por defecto
Dictionary::Dictionary() {}

// Constructor de copia
Dictionary::Dictionary (const Dictionary & other) {
    words = other.words;
}

// Indica si una palabra está en el diccionario o no
bool Dictionary::exists (const string & val) const {
    bool existe = false;
    
    for (Dictionary::const_iterator pos = Dictionary::cbegin(); pos != Dictionary::cend(); ++pos)
        if (*pos == val)
            existe = true;

    return existe;
}

// Inserta una palabra en el diccionario
bool Dictionary::insert (const string & val) {
    pair < set<string>::iterator, bool > exito;

    exito = words.insert(val);

    return exito.second;
}

// Elimina una palabra del diccionario
bool Dictionary::erase (const string & val) {
    return words.erase(val);
}

// Elimina todas las palabras contenidas en el Diccionario
void Dictionary::clear() {
    words.clear();
}

// Comprueba si el diccionario está vacío
bool Dictionary::empty() {
    return words.empty();
}

// Tamaño del diccionario
unsigned int Dictionary::size () const {
    return words.size();
}

// Indica el número de apariciones de una letra
int Dictionary::getOcurrences (const char c) {
    int veces = 0;

    for (Dictionary::const_iterator pos = Dictionary::cbegin(); pos != Dictionary::cend(); ++pos){
        string palabra = *pos;

        for (int i=0; i<palabra.length(); i++)
            if (toupper(palabra[i])==toupper(c))
                veces++;
    }
    
    return veces;
}

// Cuenta el total de letras de un diccionario
int Dictionary::getTotalLetters () {
    int total = 0;

    for (Dictionary::const_iterator pos = Dictionary::cbegin(); pos != Dictionary::cend(); ++pos){
        string palabra = (*pos);
        total+=palabra.length();
    }
    
    return total;
} 

// Devuelve las palabras del diccionario con una longitud dada
vector<string> Dictionary::wordsOfLength (int length) {
    vector<string> total;

    for (Dictionary::const_iterator pos = Dictionary::cbegin(); pos != Dictionary::cend(); ++pos){
        string palabra = *pos;
        
        if (palabra.length() == length)
            total.push_back (palabra);
    }
    
    return total;
} 

// Sobrecarga del operador de salida.
ostream & operator << (ostream & os, const Dictionary & dic) {

    for (Dictionary::const_iterator pos = dic.cbegin(); pos != dic.cend(); ++pos)
        os << (*pos) << endl;
    
    return os;
}

// Sobrecarga del operador de entrada.
istream & operator >> (istream & is, Dictionary & dic) {
    string word;

    while (is >> word)
        dic.insert(word);

    return is;
}
