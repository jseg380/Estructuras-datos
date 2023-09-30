/**
 * @file imageop.cpp
 * @brief Fichero con definiciones para el resto de métodos de la clase Image
 */

#include <iostream>
#include <cmath>
#include <image.h>

#include <cassert>

// Genera una subimagen
Image Image :: Crop(int nrow, int ncol, int height, int width) const {

  Image a_devolver (height, width);

  for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
      a_devolver.set_pixel (i, j, get_pixel ( nrow+i, ncol+j ));

  return a_devolver;
}

// Genera una imagen aumentada 2x.
Image Image :: Zoom2X(int nrow, int ncol, int height, int width) const {

  int rows = get_rows(),
      cols = get_cols();
  
  Image a_devolver;

  Image ampliada (height*2-1, width*2-1);

  for (int i = 0; i < ampliada.get_rows(); i+=2)
    for (int j = 0; j < ampliada.get_cols(); j+=2)
      // Establecer los pixeles originales
      ampliada.set_pixel(i, j, get_pixel(nrow + i/2, ncol + j/2));
  
  for (int i = 1; i < ampliada.get_rows(); i+=2)
    for (int j = 1; j < ampliada.get_cols(); j+=2) {
      double supIzq = (int) ampliada.get_pixel(i-1, j-1),
          supDcha = (int) ampliada.get_pixel(i-1, j+1),
          infIzq = (int) ampliada.get_pixel(i+1, j-1),
          infDcha = (int) ampliada.get_pixel(i+1, j+1),
          pixel = (supIzq + supDcha + infIzq + infDcha) / 4;
      
      pixel = (int) (pixel + 0.5);
      
      ampliada.set_pixel(i, j, (img::byte) pixel);
    }

  for (int i = 0; i < ampliada.get_rows(); i++)
    for (int j = 0; j < ampliada.get_cols(); j++) {
      double pixel;
      bool cambiar_pixel = false;

      if (i%2 == 0 && j%2 != 0) {
        pixel = ((int) ampliada.get_pixel(i, j-1) + 
                  (int) ampliada.get_pixel(i, j+1)) / 2.0;
        cambiar_pixel = true;
      }
      else if (i%2 != 0 && j%2 == 0) {
        pixel = ((int) ampliada.get_pixel(i-1, j) + 
                (int) ampliada.get_pixel(i+1, j)) / 2.0;
        cambiar_pixel = true;
      }

      if (cambiar_pixel) {
        pixel = (int) (pixel + 0.5);

        ampliada.set_pixel(i, j, (img::byte) pixel);
      }
    }

  a_devolver = ampliada;

  return a_devolver;
}

//Calcula la media de los píxeles de una imagen entera o de un fragmento de ésta.
double Image ::  Mean (int i, int j, int height, int width) const {

  float media = 0;
  for (int k=0; k < height; k++)
    for (int l=0; l < width; l++)
      media += (float)get_pixel (i+k, j+l);

  media = media / (height*width);

  return media;
}

//Genera un icono como reducción de una imagen
Image Image :: Subsample (int factor) const {

  Image icono((int) get_rows()/factor, (int) get_cols()/factor);

  for (int i=0; i < icono.get_rows(); i++)
    for (int j=0; j < icono.get_cols(); j++){

      float valor = Mean (i*factor, j*factor, factor, factor);
      icono.set_pixel (i, j, (img::byte) roundf(valor));
    }

  return icono;
}

//Modifica el contraste de una Imagen .
void Image :: AdjustContrast (img::byte in1, img::byte in2, img::byte out1, img::byte out2){

  bool valida = 0 <= (in1, in2, out1, out2) <= 255 && in1 < in2 && out1 < out2;

  if (valida) {

    float a, b, min, max;

    for (int i=0; i<get_rows(); i++)
      for (int j=0; j<get_cols(); j++){

        float pixel = get_pixel(i, j);

        if (pixel >= 0 && pixel < in1){

          a=0;
          b=(float)in1;
          min=0;
          max=(float)out1;
        }
        else if (pixel >= in1 && pixel <= in2){

          a=(float)in1;
          b=(float)in2;
          min=(float)out1;
          max=(float)out2;
        }
        else if (pixel > in2 && pixel <= 255){

          a=(float)in2;
          b=255;
          min=(float)out2;
          max=255;
        }

        // En el casteo a entero por defecto se trunca. Si se le suma 0.5 al
        // número, al truncarlo dará el mismo número que redondear el original
        //valor = (int) (valor + 0.5);
      float constante = ((max - min) / (b - a));
      float valor = min + ( constante * (pixel - a) );
      set_pixel (i, j, (img::byte) roundf(valor));

    }
  }

}

// Baraja pseudoaleatoriamente las filas de una imagen.
void Image :: ShuffleRows(){

  const int p = 9973;
  
  Image temp(rows,cols);
  int newr;

  for (int r=0; r<rows; r++){

    newr = r*p % rows;

    for (int c=0; c<cols;c++)
      temp.set_pixel(r,c,get_pixel(newr,c));
  }
  
  Copy(temp);
}