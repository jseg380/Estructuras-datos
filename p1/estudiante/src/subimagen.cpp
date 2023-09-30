// Fichero: subimagen.cpp
// Genera una subimagen
//

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <image.h>

using namespace std;

int main (int argc, char *argv[]){
 
  char *origen, *destino; // nombres de los ficheros
  int fila_inic, col_inic, num_filas, num_cols;
  Image entrada, resultado;

  // Comprobar validez de la llamada
  if (argc != 7){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: subimagen <fich_origen> <fich_rdo> <fila> <col> <filas_sub> <cols_sub>\n";
    exit (1);
  }

  // Obtener argumentos
  origen  = argv[1];
  destino = argv[2];
  fila_inic = atoi(argv[3]);
  col_inic = atoi(argv[4]);
  num_filas = atoi(argv[5]);
  num_cols = atoi(argv[6]);

  // Mostramos argumentos
  cout << endl;
  cout << "Fichero origen: " << origen << endl;
  cout << "Fichero resultado: " << destino << endl;
  cout << "Fila inicial: " << fila_inic << endl;
  cout << "Columna inicial: " << col_inic << endl;
  cout << "Número de filas: " << num_filas << endl;
  cout << "Número de columnas: " << num_cols << endl;

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
  resultado = entrada.Crop (fila_inic, col_inic, num_filas, num_cols);

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