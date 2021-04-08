// Fichero: morphing.cpp
// Calcula las imagenes intermedias de la transicion entre dos imagenes PGM
// Formato:
//    morphing <FichImagenOriginal> <FichImagenDestino>
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

  // Calcular morphing
  vector<string> fich_intermedios;
  for(int i = 0; i < 256; i++){
    string fich = "imagenes_pgm_ppm/morphing/";
    fich += to_string(i);
    fich += ".pgm";
    fich_intermedios.push_back(fich);
  }
  morphing(origen, destino, fich_intermedios);
  
  cout << endl;
  
  // Liberar la imagen
  delete [] image;

  return (0);
}