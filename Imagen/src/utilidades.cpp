#include "utilidades.h"

Imagen CrearImagenPGM(const char* fichE){
    int filas, columnas;
    byte *pixeles;
    pixeles = LeerImagenPGM(fichE, filas, columnas);
    Imagen img(filas, columnas);
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            img.asigna_pixel(i, j, pixeles[i * img.num_columnas() + j]);
        }
    }
    return img;
}

void CrearArchivoPGM(const Imagen & img, const char *fichS){
    byte *pixeles = new byte[img.num_filas() * img.num_columnas()];
        for(int i = 0; i < img.num_filas(); i++){
            for(int j = 0; j < img.num_columnas(); j++){
                pixeles[i * img.num_columnas() + j] = img.valor_pixel(i, j);
            }
        }

    EscribirImagenPGM(fichS, pixeles, img.num_filas(), img.num_columnas());
}

double calcularMedia(byte* img, int tam){
    double suma = 0;
    for(int i = 0; i < tam; i++)
        suma += img[i];
    
    return (suma / tam);
}

double calcularT(byte* & img1, byte* & img2, int tam1, int tam2){
    return ((calcularMedia(img1, tam1) + calcularMedia(img2, tam2)) / 2);
}

void CalcularSubimagenes(byte* & original, int tam, byte* & sub1, int & tam_sub1, byte* & sub2, int & tam_sub2, double T){
    int contador_sub1, contador_sub2;
    contador_sub1 = contador_sub2 = 0;

    for(int i = 0; i < tam; i++)
            if(original[i] <= T)
                contador_sub1++;
            else
                contador_sub2++;

    sub1 = new byte[contador_sub1];
    sub2 = new byte[contador_sub2]; 
    tam_sub1 = contador_sub1;
    tam_sub2 = contador_sub2;   
    contador_sub1 = contador_sub2 = 0;      
    
    for(int i = 0; i < tam; i++)
        if(original[i] <= T){
            sub1[contador_sub1] = original[i];
            contador_sub1++;
        }
        else{
            sub2[contador_sub2] = original[i];
            contador_sub2++;
        }
   
}

void calcular_valores(Imagen & img, int & min, int & max){
    min = max = img.valor_pixel(0,0);
    for(int i = 0; i < img.num_filas(); i++){
        for(int j = 0; j < img.num_columnas(); j++){
            if(min > img.valor_pixel(i,j))
                min = img.valor_pixel(i,j);
            if(max < img.valor_pixel(i,j))
                max = img.valor_pixel(i,j);
        }      
    }
        
}

void umbralizar_escala_grises(const char *fichE, const char *fichS, byte T_1, byte T_2){
    assert( T_1 < T_2 );
    TipoImagen tipo = LeerTipoImagen(fichE);
    assert(tipo == TipoImagen::IMG_PGM);
    Imagen img = CrearImagenPGM(fichE);

    for(int i = 0; i < img.num_filas(); i++){
        for(int j = 0; j < img.num_columnas(); j++){
            if(img.valor_pixel(i, j) < T_1 || img.valor_pixel(i, j) > T_2)
                img.asigna_pixel(i, j, 255);
            else
                img.asigna_pixel(i, j, 0);
        }
    }

    CrearArchivoPGM(img, fichS);
}

void umbralizar_automatica(const char *fichE, const char *fichS){
    TipoImagen tipo = LeerTipoImagen(fichE);
    assert(tipo == TipoImagen::IMG_PGM);
    Imagen img = CrearImagenPGM(fichE);
    const double EPSILON = 0.1;

    byte* porencima;
    int tencima = 0;
    byte* pordebajo;
    int tdebajo = 0;
    int tam = img.num_filas() * img.num_columnas();
    byte* completa = new byte[tam];

    for(int i = 0; i < img.num_filas(); i++){
        for(int j = 0; j < img.num_columnas(); j++){
            completa[i * img.num_columnas() + j] = img.valor_pixel(i,j);
        }
    }

    double T = calcularMedia(completa,tam);
    double Tanterior;      
    
    do{
        Tanterior = T;
        CalcularSubimagenes(completa, tam, porencima, tencima, pordebajo, tdebajo, T);
        T = calcularT(porencima, pordebajo, tencima, tdebajo);
    } while(abs(T - Tanterior) > EPSILON);

    umbralizar_escala_grises(fichE, fichS, 0, T);
}

void zoom(const char *fichE, const char *fichS, int x_1, int y_1, int x_2, int y_2){
    TipoImagen tipo = LeerTipoImagen(fichE);
    assert(tipo == TipoImagen::IMG_PGM);
    Imagen img = CrearImagenPGM(fichE);
    assert(0 <= x_1 && x_1 < x_2 && x_2 < img.num_columnas() && 0 <= y_1 && y_1 < y_2 && y_2 < img.num_filas() && (x_2 - x_1) == (y_2 - y_1));

    int N = x_2 - x_1;
    int tam_zoom = 2*N-1;
    Imagen zoom_final(tam_zoom, tam_zoom);
    int fils = 0, cols = 0;

    //rellenamos el grid intermitentemente (solo con is y js pares)
    for(int i = 0; i < tam_zoom; i++){
        for (int j = 0; j < tam_zoom; j++){
            if((i % 2) == 0 && (j % 2) == 0){
                zoom_final.asigna_pixel(i, j, img.valor_pixel(fils + x_1, cols + y_1));
                cols++;
            }
        }
        if(i % 2 == 0){
            fils++;
            cols = 0;
        }
        
    }

    //Interpolamos columnas
    for(int i = 0; i < tam_zoom; i += 2){
        for (int j = 0; j < tam_zoom; j++){
            if((j % 2) == 1){
                byte media = (zoom_final.valor_pixel(i, j-1) + zoom_final.valor_pixel(i, j+1)) / 2;
                zoom_final.asigna_pixel(i,j,media);
            }
        }
    }

    //Interpolamos filas
    for(int i = 1; i < tam_zoom; i += 2){
        for (int j = 0; j < tam_zoom; j++){
            byte media = (zoom_final.valor_pixel(i-1, j) + zoom_final.valor_pixel(i+1, j)) / 2;
            zoom_final.asigna_pixel(i,j,media);
        }
    }
    
    CrearArchivoPGM(zoom_final, fichS);
}

void icono(const char *fichE, const char *fichS, int nf, int nc){
    TipoImagen tipo = LeerTipoImagen(fichE);
    assert(tipo == TipoImagen::IMG_PGM);
    Imagen img = CrearImagenPGM(fichE);
    assert(img.num_filas() % nf == 0 && img.num_columnas() % nc == 0);

    int subfilas = img.num_filas() / nf;
    int subcolumnas = img.num_columnas() / nc;
    Imagen aux(nf, nc);
    int suma;
    
    for(int i=0; i<nf; i++){
        for(int j=0; j<nc ; j++){
            suma = 0;
            for(int k=0; k<subfilas; k++){
                for(int l=0; l<subcolumnas; l++){
                    suma += img.valor_pixel(i*subfilas + k, j*subcolumnas + l);
                }
            }
            aux.asigna_pixel(i, j, suma /(subfilas * subcolumnas));
        }
    }

    CrearArchivoPGM(aux, fichS);
}

void contraste_lineal(const char* fichE, const char* fichS, int min, int max){
    TipoImagen tipo = LeerTipoImagen(fichE);
    assert(tipo == TipoImagen::IMG_PGM);
    assert(min >= 0 && max <= 255);
    Imagen img = CrearImagenPGM(fichE);

    int minimo_imagen, maximo_imagen;
    calcular_valores(img, minimo_imagen, maximo_imagen);
    double constante = ((double) max - (double) min) / ((double) maximo_imagen - (double) minimo_imagen);

    for(int i = 0; i < img.num_filas(); i++){
        for(int j = 0; j < img.num_columnas(); j++){
            byte valor = img.valor_pixel(i,j);
            img.asigna_pixel(i,j, min + (constante * (valor - minimo_imagen)));
        }
    }

    CrearArchivoPGM(img, fichS);
}

void morphing(const char *fich_orig, const char *fich_rdo, vector<string> fich_intermedios){
    TipoImagen tipo_fich_orig = LeerTipoImagen(fich_orig);
    TipoImagen tipo_fich_rdo = LeerTipoImagen(fich_rdo);
    assert(tipo_fich_orig == TipoImagen::IMG_PGM && tipo_fich_rdo == TipoImagen::IMG_PGM);

    Imagen img_orig = CrearImagenPGM(fich_orig);
    Imagen img_rdo = CrearImagenPGM(fich_rdo);
    assert(img_orig.num_filas() == img_rdo.num_filas() && img_orig.num_columnas() == img_rdo.num_columnas());
    int iter=0;

    const char *fich = fich_intermedios[iter].c_str();
    CrearArchivoPGM(img_orig,fich);
    iter++;

    while(img_orig != img_rdo){
        for(int i = 0; i < img_orig.num_filas(); i++){
            for(int j = 0; j < img_orig.num_columnas(); j++){
                if(img_orig.valor_pixel(i,j) < img_rdo.valor_pixel(i,j)){
                    img_orig.asigna_pixel(i,j,img_orig.valor_pixel(i,j) + 1);
                }
                if(img_orig.valor_pixel(i,j) > img_rdo.valor_pixel(i,j)){
                    img_orig.asigna_pixel(i,j,img_orig.valor_pixel(i,j) - 1);
                }
            }
        }

        const char *fich = fich_intermedios[iter].c_str();
        CrearArchivoPGM(img_orig,fich);
        iter++;
    }
}