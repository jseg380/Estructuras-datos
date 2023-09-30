#include "letters_set.h"
#include "letters_bag.h"
#include "dictionary_ed.h"
#include <iostream>
#include <fstream>
#include <cstdlib>  // Para exit

using namespace std;

int main (int argc, char **argv){

    ifstream ifs1 (argv[1]);
    ifstream ifs2 (argv[2]);
    Dictionary diccionario;
    string cadena;

    while (ifs1 >> cadena)
        diccionario.insert(cadena);

    LettersSet valores;

    ifs2 >> valores;

    cout << "Letra\tFAbs.\tFrel." << endl;

    LettersSet::const_iterator pos;

    for (pos = valores.cbegin(); pos != valores.cend(); ++pos)
        cout << (*pos).first << "\t" << diccionario.getOcurrences((*pos).first) << "\t"
             << ((double)diccionario.getOcurrences((*pos).first) / (double)diccionario.getTotalLetters()) << endl;

    return 0;
}
