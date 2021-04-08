BINDIR = ./bin/
INCLDIR = ./include/
OBJDIR = ./obj/
SRCDIR = ./src/
DOCDIR = ./doc/doxys/
CC = g++
CFLAGS = -Wall -std=c++11 -g -I$(INCLDIR)

# ************ Compilacion ******************
all: clean rutas_aereas

rutas_aereas: rutas_aereas.o imagen.o imagenES.o Punto.o Ruta.o AlmacenRutas.o Pais.o Paises.o
	$(CC) $(CFLAGS) -o $(BINDIR)rutas_aereas $(OBJDIR)Punto.o $(OBJDIR)Ruta.o $(OBJDIR)AlmacenRutas.o $(OBJDIR)imagen.o $(OBJDIR)imagenES.o $(OBJDIR)rutas_aereas.o  $(OBJDIR)Pais.o $(OBJDIR)Paises.o

rutas_aereas.o:
	$(CC) $(CFLAGS) -c $(SRCDIR)rutas_aereas.cpp -o $(OBJDIR)rutas_aereas.o

imagen.o:
	$(CC) $(CFLAGS) -c $(SRCDIR)imagen.cpp -o $(OBJDIR)imagen.o

imagenES.o:
	$(CC) $(CFLAGS) -c $(SRCDIR)imagenES.cpp -o $(OBJDIR)imagenES.o

Punto.o:
	$(CC) $(CFLAGS) -c $(SRCDIR)Punto.cpp -o $(OBJDIR)Punto.o

Ruta.o:
	$(CC) $(CFLAGS) -c $(SRCDIR)Ruta.cpp -o $(OBJDIR)Ruta.o

AlmacenRutas.o:
	$(CC) $(CFLAGS) -c $(SRCDIR)AlmacenRutas.cpp -o $(OBJDIR)AlmacenRutas.o

Pais.o:
	$(CC) $(CFLAGS) -c $(SRCDIR)Pais.cpp -o $(OBJDIR)Pais.o

Paises.o:
	$(CC) $(CFLAGS) -c $(SRCDIR)Paises.cpp -o $(OBJDIR)Paises.o

# ************ Generación de documentación ******************
documentacion:
	doxygen $(DOCDIR)Doxyfile


# ************ Limpieza ************
clean:
	rm -f $(OBJDIR)* $(BINDIR)*

clean_documentacion:
	rm -rf $(DOCDIR)html $(DOCDIR)latex

clean_imagenes:
	rm -f *.ppm *pgm