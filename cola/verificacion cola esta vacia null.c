#include "cola.h"
#include <stdlib.h>
#include <stdio.h>


/* Definicion de la estructura de la cola y de los nodos de la cola.  */

typedef struct nodo{
	void* dato;
	struct nodo* siguiente;
}nodo_cola_t;

struct cola {
    nodo_cola_t* primero;
    nodo_cola_t* ultimo;
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA COLA
 * *****************************************************************/
 
 cola_t* cola_crear(void){
	 cola_t* cola = malloc(sizeof(cola_t));
	 if (cola == NULL) {
        return NULL;
	}
	cola->primero = malloc(sizeof(nodo_cola_t));
	cola->ultimo = malloc(sizeof(nodo_cola_t));
	if (cola->primero == NULL || cola->ultimo == NULL){
		free(cola);
		return NULL;
	}
	return cola;
}

bool cola_esta_vacia(const cola_t *cola){
	if (cola->primero->dato == NULL){
		return false;
	}
	return true;
}


int main(void){
	cola_t *cola = cola_crear();
	if (cola_esta_vacia(cola)){
		printf(" esta vacia entro bien devuelve null\n");
	}
	else{
		printf("no pone null en algo vacio\n");
	}
	void* devol = cola->primero->dato;
	printf("%p",devol); 
	return 0;
}
