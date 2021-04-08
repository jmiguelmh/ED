/**
 * @file imagen.h
 * @brief Fichero cabecera de Imagen
 */
#ifndef __IMAGEN_H
#define __IMAGEN_H

#include "imagenES.h"
#include <cassert>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/**
 * @brief enum Tipo_Pegado
 * 
 * Tipo_Pegado es un enum que indica como se pegara la imagen con la mascara (OPACO o BLENDING)
 */
enum Tipo_Pegado {OPACO, BLENDING};

/**
 * @brief struct Pixel
 * 
 * Una instancia de Pixel indica el color de un determinado pixel baso en el sistema R,G,B,alpha (siendo alpha la transparencia)
 */
struct Pixel{
  unsigned char r,g,b;
  unsigned char transp; //0 no 255 si
}; 

/**
 * @brief T.D.A. Imagen
 * 
 * Una instancia de imagen contiene una matriz de pixeles y dos enteros que indican el numero de filas y columnas
 */
class Imagen{
private:
  /**
     * Un objeto valido @e rep del TDA Imagen representa una estructura de datos no lineal que almacena toda la informacion necesaria para representar una imagen pgm
     *  
     * Un objeto valido del TDA Imagen debe tener un numero de filas y columnas superior a cero
     */
  Pixel ** data;
  int nf,nc;

  /**
   * @brief Borrar imagen (Metodo privado)
   */
  void Borrar();

  /**
   * @brief Copiar imagen (Metodo privado)
   * @param I Imagen a copiar
   */
  void Copiar(const Imagen &I);

public:
  /**
   * @brief Constructor por defecto
   */
  Imagen();

  /**
   * @brief Constructor con parametros
   * @param f Numero de filas
   * @param c Numero de columnas
   */
  Imagen(int f,int c);

  /**
   * @brief Constructor de copiar
   * @param I Imagen a copiar
   */
  Imagen(const Imagen & I);

  /**
   * @brief Sobrecarga del operador =
   * @param I Imagen a asignar
   * @return La imagen asignada
   */
  Imagen & operator=(const Imagen & I);

  /**
   * @brief Destructor por defecto
   */
  ~Imagen();

  /**
   * @brief Sobrecarga del operador ()
   * @param i Fila
   * @param j Columna
   * @return Pixel que pertenece a esa fila y columnas
   * @note Se puede usar tanto como metodo set o get
   */
  Pixel & operator ()(int i,int j);

  /**
   * @brief Sobrecarga del operador () constante
   * @param i Fila
   * @param j Columna
   * @return Pixel que pertenece a esa fila y columnas
   * @note Solo se puede usar como get
   */
  const Pixel & operator ()(int i,int j)const;

  /**
   * @brief Crear un archivo a partir de una Imagen
   * @param nombre Nombre del archivo de la imagen
   */
  void EscribirImagen(const char * nombre);


  /**
   * @brief Crear una Imagen a traves de un archivo usando una mascara
   * @param nombre Nombre del archivo de la imagen
   * @param nombremascara Nombre del archivo de la mascara
   */
  void LeerImagen (const char *nombre,const string &nombremascara="");

  /**
   * @brief Limpia la transparencia de la imagen
   */
  void LimpiarTransp();

  /**
   * @brief Consultor de filas
   * @return El numero de filas
   */
  int num_filas()const;

  /**
   * @brief Consultor de columnas
   * @return El numero de columnas
   */
  int num_cols()const;

  /**
   * @brief Superpone una imagen sobre otra
   * @param posi Filas sobre la que se va a superponer
   * @param posj Columnas sobre la que se va a superponer
   * @param I Imagen a superponer
   * @param tippegado Tipo de pegado a usar, por defecto OPACO
   */
  void PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado=OPACO);

  /**
   * @brief Extrae una imagen de otra
   * @param posi Fila a partir de la cual se va a extraer
   * @param posj Columna a partir de la cual se va extraer
   * @param dimi Filas de la imagen extraida
   * @param dimj Columnas de la imagen extraida
   * @return La imagen extraida
   */
  Imagen ExtraeImagen(int posi,int posj,int dimi,int dimj);

};

#endif