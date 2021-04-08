/**
 * @file AlmacenRutas.h
 * @brief Fichero cabecera de AlmacenRutas
 * @author Jose Miguel Marquez Herreros y Alejandro Pérez Argüello
 * @date 8 Enero, 2021
 */
#ifndef __ALMACENRUTAS_H
#define __ALMACENRUTAS_H

#include <vector>
#include "Ruta.h"
/**
 * @brief T.D.A. ALmacenRutas
 * 
 * Una instancia de AlmacenRutas contiene  un entero con el número de Rutas que contiene y un vector de la STL de tipo Ruta
 * con dichas rutas
 */

class AlmacenRutas
{
    private:
            /**
         * Un objeto valido @e rep del TDA AlmacenRutas representa una 
         * estructura de datos lineal que almacena una serie de Rutas
         *  
         * Un objeto valido del TDA Ruta debe tener un número de rutas no negativo y sus rutas deben ser válidas
         */
        vector<Ruta> rutas;
        int numRutas;

    public:
        /**
         * @brief Constructor sin argumentos
         */
        AlmacenRutas();

       /**
    	 * @brief Constructor por copia
         * @param otro AlmacenRutas a copiar
		 */        
        AlmacenRutas(const AlmacenRutas &otro);

        /**
    	 * @brief destructor por defecto 
		 */        
        ~AlmacenRutas() = default;

        /**
    	 * @brief sobrecarga del operador =
         * @param otro AlmacenRutas a copiar
         * @return puntero a this
		 */
        AlmacenRutas &operator=(const AlmacenRutas &otro);

        /**
    	 * @brief Devuelve la ruta del orden del codigo que le des
         * @param codigo posicion de la ruta a dar
         * @return la ruta
		 */
        Ruta GetRuta(string codigo) const;

        /**
    	 * @brief añade una ruta al final del vector
         * @param ruta a añadir
		 */
        void aniadirRuta(const Ruta &ruta);

        /**
		 * @brief T.D.A. IteratorAlmacenRutas
		 * 
		 * Una instancia @e i del tipo datos abstracto @c IteratorAlmacenRutas es un objeto
		 * que permite recorrer el TDA AlmacenRutas de forma ordenada
		 * Tiene permisos de lectura y escritura en el AlmacenRutas
		 */
        class IteradorAlmacenRutas
        {
            private:
                /**
                 * @page repConjunto Rep del IteratorAlmacenRutas
                 * 
                 * Un objeto valido @e rep del TDA IteratorAlmacenRutas representa una
                 * herramienta para recorrer el TDA AlmacenRutas de forma ordenada
                 */
                vector<Ruta>::iterator iterador;
                friend class AlmacenRutas;

            public:
                /**
                 * @brief Constructor por defecto
                 */
                IteradorAlmacenRutas() = default;

                /**
                 * @brief Constructor de copia
                 * @param otro IteradorAlmacenRutas a copiar
                 */
                IteradorAlmacenRutas(const IteradorAlmacenRutas &it) = default;

                /**
                 * @brief Destructor por defecto
                 */
                ~IteradorAlmacenRutas() = default;

                /**
                 * @brief sobrecarga del operador de desigualdad de IteradorAlmacenRutas
                 * @param otro IderatorAlmacenRutas a comparar
                 * @return true si son distintos, false en caso contrario
                 */
                bool operator!=(const IteradorAlmacenRutas &it) const;

                /**
                 * @brief sobrecarga del operador de igualdad de IteradorAlmacenRutas
                 * @param otro IderatorAlmacenRutas a comparar
                 * @return true si son iguales, false en caso contrario
                 */
                bool operator==(const IteradorAlmacenRutas &it) const;

                /**
                 * @brief sobrecarga del operador de asignacion de IteradorAlmacenRutas
                 * @param otro IteradorAlmacenRutas a asignar
                 * @return El objeto del TDA IteradorAlmacenRutas que ha sido asignado
                 */
                IteradorAlmacenRutas &operator=(const IteradorAlmacenRutas &it) = default;

                /**
                 * @brief sobrecarga del operador asterisco de IteradorAlmacenRuta
                 * @return La ruta a la que apunta el IteradorAlmacenRuta
                 */
                Ruta &operator*();

                /**
                 * @brief sobrecarga del operador de pre-incremento de IteradorAlmacenRutas
                 * @return El siguiente objeto IteradorAlmacenRutas del TDA AlmacenRutas
                 */                
                IteradorAlmacenRutas &operator++();

                /**
                 * @brief sobrecarga del operador de pre-decremento de IteradorAlmacenRutas
                 * @return El anterior objeto IteradorAlmacenRutas del TDA AlmacenRutas
                 */   
                IteradorAlmacenRutas &operator--();
        };

        /**
		 * @brief metodo begin de IteradorAlmacenRuta
		 * @return devuelve un IteradorAlmacenRuta que apunta al comienzo del AlmacenRutas
		 */
        IteradorAlmacenRutas begin();

        /**
		 * @brief metodo end de IteradorAlmacenRuta
		 * @return devuelve un IteradorAlmacenRuta que apunta al final del AlmacenRutas
		 */
        IteradorAlmacenRutas end();

        /**
		 * @brief T.D.A. IteratorAlmacenRutasConst
		 * 
		 * Una instancia @e i del tipo datos abstracto @c IteratorAlmacenRutasConst es un objeto
		 * que permite recorrer el TDA AlmacenRutasConst de forma ordenada
		 * Tiene permisos solo de lectura del AlmacenRutas
		 */
        class IteradorAlmacenRutasConst
        {
            private:
                /**
                 * @page repConjunto Rep del IteratorAlmacenRutasConst
                 * 
                 * Un objeto valido @e rep del TDA IteratorAlmacenRutasConst representa una
                 * herramienta para recorrer el TDA AlmacenRutasConst de forma ordenada sin modificarla
                 */              
                vector<Ruta>::const_iterator iterador_constante;
                friend class AlmacenRutas;

            public:
                /**
                 * @brief Constructor por defecto
                 */
                IteradorAlmacenRutasConst() = default;

                /**
                 * @brief Constructor de copia
                 * @param otro IteradorAlmacenRutasConst a copiar
                 */
                IteradorAlmacenRutasConst(const IteradorAlmacenRutasConst &it) = default;

                /**
                 * @brief Destructor por defecto
                 */
                ~IteradorAlmacenRutasConst() = default;

                /**
                 * @brief sobrecarga del operador de desigualdad de IteradorAlmacenRutasConst
                 * @param otro IderatorAlmacenRutasConst a comparar
                 * @return true si son distintos, false en caso contrario
                 */
                bool operator!=(const IteradorAlmacenRutasConst &it) const;

                /**
                 * @brief sobrecarga del operador de igualdad de IteradorAlmacenRutasConst
                 * @param otro IderatorAlmacenRutasConst a comparar
                 * @return true si son iguales, false en caso contrario
                 */
                bool operator==(const IteradorAlmacenRutasConst &it) const;

                /**
                 * @brief sobrecarga del operador de asignacion de IteradorAlmacenRutasConst
                 * @param otro IteradorAlmacenRutasConst a asignar
                 * @return El objeto del TDA IteradorAlmacenRutasConst que ha sido asignado
                 */
                IteradorAlmacenRutasConst &operator=(const IteradorAlmacenRutasConst &it) = default;

                /**
                 * @brief sobrecarga del operador asterisco de IteradorAlmacenRutaConst
                 * @return La ruta a la que apunta el IteradorAlmacenRuta
                 */
                const Ruta &operator*() const;
                
                /**
                 * @brief sobrecarga del operador de pre-incremento de IteradorAlmacenRutasConst
                 * @return El siguiente objeto IteradorAlmacenRutasConst del TDA AlmacenRutas
                 */ 
                IteradorAlmacenRutasConst &operator++();

                /**
                 * @brief sobrecarga del operador de pre-decremento de IteradorAlmacenRutasConst
                 * @return El anterior objeto IteradorAlmacenRutasConst del TDA AlmacenRutas
                 */ 
                IteradorAlmacenRutasConst &operator--();
        };

         /**
		 * @brief metodo begin de IteradorAlmacenRutaConst
		 * @return devuelve un IteradorAlmacenRutaConst que apunta al comienzo del AlmacenRutas
		 */
        IteradorAlmacenRutasConst cbegin();

        /**
		 * @brief metodo end de IteradorAlmacenRutaConst
		 * @return devuelve un IteradorAlmacenRutaConst que apunta al final del AlmacenRutas
		 */
        IteradorAlmacenRutasConst cend();

        /**
    	 * @brief sobrecarga del operador >>
         * @param is flujo de entrada
         * @param A almacenRutas a "leer"
         * @return el flujo
		 */
        friend istream &operator>>(istream &is, AlmacenRutas &A);

        /**
    	 * @brief sobrecarga del operador <<
         * @param os flujo de salida
         * @param A almacenRutas "escribir"
         * @return el flujo
		 */
        friend ostream &operator<<(ostream &os, const AlmacenRutas &A);
};

#endif