#include "Ruta.h"

Ruta::Ruta()
{
    numPuntos = 0;
}

Ruta::Ruta(const Ruta & otro)
{
    nombre = otro.nombre;
    numPuntos = otro.numPuntos;
    puntos = otro.puntos;
}

string Ruta::getNombre() const
{
    return nombre;
}

Ruta & Ruta::operator=(const Ruta & otro)
{
    nombre = otro.nombre;
    numPuntos = otro.numPuntos;
    puntos = otro.puntos;
    return *this;
}

void Ruta::aniadirPunto(const Punto & punto)
{
    numPuntos++;
    puntos.push_back(punto);
}

void Ruta::eliminarUltimoPunto()
{
    if(numPuntos > 0)
    {
        numPuntos--;
        puntos.pop_back();
    }
}

Ruta::IteradorRuta::IteradorRuta() = default;

Ruta::IteradorRuta::IteradorRuta(const IteradorRuta & it) = default;

Ruta::IteradorRuta::~IteradorRuta() = default;

bool Ruta::IteradorRuta::operator!=(const IteradorRuta & it) const
{
    return this->iterador != it.iterador;
}

bool Ruta::IteradorRuta::operator==(const IteradorRuta & it) const
{
    return this->iterador == it.iterador;
}

Ruta::IteradorRuta & Ruta::IteradorRuta::operator=(const IteradorRuta & it) = default;

Punto & Ruta::IteradorRuta::operator*()
{
    return *iterador;
}

Ruta::IteradorRuta & Ruta::IteradorRuta::operator++()
{
    ++iterador;
    return *this;
}

Ruta::IteradorRuta & Ruta::IteradorRuta::operator--()
{
    --iterador;
    return *this;
}

Ruta::IteradorRuta Ruta::begin()
{
    IteradorRuta it;
    it.iterador = puntos.begin();
    return it;
}

Ruta::IteradorRuta Ruta::end()
{
    IteradorRuta it;
    it.iterador = puntos.end();
    return it;
}

Ruta::IteradorRutaConst::IteradorRutaConst() = default;

Ruta::IteradorRutaConst::IteradorRutaConst(const IteradorRutaConst & it) = default;

Ruta::IteradorRutaConst::~IteradorRutaConst() = default;

bool Ruta::IteradorRutaConst::operator!=(const IteradorRutaConst & it) const
{
    return this->iterador_constante != it.iterador_constante;
}

bool Ruta::IteradorRutaConst::operator==(const IteradorRutaConst & it) const
{
    return this->iterador_constante == it.iterador_constante;
}

Ruta::IteradorRutaConst & Ruta::IteradorRutaConst::operator=(const IteradorRutaConst & it) = default;

const Punto & Ruta::IteradorRutaConst::operator*() const
{
    return *iterador_constante;
}

Ruta::IteradorRutaConst & Ruta::IteradorRutaConst::operator++()
{
    ++iterador_constante;
    return *this;
}

Ruta::IteradorRutaConst & Ruta::IteradorRutaConst::operator--()
{
    --iterador_constante;
    return *this;
}

Ruta::IteradorRutaConst Ruta::begin() const
{
    IteradorRutaConst it;
    it.iterador_constante = puntos.cbegin();
    return it;
}

Ruta::IteradorRutaConst Ruta::end() const
{
    IteradorRutaConst it;
    it.iterador_constante = puntos.cend();
    return it;
}

istream & operator>>(istream & is, Ruta & R){
    char irrelevante;
    int numPuntos;
    is >> R.nombre >> numPuntos;
    for(int i=0; i<numPuntos; i++){
        Punto aux;
        is >> irrelevante;
        is >> aux;
        is >> irrelevante;
        R.aniadirPunto(aux);
    }

    return is;
}

ostream & operator<<(ostream & os, const Ruta & R){
    os << R.nombre << " " << R.numPuntos << " ";
    for(int i = 0; i < R.numPuntos; i++){
        os << "(" << R.puntos[i] << ")"<<" ";
    }
    return os;
}