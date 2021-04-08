/**
 * @file utilidades.h
 * @brief Funciones adicionales con objetos del TDA Imagen
 */

#ifndef UTILIDADES
#define UTILIDADES

#include "imagen.h"
#include "ImagenES.h"
#include <cassert>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

//Funciones auxiliares
/**
 * @brief crea un objeto del TDA Imagen
 * @param fichE direccion del archivo PGM
 * @retval objeto del TDA Imagen creado a partir del archivo
 * @pre el archivo al que apunta la direccion debe ser del tipo PGM
 */
Imagen CrearImagenPGM(const char* fichE);

/**
 * @brief crea un archivo del tipo PGM a partir de un objeto del TDA imagen
 * @param img objeto del TDA imagen a exportar
 * @param fichS direccion donde se va almacenar el archivo
 * @pre El directorio donde se va almacenar debe existir previamente
 */
void CrearArchivoPGM(const Imagen & img, const char *fichS);

/**
 * @brief calcula el nivel medio de gris de una imagen PGM
 * @param img puntero que contiene los pixeles de la imagen
 * @param tam tamanio del puntero (numero de pixeles)
 * @retval el nivel de gris medio de la imagen (valor entre 0 y 255)
 * @note utilizado en el ejercicio 2
 */
double calcularMedia(byte* img, int tam);

/**
 * @brief calcula la constante T para la umbralizacion automatica
 * @param img1 puntero que contiene los pixeles de la imagen 1
 * @param img2 puntero que contiene los pixeles de la imagen 2
 * @param tam1 tamanio del puntero de la imagen 1
 * @param tam2 tamanio del puntero de la imagen 2
 * @retval la constante T
 * @note utilizado en el ejercicio 2
 */
double calcularT(byte* & img1, byte* & img2, int tam1, int tam2);

/**
 * @brief calcula las dos subimagenes a partir de una imagen con T
 * @param original puntero que contiene los pixeles de la imagen original
 * @param sub1 puntero que contiene los pixeles de la imagen 1
 * @param tam_sub1 tamanio del puntero de la imagen 1
 * @param sub2 puntero que contiene los pixeles de la imagen 2
 * @param tam_sub2 tamanio del puntero de la imagen 2
 * @param T constante a aplicar para obtener las subimagenes
 * @note utilizado en el ejercicio 2
 */
void CalcularSubimagenes(byte* & original, int tam, byte* & sub1, int & tam_sub1, byte* & sub2, int & tam_sub2, double T);

/**
 * @brief calcula el nivel de color maximo y minimo de los pixeles de una imagen
 * @param img objeto del TDA imagen donde se van a buscar los valores maximo y minimo
 * @param min valor del pixel más oscuro de la imagen
 * @param max valor del pixel más claro de la imagen
 * @note utilizado en el ejercicio 5
 */
void calcular_valores(Imagen & img, int & min, int & max);

//Ejercicios
//Ejercicio 1
/**
 * @brief umbralizacion de una imagen PGM a partir de dos valores y creacion del correspondiente archivo
 * @param fichE direccion del archivo PGM
 * @param fichS direccion donde se va almacenar el archivo
 * @param T_1 umbral inferior
 * @param T_2 umbral superior
 */
void umbralizar_escala_grises(const char *fichE, const char *fichS, byte T_1, byte T_2);

//Ejercicio 2
/**
 * @brief umbralizacion automatica de una imagen PGM y creacion del correspondiente archivo
 * @param fichE direccion del archivo PGM
 * @param fichS direccion donde se va almacenar el archivo
 * @note la umbralizacion se lleva a cabo a partir de una valor calculado mediante una formula
 */
void umbralizar_automatica(const char *fichE, const char *fichS);

//Ejercicio 3
/**
 * @brief zoom de una porcion de una imagen (necesario esquina superior izquierda e inferior derecha)
 * @param fichE direccion del archivo PGM
 * @param fichS direccion donde se va almacenar el archivo
 * @param x_1 columna de la esquina superior izquierda
 * @param y_1 fila de la esquina superior izquierda
 * @param x_2 columna de la esquina inferior derecha
 * @param y_2 fila de la esquina inferior derecha
 * @pre x_1 tiene que se menor que x_2 y y_1 tiene que ser menor que y_2
 * @pre el espacio definido por las esquinas debe ser cuadrado (x_2 - x_1 == y_2 - y_1)
 */
void zoom(const char *fichE, const char *fichS, int x_1, int y_1, int x_2, int y_2);

//Ejercicio 4
/**
 * @brief se crea un icono de una imagen
 * @param fichE direccion del archivo PGM
 * @param fichS direccion donde se va almacenar el archivo
 * @param nf numero de filas del icono final
 * @param nc numero de columnas del icono final
 * @pre nf y nc tienen que ser divisibles entre las filas y las columnas de la imagen respectivamente
 */
void icono(const char *fichE, const char *fichS, int nf, int nc);

//Ejercicio5
/**
 * @brief modificacion del contraste de una imagen a partir de un minimo y un maximo
 * @param fichE direccion del archivo PGM
 * @param fichS direccion donde se va almacenar el archivo
 * @param min valor minimo de los pixeles de la imagen tras aplicarle el contraste
 * @param min valor maximo de los pixeles de la imagen tras aplicarle el contraste
 * @pre los valores minimos y maximos deben estar comprendidos entre 0 y 255
 */
void contraste_lineal(const char* fichE, const char* fichS, int min, int max);

//Ejercicio 6
/**
 * @brief crear las imagenes de una transicion de una imagen a otra mediante morphing
 * @param fichE direccion del archivo PGM
 * @param fichS direccion donde se va almacenar el archivo
 * @param fich_intermedio vector del tipo string con los nombres de los archivos intermedios
 * @pre fich_intermedios debe contener las direcciones de 256 archivos intermedios
 * @note El algoritmo de morphing creara tantos archivos intermedios como sean necesarios
 */
void morphing(const char *fich_orig, const char *fich_rdo, vector<string> fich_intermedios);

#endif