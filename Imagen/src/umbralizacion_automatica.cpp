// Fichero: umbralizacion_automatica.cpp
// Calcula la umbralizacion automatica de una imagen PGM
// Formato:
//    umbralizacion_automatica <FichImagenOriginal> <FichImagenDestino>
//    donde:
//   <FichImagenOriginal> es la imagen PGM a la que se va a calcular su umbralizacion. No se modifica.
//   <FichImagenDestino> es la imagen PGM resultado de calcular la umbralizacion de <FichImagenOriginal>.

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <ImagenES.h>
#include "utilidades.h"

using namespace std;

int main (int argc, char *argv[]){
 
  char *origen, *destino; // nombres de los ficheros

  unsigned char *image;
  int nf, nc; // Num. de filas y columnas de las imagenes

  // Comprobar validez de la llamada
  if (argc != 3){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino>\n";
    exit (1);
  }

  origen  = argv[1];
  destino = argv[2];

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

  // Calcular umbralizacion automatica
  umbralizar_automatica(origen, destino);
  
  cout << endl;
  
  // Liberar la imagen
  delete [] image;

  return (0);
}