/**
 * @file Punto.h
 * @brief Fichero cabecera de Punto
 * @author Jose Miguel Marquez Herreros y Alejandro Pérez Argüello
 * @date 8 Enero, 2021
 */
#ifndef __PUNTO_H
#define __PUNTO_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/**
 * @brief T.D.A. Punto
 * 
 * Una instancia de punto contiene dos valores de tipo double representando una latitud y una longitud, y un string con una descripción opcional
 */
class Punto{
private:
    /**
     * Un objeto valido @e rep del TDA Punto representa una 
     * estructura de datos no lineal que almacena una localización
     *  
     * Un objeto valido del TDA Punto debe incluir coordenadas válidas
     */
    double latitud, longitud;
    string descripcion;

public:
    /**
     * @brief Constructor sin argumentos
     */
    Punto();

    /**
     * @brief Constructor con parametros latitud y longitud
     * @param lat latitud
     * @param lng longitud
     */
    Punto(double lat, double lng);

    /**
     * @brief Constructor con parametros latitud y longitud y descripción
     * @param lat latitud
     * @param lng longitud
     * @param st string asociado. Es una "descripción"
     */
    Punto(double lat, double lng, string st);

    /**
     * @brief Constructor por copia
     * @param otro Punto a copiar
     */
    Punto(const Punto & otro);

    /**
     * @brief destructor por defecto 
     */
    ~Punto() = default;

    /**
     * @brief Consultor para la latitud
     * @return La latitud
     */
    double getLatitud() const;

    /**
     * @brief Consultor para la longitud
     * @return La longitud
     */
    double getLongitud() const;

    /**
     * @brief Modificador para la latitud 
     * @param lat latitud nueva
     */
    void setLatitud(double lat);

    /**
     * @brief Modificador para la longitud
     * @param lng longitud nueva
     */
    void setLongitud(double lng);

    /**
     * @brief sobrecarga del operador =
     * @param otro Punto a copiar
     * @return puntero a this
     */
    Punto & operator=(const Punto & otro);

    /**
     * @brief sobrecarga del operador !=
     * @param otro Punto a comparar
     * @return true si son diferentes, false otherwise
     */
    bool operator!=(const Punto & otro) const;

    /**
     * @brief sobrecarga del operador ==
     * @param otro Punto a comparar
     * @return false si son diferentes, true otherwise
     */
    bool operator==(const Punto & otro) const;

    /**
     * @brief sobrecarga del operador <<
     * @param os flujo de salida
     * @param P punto a "escribir"
     * @return el flujo
     */
    friend ostream & operator<<(ostream & os, const Punto &P);
    
    /**
     * @brief sobrecarga del operador >>
     * @param is flujo de entrada
     * @param P punto a "leer"
     * @return el flujo
     */
    friend istream & operator>>(istream & is, Punto &P);
};

#endif