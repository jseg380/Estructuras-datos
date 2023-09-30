#include "solver.h"

// Constructor con parámetros. Crea un solver al que asocia el Dictionary 
// y LettersSet pasados como argumentos.
Solver::Solver(const Dictionary & dict, const LettersSet & letters_set) {
    diccionario = dict;
    valores = letters_set;
}

// Construye el vector de soluciones a partir de las letras de una partida.
pair<vector<string>,int> Solver::getSolutions (const vector<char> &available_letters, bool score_game){
    if (score_game)
        return puntuacion(available_letters);
    else
        return longitud(available_letters);
}

////////////////////////////////////////////////////////////////////////////////
//                                 PRIVATE
////////////////////////////////////////////////////////////////////////////////

// Construye el vector de soluciones a partir de las letras de una partida. El 
// tipo de partida es a puntuacion.
pair<vector<string>,int> Solver::puntuacion (const vector<char> &available_letters){
    pair<vector<string>,int> soluciones;
    vector<string> palabras;
    vector<char> letras;
    int puntuacion = 0;
    int puntuacion_solucion = 0;

    for (Dictionary::iterator it = diccionario.begin(); it != diccionario.end(); ++it){
        letras = available_letters;

        string palabra = *it;
        int long_palabra = palabra.length();
        int n_letras_coincidentes = coincidentes(letras, palabra);

        if (n_letras_coincidentes == long_palabra){
            puntuacion = valores.getScore(palabra);

            if (puntuacion > puntuacion_solucion){
                puntuacion_solucion = puntuacion;
                palabras.clear();
                palabras.push_back(palabra);
            }
            else if (puntuacion == puntuacion_solucion)
                palabras.push_back(palabra);
        }
    }
    soluciones.first = palabras;
    soluciones.second = puntuacion_solucion;
    return soluciones;
}

// Construye el vector de soluciones a partir de las letras de una partida. El 
// tipo de partida es a longitud.
pair<vector<string>,int> Solver::longitud (const vector<char> &available_letters){
    pair<vector<string>,int> soluciones;
    vector<string> palabras;
    vector<char> letras;
    int longitud_solucion = 0;

    for (Dictionary::iterator it = diccionario.begin(); it != diccionario.end(); ++it){
        letras = available_letters;

        string palabra = *it;
        int long_palabra = palabra.length();
        int n_letras_coincidentes = coincidentes(letras, palabra);

        if (n_letras_coincidentes == long_palabra){
            if (long_palabra > longitud_solucion){
                longitud_solucion = long_palabra;
                palabras.clear();
                palabras.push_back(palabra);
            }
            else if (long_palabra == longitud_solucion)
                palabras.push_back(palabra);
        }
    }
    soluciones.first = palabras;
    soluciones.second = longitud_solucion;
    return soluciones;
}

// Calcula el número de letras coincidentes entre una palabra y las letras 
// disponibles.
int Solver::coincidentes (vector<char> &available_letters, string word){
    int n_letras_coincidentes = 0;
    int long_palabra = word.length();

    for (int i = 0; i < long_palabra; i++){
        bool cont = true;
        for (vector<char>::iterator it = available_letters.begin(); it != available_letters.end() && cont; ++it)
            if (toupper(word[i]) == toupper(*it)){
                n_letras_coincidentes++;
                available_letters.erase(it);
                cont = false;
            }
    }

    return n_letras_coincidentes;
}




/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                            SOLVER EFICIENTE                                */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/





// Constructor con parámetros. Crea un SolverEficiente al que asocia el Dictionary 
// y LettersSet pasados como argumentos.
SolverEficiente::SolverEficiente(const Dictionary & dict, const LettersSet & letters_set) {
    diccionario = dict;
    valores = letters_set;
}

// Construye el vector de soluciones a partir de las letras de una partida.
pair<vector<string>,int> SolverEficiente::getSolutions (const vector<char> &available_letters, bool score_game){
    if (score_game)
        return puntuacion(available_letters);
    else
        return longitud(available_letters);
}

////////////////////////////////////////////////////////////////////////////////
//                                 PRIVATE
////////////////////////////////////////////////////////////////////////////////

// Construye el vector de soluciones a partir de las letras de una partida. El 
// tipo de partida es a puntuacion.
pair<vector<string>,int> SolverEficiente::puntuacion (const vector<char> &available_letters){
    pair<vector<string>,int> soluciones;
    vector<string> palabras;
    vector<char> letras;
    int puntuacion = 0;
    int puntuacion_solucion = 0;

    for (Dictionary::possible_words_iterator it = diccionario.possible_words_begin(available_letters); it != diccionario.possible_words_end(); ++it){
        letras = available_letters;
        cout << "P possible_words_iterator: " << *it << "\n";

        string palabra = *it;
        int long_palabra = palabra.length();
        int n_letras_coincidentes = coincidentes(letras, palabra);

        if (n_letras_coincidentes == long_palabra){
            puntuacion = valores.getScore(palabra);

            if (puntuacion > puntuacion_solucion){
                puntuacion_solucion = puntuacion;
                palabras.clear();
                palabras.push_back(palabra);
            }
            else if (puntuacion == puntuacion_solucion)
                palabras.push_back(palabra);
        }
    }
    soluciones.first = palabras;
    soluciones.second = puntuacion_solucion;
    return soluciones;
}

// Construye el vector de soluciones a partir de las letras de una partida. El 
// tipo de partida es a longitud.
pair<vector<string>,int> SolverEficiente::longitud (const vector<char> &available_letters){
    pair<vector<string>,int> soluciones;
    vector<string> palabras;
    vector<char> letras;
    int longitud_solucion = 0;

    for (Dictionary::possible_words_iterator it = diccionario.possible_words_begin(available_letters); it != diccionario.possible_words_end(); ++it){
        letras = available_letters;
        cout << "L possible_words_iterator: " << *it << "\n";

        string palabra = *it;
        int long_palabra = palabra.length();
        int n_letras_coincidentes = coincidentes(letras, palabra);

        if (n_letras_coincidentes == long_palabra){
            if (long_palabra > longitud_solucion){
                longitud_solucion = long_palabra;
                palabras.clear();
                palabras.push_back(palabra);
            }
            else if (long_palabra == longitud_solucion)
                palabras.push_back(palabra);
        }
    }
    soluciones.first = palabras;
    soluciones.second = longitud_solucion;
    return soluciones; 
}

// Calcula el número de letras coincidentes entre una palabra y las letras 
// disponibles.
int SolverEficiente::coincidentes (vector<char> &available_letters, string word){
    int n_letras_coincidentes = 0;
    int long_palabra = word.length();

    for (int i = 0; i < long_palabra; i++){
        bool cont = true;
        for (vector<char>::iterator it = available_letters.begin(); it != available_letters.end() && cont; ++it)
            if (toupper(word[i]) == toupper(*it)){
                n_letras_coincidentes++;
                available_letters.erase(it);
                cont = false;
            }
    }

    return n_letras_coincidentes;
}