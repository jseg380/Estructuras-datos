/**
 * @file conjunto_letras.cpp
 * @brief Archivo para probar el funcionamienot del TDA LettersSet
 */

#include "letters_set.h"
#include <iostream>
#include <fstream>
#include <cstdlib>   // Para exit

using namespace std;



int main(int argc, char * argv[]) {
    
    if (argc != 3) {
        cerr << "Se esperaban 2 argumentos.";
        cerr << "Uso: " << argv[0] << " <archivo_letras> <palabra>" << endl;
        cerr << "<archivo_letras> es un archivo que contiene información sobre "
             << "las letras (cantidad y puntuación)" << endl;
        cerr << "<palabra> es la palabra a la que se quiere calcular su puntuación" << endl;
        exit(1);
    }

    // Comprobar que el archivo (argv[1]) existe

    ifstream ifs;

    ifs.open(argv[1]);

    if (ifs.fail()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    LettersSet ls;
    ifs >> ls;
    string palabra(argv[2]);
    int num = ls.getScore(palabra);
    cout << num << endl;

    ifs.close();

    return 0;
}
