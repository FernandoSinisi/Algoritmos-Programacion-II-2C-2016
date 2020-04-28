#include "lista.h"
#include "testing.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>


/* Declaro las funciones auxiliares */
  
bool sumar (void* dato , void* extra);

bool contar (void* dato , void* extra);


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

/*Pruebas con lista vacia*/

void prueba_lista_vacia(){
	lista_t* lista = lista_crear();
	int i = 10;
	char letra = 'r';
	print_test("Prueba crear lista vacia." ,lista_esta_vacia(lista));
	print_test("Prueba ver primero en lista vacia." , lista_ver_primero(lista) == NULL);
	print_test("Prueba ver ultimo en lista vacia." , lista_ver_ultimo(lista) == NULL);
	print_test("Prueba borrar primero en lista vacia." , lista_borrar_primero(lista) == NULL);
	print_test("Prueba obtener largo en lista vacia." , lista_largo(lista) == 0);
	bool dato1 = lista_insertar_primero(lista,&i);
	bool dato2 = lista_insertar_ultimo(lista,&letra);
	print_test("Prueba insertar primero en lista vacia." , dato1);
	print_test("Prueba insertar ultimo en lista vacia." , dato2);
	int* valor1 = lista_ver_primero(lista);
	char* valor2 = lista_ver_ultimo(lista);
	print_test("Prueba ver primero en lista con 2 elementos. " , *valor1 == 10);
	print_test("Prueba ver ultimo en lista con 2 elementos. " , *valor2 == 'r');
	lista_destruir(lista,NULL);
	print_test("La lista fue destruida." , true);
}

/*Prueba que la funcion lista_esta_vacia funcione correctamente*/

void prueba_lista_esta_vacia(){
	lista_t* lista = lista_crear();
	int vector[100];
	for(int i = 0; i<100; i++){
		vector[i]=i;
		lista_insertar_ultimo(lista,&vector[i]);
		lista_insertar_primero(lista,&vector[i]);
	}
	print_test("Prueba insertar  200 elementos, la lista no esta vacia." , !lista_esta_vacia(lista));
	for(int i = 199; i>=0; i--){
		lista_borrar_primero(lista);
		if (i==49){
			print_test("Prueba eliminados 50 elementos, la lista no esta vacia." , !lista_esta_vacia(lista));
		}
	}
	print_test("Prueba eliminados 200 elementos, la lista esta vacia." , lista_esta_vacia(lista));
	lista_destruir(lista,NULL);
	print_test("La lista fue destruida." , true);	
}	
 /*Prueba que la lista funcione con gran volumen. */

void prueba_lista_volumen(){
	lista_t* lista1 = lista_crear();
	lista_t* lista2 = lista_crear();
	int vector[10000];
	for (int i = 0 ; i<10000 ; i++){
		vector[i] = i;
		lista_insertar_ultimo(lista1,&vector[i]);
		lista_insertar_primero(lista2,&vector[i]);
		if(i == 4999){
			int *j = lista_ver_primero(lista1);
			int *k = lista_ver_primero(lista2);
			int *l = lista_ver_ultimo(lista1);
			int *m = lista_ver_ultimo(lista2);
			print_test("Prueba ver primero 5000 elementos insertados al final." , *j == 0);
			print_test("Prueba ver ultimo 5000 elementos insertados al final." , *l == 4999);
			print_test("Prueba esta vacia 5000 elementos insertados al final." ,!lista_esta_vacia(lista1));
			print_test("Prueba obtener largo 5000 elementos insertados al final." , lista_largo(lista1) == 5000);
			print_test("Prueba ver primero 5000 elementos insertados al comienzo." , *k == 4999);
			print_test("Prueba ver ultimo 5000 elementos insertados al comienzo." , *m == 0);
			print_test("Prueba esta vacia 5000 elementos insertados al comienzo." ,!lista_esta_vacia(lista2));
			print_test("Prueba obtener largo 5000 elementos insertados al comienzo." , lista_largo(lista2) == 5000);
			
		}
	}
	int* j = lista_ver_primero(lista1); 
	int *k = lista_ver_primero(lista2);
	print_test("Prueba ver primero 10000 elementos insertados" , *j == 0 && *k == 9999);
	for (int i = 9999 ; i>=0 ; i--){
		lista_borrar_primero(lista1);
		lista_borrar_primero(lista2);
		if (i == 2499){
			j = lista_ver_primero(lista1);
			k = lista_ver_primero(lista2);
			print_test("Prueba ver primero 2500 elementos eliminados." , *j == 7501 && *k == 2498);
			print_test("Prueba obtener largo 2500 elementos eliminados." , lista_largo(lista2) == 2499);
		}
	}
	print_test("Prueba obtener largo 5000." , lista_largo(lista2) == 0);
	bool condicion1 = lista_ver_primero(lista1) == NULL && lista_ver_primero(lista2) == NULL;
	bool condicion2 = lista_esta_vacia(lista1) && lista_esta_vacia(lista2);
	print_test("Prueba ver primero eliminados todos los elementos." , condicion1 );
	print_test("Prueba esta vacia eliminados todos los elementos." , condicion2 );
	lista_destruir(lista1,NULL);
	lista_destruir(lista2,NULL);
	print_test("Las listas fueron destruida." , true);
}

/*prueba que las funciones insertar primero e insertar ultimo y funcionen correctamente */
	
void prueba_insertar_primero_ultimo(){
	lista_t* lista = lista_crear();
	int i = 5;
	double j = 3.14;
	char k = 'c';
	char l[] = "fernando";
	lista_insertar_ultimo(lista,&i);
	int* valor_1 = lista_ver_primero(lista);
	int* valor_2 = lista_borrar_primero(lista);
	print_test("Prueba insertar ultimo 1 elemento." , *valor_1 == i);
	print_test("Prueba borrar primero. " , *valor_2 == i);
	print_test("Prueba borrar primero lista vacia." , lista_borrar_primero(lista) == NULL);
	lista_insertar_primero(lista,&i);
	lista_insertar_ultimo(lista,&j);
	lista_insertar_primero(lista,&k);
	lista_insertar_ultimo(lista,l);
	char* caracter = lista_ver_primero(lista); 
	print_test("Prueba del orden de la lista." , *caracter == 'c');
	char* r = lista_borrar_primero(lista);
	int* s = lista_borrar_primero(lista);
	double* t = lista_borrar_primero(lista);
	char* u = lista_borrar_primero(lista);
	print_test("Prueba insertar y borrar elementos en orden." ,*r == k && *s == i && *t == j && u == l);
	lista_destruir(lista,NULL);
	print_test("La lista fue destruida." , true);
}

 /*prueba funcion destruir dato por parametro */

void destruir_dato(void* dato){
	free(dato);
}
	
void prueba_lista_destruir_dato(){
	lista_t* lista = lista_crear();
	int* entero = malloc(sizeof(int));
	char* caracter = malloc(sizeof(char));
	*caracter = 'c';
	*entero = 5;
	print_test("Prueba la lista fue creada.", lista != NULL);
	lista_insertar_primero(lista,entero);
	lista_insertar_primero(lista,caracter);
	lista_destruir(lista,destruir_dato);
	print_test("La lista fue destruida con funcion auxiliar." , true);
}
	
/* prueba del iterador externo */
	
void prueba_iterador_externo(){
	lista_t* lista1 = lista_crear();
	lista_iter_t* iter1 = lista_iter_crear(lista1);
	lista_t* lista2 = lista_crear();
	int vector[100];
	for(int i = 0; i<100; i++){
		vector[i]=i;
		lista_insertar_ultimo(lista2,&vector[i]);
	}
	lista_iter_t* iter2 = lista_iter_crear(lista2);
	print_test("Prueba crear iterador." , iter1 != NULL);
	print_test("Prueba crear iterador para lista vacia." ,lista_iter_ver_actual(iter1) == NULL);
	print_test("Prueba borrar actual en lista vacia." , lista_iter_borrar(iter1) == NULL );
	print_test("Prueba insertar en lista vacia." ,lista_iter_insertar(iter1, &vector[88]));
	print_test("Prueba ver actual luego de insertar en lista vacia.",*(int*)lista_iter_ver_actual(iter1) == 88);
	print_test("Prueba ver actual del iterador." ,  *(int*)lista_iter_ver_actual(iter2) == 0);
	print_test("Prueba crear iterador para lista no vacia." ,lista_iter_ver_actual(iter2) != NULL);
	print_test("Prueba iterador esta al final." , !lista_iter_al_final(iter2)); 
	print_test("Prueba ver actual del iterador." ,  *(int*)lista_iter_ver_actual(iter2) == 0);
	print_test("Prueba borrar actual del iterador." , *(int*)lista_iter_borrar(iter2) == 0);
	print_test("Prueba ver actual del iterador luego de borrar." , *(int*)lista_iter_ver_actual(iter2) == 1);
	print_test("Prueba esta al final el iterador." , !lista_iter_al_final(iter2));
	for(int x = 0; x<50;x++){
		lista_iter_avanzar(iter2);
	}
	print_test("Prueba largo de la lista modificada por iterador." ,lista_largo(lista2) == 99);
	print_test("Prueba esta al final el iterador luego de avanzar." , !lista_iter_al_final(iter2));
	print_test("Prueba ver actual luego de avanzar." , *(int*)lista_iter_ver_actual(iter2) == 51);
	char palabra[] = "fernando" ;
	print_test("Prueba insertar en medio de la lista." , lista_iter_insertar(iter2, palabra));
	print_test("Prueba ver actual luego de insertar en medio." , lista_iter_ver_actual(iter2) == palabra);
	for(int y = 0 ; y<50 ; y++){
		lista_iter_avanzar(iter2);
	}
	print_test("Prueba avanzar hasta el final." , lista_iter_al_final(iter2));
	print_test("Prueba insertar al final de la lista." , lista_iter_insertar(iter2, &vector[5]));
	print_test("Prueba ver actual luego de insertar al final." , *(int*)lista_iter_ver_actual(iter2) == 5);
	print_test("Prueba esta al final al insertar al final." , !lista_iter_al_final(iter2));
	lista_destruir(lista2,NULL);
	lista_iter_destruir(iter2);
	lista_destruir(lista1,NULL);
	lista_iter_destruir(iter1);
	print_test("La listas fueron destruidas." , true);
	print_test("Los iteradores fueron destruidos." , true);
	lista_t* lista3 = lista_crear();
	print_test("La lista fue creada.", lista3 != NULL);
	lista_insertar_ultimo(lista3,&vector[1]);
	lista_insertar_ultimo(lista3,&vector[2]);
	lista_insertar_ultimo(lista3,&vector[3]);
	lista_iter_t* iter3 = lista_iter_crear(lista3);
	print_test("El iterador fue creado.", iter3 != NULL);
	print_test("Prueba ver primero." , *(int*)lista_ver_primero(lista3) == 1 );
	print_test("Prueba ver ultimo." , *(int*)lista_ver_ultimo(lista3) == 3);
	print_test("Prueba  no esta al final al insertar 3 valores en lista vacia.", !lista_iter_al_final(iter3));
	print_test("Prueba ver actual (valor 1) luego de insertar." , *(int*)lista_iter_ver_actual(iter3) == 1);
	print_test("Prueba avanzar el iterador." , lista_iter_avanzar(iter3));
	print_test("Prueba ver actual (valor 2 )luego de avanzar." , *(int*)lista_iter_ver_actual(iter3) == 2);
	print_test("Prueba borrar actual (valor 2)del iterador." , *(int*)lista_iter_borrar(iter3) == 2);
	print_test("Prueba largo (2) de la lista." , lista_largo(lista3) == 2);
	print_test("Prueba ver primero." , *(int*)lista_ver_primero(lista3) == 1 );
	print_test("Prueba ver ultimo." , *(int*)lista_ver_ultimo(lista3) == 3);
	print_test("Prueba ver actual (valor 3) luego de borrar." , *(int*)lista_iter_ver_actual(iter3) == 3);
	print_test("Prueba borrar actual (valor 3) del iterador." , *(int*)lista_iter_borrar(iter3) == 3);
	print_test("Prueba largo (1) de la lista." , lista_largo(lista3) == 1);
	print_test("Prueba no puede avanzar el iterador." , !lista_iter_avanzar(iter3));
	print_test("Prueba no puede borrar actual (null) del iterador." , lista_iter_borrar(iter3) == NULL);
	print_test("Prueba ver actual (null)." , lista_iter_ver_actual(iter3) == NULL);
	print_test("Prueba ver primero lista." , *(int*)lista_ver_primero(lista3) == 1 );
	print_test("Prueba ver ultimo lista." , *(int*)lista_ver_ultimo(lista3) == 1);
	print_test("Prueba ver largo de la lista." , lista_largo(lista3) == 1);
    print_test("Prueba insertar al final luego de borrar ultimo.", lista_insertar_ultimo(lista3,&vector[4]));
    lista_iter_t* iter4 = lista_iter_crear(lista3);
    print_test("El iterador fue creado.", iter4 != NULL);
    print_test("Prueba nuevo iterador fue creado con lista modificada por otro iterador.", iter4 != NULL);
    print_test("Prueba  no esta al final.", !lista_iter_al_final(iter4));
	print_test("Prueba ver actual (valor1)." , *(int*)lista_iter_ver_actual(iter4) == 1);
	print_test("Prueba borrar actual (valor 1)del iterador." , *(int*)lista_iter_borrar(iter4) == 1);
	print_test("Prueba ver actual (valor2)." , *(int*)lista_iter_ver_actual(iter4) == 4);
	print_test("Prueba borrar actual (valor 2)del iterador." , *(int*)lista_iter_borrar(iter4) == 4);
	print_test("Prueba no puede borrar actual (null) del iterador." , lista_iter_borrar(iter4) == NULL);
	print_test("Prueba ver actual (null)." , lista_iter_ver_actual(iter4) == NULL);
	print_test("Prueba avanzar el iterador es false." , !lista_iter_avanzar(iter4));
	print_test("Prueba esta vacia borrados todos los elementos." , lista_esta_vacia(lista3));
	print_test("Prueba largo de la lista vacia." , lista_largo(lista3) == 0);
	lista_destruir(lista3,NULL);
	lista_iter_destruir(iter3);
	lista_iter_destruir(iter4);
	print_test("La lista fue destruida." , true);
	print_test("Los iteradores fueron destruidos." , true);
	int array [1000];
	lista_t* lista5 = lista_crear();
	print_test("La lista fue creada vacia.", lista5 != NULL);
	print_test("Prueba crear lista vacia." ,lista_esta_vacia(lista5));
	for (int i = 0 ; i<1000 ; i++){
		array[i] = i;
		lista_insertar_primero(lista5,&array[i]);
	}
	print_test("Prueba ver primero luego de insertar primeros." , *(int*)lista_ver_primero(lista5) == 999);
	print_test("Prueba largo 1000." , lista_largo(lista5) == 1000);
	for (int i = 0 ; i<1000 ; i++){
		lista_insertar_ultimo(lista5,&array[i]);
	}
	print_test("Prueba ver primero luego de insertar ultimos." , *(int*)lista_ver_primero(lista5) == 999);
	print_test("Prueba largo 2000." , lista_largo(lista5) == 2000);
	lista_iter_t* iter5 = lista_iter_crear(lista5);
	print_test("El iterador fue creado.", iter5 != NULL);
	print_test("Prueba ver actual del iterador." , *(int*)lista_iter_ver_actual(iter5) == 999);
	print_test("Prueba insertar con actual al principio." ,lista_iter_insertar(iter5, &vector[10]));
	print_test("Prueba ver primero luego de insertar con iterador." , *(int*)lista_ver_primero(lista5) == 10);
	print_test("Prueba ver actual luego de insertar con iterador.",*(int*)lista_iter_ver_actual(iter5) == 10);
	lista_destruir(lista5,NULL);
	lista_iter_destruir(iter5);
	print_test("La lista fue destruida." , true);
	print_test("El iterador fue destruido." , true);
}
              
/* prueba del iterador interno */
	
void prueba_iterador_interno(){
	lista_t* lista1 = lista_crear();
	lista_t* lista2 = lista_crear();
	print_test("La listas fueron creadas.", lista1 != NULL && lista2 != NULL);
	int vector[10];
	for(int i = 0; i<10; i++){
		vector[i]=i;
		lista_insertar_ultimo(lista1,&vector[i]);
		lista_insertar_primero(lista1,&vector[i]);
	}
	int suma = 0,total=0;
	lista_insertar_ultimo(lista2,"Battlefield");
	lista_insertar_ultimo(lista2,"Fifa 17");
	lista_insertar_ultimo(lista2, "Dark Souls 3");
	lista_insertar_ultimo(lista2, "Titanfall 2");
	lista_iterar(lista1, sumar, &suma);
	lista_iterar(lista2 ,contar , &total);	
	print_test("Prueba iterador interno sumar", suma == 90);
	print_test("Prueba iterador interno contar", total == 4);
	lista_destruir(lista1,NULL);
	lista_destruir(lista2,NULL);
	print_test("La listas fueron destruidas." , true);
}

/* Funciones auxiliares */
  
bool sumar (void* numero , void* suma){
	*(int*) suma+= *(int*)numero;
	return true;
}

bool contar (void* numero , void* suma){
	*(int*) suma+=1;
	return true;
}		
 


void pruebas_lista_alumno() {
    lista_t* lista = NULL;
    print_test("Puntero a lista inicializado a NULL", lista == NULL);
    prueba_lista_vacia();
    prueba_lista_esta_vacia();
    prueba_lista_volumen();
    prueba_insertar_primero_ultimo();
    prueba_lista_destruir_dato();
    prueba_iterador_externo();
    prueba_iterador_interno();
 }
 	 

