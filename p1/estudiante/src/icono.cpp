// Fichero: icono.cpp
// Genera un icono como reducción de una imagen
//

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <image.h>

using namespace std;

int main (int argc, char *argv[]){
 
  char *origen, *destino; // nombres de los ficheros
  int factor;
  Image entrada, resultado;

  // Comprobar validez de la llamada
  if (argc != 4){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: icono <fich_origen> <factor>\n";
    exit (1);
  }

  // Obtener argumentos
  origen  = argv[1];
  destino = argv[2];
  factor = atoi(argv[3]);

  // Mostramos argumentos
  cout << endl;
  cout << "Fichero origen: " << origen << endl;
  cout << "Fichero resultado: " << destino << endl;
  cout << "Factor: " << factor << endl;

  // Leer la imagen del fichero de entrada
  if (!entrada.Load(origen)){
    cerr << "Error: No pudo leerse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
  }

  // Mostrar los parametros de la Imagen
  cout << endl;
  cout << "Dimensiones de " << origen << ":" << endl;
  cout << "   Imagen   = " << entrada.get_rows()  << " filas x " << entrada.get_cols() << " columnas " << endl;

  // Calcular la subimagen
  resultado = entrada.Subsample (factor);

  // Guardar la imagen resultado en el fichero
  if (resultado.Save(destino))
    cout  << "La imagen se guardo en " << destino << endl;
  else{
    cerr << "Error: No pudo guardarse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
  }

  return 0;

}