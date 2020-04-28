#include "cola.h"
#include "testing.h"
#include <stddef.h>
#include <stdlib.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

/*Pruebas con cola vacia*/

void prueba_cola_vacia(){
	cola_t* cola = cola_crear();
	int i = 10;
	print_test("Crear cola vacia" ,cola_esta_vacia(cola));
	print_test("Ver primero en cola vacia" , cola_ver_primero(cola) == NULL);
	print_test("Desencolar en cola vacia" , cola_desencolar(cola) == NULL);
	cola_encolar(cola,&i);
	bool dato = cola_encolar(cola,&i);
	print_test("Encolar en cola vacia " , dato);
	int* valor = cola_ver_primero(cola);
	print_test("Encolar 1 elemento y ver primero en cola vacia " , *valor == 10);
	cola_destruir(cola,NULL);
	print_test("La cola fue destruida sin funcion destruir" , true);
}

/*Prueba que la funcion cola_esta_vacia funcione correctamente*/

void prueba_cola_esta_vacia(){
	cola_t* cola = cola_crear();
	int vector[100];
	for(int i = 0; i<100; i++){
		vector[i]=i;
		cola_encolar(cola,&vector[i]);
	}
	print_test("Encolados 100 elementos no esta vacia" , !cola_esta_vacia(cola));
	for(int i = 99; i>=0; i--){
		cola_desencolar(cola);
		if (i==49){
			print_test("Desencolados 50 elementos no esta vacia" , !cola_esta_vacia(cola));
		}
	}
	print_test("Desencolados 100 elementos esta vacia" , cola_esta_vacia(cola));
	cola_destruir(cola,NULL);
	print_test("La cola fue destruida sin funcion destruir" , true);	
}	
/* Prueba que la cola funcione con gran volumen. */ 

void prueba_cola_ver_primero(){
	cola_t* cola = cola_crear();
	int vector[10000];
	for (int i = 0 ; i<10000 ; i++){
		vector[i] = i;
		cola_encolar(cola,&vector[i]);
		if(i == 4999){
			int *j = cola_ver_primero(cola);
			print_test("Prueba ver primero 5000 elementos encolados" ,  *j == 0);
			print_test("Prueba esta vacia 5000 elementos encolados" ,!cola_esta_vacia(cola));
		}
	}
	int* k = cola_ver_primero(cola); 
	print_test("Prueba ver primero 10000 elementos encolados" , *k == 0);
	for (int i = 9999 ; i>=0 ; i--){
		cola_desencolar(cola);
		if (i == 2499){
			int* l = cola_ver_primero(cola);
			print_test("Prueba ver primero 2500 elementos luego de desencolar" , *l == 7501);
		}
	}
	print_test("Prueba ver primero luego de desencolar todo" , cola_ver_primero(cola) == NULL);
	print_test("Prueba esta vacia luego de desencolar todo" , cola_esta_vacia(cola));
	cola_destruir(cola,NULL);
	print_test("La cola fue destruida" , true);
}

/* prueba que las funciones encolar y desencolar funcionen correctamente */
	
void prueba_cola_encolar_desencolar(){
	cola_t* cola = cola_crear();
	int i = 5;
	double j = 3.14;
	char k = 'c';
	char l[] = "fernando";
	cola_encolar(cola,&i);
	int* valor_1 = cola_ver_primero(cola);
	int* valor_2 = cola_desencolar(cola);
	print_test("Prueba cola encolar 1 elemento" , *valor_1 == 5);
	print_test("Prueba cola desencolar 1 elemento" , *valor_2 == 5);
	print_test("Prueba cola desencolar pila vacia" , cola_desencolar(cola) == NULL);
	cola_encolar(cola,&i);
	cola_encolar(cola,&j);
	cola_encolar(cola,&k);
	cola_encolar(cola,l);
	int* entero = cola_ver_primero(cola); 
	print_test("Prueba cola encolar en orden" , *entero == 5);
	int* v = cola_desencolar(cola);
	double* s = cola_desencolar(cola);
	char* t = cola_desencolar(cola);
	char* r = cola_desencolar(cola);
	print_test("Prueba cola encolar desencolar en orden" ,*r == *l && *t =='c' && *s == 3.14 && *v == 5);
	cola_destruir(cola,NULL);
	print_test("La cola fue destruida" , true);
}

/* prueba funcion destruir dato por parametro */

void destruir_dato(void* dato){
	free(dato);
}
	
	
void prueba_cola_destruir_dato(){
	cola_t* cola = cola_crear();
	int* entero = malloc(sizeof(int));
	char* caracter = malloc(sizeof(char));
	*caracter = 'c';
	*entero = 5;
	print_test("Cola fue creada", cola != NULL);
	cola_encolar(cola,entero);
	cola_encolar(cola,caracter);
	cola_destruir(cola,destruir_dato);
	print_test("La cola fue destruida con funcion auxiliar" , true);
}
	
	

void pruebas_cola_alumno() {
    cola_t* cola = NULL;
    print_test("Puntero a cola inicializado a NULL", cola == NULL);
    prueba_cola_vacia();
    prueba_cola_esta_vacia();
    prueba_cola_ver_primero();
    prueba_cola_encolar_desencolar();
    prueba_cola_destruir_dato();
 }
	


