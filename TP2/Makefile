# Constantes globales para la compilacion
EXEC1 = uniq-count
EXEC2 = comm
EXEC3 = heap_utils 
CC = gcc
OBJ = pila.o unic-count.o comm.o heap-utils.o strutil.o hash.o lista.o vector_dinamico.o top_k.o prueba_top_k.o
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion 
CFLAGS += -Wshadow -Wpointer-arith -Wunreachable-code
CFLAGS += -Wbad-function-cast -Werror -pedantic


#Instruccion que se va a ejecutar por default

all: $(EXEC1) $(EXEC2) $(EXEC3)

#El default que se compila tiene dependencia a los objetos OBJ
#El comando compila los OBJ con CC y CFLAGS resultando el EXEC

	
$(EXEC1): hash.o pila.o strutil.o lista.o uniq-count.o
	$(CC) $(CFLAGS) hash.o pila.o strutil.o lista.o uniq-count.c -o  $(EXEC1)

$(EXEC2): comm.o hash.o lista.o strutil.o pila.o
	$(CC) $(CFLAGS) lista.o strutil.o pila.o hash.o comm.c -o  $(EXEC2)

$(EXEC3): heap_utils.o vector_dinamico.o heap.o pruebas.o
	$(CC) $(CFLAGS) vector_dinamico.o heap.o heap_utils.o pruebas.c -o  $(EXEC3)


#Todos los objetos definidos en "OBJ=" con dependencia a los archivos .c y .h van a compilarse de la misma manera

%.o: %.c %.h 
	$(CC) $(CFLAGS) -c $<
	
#Borra todos los archivos .o del directorio
clean:
	rm *.o $(EXEC1) $(EXEC2) $(EXEC3) 

#Make compila unicamente los elementos que se hayan modificado recientemente
	
