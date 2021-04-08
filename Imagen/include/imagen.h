/**
 * @file imagen.h
 * @brief Fichero cabecera del TDA Imagen
 */

#ifndef IMAGEN
#define IMAGEN

typedef unsigned char byte;

/**
 * @brief T.D.A. Imagen
 * 
 * Una instancia @e c del tipo datos abstracto @c Imagen es un objeto
 * compuesto por una matriz bidimensional definida por dos numeros
 * enteros que representan, respectivamente, filas y columnas.
 * 
 * @author Jose Miguel Marquez Herreros, Alejandro Perez Argüello
 * @date Octubre 2020
 */

class Imagen{

private:
    /**
     * @page repConjunto Rep del TDA Imagen
     * 
     * @section invConjunto Invariante del la representacion
     * 
     * El invariante es filas>0 && cols>0
     * 
     * @section faConjunto Funcion de abstraccion
     * 
     * Un objeto valido @e rep del TDA Imagen representa una matriz de
     * dimension filas x columnas
     * 
     */
    int filas;
    int cols;
    byte **img;

    /**
     * @brief Reserva de memoria para la matriz
     * @param f numero de filas
     * @param c numero de columnas
     * @pre f y c deben ser mayores que 0
     */
    void reservar(int f, int c);

    /**
     * @brief Liberacion de memoria ocupada por la matriz
     */
    void liberar();

public:
    /**
     * @brief Constructor por defecto. Crea una imagen 256 x 256
     */
    Imagen();

    /**
     * @brief Constructor de copia
     * @param i objeto valido de TDA Imagen
     */
    Imagen(const Imagen & i);
    
    /**
     * @brief Constructor definiendo filas y columnas
     * @param f numero de filas
     * @param c numero de columnas
     */
    Imagen(int f, int c);
    
    /**
     * @brief Destructor del TDA Imagen basico
     */
    ~Imagen();
    
    /**
     * @brief Metodo get de filas
     * @return Devuelve el numero de filas
     */
    int num_filas() const;

    /**
     * @brief Metodo get de columnas
     * @return Devuelve el numero de columnas
     */
    int num_columnas() const;

    /**
     * @brief asigna el valor de un pixel
     * @param f fila donde quieres asignar
     * @param c columna donde quieres asignar
     * @param valor valor a asignar al pixel
     */
    void asigna_pixel(int f, int c, byte valor);
     /**
     * @brief comprueba el valor de un pixel
     * @param f fila donde quieres buscar
     * @param c columna donde quieres buscar
     * @retval valor del pixel
     */
    byte valor_pixel(int f, int c) const;


    /**
     * @brief sobrecarga del operador asignación
     * @param i objeto del tipo imagen a copiar
     * @retval puntero a this para poder encadenar asignaciones
     */
    Imagen & operator=(const Imagen & image);

    /**
     * @brief sobrecarga del operador igual "=="
     * @param i objeto del tipo imagen
     * @retval booleano verdadero si son iguales, falso si no
     */
    bool operator==(const Imagen & image);

    /**
     * @brief sobrecarga del operador igual "!="
     * @param i objeto del tipo imagen
     * @retval booleano verdadero si no son iguales, falso si lo son
     */
    bool operator!=(const Imagen & image);
};

#endif