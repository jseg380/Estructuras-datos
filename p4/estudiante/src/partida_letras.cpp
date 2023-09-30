#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>

#include "dictionary_ed.h"
#include "letters_set.h"
#include "letters_bag.h"
#include "solver.h"

using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 5) {
        cerr << "Los parámetros son: " << endl
             << "1.- Un fichero con el diccionario" << endl
             << "2.- Un fichero de letras y su puntuación" << endl
             << "3.- Modo de juego (L = longitud, P = puntuación)" << endl
             << "4.- Cantidad de letras para la partida" << endl;
        exit(1);
    }

    ifstream ifs1(argv[1]);
    ifstream ifs2(argv[2]);
    string modo = argv[3];
    int num = atoi(argv[4]);

    Dictionary diccionario;
    LettersSet letterset;

    string cad;

    while (ifs1 >> cad)
        diccionario.insert(cad);

    ifs2 >> letterset;

    Solver palabras(diccionario, letterset);
    LettersBag lettersbag(letterset);

    vector<char> letras = lettersbag.extractLetters(num);

    bool modo_l;

    if (modo == "L")
        modo_l = false;
    else
        modo_l = true;


    pair<vector<string>, int> resultados = palabras.getSolutions(letras, modo_l);
    vector<string> soluciones = resultados.first;

    cout << "LETRAS DISPONIBLES:" << endl;

    for (int i = 0; i < letras.size(); i++)
        if (i != letras.size() - 1)
            cout << letras[i] << " ";
        else
            cout << letras[i] << endl;

    cout << "SOLUCIONES:" << endl;

    for (int i = 0; i < soluciones.size(); i++)
        cout << soluciones[i] << endl;

    cout << "PUNTUACION:" << endl;

    cout << resultados.second << endl;

    return 0;
}
