#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strutil.c"

int main(){
	char* cadena = "fer,genio,,hola,,termine";
	char* cad2 = "";
	char* cad3 = "8 9 * ";
	char** lista = split(cadena,',');
	char** lista3 = split(cad3,' ');
	printf("(%s)\n%s\n%s\n%s\n%s\n%s\n",lista[0],lista[1],lista[2],lista[3],lista[4],lista[5]);
	char** lista2 = split(cad2,',');
	printf("%s\n",lista2[0]);
	printf("%s-\n%s-\n%s-\n%s-\n",lista3[0],lista3[1],lista3[2],lista3[3]);
	if(lista[6] == NULL){
		printf("termina en null lista 1\n");
	}
	if(lista2[1] == NULL){
		printf("termina en null lista 2\n");
	}
	if(lista3[4] == NULL){
		printf("termina en null lista 3\n");
	}
	char* linea = NULL;
	size_t capacidad = 0;
	char** get;
	ssize_t len = getline(&linea, &capacidad,stdin);
	if (len==-1){
		fprintf(stderr, "Error, no se puede leer la linea\n");
		return -1;
	}
	while(len!=-1){
		get = split(cadena,' ');
		printf("espliteo\n");
		free_strv(get);
		len = getline(&linea, &capacidad,stdin);
		
	}
	free_strv(lista);
	free_strv(lista2);
	free_strv(lista3);
	//free_strv(get);
	free(linea);
	return 0;
}	
