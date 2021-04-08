/**
 * @file Pila_max_Cola.h
 * @brief Fichero cabecera del TDA Pila_max_Cola
 * @author Jose Miguel Marquez Herreros, Alejandro Perez Argüello
 * @date 24 Noviembre, 2020
 */

#ifndef __Pila_max_Cola_H__
#define __Pila_max_Cola_H__

#include <cola.h>
#include <utility>

/**
 * @brief Struct Celda_pila
 * 
 * Una instancia @e c del tipo datos abstracto @c Celda_pila es un objeto
 * compuesto por dos valores de tipo entero que contiene que representan
 * el valor que contiene la pila en esa posicion y el maximo (entero mas grande)
 * de la pila
 */

struct Celda_pila{
    int valor;
    int maximo;
};

/**
 * @brief T.D.A. Pila_max_Cola
 * 
 * Una instancia @e c del tipo datos abstracto @c Pila_max_Cola es un objeto
 * compuesto por dos colas de la STL, una variable entera que almacena en todo
 * momento el valor maximo que se encuentra en la cola y otra que almacena el
 * tamaño de Pila_max_Cola
 */

class Pila_max_Cola{
private:

    /**
     * @page repConjunto Rep del TDA Pila_max_Cola
     * 
     * Un objeto valido @e rep del TDA Pila_max_Cola representa una pila
     * (politica LIFO) que en todo momento tiene almacenado el valor maximo
     * que se encuentra en esta almacenado en el maximo de Celda_pila
     * 
     * size no puede tomar nunca una valor negativo
     * 
     * El valor de max esta por defecto a 0 (Pila_max_Cola vacia) y al valor
     * mas grande que contenga la Pila_max_Cola si esta no esta vacia.
     */

    Cola<Celda_pila> cola1, cola2;
    int size, max;

public:

    /**
     * @brief constructor por defecto
     * @note inicializa max y size a 0
     */

    Pila_max_Cola();

    /**
     * @brief constructor copia
     * @param original Pila_max_Cola a copiar
     */
    
    Pila_max_Cola(const Pila_max_Cola & original);

    /**
     * @brief destructor por defecto
     */

    ~Pila_max_Cola() = default;

    /**
     * @brief sobrecarga del operador asignación
     * @param otro Pila_max_Cola a copiar
     * @return referencia a this
     */

    Pila_max_Cola & operator=(const Pila_max_Cola & otro) = default;

    /**
     * @brief devuelve true si Pila_max_Cola está vacía
     * @return true si Pila_max_Cola está vacía, false si no
     */

    bool vacia() const;

    /**
     * @brief devuelve el elemento que se encuentra en el tope de Pila_max_Cola
     * @return una Celda_pila que contiene valor y maximo de Pila_max_Cola
     */

    Celda_pila & tope();

    /**
     * @brief quita el tope de Pila_max_Cola
     */

    void quitar();

    /**
     * @brief pone un elemento en el tope de Pila_max_Cola.
     * @note Si su valor es mayor que el máximo de Pila_max_Cola, entonces ese valor se
     * convierte en el nuevo máximo. Si no, asimila el máximo existente en Pila_max_Cola
     * @param elemento nuevo valor entero a introducir en Pila_max_Cola
     */

    void poner(const int & elemento);

    /**
     * @brief consulta del tamanio de Pila_max_Cola
     * @return numero de elementos en Pila_max_Cola
     */

    int num_elementos() const;
};

#endif // __Pila_max_Cola_H__