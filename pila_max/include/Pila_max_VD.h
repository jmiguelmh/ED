/**
 * @file Pila_max_VD.h
 * @brief Fichero cabecera del TDA Pila_max_VD
 * @author Jose Miguel Marquez Herreros, Alejandro Perez Argüello
 * @date 24 Noviembre, 2020
 */

#ifndef __Pila_max_VD_H__
#define __Pila_max_VD_H__

#include <vector>

/**
 * @brief Struct Celda_pila
 * 
 * Una instancia @e c del tipo datos abstracto @c Celda_pila es un objeto
 * compuesto por dos valores de tipo entero que contiene que representan
 * el valor que contiene la pila en esa posicion y el maximo (entero mas grande)
 * de la pila
 * 
 */

struct Celda_pila{
    int valor;
    int maximo;
};

/**
 * @brief T.D.A. Pila_max_VD
 * 
 * Una instancia @e c del tipo datos abstracto @c Pila_max_VD es un objeto
 * compuesto por un vector de la STL y una variable entera que almacena en todo
 * momento el valor maximo que se encuentra en la cola
 */

class Pila_max_VD{
private:

    /**
     * @page repConjunto Rep del TDA Pila_max_VD
     * 
     * Un objeto valido @e rep del TDA Pila_max_VD representa una pila
     * (politica LIFO) que en todo momento tiene almacenado el valor maximo
     * que se encuentra en esta almacenado en el maximo de Celda_pila
     * 
     * El valor de max esta por defecto a 0 (Pila_max_VD vacia) y al valor
     * mas grande que contenga la Pila_max_VD si esta no esta vacia.
     */

    std::vector<Celda_pila> v;
    int max;

public:

    /**
     * @brief constructor por defecto
     * @note inicializa max a 0
     */

    Pila_max_VD();

    /**
     * @brief constructor copia
     * @param original Pila_max_VD a copiar
     */

    Pila_max_VD(const Pila_max_VD & original);

    /**
     * @brief destructor por defecto
     */

    ~Pila_max_VD() = default;

    /**
     * @brief sobrecarga del operador asignación
     * @param otro Pila_max_VD a copiar
     * @return referencia a this
     */

    Pila_max_VD & operator=(const Pila_max_VD & otro) = default;

    /**
     * @brief devuelve true si Pila_max_VD está vacía
     * @return true si Pila_max_VD está vacía, false si no
     */

    bool vacia() const;

    /**
     * @brief devuelve el elemento que se encuentra en el tope de Pila_max_VD
     * @return una Celda_pila que contiene valor y maximo de Pila_max_VD
     */

    Celda_pila & tope();

     /**
     * @brief quita el tope de Pila_max_VD
     */
    
    void quitar();

    /**
     * @brief pone un elemento en el tope de Pila_max_VD.
     * @note Si su valor es mayor que el máximo de Pila_max_VD, entonces ese valor se
     * convierte en el nuevo máximo. Si no, asimila el máximo existente en Pila_max_VD
     * @param elemento nuevo valor entero a introducir en Pila_max_VD
     */

    void poner(const int & elemento);

    /**
     * @brief consulta del tamanio de Pila_max_VD
     * @return numero de elementos en Pila_max_VD
     */

    int num_elementos() const;
};

#endif // __Pila_max_VD_H__