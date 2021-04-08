#include "Paises.h"

Paises::Paises() = default;

void Paises::Insertar(const Pais &P)
{
    datos.insert(P);
}

void Paises::Borrar(const Pais &P)
{
    datos.erase(P);
}

Paises::iterator::iterator() = default;

Paises::iterator & Paises::iterator::operator++()
{
    ++p;
    return *this;
}

Paises::iterator & Paises::iterator::operator--()
{
    --p;
    return *this;
}

bool Paises::iterator::operator==(const iterator &it)
{
    return it.p == p;
}

bool Paises::iterator::operator!=(const iterator &it)
{
    return it.p != p;
}

const Pais & Paises::iterator::operator*() const
{
    return *p;
}

Paises::const_iterator::const_iterator() = default;

Paises::const_iterator::const_iterator(const iterator &it)
{
    p = it.p;
}

Paises::const_iterator & Paises::const_iterator::operator=(const iterator &it)
{
    p = it.p;
    return *this;
}

Paises::const_iterator & Paises::const_iterator::operator++()
{
    ++p;
    return *this;
}

Paises::const_iterator & Paises::const_iterator::operator--()
{
    --p;
    return *this;
}

bool Paises::const_iterator::operator==(const const_iterator &it)
{
    return it.p == p;
}

bool Paises::const_iterator::operator!=(const const_iterator &it)
{
    return it.p != p;
}

const Pais & Paises::const_iterator::operator*() const
{
    return *p;
}

Paises::iterator Paises::begin()
{
    iterator it;
    it.p = datos.begin();
    return it;
}

Paises::const_iterator Paises::begin() const
{
    const_iterator it;
    it.p = datos.begin();
    return it;
}

Paises::iterator Paises::end()
{
    iterator it;
    it.p = datos.end();
    return it;
}

Paises::const_iterator Paises::end() const
{
    const_iterator it;
    it.p = datos.end();
    return it;
}

Paises::iterator Paises::find(const Pais &p)
{
    iterator it;
    set<Pais>::iterator i;
    for (i = datos.begin(); i != datos.end() && !((*i) == p); ++i)
        ;
    it.p = i;
    return it;
}

Paises::iterator Paises::find(const Punto &p)
{
    iterator it;
    set<Pais>::iterator i;
    for (i = datos.begin(); i != datos.end() && !((*i).GetPunto() == p); ++i)
        ;
    it.p = i;
    return it;
}

istream & operator>>(istream &is, Paises &R)
{
    Paises rlocal;
    //leemos el comentario
    if (is.peek() == '#')
    {
        string a;
        getline(is, a);
    }

    Pais P;
    while (is >> P)
    {
        rlocal.Insertar(P);
    }
    R = rlocal;
    return is;
}

ostream & operator<<(ostream &os, const Paises &R)
{

    Paises::const_iterator it;
    for (it = R.begin(); it != R.end(); ++it)
    {
        os << *it << "\t";
    }
    return os;
}