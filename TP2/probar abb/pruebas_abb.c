/*
 * prueba_abb.c
 * Pruebas para el tipo de dato abstracto Tabla de abb
 * Copyright: (2011) Margarita Manterola, Maximiliano Curia
 * Licencia: CC-BY-SA 2.5 (ar) ó CC-BY-SA 3.0
 */

#include "abb.h"
#include "testing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  
#include <unistd.h>  // For ssize_t in Linux.


/* ******************************************************************
 *                        PRUEBAS UNITARIAS
 * *****************************************************************/

static void prueba_crear_abb_vacio()
{
    abb_t* abb = abb_crear(strcmp,NULL);

    print_test("Prueba abb crear arbol vacio", abb);
    print_test("Prueba abb la cantidad de elementos es 0", abb_cantidad(abb) == 0);
    print_test("Prueba abb obtener clave A, es NULL, no existe", !abb_obtener(abb, "A"));
    print_test("Prueba abb pertenece clave A, es false, no existe", !abb_pertenece(abb, "A"));
    print_test("Prueba abb borrar clave A, es NULL, no existe", !abb_borrar(abb, "A"));

    abb_destruir(abb);
}

static void prueba_iterar_abb_vacio()
{
    abb_t* abb = abb_crear(strcmp,NULL);
    abb_iter_t* iter = abb_iter_in_crear(abb);
    print_test("Prueba abb iter crear iterador abb vacio", iter);
    print_test("Prueba abb iter esta al final", abb_iter_in_al_final(iter));
    print_test("Prueba abb iter avanzar es false", !abb_iter_in_avanzar(iter));
    print_test("Prueba abb iter ver actual es NULL", !abb_iter_in_ver_actual(iter));
	abb_iter_in_destruir(iter);
    abb_destruir(abb);
}

static void prueba_abb_insertar()
{
    abb_t* abb = abb_crear(strcmp,NULL);

    char *clave1 = "perro", *valor1 = "guau";
    char *clave2 = "gato", *valor2 = "miau";
    char *clave3 = "vaca", *valor3 = "mu";

    /* Inserta 1 valor y luego lo borra */
    print_test("Prueba abb insertar clave1", abb_guardar(abb, clave1, valor1));
    print_test("Prueba abb la cantidad de elementos es 1", abb_cantidad(abb) == 1);
    print_test("Prueba abb obtener clave1 es valor1", abb_obtener(abb, clave1) == valor1);
    print_test("Prueba abb obtener clave1 es valor1", abb_obtener(abb, clave1) == valor1);
    print_test("Prueba abb pertenece clave1, es true", abb_pertenece(abb, clave1));
    print_test("Prueba abb borrar clave1, es valor1", abb_borrar(abb, clave1) == valor1);
    print_test("Prueba abb la cantidad de elementos es 0", abb_cantidad(abb) == 0);

    /* Inserta otros 2 valores y no los borra (se destruyen con el abb) */
    print_test("Prueba abb insertar clave2", abb_guardar(abb, clave2, valor2));
    print_test("Prueba abb la cantidad de elementos es 1", abb_cantidad(abb) == 1);
    print_test("Prueba abb obtener clave2 es valor2", abb_obtener(abb, clave2) == valor2);
    print_test("Prueba abb obtener clave2 es valor2", abb_obtener(abb, clave2) == valor2);
    print_test("Prueba abb pertenece clave2, es true", abb_pertenece(abb, clave2));

    print_test("Prueba abb insertar clave3", abb_guardar(abb, clave3, valor3));
    print_test("Prueba abb la cantidad de elementos es 2", abb_cantidad(abb) == 2);
    print_test("Prueba abb obtener clave3 es valor3", abb_obtener(abb, clave3) == valor3);
    print_test("Prueba abb obtener clave3 es valor3", abb_obtener(abb, clave3) == valor3);
    print_test("Prueba abb pertenece clave3, es true", abb_pertenece(abb, clave3));

    abb_destruir(abb);
}

static void prueba_abb_reemplazar()
{
    abb_t* abb = abb_crear(strcmp,NULL);

    char *clave1 = "perro", *valor1a = "guau", *valor1b = "warf";
    char *clave2 = "gato", *valor2a = "miau", *valor2b = "meaow";

    /* Inserta 2 valores y luego los reemplaza */
    print_test("Prueba abb insertar clave1", abb_guardar(abb, clave1, valor1a));
    print_test("Prueba abb obtener clave1 es valor1a", abb_obtener(abb, clave1) == valor1a);
    print_test("Prueba abb obtener clave1 es valor1a", abb_obtener(abb, clave1) == valor1a);
    print_test("Prueba abb insertar clave2", abb_guardar(abb, clave2, valor2a));
    print_test("Prueba abb obtener clave2 es valor2a", abb_obtener(abb, clave2) == valor2a);
    print_test("Prueba abb obtener clave2 es valor2a", abb_obtener(abb, clave2) == valor2a);
    print_test("Prueba abb la cantidad de elementos es 2", abb_cantidad(abb) == 2);

    print_test("Prueba abb insertar clave1 con otro valor", abb_guardar(abb, clave1, valor1b));
    print_test("Prueba abb obtener clave1 es valor1b", abb_obtener(abb, clave1) == valor1b);
    print_test("Prueba abb obtener clave1 es valor1b", abb_obtener(abb, clave1) == valor1b);
    print_test("Prueba abb insertar clave2 con otro valor", abb_guardar(abb, clave2, valor2b));
    print_test("Prueba abb obtener clave2 es valor2b", abb_obtener(abb, clave2) == valor2b);
    print_test("Prueba abb obtener clave2 es valor2b", abb_obtener(abb, clave2) == valor2b);
    print_test("Prueba abb la cantidad de elementos es 2", abb_cantidad(abb) == 2);

    abb_destruir(abb);
}

static void prueba_abb_reemplazar_con_destruir()
{
    abb_t* abb = abb_crear(strcmp,free);

    char *clave1 = "perro", *valor1a, *valor1b;
    char *clave2 = "gato", *valor2a, *valor2b;

    /* Pide memoria para 4 valores */
    valor1a = malloc(10 * sizeof(char));
    valor1b = malloc(10 * sizeof(char));
    valor2a = malloc(10 * sizeof(char));
    valor2b = malloc(10 * sizeof(char));

    /* Inserta 2 valores y luego los reemplaza (debe liberar lo que reemplaza) */
    print_test("Prueba abb insertar clave1", abb_guardar(abb, clave1, valor1a));
    print_test("Prueba abb obtener clave1 es valor1a", abb_obtener(abb, clave1) == valor1a);
    print_test("Prueba abb obtener clave1 es valor1a", abb_obtener(abb, clave1) == valor1a);
    print_test("Prueba abb insertar clave2", abb_guardar(abb, clave2, valor2a));
    print_test("Prueba abb obtener clave2 es valor2a", abb_obtener(abb, clave2) == valor2a);
    print_test("Prueba abb obtener clave2 es valor2a", abb_obtener(abb, clave2) == valor2a);
    print_test("Prueba abb la cantidad de elementos es 2", abb_cantidad(abb) == 2);

    print_test("Prueba abb insertar clave1 con otro valor", abb_guardar(abb, clave1, valor1b));
    print_test("Prueba abb obtener clave1 es valor1b", abb_obtener(abb, clave1) == valor1b);
    print_test("Prueba abb obtener clave1 es valor1b", abb_obtener(abb, clave1) == valor1b);
    print_test("Prueba abb insertar clave2 con otro valor", abb_guardar(abb, clave2, valor2b));
    print_test("Prueba abb obtener clave2 es valor2b", abb_obtener(abb, clave2) == valor2b);
    print_test("Prueba abb obtener clave2 es valor2b", abb_obtener(abb, clave2) == valor2b);
    print_test("Prueba abb la cantidad de elementos es 2", abb_cantidad(abb) == 2);

    /* Se destruye el abb (se debe liberar lo que quedó dentro) */
    abb_destruir(abb);
}

static void prueba_abb_borrar()
{
    abb_t* abb = abb_crear(strcmp,NULL);

    char *clave1 = "perro", *valor1 = "guau";
    char *clave2 = "gato", *valor2 = "miau";
    char *clave3 = "vaca", *valor3 = "mu";

    /* Inserta 3 valores y luego los borra */
    print_test("Prueba abb insertar clave1", abb_guardar(abb, clave1, valor1));
    print_test("Prueba abb insertar clave2", abb_guardar(abb, clave2, valor2));
    print_test("Prueba abb insertar clave3", abb_guardar(abb, clave3, valor3));

    /* Al borrar cada elemento comprueba que ya no está pero los otros sí. */
    print_test("Prueba abb pertenece clave3, es verdadero", abb_pertenece(abb, clave3));
    print_test("Prueba abb borrar clave3, es valor3", abb_borrar(abb, clave3) == valor3);
    print_test("Prueba abb borrar clave3, es NULL", !abb_borrar(abb, clave3));
    print_test("Prueba abb pertenece clave3, es falso", !abb_pertenece(abb, clave3));
    print_test("Prueba abb obtener clave3, es NULL", !abb_obtener(abb, clave3));
    print_test("Prueba abb la cantidad de elementos es 2", abb_cantidad(abb) == 2);

    print_test("Prueba abb pertenece clave1, es verdadero", abb_pertenece(abb, clave1));
    print_test("Prueba abb borrar clave1, es valor1", abb_borrar(abb, clave1) == valor1);
    print_test("Prueba abb borrar clave1, es NULL", !abb_borrar(abb, clave3));
    print_test("Prueba abb pertenece clave1, es falso", !abb_pertenece(abb, clave1));
    print_test("Prueba abb obtener clave1, es NULL", !abb_obtener(abb, clave1));
    print_test("Prueba abb la cantidad de elementos es 1", abb_cantidad(abb) == 1);

    print_test("Prueba abb pertenece clave2, es verdadero", abb_pertenece(abb, clave2));
    print_test("Prueba abb borrar clave2, es valor2", abb_borrar(abb, clave2) == valor2);
    print_test("Prueba abb borrar clave2, es NULL", !abb_borrar(abb, clave3));
    print_test("Prueba abb pertenece clave2, es falso", !abb_pertenece(abb, clave2));
    print_test("Prueba abb obtener clave2, es NULL", !abb_obtener(abb, clave2));
    print_test("Prueba abb la cantidad de elementos es 0", abb_cantidad(abb) == 0);

    abb_destruir(abb);
}

static void prueba_abb_borrar_2_hijos(){
	
	abb_t* abb = abb_crear(strcmp,NULL);
	
	char *clave1 = "1", *valor1 = "1";
    char *clave2 = "2", *valor2 = "2";
    char *clave3 = "4", *valor3 = "4";
	char *clave4 = "3", *valor4 = "3";
    char *clave5 = "5", *valor5 = "5";
    print_test("Prueba abb insertar clave1", abb_guardar(abb, clave1, valor1));
    print_test("Prueba abb insertar clave2", abb_guardar(abb, clave2, valor2));
    print_test("Prueba abb insertar clave3", abb_guardar(abb, clave3, valor3));
    print_test("Prueba abb insertar clave4", abb_guardar(abb, clave4, valor4));
    print_test("Prueba abb insertar clave5", abb_guardar(abb, clave5, valor5));
    print_test("Prueba abb pertenece clave3, es verdadero", abb_pertenece(abb, clave3));
    print_test("Prueba abb borrar clave3, es valor3", abb_borrar(abb, clave3) == valor3);
    print_test("Prueba abb pertenece clave2, es falso", !abb_pertenece(abb, clave3));
    print_test("Prueba abb la cantidad de elementos es 4", abb_cantidad(abb) == 4);
    
    abb_destruir(abb);
}
    
    
static void prueba_abb_clave_vacia()
{
    abb_t* abb = abb_crear(strcmp,NULL);

    char *clave = "", *valor = "";

    print_test("Prueba abb insertar clave vacia", abb_guardar(abb, clave, valor));
    print_test("Prueba abb la cantidad de elementos es 1", abb_cantidad(abb) == 1);
    print_test("Prueba abb obtener clave vacia es valor", abb_obtener(abb, clave) == valor);
    print_test("Prueba abb pertenece clave vacia, es true", abb_pertenece(abb, clave));
    print_test("Prueba abb borrar clave vacia, es valor", abb_borrar(abb, clave) == valor);
    print_test("Prueba abb la cantidad de elementos es 0", abb_cantidad(abb) == 0);

    abb_destruir(abb);
}

static void prueba_abb_valor_null()
{
    abb_t* abb = abb_crear(strcmp,NULL);

    char *clave = "", *valor = NULL;

    /* Inserta 1 valor y luego lo borra */
    print_test("Prueba abb insertar clave vacia valor NULL", abb_guardar(abb, clave, valor));
    print_test("Prueba abb la cantidad de elementos es 1", abb_cantidad(abb) == 1);
    print_test("Prueba abb obtener clave vacia es valor NULL", abb_obtener(abb, clave) == valor);
    print_test("Prueba abb pertenece clave vacia, es true", abb_pertenece(abb, clave));
    print_test("Prueba abb borrar clave vacia, es valor NULL", abb_borrar(abb, clave) == valor);
    print_test("Prueba abb la cantidad de elementos es 0", abb_cantidad(abb) == 0);

    abb_destruir(abb);
}

static void prueba_abb_volumen(int largo){
	
	abb_t* abb = abb_crear(strcmp,NULL);
	int largo_clave = 10;
	unsigned int valores[largo];
	char clave[largo_clave];
    unsigned int j = 0;
    bool ok = true;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < largo; i++) {
		j=rand()%(largo+1);
		valores[j] = j;
		sprintf(clave,"%08ui",j);
        ok = abb_guardar(abb, clave, &valores[j]);
        if (!ok) break;
    }
	print_test("Prueba abb almacenar muchos elementos", ok);
	char *clave1 = "1", *valor1 = "1";
    char *clave2 = "2", *valor2 = "2";
    char *clave3 = "4", *valor3 = "4";
	char *clave4 = "3", *valor4 = "3";
    char *clave5 = "5", *valor5 = "5";
    print_test("Prueba abb insertar clave1", abb_guardar(abb, clave1, valor1));
    print_test("Prueba abb insertar clave2", abb_guardar(abb, clave2, valor2));
    print_test("Prueba abb insertar clave3", abb_guardar(abb, clave3, valor3));
    print_test("Prueba abb insertar clave4", abb_guardar(abb, clave4, valor4));
    print_test("Prueba abb insertar clave5", abb_guardar(abb, clave5, valor5));
    print_test("Prueba abb pertenece clave3, es verdadero", abb_pertenece(abb, clave3));
    print_test("Prueba abb pertenece clave2, es verdadero", abb_pertenece(abb, clave2));
    print_test("Prueba abb pertenece clave1, es verdadero", abb_pertenece(abb, clave1));
    abb_destruir(abb);
}
    
    
static ssize_t buscar(const char* clave, char* claves[], size_t largo)
{
    for (size_t i = 0; i < largo; i++) {
        if (strcmp(clave, claves[i]) == 0) return (ssize_t) i;
    }
    return -1;
}

static void prueba_abb_iterar_in()
{
    abb_t* abb = abb_crear(strcmp,NULL);

    char *claves[] = {"perro", "gato", "vaca"};
    char *valores[] = {"guau", "miau", "mu"};

    /* Inserta 3 valores */
    print_test("Prueba abb insertar clave1", abb_guardar(abb, claves[0], valores[0]));
    print_test("Prueba abb insertar clave2", abb_guardar(abb, claves[1], valores[1]));
    print_test("Prueba abb insertar clave3", abb_guardar(abb, claves[2], valores[2]));

    // Prueba de iteración sobre las claves almacenadas.
    abb_iter_t* iter = abb_iter_in_crear(abb);
    const char *clave;
    ssize_t indice;

    print_test("Prueba abb iterador esta al final, es false", !abb_iter_in_al_final(iter));

    /* Primer valor */
    clave = abb_iter_in_ver_actual(iter);
    indice = buscar(clave, claves, sizeof(claves) / sizeof(char *));
    print_test("Prueba abb iterador ver actual, es una clave valida", indice != -1);
    print_test("Prueba abb iterador ver actual, no es el mismo puntero", clave != claves[indice]);
    print_test("Prueba abb iterador avanzar es true", abb_iter_in_avanzar(iter));
    print_test("Prueba abb iterador esta al final, es false", !abb_iter_in_al_final(iter));

    /* Segundo valor */
    clave = abb_iter_in_ver_actual(iter);
    indice = buscar(clave, claves, sizeof(claves) / sizeof(char *));
    print_test("Prueba abb iterador ver actual, es una clave valida", indice != -1);
    print_test("Prueba abb iterador ver actual, no es el mismo puntero", clave != claves[indice]);
    print_test("Prueba abb iterador avanzar es true", abb_iter_in_avanzar(iter));
    print_test("Prueba abb iterador esta al final, es false", !abb_iter_in_al_final(iter));

    /* Tercer valor */
    clave = abb_iter_in_ver_actual(iter);
    indice = buscar(clave, claves, sizeof(claves) / sizeof(char *));
    print_test("Prueba abb iterador ver actual, es una clave valida", indice != -1);
    print_test("Prueba abb iterador ver actual, no es el mismo puntero", clave != claves[indice]);
    /* Se anula esta prueba por diferencias de criterios */
    abb_iter_in_avanzar(iter);
    print_test("Prueba abb iterador esta al final, es true", abb_iter_in_al_final(iter));

    /* Vuelve a tratar de avanzar, por las dudas */
    print_test("Prueba abb iterador ver actual, es NULL", !abb_iter_in_ver_actual(iter));
    print_test("Prueba abb iterador avanzar es false", !abb_iter_in_avanzar(iter));
    print_test("Prueba abb iterador esta al final, es true", abb_iter_in_al_final(iter));

    abb_iter_in_destruir(iter);
    abb_destruir(abb);
}

static void prueba_abb_iterar_post()
{
    abb_t* abb = abb_crear(strcmp,NULL);

    char *claves[] = {"15", "12", "18","11", "14", "19","17"};
    char *valores[] = {"hola", "como", "estas","todo", "bien", "y","vos",};

    /* Inserta 8 valores */
    print_test("Prueba abb insertar clave1", abb_guardar(abb, claves[0], valores[0]));
    print_test("Prueba abb insertar clave2", abb_guardar(abb, claves[1], valores[1]));
    print_test("Prueba abb insertar clave3", abb_guardar(abb, claves[2], valores[2]));
	print_test("Prueba abb insertar clave4", abb_guardar(abb, claves[3], valores[3]));
    print_test("Prueba abb insertar clave5", abb_guardar(abb, claves[4], valores[4]));
    print_test("Prueba abb insertar clave6", abb_guardar(abb, claves[5], valores[5]));
    print_test("Prueba abb insertar clave7", abb_guardar(abb, claves[6], valores[6]));
   
    // Prueba de iteración sobre las claves almacenadas.
    abb_iter_post_t* iter = abb_iter_post_crear(abb);
    const char *clave;
    ssize_t indice;

    print_test("Prueba abb iterador esta al final, es false", !abb_iter_post_al_final(iter));

    /* Primer valor */
    clave = abb_iter_post_ver_actual(iter);
    indice = buscar(clave, claves, sizeof(claves) / sizeof(char *));
    print_test("Prueba abb iterador ver actual, es una clave valida", indice != -1);
    print_test("Prueba abb iterador ver actual, no es el mismo puntero", clave != claves[indice]);
    print_test("Prueba abb iterador ver actual, es primer clave post orden", !strcmp(clave,claves[3]));
    print_test("Prueba abb iterador avanzar es true", abb_iter_post_avanzar(iter));
    print_test("Prueba abb iterador esta al final, es false", !abb_iter_post_al_final(iter));

    /* Segundo valor */
    clave = abb_iter_post_ver_actual(iter);
    indice = buscar(clave, claves, sizeof(claves) / sizeof(char *));
    print_test("Prueba abb iterador ver actual, es una clave valida", indice != -1);
    print_test("Prueba abb iterador ver actual, no es el mismo puntero", clave != claves[indice]);
    print_test("Prueba abb iterador ver actual, es segunda clave post orden", !strcmp(clave,claves[4]));
    print_test("Prueba abb iterador avanzar es true", abb_iter_post_avanzar(iter));
    print_test("Prueba abb iterador esta al final, es false", !abb_iter_post_al_final(iter));

	/* Tercer valor */
    clave = abb_iter_post_ver_actual(iter);
	print_test("Prueba abb iterador ver actual, es tercera clave post orden",  !strcmp(clave,claves[1]));
	print_test("Prueba abb iterador avanzar es true", abb_iter_post_avanzar(iter));
    print_test("Prueba abb iterador esta al final, es false", !abb_iter_post_al_final(iter));
    
    /* Cuarto valor */
    clave = abb_iter_post_ver_actual(iter);
	print_test("Prueba abb iterador ver actual, es cuarta clave post orden",  !strcmp(clave,claves[6]));
	print_test("Prueba abb iterador avanzar es true", abb_iter_post_avanzar(iter));
    print_test("Prueba abb iterador esta al final, es false", !abb_iter_post_al_final(iter));
    
    /* Quinto valor */
    clave = abb_iter_post_ver_actual(iter);
	print_test("Prueba abb iterador ver actual, es quinta clave post orden",  !strcmp(clave,claves[5]));
	print_test("Prueba abb iterador avanzar es true", abb_iter_post_avanzar(iter));
    print_test("Prueba abb iterador esta al final, es false", !abb_iter_post_al_final(iter));
    
    /* Sexto valor */
    clave = abb_iter_post_ver_actual(iter);
	print_test("Prueba abb iterador ver actual, es sexta clave post orden",  !strcmp(clave,claves[2]));
	print_test("Prueba abb iterador avanzar es true", abb_iter_post_avanzar(iter));
    print_test("Prueba abb iterador esta al final, es false", !abb_iter_post_al_final(iter));
	
	/* Septimo valor */
    clave = abb_iter_post_ver_actual(iter);
	print_test("Prueba abb iterador ver actual, es ultima clave post orden",  !strcmp(clave,claves[0]));
    print_test("Prueba abb iterador no esta al final, es true", !abb_iter_post_al_final(iter));
    print_test("Prueba abb iterador avanzar es true", abb_iter_post_avanzar(iter));
	print_test("Prueba abb iterador esta al final, es true", abb_iter_post_al_final(iter));
	print_test("Prueba abb iterador avanzar es false", !abb_iter_post_avanzar(iter));

    abb_iter_post_destruir(iter);
    abb_destruir(abb);
}

/*prueba iterador interno */

bool sumar (const char* clave, void* numero , void* suma){
	*(int*) suma+= *(int*)numero;
	return true;
}

bool contar (const char* clave,void* numero , void* suma){
	*(int*) suma+=1;
	return true;
}
bool obtener_ult(const char* clave,void* numero , void* ultimo){
	*(int*) ultimo = *(int*)numero;
	return true;
}

void prueba_iterador_interno(){
	abb_t* abb = abb_crear(strcmp,NULL);
	int suma = 0,total=0;
    char *claves[] = {"perro", "gato", "vaca","caballo","leon","perro","delfin","jirafa","sapo","rana"};
    int valores[10];
	for(int i = 0; i<10; i++){
		valores[i]=i;
		print_test("Prueba abb insertar clave valor", abb_guardar(abb, claves[i], &valores[i]));
	}
	abb_in_order(abb, sumar, &suma);
	abb_in_order(abb, contar, &total);
	print_test("Prueba iterador interno in sumar", suma == 45);
	print_test("Prueba iterador interno in contar", total == 9);
	abb_post_order(abb, sumar, &suma);
	abb_post_order(abb, contar, &total);
	print_test("Prueba iterador interno post sumar", suma == 90);
	print_test("Prueba iterador interno post contar", total == 18);
	abb_destruir(abb);
	print_test("El arbol fue destruido." , true);
	abb_t* abb2 = abb_crear(strcmp,NULL);
	int ultimo_visitado = 0;
	char *claves2[] = {"10", "11", "9","15","12","14","20","1","3","7"};
	int valores2[10]= {10, 11, 9, 15, 12, 14, 20, 1, 3, 7};
	for(int i = 0; i<10; i++){
		abb_guardar(abb2, claves2[i], &valores2[i]);
	}
	print_test("Prueba abb se guardaron 10 elementos", true);
	print_test("Prueba abb la cantidad de elementos es 10", abb_cantidad(abb2) ==10);
	abb_in_order(abb2,obtener_ult, &ultimo_visitado);
	print_test("Prueba iterador interno in obtener ultimo", ultimo_visitado == 9);
	abb_post_order(abb2,obtener_ult, &ultimo_visitado);
	print_test("Prueba iterador interno post obtener ultimo", ultimo_visitado == 10);
    abb_destruir(abb2);
    print_test("El arbol fue destruido." , true);
	return;
}

void prueba_obtener_items(){
	abb_t* abb = abb_crear(strcmp,NULL);
	char *claves2[10] = {"10", "11", "9","15","12","14","20","1","3","7"};
	int valores2[10]= {20, 22, 18, 30, 24, 28, 40, 2, 6, 14};
	for(int i = 0; i<10; i++){
		abb_guardar(abb, claves2[i], &valores2[i]);
	}
	print_test("Prueba insertar 10 elementos",true);
	abb_item_t* array = abb_obtener_items(abb);
	print_test("Prueba abb obtener items 1° elemento", !strcmp(array[0].clave,"1") && *(int*)array[0].valor == 2 );
	print_test("Prueba abb obtener items 2° elemento", !strcmp(array[1].clave,"10") && *(int*)array[1].valor == 20 );
	print_test("Prueba abb obtener items 3° elemento", !strcmp(array[2].clave,"11") && *(int*)array[2].valor == 22 );
	print_test("Prueba abb obtener items ultimo elemento", !strcmp(array[9].clave,"9") && *(int*)array[9].valor == 18 );
	abb_destruir(abb);
	free(array);
	return;
}


/* ******************************************************************
 *                        FUNCIÓN PRINCIPAL
 * *****************************************************************/


void pruebas_abb_alumno()
{
    /* Ejecuta todas las pruebas unitarias. */
    prueba_crear_abb_vacio();
    prueba_iterar_abb_vacio();
    prueba_abb_insertar();
    prueba_abb_reemplazar();
    prueba_abb_reemplazar_con_destruir();
    prueba_abb_borrar();
    prueba_abb_borrar_2_hijos();
    prueba_abb_clave_vacia();
    prueba_abb_valor_null();
    prueba_abb_volumen(5000);
    prueba_abb_iterar_in();
    prueba_abb_iterar_post();
    prueba_iterador_interno();
    prueba_obtener_items();
}


