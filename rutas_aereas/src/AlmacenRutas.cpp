#include "AlmacenRutas.h"

AlmacenRutas::AlmacenRutas()
{
    numRutas = 0;
}

AlmacenRutas::AlmacenRutas(const AlmacenRutas &otro)
{
    numRutas = otro.numRutas;
    rutas = otro.rutas;
}

AlmacenRutas & AlmacenRutas::operator=(const AlmacenRutas &otro)
{
    numRutas = otro.numRutas;
    rutas = otro.rutas;
    return *this;
}

Ruta AlmacenRutas::GetRuta(string codigo) const
{
    Ruta aux(rutas[0]);
    for(int i=0; i<numRutas; i++){
        if(rutas[i].getNombre() == codigo){
            aux = rutas[i];
        }
    }
    return aux;
}

void AlmacenRutas::aniadirRuta(const Ruta &ruta)
{
    numRutas++;
    rutas.push_back(ruta);
}

bool AlmacenRutas::IteradorAlmacenRutas::operator!=(const IteradorAlmacenRutas &it) const
{
    return this->iterador != it.iterador;
}

bool AlmacenRutas::IteradorAlmacenRutas::operator==(const IteradorAlmacenRutas &it) const
{
    return this->iterador == it.iterador;
}

Ruta & AlmacenRutas::IteradorAlmacenRutas::operator*()
{
    return *iterador;
}

AlmacenRutas::IteradorAlmacenRutas & AlmacenRutas::IteradorAlmacenRutas::operator++()
{
    ++iterador;
    return *this;
}

AlmacenRutas::IteradorAlmacenRutas & AlmacenRutas::IteradorAlmacenRutas::operator--()
{
    --iterador;
    return *this;
}

AlmacenRutas::IteradorAlmacenRutas AlmacenRutas::begin()
{
    IteradorAlmacenRutas it;
    it.iterador = rutas.begin();
    return it;
}

AlmacenRutas::IteradorAlmacenRutas AlmacenRutas::end()
{
    IteradorAlmacenRutas it;
    it.iterador = rutas.end();
    return it;
}

bool AlmacenRutas::IteradorAlmacenRutasConst::operator!=(const IteradorAlmacenRutasConst &it) const
{
    return this->iterador_constante != it.iterador_constante;
}

bool AlmacenRutas::IteradorAlmacenRutasConst::operator==(const IteradorAlmacenRutasConst &it) const
{
    return this->iterador_constante == it.iterador_constante;
}

const Ruta & AlmacenRutas::IteradorAlmacenRutasConst::operator*() const
{
    return *iterador_constante;
}

AlmacenRutas::IteradorAlmacenRutasConst & AlmacenRutas::IteradorAlmacenRutasConst::operator++()
{
    ++iterador_constante;
    return *this;
}

AlmacenRutas::IteradorAlmacenRutasConst & AlmacenRutas::IteradorAlmacenRutasConst::operator--()
{
    --iterador_constante;
    return *this;
}

AlmacenRutas::IteradorAlmacenRutasConst AlmacenRutas::cbegin()
{
    IteradorAlmacenRutasConst it;
    it.iterador_constante = rutas.cbegin();
    return it;
}

AlmacenRutas::IteradorAlmacenRutasConst AlmacenRutas::cend()
{
    IteradorAlmacenRutasConst it;
    it.iterador_constante = rutas.cend();
    return it;
}

istream &operator>>(istream &is, AlmacenRutas &A)
{
    string magic;
    is >> magic;
    if (magic == "#Rutas")
    {
        A.numRutas = 0;
        while (!is.eof())
        {
            Ruta aux;
            is >> aux;
            A.aniadirRuta(aux);
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const AlmacenRutas &A)
{
    os << "#Rutas\n";
    for (int i = 0; i < A.numRutas; i++)
    {
        os << A.rutas[i] << "\n";
    }
    return os;
}