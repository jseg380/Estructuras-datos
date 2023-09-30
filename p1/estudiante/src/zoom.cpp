// Fichero: zoom.cpp
// Genera una imagen aumentada 2x
//

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <image.h>

using namespace std;

int main (int argc, char *argv[]){
 
  char *origen, *destino; // nombres de los ficheros
  int fila_inic, col_inic, lado;
  Image entrada, resultado;

  // Comprobar validez de la llamada
  if (argc != 6){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: subimagen <fich_origen> <fich_rdo> <fila> <col> <lado>\n";
    exit (1);
  }

  // Obtener argumentos
  origen  = argv[1];
  destino = argv[2];
  fila_inic = atoi(argv[3]);
  col_inic = atoi(argv[4]);
  lado = atoi(argv[5]);

  // Mostramos argumentos
  cout << endl;
  cout << "Fichero origen: " << origen << endl 
       << "Fichero resultado: " << destino << endl 
       << "Fila inicial: " << fila_inic << endl
       << "Columna inicial: " << col_inic << endl 
       << "Lado: " << lado << endl;

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
  resultado = entrada.Zoom2X (fila_inic, col_inic, lado, lado);

  // Mostrar los parametros de la imagen aumentada
  cout << endl;
  cout << "Dimensiones de " << destino << ":" << endl;
  cout << "   Imagen   = " << resultado.get_rows()  << " filas x " << resultado.get_cols() << " columnas " << endl;

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