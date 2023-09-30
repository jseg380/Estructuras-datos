/**
 * @file bolsa_letras.cpp
 * @brief Archivo para probar el funcionamienot del TDA LettersBag
 */

#include "letters_set.h"
#include "letters_bag.h"
#include <iostream>
#include <fstream>
#include <cstdlib>  // Para exit

using namespace std;

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        cerr << "Se esperaba 1 argumento.";
        cerr << "Uso: " << argv[0] << " <archivo_letras>" << endl;
        cerr << "<archivo_letras> es un archivo que contiene información sobre "
             << "las letras (cantidad y puntuación)" << endl;
        exit(1);
    }

    ifstream ifs;

    ifs.open(argv[1]);
    
    if (ifs.fail()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    LettersSet ls;
    
    ifs >> ls;
    
    LettersBag lb(ls);
    for (int i = lb.size(); i>0 ; i--)
        cout << lb.extractLetter() << endl;
    
    ifs.close();

    return 0;
}
