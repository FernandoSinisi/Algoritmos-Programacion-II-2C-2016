#include "cola.h"
#include <stdlib.h>

/* Definicion de la estructura de la cola y de los nodos de la cola.  */

typedef struct nodo{
	void* dato;
	struct nodo* siguiente;
}nodo_cola_t;

struct cola {
    nodo_cola_t* primero;
    nodo_cola_t* ultimo;
};

nodo_cola_t* nodo_crear(void* valor);

/* *****************************************************************
 *                    PRIMITIVAS DE LA COLA
 * *****************************************************************/
 
 cola_t* cola_crear(void){
	 cola_t* cola = malloc(sizeof(cola_t));
	 if (cola == NULL) {
        return NULL;
	}
	cola->primero = NULL;
	cola->ultimo = NULL;
	return cola;
}

bool cola_esta_vacia(const cola_t *cola){
	return cola->primero == NULL;
}

void* cola_ver_primero(const cola_t *cola){
	if (cola_esta_vacia(cola)){
		return NULL;
	}
	return cola->primero->dato;
}

bool cola_encolar(cola_t *cola, void* valor){
	nodo_cola_t* nodo_nuevo = nodo_crear(valor);
	if (nodo_nuevo == NULL){
		return false;
	}
	if(cola_esta_vacia(cola)){
		cola->primero = nodo_nuevo;
		cola->ultimo = nodo_nuevo;
		return true;
	}
	cola->ultimo->siguiente = nodo_nuevo;
	cola->ultimo = cola->ultimo->siguiente;
	return true;
}

void* cola_desencolar(cola_t *cola){
	if (cola_esta_vacia(cola)){
		return NULL;
	}
	nodo_cola_t* nodo_eliminar = cola->primero;
	cola->primero = cola->primero->siguiente;
	void* dato = nodo_eliminar->dato;
	free(nodo_eliminar);
	return dato;
}

void cola_destruir(cola_t *cola, void destruir_dato(void*)){
	while(!cola_esta_vacia(cola)){
			void* aux = cola_desencolar(cola);
			if(destruir_dato != NULL){
				destruir_dato(aux);
		}
	}
	free(cola);
}

/* ********* Funcion auxiliar para crear nodo *********** */
		
nodo_cola_t* nodo_crear(void*valor){
	nodo_cola_t* nodo_nuevo = malloc(sizeof(nodo_cola_t));
	if (nodo_nuevo == NULL){
		return NULL;
	}
	nodo_nuevo->dato = valor;
	nodo_nuevo->siguiente = NULL;
	return nodo_nuevo;
}
			


	
		
		
		
	



