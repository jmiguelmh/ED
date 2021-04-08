BINDIR = ./bin/
INCLDIR = ./include/
OBJDIR = ./obj/
SRCDIR = ./src/

CC = g++
CFLAGS = -Wall -std=c++11 -g -I$(INCLDIR)

all: clean negativo umbralizacion_normal umbralizacion_automatica zoom icono contraste_lineal morphing

negativo: negativo.o ImagenES.o
	$(CC) $(CFLAGS) -o $(BINDIR)negativo $(OBJDIR)negativo.o $(OBJDIR)ImagenES.o

umbralizacion_normal: umbralizacion_normal.o ImagenES.o utilidades.o imagen.o
	$(CC) $(CFLAGS) -o $(BINDIR)umbralizacion_normal $(OBJDIR)umbralizacion_normal.o $(OBJDIR)ImagenES.o $(OBJDIR)imagen.o $(OBJDIR)utilidades.o

umbralizacion_automatica: umbralizacion_automatica.o ImagenES.o utilidades.o imagen.o
	$(CC) $(CFLAGS) -o $(BINDIR)umbralizacion_automatica $(OBJDIR)umbralizacion_automatica.o $(OBJDIR)ImagenES.o $(OBJDIR)imagen.o $(OBJDIR)utilidades.o

zoom: zoom.o ImagenES.o utilidades.o imagen.o
	$(CC) $(CFLAGS) -o $(BINDIR)zoom $(OBJDIR)zoom.o $(OBJDIR)ImagenES.o $(OBJDIR)imagen.o $(OBJDIR)utilidades.o

icono: icono.o ImagenES.o utilidades.o imagen.o
	$(CC) $(CFLAGS) -o $(BINDIR)icono $(OBJDIR)icono.o $(OBJDIR)ImagenES.o $(OBJDIR)imagen.o $(OBJDIR)utilidades.o

contraste_lineal: contraste_lineal.o ImagenES.o utilidades.o imagen.o
	$(CC) $(CFLAGS) -o $(BINDIR)contraste_lineal $(OBJDIR)contraste_lineal.o $(OBJDIR)ImagenES.o $(OBJDIR)imagen.o $(OBJDIR)utilidades.o

morphing: morphing.o ImagenES.o utilidades.o imagen.o
	$(CC) $(CFLAGS) -o $(BINDIR)morphing $(OBJDIR)morphing.o $(OBJDIR)ImagenES.o $(OBJDIR)imagen.o $(OBJDIR)utilidades.o
	mkdir imagenes_pgm_ppm/morphing

negativo.o: $(SRCDIR)negativo.cpp
	$(CC) $(CFLAGS) -c $(SRCDIR)negativo.cpp -o $(OBJDIR)negativo.o

umbralizacion_normal.o: $(SRCDIR)umbralizacion_normal.cpp
	$(CC) $(CFLAGS) -c $(SRCDIR)umbralizacion_normal.cpp -o $(OBJDIR)umbralizacion_normal.o

umbralizacion_automatica.o: $(SRCDIR)umbralizacion_automatica.cpp
	$(CC) $(CFLAGS) -c $(SRCDIR)umbralizacion_automatica.cpp -o $(OBJDIR)umbralizacion_automatica.o

zoom.o: $(SRCDIR)zoom.cpp
	$(CC) $(CFLAGS) -c $(SRCDIR)zoom.cpp -o $(OBJDIR)zoom.o

icono.o: $(SRCDIR)icono.cpp
	$(CC) $(CFLAGS) -c $(SRCDIR)icono.cpp -o $(OBJDIR)icono.o

contraste_lineal.o: $(SRCDIR)contraste_lineal.cpp
	$(CC) $(CFLAGS) -c $(SRCDIR)contraste_lineal.cpp -o $(OBJDIR)contraste_lineal.o

morphing.o: $(SRCDIR)morphing.cpp
	$(CC) $(CFLAGS) -c $(SRCDIR)morphing.cpp -o $(OBJDIR)morphing.o

utilidades.o: $(SRCDIR)utilidades.cpp
	$(CC) $(CFLAGS) -c $(SRCDIR)utilidades.cpp -o $(OBJDIR)utilidades.o

imagen.o: $(SRCDIR)imagen.cpp $(INCLDIR)imagen.h
	$(CC) $(CFLAGS) -c $(SRCDIR)imagen.cpp -o $(OBJDIR)imagen.o

ImagenES.o: $(SRCDIR)ImagenES.cpp ./include/ImagenES.h
	$(CC) $(CFLAGS) -c $(SRCDIR)ImagenES.cpp -o $(OBJDIR)ImagenES.o

clean:
	rm -f $(OBJDIR)* $(BINDIR)*
	rm -rf imagenes_pgm_ppm/morphing