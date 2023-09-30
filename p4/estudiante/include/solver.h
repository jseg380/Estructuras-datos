#include <set>
#include <vector>
#include "dictionary_ed.h"
#include "letters_set.h"

using namespace std;

/**
 * @brief Clase Solver
 */
class Solver {
private:
    Dictionary diccionario;
    LettersSet valores;

public:

    /**
     * @brief Constructor por parámetros. Crea un solver al que asocia el 
     *  Dictionary y el LettersSet pasados como argumentos.
     * 
     * @param dict Diccionario con las palabras válidas.
     * @param letters_set LettersSet con información sobre la puntuación de las 
     *  letras.
     */
    Solver (const Dictionary & dict, const LettersSet & letters_set);

    /**
     * @brief Construye el vector de soluciones a partir de las letras de una 
     *  partida.
     * 
     * @param available_letters Vector de char con las letras disponibles para 
     *  la partida.
     * @param score_game Booleano que indica el tipo de partida. 
     * @n True si es a puntuación, false si es a longitud.
     * @return Vector de palabras que constituyen las mejores soluciones y la 
     *  puntuación que obtienen.
     */
    pair<vector<string>,int> getSolutions (const vector<char> &available_letters, bool score_game);

private:
    /**
     * @brief Construye el vector de soluciones a partir de las letras de una 
     *  partida. El tipo de partida es a puntuación.
     * 
     * @param available_letters Vector de char con las letras disponibles para 
     *  la partida.
     * @return Vector de palabras que constituyen las mejores soluciones y la 
     *  puntuación que obtienen.
     */
    pair<vector<string>,int> puntuacion (const vector<char> &available_letters);

    /**
     * @brief Construye el vector de soluciones a partir de las letras de una 
     *  partida. El tipo de partida es a longitud.
     * 
     * @param available_letters Vector de char con las letras disponibles para 
     *  la partida.
     * @return Vector de palabras que constituyen las mejores soluciones y la 
     *  puntuación que obtienen.
     */
    pair<vector<string>,int> longitud (const vector<char> &available_letters);

    /**
     * @brief Calcula el número de letras coincidentes entre una palabra y las 
     *  letras disponibles.
     * 
     * @param available_letters Vector de char con las letras disponibles para 
     *  la partida.
     * @param word Palabra a comparar.
     * @return Número de letras coincidentes.
     */
    int coincidentes (vector<char> &available_letters, string word);
};





/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                            SOLVER EFICIENTE                                */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/





/**
 * @brief Clase SolverEficiente
 */
class SolverEficiente {
private:
    Dictionary diccionario;
    LettersSet valores;

public:

    /**
     * @brief Constructor por parámetros. Crea un SolverEficiente al que asocia el 
     *  Dictionary y el LettersSet pasados como argumentos.
     * 
     * @param dict Diccionario con las palabras válidas.
     * @param letters_set LettersSet con información sobre la puntuación de las 
     *  letras.
     */
    SolverEficiente (const Dictionary & dict, const LettersSet & letters_set);

    /**
     * @brief Construye el vector de soluciones a partir de las letras de una 
     *  partida.
     * 
     * @param available_letters Vector de char con las letras disponibles para 
     *  la partida.
     * @param score_game Booleano que indica el tipo de partida. 
     * @n True si es a puntuación, false si es a longitud.
     * @return Vector de palabras que constituyen las mejores soluciones y la 
     *  puntuación que obtienen.
     */
    pair<vector<string>,int> getSolutions (const vector<char> &available_letters, bool score_game);

private:
    /**
     * @brief Construye el vector de soluciones a partir de las letras de una 
     *  partida. El tipo de partida es a puntuación.
     * 
     * @param available_letters Vector de char con las letras disponibles para 
     *  la partida.
     * @return Vector de palabras que constituyen las mejores soluciones y la 
     *  puntuación que obtienen.
     */
    pair<vector<string>,int> puntuacion (const vector<char> &available_letters);

    /**
     * @brief Construye el vector de soluciones a partir de las letras de una 
     *  partida. El tipo de partida es a longitud.
     * 
     * @param available_letters Vector de char con las letras disponibles para 
     *  la partida.
     * @return Vector de palabras que constituyen las mejores soluciones y la 
     *  puntuación que obtienen.
     */
    pair<vector<string>,int> longitud (const vector<char> &available_letters);

    /**
     * @brief Calcula el número de letras coincidentes entre una palabra y las 
     *  letras disponibles.
     * 
     * @param available_letters Vector de char con las letras disponibles para 
     *  la partida.
     * @param word Palabra a comparar.
     * @return Número de letras coincidentes.
     */
    int coincidentes (vector<char> &available_letters, string word);
};