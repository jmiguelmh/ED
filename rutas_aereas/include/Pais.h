/**
 * @file Pais.h
 * @brief Fichero cabecera de Pais
 */
#ifndef __PAIS_H
#define __PAIS_H

#include "Punto.h"

/**
 * @brief T.D.A. Pais
 * 
 * Una instancia de pais contiene un valor de tipo Punto que indica la localizacion, un string que contiene el nombre del pais y otro string que contiene la bandera
 */
class Pais
{
private:
    /**
     * Un objeto valido @e rep del TDA Pais representa una 
     * estructura de datos no lineal que almacena toda la informacion necesaria para representar a un determinado pais
     *  
     * Un objeto valido del TDA Pais debe tener un Punto no nulo con coordenadas validas, un nombre que no sea nulo y una bandera no nula
     */
    Punto p;
    string pais;
    string bandera;

public:
    /**
     * @brief Constructor sin argumentos
     */
    Pais();

    /**
     * @brief Consultor de punto
     * @return El punto
     */
    Punto GetPunto() const;

    /**
     * @brief Consultor de Pais
     * @return El nombre del Pais
     */
    string GetPais() const;

    /**
     * @brief Consultor de bandera
     * @return La bandera
     */
    string GetBandera() const;

    /**
     * @brief sobrecarga del operador <
     * @param P Pais a comparar
     * @return true si this es menor que P, false en el caso contrario
     */
    bool operator<(const Pais &P) const;

    /**
     * @brief sobrecarga del operador ==
     * @param P Pais a comparar
     * @return true si son iguales, false en el caso contrario
     */
    bool operator==(const Pais &P) const;

    /**
     * @brief sobrecarga del operador !=
     * @param P Pais a comparar
     * @return true si son distintos, false en el caso contrario
     */
    bool operator!=(const Punto &P) const;

    /**
     * @brief sobrecarga del operador >>
     * @param is flujo de entrada
     * @param P pais a "leer"
     * @return el flujo
     */
    friend istream &operator>>(istream &is, Pais &P);

    /**
     * @brief sobrecarga del operador <<
     * @param os flujo de salida
     * @param P pais a "escribir"
     * @return el flujo
     */
    friend ostream &operator<<(ostream &os, const Pais &P);
};
#endif