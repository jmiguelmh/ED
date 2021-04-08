#include "imagen.h"
#include <cassert>

void Imagen::reservar(int f, int c){
    assert(f > 0 && c > 0);
    filas = f;
    cols = c;
    img = new byte*[filas];
    for(int i = 0; i < filas; i++)
        img[i] = new byte[cols];
}

void Imagen::liberar(){
    for(int i = 0; i < filas; i++)
        delete[] img[i];
    delete[] img;
}

Imagen::Imagen(){
    reservar(256,256);
}

Imagen::Imagen(const Imagen & i){
    *this = i;
}



Imagen::Imagen(int f, int c){
    reservar(f,c);
}

Imagen::~Imagen(){
    liberar();
}

int Imagen::num_filas() const{
    return filas;
}

int Imagen::num_columnas() const{
    return cols;
}

void Imagen::asigna_pixel(int f, int c, byte valor){
    assert(f >= 0 && f < filas && c >= 0 && c < cols);
    img[f][c] = valor;
}



byte Imagen::valor_pixel(int f, int c) const{
    assert(f >= 0 && f < filas && c >= 0 && c < cols);
    return img[f][c];
}

Imagen & Imagen::operator=(const Imagen & image){
    if(&image != this){
        if(filas != image.filas || cols != image.cols){
            liberar();
            reservar(image.filas, image.cols);
        }
        for(int i = 0; i < filas; i++){
            for(int j = 0; j < cols; j++){
                img[i][j] = image.img[i][j];
            }
        }
    }

    return *this; 
}

bool Imagen::operator==(const Imagen & image){
    bool resultado = true;
    if(&image != this){
        resultado = false;
        if(filas == image.filas || cols == image.cols){
            resultado=true;
            for(int i=0; i<filas; i++)
                for(int j=0; j<cols; j++)
                    if(img[i][j] != image.img[i][j])
                        resultado = false;
        }
    }

    return resultado;
}

bool Imagen::operator!=(const Imagen & image){
    return !(*this == image);
}