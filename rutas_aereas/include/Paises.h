/**
 * @file Paises.h
 * @brief Fichero cabecera de Paises
 */
#ifndef __PAISES_H
#define __PAISES_H

#include "Pais.h"
#include <set>

using namespace std;

/**
 * @brief T.D.A. Paises
 * 
 * Una instancia de Paises contiene un conjunto de objetos del TDA Pais
 */
class Paises
{
private:
	/**
     * Un objeto valido @e rep del TDA Paises representa una estructura de datos no lineal que almacena una serie objetos del TDA Pais
     *  
     * Un objeto valido del TDA Paises debe contener objetos del TDA Pais que sean validos
     */
	set<Pais> datos;

public:
	/**
     * @brief Constructor sin argumentos
     */
	Paises();

	/**
     * @brief Insertar un nuevo Pais
	 * @param P Pais a insertar
     */
	void Insertar(const Pais &P);

	/**
     * @brief Borrar un Pais
	 * @param P Pais a borrar
     */
	void Borrar(const Pais &P);

	/**
     * @brief T.D.A. Iterator
     * 
     * Una instancia @e i del tipo datos abstracto @c Iterator es un objeto
     * que permite recorrer el TDA Paises de forma ordenada
     * Tiene permisos de lectura y escritura
     */
	class iterator
	{
	private:
		/**
		 * @page repConjunto Rep del Iterator
		 * 
		 * Un objeto valido @e rep del TDA Iterator representa una
		 * herramienta para recorrer el TDA Paises de forma ordenada
		 */
		set<Pais>::iterator p;

	public:
		/**
         * @brief Constructor por defecto
         */
		iterator();

		/**
         * @brief sobrecarga del operador de pre-incremento
         * @return El siguiente objeto Iterator de Paises
         */
		iterator &operator++();

		/**
         * @brief sobrecarga del operador de pre-decremento
         * @return El anterior objeto Iterator
         */
		iterator &operator--();

		/**
         * @brief sobrecarga del operador de igualdad
         * @param it Iterator a comparar
         * @return true si son iguales, false en caso contrario
         */
		bool operator==(const iterator &it);

		/**
         * @brief sobrecarga del operador de desigualdad
         * @param it Iterator a comparar
         * @return true si son distintos, false en caso contrario
         */
		bool operator!=(const iterator &it);

		/**
         * @brief sobrecarga del operador asterisco
         * @return El Pais que apunta el Iterator
         */
		const Pais &operator*() const;

		friend class Paises;
		friend class const_iterator;
	};

	/**
     * @brief T.D.A. Const_iterator
     * 
     * Una instancia @e i del tipo datos abstracto @c Const_iterator es un objeto
     * que permite recorrer el TDA Paises de forma ordenada
     * Solo tiene permisos de lectura
     */
	class const_iterator
	{
	private:
		set<Pais>::const_iterator p;

	public:
		/**
         * @brief Constructor por defecto
         */
		const_iterator();

		/**
         * @brief Constructor de copia
         * @param it Const_iterator a copiar
         */
		const_iterator(const iterator &it);

		/**
         * @brief sobrecarga del operador de asignacion
         * @param it Const_iterator a asignar
         * @return El Const_iterator asignado
         */
		const_iterator &operator=(const iterator &it);

		/**
         * @brief sobrecarga del operador de pre-incremento
         * @return El siguiente objeto Const_iterator
         */
		const_iterator &operator++();

		/**
         * @brief sobrecarga del operador de pre-decremento
         * @return El anterior objeto Const_iterator
         */
		const_iterator &operator--();

		/**
         * @brief sobrecarga del operador de igualdad
         * @param it Const_iterator a comparar
         * @return true si son iguales, false en caso contrario
         */
		bool operator==(const const_iterator &it);

		/**
         * @brief sobrecarga del operador de desigualdad
         * @param it Const_iterator a comparar
         * @return true si son distintos, false en caso contrario
         */
		bool operator!=(const const_iterator &it);

		/**
         * @brief sobrecarga del operador asterisco
         * @return El Pais que apunta el Const_iterator
         */
		const Pais &operator*() const;

		friend class Paises;
	};

	/**
     * @brief metodo begin
     * @return devuelve un iterator que apunta al comienzo de Paises
     */
	iterator begin();

	/**
     * @brief metodo begin constante
     * @return devuelve un iterator que apunta al comienzo de Paises
     */
	const_iterator begin() const;

	/**
     * @brief metodo end
     * @return devuelve un iterator que apunta al final de Paises
     */
	iterator end();

	/**
     * @brief metodo end constante
     * @return devuelve un iterator que apunta al final de Paises
     */
	const_iterator end() const;

	/**
     * @brief metodo find a traves de pais
	 * @param p Pais a buscar
     * @return devuelve un iterator que apunta al Pais pasado por parámetro
	 * @note si no se encuentra el pais se devuelve end
     */
	iterator find(const Pais &p);

	/**
     * @brief metodo find a traves de punto
	 * @param p Punto a buscar
     * @return devuelve un iterator que apunta al Pais que contiene el Punto pasado por parametro
	 * @note si no se encuentra el pais con dicho punto se devuelve end
     */
	iterator find(const Punto &p);

	/**
     * @brief sobrecarga del operador >>
     * @param is flujo de entrada
     * @param R son los paises al leer
     * @return el flujo
     */
	friend istream &operator>>(istream &is, Paises &R);

	/**
     * @brief sobrecarga del operador <<
     * @param os flujo de salida
     * @param R paises a escribir
     * @return el flujo
     */
	friend ostream &operator<<(ostream &os, const Paises &R);
};
#endif
