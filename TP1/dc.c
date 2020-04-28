#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "strutil.h"
#include "pila.h"
#define FALLA -1
#define CANT_EXT 2

/* *****************************************************************
 *                      FUNCIONES AUXILIARES
 * *****************************************************************/
 
int operacion_fallida(char* linea,pila_t* pila){
	pila_destruir(pila);
	free(linea);
	fprintf(stderr, "Error, la operacion ingresada no es valida\n");
	return FALLA;
}

bool es_suma(char* cad){
	if(!strcmp(cad,"+"))
		return true;
	return false;
}

bool es_resta(char* cad){
	if(!strcmp(cad,"-"))
		return true;
	return false;
}

bool es_producto(char* cad){
	if(!strcmp(cad,"*"))
		return true;
	return false;
}

bool es_division(char* cad){
	if(!strcmp(cad,"/"))
		return true;
	return false;
}

bool es_operacion(char* cad){
	if(es_suma(cad) || es_resta(cad) || es_division(cad) || es_producto(cad))
		return true;
	return false;
}


void* realizar_operacion(char*linea,pila_t* pila_num,size_t len){
		char** array_cad = split(linea, ' ');
		char* cad_fin;
		char* sub_cad;
		double array_aux[len*CANT_EXT];
		size_t pos_aux = 0, pos_array = 0;
		double numero,resultado;
		while(array_cad[pos_array]){
			sub_cad = array_cad[pos_array];
			if(!strcmp(sub_cad,"") || !strcmp(sub_cad,"\n") ){
				pos_array++;
				continue;
			}
			if(es_operacion(sub_cad)){
				double* num1 = (double*)pila_desapilar(pila_num);
				double* num2 = (double*)pila_desapilar(pila_num);
				if(!num1 || !num2 ){
					free_strv(array_cad);
					return NULL;
				}
				if(es_suma(sub_cad)){
					resultado = *num2 + *num1;
				}
				if(es_resta(sub_cad)){
					resultado = *num2 - *num1;
				}
				if(es_division(sub_cad)){
					resultado = *num2 / *num1;
				}
				if(es_producto(sub_cad)){
					resultado = *num2 * *num1;
				}
				array_aux[pos_aux] = resultado;
			}
			else{
				numero = strtod(sub_cad, &cad_fin);
				if(!strcmp(cad_fin,"") || !strcmp(cad_fin,"\n")){
					array_aux[pos_aux] = numero;
				}
				else{
					free_strv(array_cad);
					return NULL;
				}
			}
			pila_apilar(pila_num,array_aux+pos_aux);
			pos_array++;
			pos_aux++;
		}
		if(pila_esta_vacia(pila_num)){
			free_strv(array_cad);
			return NULL;
		}
		double* resultado_final = (double*)pila_desapilar(pila_num);
		if(!pila_esta_vacia(pila_num)){
			free_strv(array_cad);
			return NULL;
		}
	double* total = malloc(sizeof(double));
	*total = *resultado_final;
	pos_array = 0;
	pos_aux = 0;
	free_strv(array_cad);
	return total;
}
	

/* *****************************************************************
 *                      FUNCION PRICIPAL
 * *****************************************************************/

int main(void){
	char* linea = NULL;
	size_t capacidad = 0;
	ssize_t len = getline(&linea, &capacidad,stdin);
	if (len==-1){
		fprintf(stderr, "Error, no se puede leer la linea\n");
		return FALLA;
	}
	pila_t* pila_num = pila_crear();
	while(len!=-1){
		linea[len-1] = '\0';
		void* resultado = realizar_operacion(linea,pila_num,len);
		if(!resultado) return operacion_fallida(linea,pila_num);
		printf("Resultado = %.2f\n",*(double*)resultado);
		free(resultado);
		len = getline(&linea, &capacidad,stdin);
	}
	pila_destruir(pila_num);
	free(linea);
	return 0;
}
