#include "Punto.h"

Punto::Punto()
{
    latitud = 0;
    longitud = 0;
}

Punto::Punto(double lat, double lng)
{
    if(lat <= 90 && lat >= -90)
        latitud = lat;

    if(lng <= 180 && lng >= -180)
        longitud = lng;
}

Punto::Punto(double lat, double lng, string st)
{
    if(lat <= 90 && lat >= -90)
        latitud = lat;

    if(lng <= 180 && lng >= -180)
        longitud = lng;
    
    descripcion = st;
}

Punto::Punto(const Punto & otro)
{
    latitud = otro.latitud;
    longitud = otro.longitud;
}

double Punto::getLatitud() const
{
    return latitud;
}

double Punto::getLongitud() const
{
    return longitud;
}

void Punto::setLatitud(double lat)
{
    if(lat <= 90 && lat >= -90)
        latitud = lat;
}

void Punto::setLongitud(double lng)
{
    if(lng <= 180 && lng >= -180)
        longitud = lng;
}

Punto & Punto::operator=(const Punto & otro)
{
    latitud = otro.latitud;
    longitud = otro.longitud;
    return *this;
}

bool Punto::operator!=(const Punto & otro) const
{
    return (latitud != otro.latitud || longitud != otro.longitud);
}

bool Punto::operator==(const Punto & otro) const
{
    return (latitud == otro.latitud && longitud == otro.longitud);
}

ostream & operator<<(ostream & os, const Punto &P)
{
    os << P.latitud << "," << P.longitud;
    return os;
}

istream & operator>>(istream & is, Punto &P)
{
    double lat, lon;
    char irrelevante;
    is >> lat >> irrelevante >> lon;
    P.setLatitud(lat);
    P.setLongitud(lon);
    return is;
}