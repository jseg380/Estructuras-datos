#include <iostream>
#include <fstream>
#include <cstdlib>    // exit

#include "letters_set.h"
#include "dictionary_ed.h"

using namespace std;

int main (int argc, char **argv){

    if (argc != 3) {
        cerr << "Los parámetros son: " << endl
             << "1.- Un fichero con el diccionario" << endl
             << "2.- Un fichero de letras" << endl;
        exit(1);
    }

    ifstream ifs1 (argv[1]);

    if (!ifs1) {
        cerr << "No se puede abrir el fichero " << argv[1] << endl;
        exit(2);
    }

    ifstream ifs2 (argv[2]);

    if (!ifs2) {
        cerr << "No se puede abrir el fichero " << argv[2] << endl;
        exit(2);
    }
    
    Dictionary diccionario;
    LettersSet valores;

    ifs1 >> diccionario;

    ifs2 >> valores;

    cout << "Letra\tUsos\tOcurrencias" << endl;

    for (LettersSet::const_iterator it = valores.cbegin(); it != valores.cend(); ++it)
        cout << (*it).first << "\t" << diccionario.getTotalUsages((*it).first) 
             << "\t" << diccionario.getOccurrences((*it).first) << endl;

    return 0;
}
