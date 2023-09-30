/**
 * @file palabras_longitud.cpp
 * @brief Archivo para probar el funcionamienot del TDA Dictionary
 */

#include "dictionary_ed.h"
#include <fstream>
#include <iostream>
#include <cstdlib>  // Para exit

using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 3) {
        cerr << "Se esperaban 2 argumentos.";
        cerr << "Uso: " << argv[0] << " <palabras> <longitud>" << endl;
        cerr << "<palabras> es un archivo que contiene las palabras de un"
             << " diccionario" << endl;
        cerr << "<longitud> es la longitud de las palabras que buscamos" << endl;
        exit(1);
    }

    ifstream ifs;

    ifs.open(argv[1]);

    if (ifs.fail()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    int longitud = stoi(argv[2]);
    
    Dictionary diccionario;

    string word;
    
    while(!ifs.eof()) {
        getline(ifs, word);
        diccionario.insert(word);
    }

    vector<string> out;
    out = diccionario.wordsOfLength(longitud);
    cout << "Palabras de longitud " << longitud << endl;
    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << endl;
    }

    ifs.close();
}
