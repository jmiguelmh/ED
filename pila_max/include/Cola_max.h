/**
 * @file Cola_max.h
 * @brief Fichero cabecera del TDA Cola_max
 * @author Jose Miguel Marquez Herreros, Alejandro Perez Argüello
 * @date 24 Noviembre, 2020
 */

#ifndef __Cola_max_H__
#define __Cola_max_H__

#include <stack>

/**
 * @brief Struct Celda_cola
 * 
 * Una instancia @e c del tipo datos abstracto @c Celda_cola es un objeto
 * compuesto por dos valores de tipo entero que contiene que representan
 * el valor que contiene la cola en esa posicion y el maximo (entero mas grande)
 * de la cola
 */

struct Celda_cola{
    int valor;
    int maximo;
};

/**
 * @brief T.D.A. Cola_max
 * 
 * Una instancia @e c del tipo datos abstracto @c Cola_max es un objeto
 * compuesto por dos pilas de la STL y una variable entera que almacena
 * en todo momento el valor maximo que se encuentra en la cola
 * 
 */

class Cola_max{
private:

    /**
     * @page repConjunto Rep del TDA Cola_max
     * 
     * Un objeto valido @e rep del TDA Cola_max representa una cola
     * (politica FIFO) que en todo momento tiene almacenado el
     * valor maximo que se encuentra en esta almacenado en el maximo
     * de Celda_cola
     * 
     * El valor de max esta por defecto a 0 (Cola_max vacia) y al valor
     * mas grande que contenga la Cola_max si esta no esta vacia.
     * Este valor se actualiza a cada insercion y borrado
     */

    std::stack<Celda_cola> pila1, pila2;
    int max;

    /**
     * @brief Actualiza el valor maximo de todas las Celda_cola
     * @note Busca el elemento mayor de la Cola_max y lo utiliza para
     * actualizar el atributo max y los maximo de todas las Celda_cola
     * que hay en Cola_max
     */
    
    void actualizar_max();
    
public:  

    /**
     * @brief constructor por defecto
     * @note inicializa los atributos de tipo pila de la STL con los
     * constructores por defecto
     */

    Cola_max()=default;

    /**
     * @brief constructor copia
     * @param otra Cola_max a copiar
     */
    
    Cola_max(Cola_max & otra);

    /**
     * @brief destructor por defecto
     */
    
    ~Cola_max() = default;
    
    /**
     * @brief sobrecarga del operador asignacion
     * @param otro Cola_max a copiar
     * @return referencia a this
     */
    
    Cola_max & operator=(const Cola_max & otro);
    
     /**
     * @brief devuelve true si Cola_max está vacía
     * @return true si la Cola_max está vacía, false si no
     */

    bool vacia() const;

    /**
     * @brief pone un elemento al final de Cola_max
     * @note Si el valor de este elemento es el máximo de la cola,
     * se actualizan TODOS los máximos de Cola_max a este. Si no, asimila el máximo existente en Cola_max
     * @param elemento nuevo valor entero a introducir en Cola_max
     */

    void poner(const int elemento);

    /**
     * @brief quita el elemento en el frente de Cola_max.
     * @note Si el valor de este elemento era el máximo de la cola,
     * se actualizan TODOS los máximos de la cola al siguiente máximo.
     */

    void quitar();

    /**
     * @brief devuelve el elemento al frente de Cola_max
     * @return una Celda_cola que contiene valor y maximo de Cola_max
     */

    Celda_cola frente() const;

    /**
     * @brief consulta del tamanio de Pila_max_Cola
     * @return numero de elementos en Cola_max
     */
    
    int num_elementos() const;
};

#endif // __Cola_max_H__

