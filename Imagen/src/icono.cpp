// Fichero: icono.cpp
// Calcula un icono de una imagen PGM
// Formato:
//    icono <FichImagenOriginal> <FichImagenDestino> <Filas> <Columnas>
//    donde:
//   <FichImagenOriginal> es la imagen PGM a la que se va a calcular su umbralizacion. No se modifica.
//   <FichImagenDestino> es la imagen PGM resultado de calcular la umbralizacion de <FichImagenOriginal>.
//   <Filas> numero de filas del icono
//   <Columnas> numero de columnas del icono 

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <ImagenES.h>
#include "utilidades.h"

using namespace std;

int main (int argc, char *argv[]){
 
  char *origen, *destino; // nombres de los ficheros
  int filas, columnas; //numero de filas y columnas del icono

  unsigned char *image;
  int nf, nc; // Num. de filas y columnas de las imagenes

  // Comprobar validez de la llamada
  if (argc != 5){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino> <X1> <Y1> <X2> <Y2>\n";
    exit (1);
  }

  origen  = argv[1];
  destino = argv[2];
  filas = atoi(argv[3]);
  columnas = atoi(argv[4]);

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

  // Calcular icono
  icono(origen, destino, filas, columnas);
  
  cout << endl;
  
  // Liberar la imagen
  delete [] image;

  return (0);
}