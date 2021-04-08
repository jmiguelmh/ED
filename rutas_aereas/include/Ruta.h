/**
 * @file Ruta.h
 * @brief Fichero cabecera de Ruta
 * @author Jose Miguel Marquez Herreros y Alejandro Pérez Argüello
 * @date 8 Enero, 2021
 */
#ifndef __RUTA_H
#define __RUTA_H

#include <string>
#include <vector>
#include "Punto.h"

/**
 * @brief T.D.A. Ruta
 * 
 * Una instancia de Ruta contiene un string con su nombre, un entero con el número de puntos que contiene y un vector de la STL de tipo Punto
 * con dichos puntos
 */
class Ruta{
private:
    /**
     * Un objeto valido @e rep del TDA Ruta representa una 
     * estructura de datos lineal que almacena una serie de Puntos
     *  
     * Un objeto valido del TDA Ruta debe tener un nombre no nulo y un número de puntos válidos no negativo
     */
    string nombre;
    int numPuntos;
    vector<Punto> puntos;

public:
    /**
     * @brief Constructor sin argumentos
     */
    Ruta();

    /**
     * @brief Constructor por copia
     * @param otro Ruta a copiar
     */
    Ruta(const Ruta & otro);

    /**
     * @brief destructor por defecto 
     */
    ~Ruta() = default;

    /**
     * @brief Consultor para el nombre
     * @return El nombre
     */
    string getNombre() const;

    /**
     * @brief sobrecarga del operador =
     * @param otro Ruta a copiar
     * @return puntero a this
     */
    Ruta & operator=(const Ruta & otro);

    /**
     * @brief añade un punto al final del vector
     * @param punto a añadir
     */
    void aniadirPunto(const Punto & punto);

    /**
     * @brief elimina el ultimo punto
     */
    void eliminarUltimoPunto();

    /**
     * @brief T.D.A. IteratorRuta 
     * 
     * Una instancia @e i del tipo datos abstracto @c IteradorRuta es un objeto
     * que permite recorrer el TDA Ruta de forma ordenada
     * Tiene permisos de lectura y escritura en la Ruta
     */
    class IteradorRuta{
    private:
        /**
         * @page repConjunto Rep del IteradorRuta
         * 
         * Un objeto valido @e rep del TDA IteradorRuta representa una
         * herramienta para recorrer el TDA Ruta de forma ordenada
         */
        vector<Punto>::iterator iterador;
        friend class Ruta;
    
    public:
        /**
         * @brief Constructor por defecto
         */
        IteradorRuta();

        /**
         * @brief Constructor de copia
         * @param otro IteradorRuta a copiar
         */
        IteradorRuta(const IteradorRuta & it);

        /**
         * @brief Destructor por defecto
         */
        ~IteradorRuta();

        /**
         * @brief sobrecarga del operador de desigualdad de IteradorRuta
         * @param otro IderatorRuta a comparar
         * @return true si son distintos, false en caso contrario
         */
        bool operator!=(const IteradorRuta & it) const;

        /**
         * @brief sobrecarga del operador de igualdad de IteradorRuta
         * @param otro IteradorRuta a comparar
         * @return true si son iguales, false en caso contrario
         */
        bool operator==(const IteradorRuta & it) const;

        /**
         * @brief sobrecarga del operador de asignacion de IteradorRuta
         * @param otro IteradorRuta a asignar
         * @return El objeto del TDA IteradorRuta que ha sido asignado
         */
        IteradorRuta & operator=(const IteradorRuta & it);

        /**
         * @brief sobrecarga del operador asterisco de IteradorRuta
         * @return El punto de la Ruta al que apunta el IteradorRuta
         */
        Punto & operator*();

        /**
         * @brief sobrecarga del operador de pre-incremento de IteradorRuta
         * @return El siguiente objeto IteradorRuta del TDA Ruta
         */
        IteradorRuta & operator++();
        
        /**
         * @brief sobrecarga del operador de pre-decremento de IteradorRuta
         * @return El anterior objeto IteradorRuta del TDA Ruta
         */
        IteradorRuta & operator--();
    };

    /**
     * @brief metodo begin de IteradorRuta
     * @return devuelve un IteradorRuta que apunta al comienzo de la Ruta
     */
    IteradorRuta begin();

    /**
     * @brief metodo end de IteradorRuta
     * @return devuelve un IteradorRuta que apunta al final de la Ruta
     */
    IteradorRuta end();

    /**
     * @brief T.D.A. IteratorRutaConst
     * 
     * Una instancia @e i del tipo datos abstracto @c IteratorRutaConst es un objeto
     * que permite recorrer el TDA Ruta de forma ordenada
     * Tiene permisos solo de lectura de la Ruta
     */
    class IteradorRutaConst{
    private:
        /**
         * @page repConjunto Rep del IteratorRutaConst
         * 
         * Un objeto valido @e rep del TDA IteratorRutaConst representa una
         * herramienta para recorrer el TDA Ruta de forma ordenada y no permite modificarlo
         */
        vector<Punto>::const_iterator iterador_constante;
        friend class Ruta;
    
    public:
        /**
         * @brief Constructor por defecto
         */
        IteradorRutaConst();

        /**
         * @brief Constructor de copia
         * @param otro IteradorRutaConst a copiar
         */
        IteradorRutaConst(const IteradorRutaConst & it);

        /**
         * @brief Destructor por defecto
         */
        ~IteradorRutaConst();

        /**
         * @brief sobrecarga del operador de desigualdad de IteradorRutaConst
         * @param otro IteratorRutaConst a comparar
         * @return true si son distintos, false en caso contrario
         */
        bool operator!=(const IteradorRutaConst & it) const;

        /**
         * @brief sobrecarga del operador de igualdad de IteradorRutaConst
         * @param otro IteratorRutaConst a comparar
         * @return true si son iguales, false en caso contrario
         */
        bool operator==(const IteradorRutaConst & it) const;

        /**
         * @brief sobrecarga del operador de asignacion de IteradorRutaConst
         * @param otro IteradorRutaConst a asignar
         * @return El objeto del TDA IteradorRutaConst que ha sido asignado
         */
        IteradorRutaConst & operator=(const IteradorRutaConst & it);

        /**
         * @brief sobrecarga del operador asterisco de IteradorRutaConst
         * @return El punto de la Ruta al que apunta el IteradorRutaConst
         */
        const Punto & operator*() const;

        /**
         * @brief sobrecarga del operador de pre-incremento de IteradorRutaConst
         * @return El siguiente objeto IteradorRutaConst del TDA Ruta
         */
        IteradorRutaConst & operator++();

        /**
         * @brief sobrecarga del operador de pre-decremento de IteradorRutaConst
         * @return El anterior objeto IteradorRutaConst del TDA Ruta
         */
        IteradorRutaConst & operator--();
    };

    /**
     * @brief metodo begin de IteradorRutaConst
     * @return devuelve un IteradorRutaConst que apunta al comienzo de la Ruta
     */
    IteradorRutaConst begin() const;

    /**
     * @brief metodo end de IteradorRutaConst
     * @return devuelve un IteradorRutaConst que apunta al final de la Ruta
     */
    IteradorRutaConst end() const;

    /**
     * @brief sobrecarga del operador >>
     * @param is flujo de entrada
     * @param R ruta a "leer"
     * @return el flujo
     */
    friend istream & operator>>(istream & is, Ruta & R);

    /**
     * @brief sobrecarga del operador <<
     * @param os flujo de salida
     * @param R ruta a "escribir"
     * @return el flujo
     */
    friend ostream & operator<<(ostream & os, const Ruta & R);
};

#endif