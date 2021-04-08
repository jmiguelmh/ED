// Fichero: zoom.cpp
// Calcula el zoom de una porcion de una imagen PGM
// Formato:
//    zoom <FichImagenOriginal> <FichImagenDestino> <X1> <Y1> <X2> <Y2>
//    donde:
//   <FichImagenOriginal> es la imagen PGM a la que se va a calcular su umbralizacion. No se modifica.
//   <FichImagenDestino> es la imagen PGM resultado de calcular la umbralizacion de <FichImagenOriginal>.
//   <X1> numero de columna de la esquina superior izquierda
//   <Y1> numero de fila de la esquina superior izquierda
//   <X2> numero de columna de la esquina inferior derecha
//   <Y2> numero de fila de la esquina inferior derecha

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <ImagenES.h>
#include "utilidades.h"

using namespace std;

int main (int argc, char *argv[]){
 
  char *origen, *destino; // nombres de los ficheros
  int x1, y1, x2, y2; //fila y columna de las esquinas

  unsigned char *image;
  int nf, nc; // Num. de filas y columnas de las imagenes

  // Comprobar validez de la llamada
  if (argc != 7){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino> <X1> <Y1> <X2> <Y2>\n";
    exit (1);
  }

  origen  = argv[1];
  destino = argv[2];
  x1 = atoi(argv[3]);
  y1 = atoi(argv[4]);
  x2 = atoi(argv[5]);
  y2 = atoi(argv[6]);

  cout << endl;
  cout << "Fichero origen: " << origen << endl;
  cout << "Fichero resultado: " << destino << endl;

  // Leer la imagen del fichero de entrada
  image = LeerImagenPGM (origen, nf, nc);
  if (!image){
    cerr << "Error: No pudo leerse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    exit (1);
  }

  // Mostrar los parametros calculados por LeerImagenPGM()
  cout << endl;
  cout << "Dimensiones de " << origen << ":" << endl;
  
  cout << "   Imagen   = " << nf  << " filas x " << nc << " columnas " << endl;

  // Calcular zoom
  zoom(origen, destino, x1, y1, x2, y2);
  
  cout << endl;
  
  // Liberar la imagen
  delete [] image;

  return (0);
}