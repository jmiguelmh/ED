// Fichero: contraste_lineal.cpp
// Calcula el contraste de una imagen PGM a partir de dos umbrales
// Formato:
//    contraste_lineal <FichImagenOriginal> <FichImagenDestino> <UmbralInferior> <UmbralSuperior>
//    donde:
//   <FichImagenOriginal> es la imagen PGM a la que se va a calcular su umbralizacion. No se modifica.
//   <FichImagenDestino> es la imagen PGM resultado de calcular la umbralizacion de <FichImagenOriginal>.
//   <UmbralInferior> valor inferior para aplicar el contraste sobre <FichImagenOriginal>
//   <UmbralSuperior> valor superior para aplicar el contraste sobre <FichImagenOriginal>

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <ImagenES.h>
#include "utilidades.h"

using namespace std;

int main (int argc, char *argv[]){
 
  char *origen, *destino; // nombres de los ficheros
  int umbral_inferior, umbral_superior; //rango del contraste

  unsigned char *image;
  int nf, nc; // Num. de filas y columnas de las imagenes

  // Comprobar validez de la llamada
  if (argc != 5){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino> <UmbralInferior> <UmbralSuperior>\n";
    exit (1);
  }

  origen  = argv[1];
  destino = argv[2];
  umbral_inferior = atoi(argv[3]);
  umbral_superior = atoi(argv[4]);

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

  // Calcular contraste lineal
  contraste_lineal(origen, destino, umbral_inferior, umbral_superior);
  
  cout << endl;
  
  // Liberar la imagen
  delete [] image;

  return (0);
}