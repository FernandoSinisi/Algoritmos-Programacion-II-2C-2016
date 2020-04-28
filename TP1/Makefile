# Constantes globales para la compilacion
EXEC1 = paste
EXEC2 = more
EXEC3 = dc
EXEC4 = strutil
CC = gcc
OBJ = pila.o paste.o more.o dc.o strutil.o
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion 
CFLAGS += -Wshadow -Wpointer-arith -Wunreachable-code
CFLAGS += -Wbad-function-cast -Werror

#Instruccion que se va a ejecutar por default

all: $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4)

#El default que se compila tiene dependencia a los objetos OBJ
#El comando compila los OBJ con CC y CFLAGS resultando el EXEC

	
$(EXEC1): paste.o
	$(CC) $(CFLAGS) paste.c -o $(EXEC1)

$(EXEC2): more.o
	$(CC) $(CFLAGS) more.c -o  $(EXEC2)

$(EXEC3): pila.o strutil.o dc.o 
	$(CC) $(CFLAGS) pila.o strutil.o dc.c -o  $(EXEC3)

$(EXEC4): strutil.o
	$(CC) $(CFLAGS) strutil.c -o $(EXEC4) 


#Todos los objetos definidos en "OBJ=" con dependencia a los archivos .c y .h van a compilarse de la misma manera

%.o: %.c %.h 
	$(CC) $(CFLAGS) -c $<
	
#Borra todos los archivos .o del directorio
clean:
	rm *.o $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4) 

#Make compila unicamente los elementos que se hayan modificado recientemente
	
