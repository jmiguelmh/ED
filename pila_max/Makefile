BINDIR = ./bin/
INCLDIR = ./include/
OBJDIR = ./obj/
SRCDIR = ./src/
CC = g++
CFLAGS = -Wall -std=c++11 -g -I$(INCLDIR)

all: clean usocolas usopilas usovd uso_Pila_max_Cola uso_Cola_max

usocolas: usocolas.o
	$(CC) $(CFLAGS) -o $(BINDIR)usocolas $(OBJDIR)usocolas.o

usocolas.o:
	$(CC) $(CFLAGS) -c $(SRCDIR)usocolas.cpp -o $(OBJDIR)usocolas.o

usopilas: usopilas.o
	$(CC) $(CFLAGS) -o $(BINDIR)usopilas $(OBJDIR)usopilas.o

usopilas.o:
	$(CC) $(CFLAGS) -c $(SRCDIR)usopilas.cpp -o $(OBJDIR)usopilas.o

usovd: usovd.o vector_dinamico.o
	$(CC) $(CFLAGS) -o $(BINDIR)usovd $(OBJDIR)usovd.o $(OBJDIR)vector_dinamico.o

usovd.o:
	$(CC) $(CFLAGS) -c $(SRCDIR)usovd.cpp -o $(OBJDIR)usovd.o

vector_dinamico.o:
	$(CC) $(CFLAGS) -c $(SRCDIR)vector_dinamico.cpp -o $(OBJDIR)vector_dinamico.o

uso_Pila_max_Cola: uso_Pila_max_Cola.o Pila_max_Cola.o
	$(CC) $(CFLAGS) -o $(BINDIR)uso_Pila_max_Cola $(OBJDIR)uso_Pila_max_Cola.o $(OBJDIR)Pila_max_Cola.o

uso_Pila_max_Cola.o:
	$(CC) $(CFLAGS) -c $(SRCDIR)uso_Pila_max_Cola.cpp -o $(OBJDIR)uso_Pila_max_Cola.o

Pila_max_Cola.o:
	$(CC) $(CFLAGS) -c $(SRCDIR)Pila_max_Cola.cpp -o $(OBJDIR)Pila_max_Cola.o

uso_Pila_max_VD: uso_Pila_max_VD.o Pila_max_VD.o
	$(CC) $(CFLAGS) -o $(BINDIR)uso_Pila_max_VD $(OBJDIR)uso_Pila_max_VD.o $(OBJDIR)Pila_max_VD.o

uso_Pila_max_VD.o:
	$(CC) $(CFLAGS) -c $(SRCDIR)uso_Pila_max_VD.cpp -o $(OBJDIR)uso_Pila_max_VD.o

Pila_max_VD.o:
	$(CC) $(CFLAGS) -c $(SRCDIR)Pila_max_VD.cpp -o $(OBJDIR)Pila_max_VD.o

uso_Cola_max: uso_Cola_max.o Cola_max.o
	$(CC) $(CFLAGS) -o $(BINDIR)uso_Cola_max $(OBJDIR)uso_Cola_max.o $(OBJDIR)Cola_max.o

uso_Cola_max.o:
	$(CC) $(CFLAGS) -c $(SRCDIR)uso_Cola_max.cpp -o $(OBJDIR)uso_Cola_max.o

Cola_max.o:
	$(CC) $(CFLAGS) -c $(SRCDIR)Cola_max.cpp -o $(OBJDIR)Cola_max.o

clean:
	rm -f $(OBJDIR)* $(BINDIR)*