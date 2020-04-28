#include "pila.h"
#include "testing.h"
#include <stddef.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

/*Pruebas con pila vacia*/

void prueba_pila_vacia(){
	pila_t* pila = pila_crear();
	int i = 8;
	print_test("Crear pila vacia" ,pila_esta_vacia(pila) == true);
	print_test("Ver tope en pila vacia" , pila_ver_tope(pila) == NULL);
	print_test("Desapilar en pila vacia" , pila_desapilar(pila) == NULL);
	pila_apilar(pila,&i);
	int* valor = pila_ver_tope(pila);
	print_test("Apilar 1 elemento en pila vacia " , *valor == 8);
	pila_destruir(pila);
	print_test("La pila fue destruida" , true);
}

/*Prueba que la funcion pila_esta_vacia funcione correctamente*/

void prueba_pila_esta_vacia(){
	pila_t* pila = pila_crear();
	int vector[100];
	for(int i = 0; i<100; i++){
		vector[i]=i;
		pila_apilar(pila,&vector[i]);
	}
	print_test("Apilados 100 elementos no esta vacia" , !pila_esta_vacia(pila) == true);
	for(int i = 99; i>=0; i--){
		pila_desapilar(pila);
		if (i==49){
			print_test("Desapilados 50 elementos no esta vacia" , !pila_esta_vacia(pila) == true);
		}
	}
	print_test("Desapilados 100 elementos esta vacia" , pila_esta_vacia(pila) == true);
	pila_destruir(pila);
	print_test("La pila fue destruida" , true);		
}	
/*Prueba que la pila funcione con gran volumen. */

void prueba_pila_ver_tope(){
	pila_t* pila = pila_crear();
	int vector[10000];
	for (int i = 0 ; i<10000 ; i++){
		vector[i] = i;
		pila_apilar(pila,&vector[i]);
		if(i == 4999){
			int *j = pila_ver_tope(pila);
			print_test("Prueba ver tope 5000 elementos apilados" ,  *j == 4999);
		}
	}
	int* k = pila_ver_tope(pila); 
	print_test("Prueba ver tope 10000 elementos apilados" , *k == 9999);
	for (int i = 9999 ; i>=0 ; i--){
		pila_desapilar(pila);
		if (i == 2499){
			int* l = pila_ver_tope(pila);
			print_test("Prueba ver tope 2500 elementos luego de desapilar" , *l == 2498);
		}
	}
	print_test("Prueba ver tope luego de desapilar todo" , pila_ver_tope(pila) == NULL);
	pila_destruir(pila);
	print_test("La pila fue destruida" , true);
}

/*prueba que las funciones apilar y desapilar funcionen correctamente*/
	
void prueba_pila_apilar_desapilar(){
	pila_t* pila = pila_crear();
	int i = 5;
	double j = 3.14;
	char k = 'c';
	char l[] = "fernando";
	pila_apilar(pila,&i);
	int* valor_1 = pila_ver_tope(pila);
	int* valor_2 = pila_desapilar(pila);
	print_test("Prueba pila apilar 1 elemento" , *valor_1 == 5);
	print_test("Prueba pila desapilar 1 elemento" , *valor_2 == 5);
	print_test("Prueba pila desapilar pila vacia" , pila_desapilar(pila) == NULL);
	pila_apilar(pila,&i);
	pila_apilar(pila,&j);
	pila_apilar(pila,&k);
	pila_apilar(pila,l);
	char* cadena = pila_ver_tope(pila); 
	print_test("Prueba pila apilar en orden" , *cadena == 'f');
	char* s = pila_desapilar(pila);
	char* t = pila_desapilar(pila);
	double* u = pila_desapilar(pila);
	int* v = pila_desapilar(pila);
	print_test("Prueba pila desapilar en orden" ,*s == *l && *t =='c' && *u == 3.14 && *v == 5);
	pila_destruir(pila);
	print_test("La pila fue destruida" , true);
}
	
void pruebas_pila_alumno() {
    pila_t* ejemplo = NULL;
    print_test("Puntero inicializado a NULL", ejemplo == NULL);
    prueba_pila_vacia();
    prueba_pila_esta_vacia();
    prueba_pila_ver_tope();
    prueba_pila_apilar_desapilar();
    }
	


