#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* *****************************************************************
 *                    FUNCION AUXILIAR
 * *****************************************************************/
void imprimir(char* cadena,ssize_t len){
	for(int i = 0; i < len-1 ;i++){
		putchar(cadena[i]);
	}
	
}

/* *****************************************************************
 *                    FUNCION PRINCIPAL
 * *****************************************************************/
 
int main(int argc, char* argv[]){
	if (argc != 3){
		fprintf(stderr, "Error, cantidad de parametros incorrecta\n");
		return -1;
	}
	FILE* file1 = fopen(argv[1],"rt");
	if(!file1){
		fprintf(stderr, "Error, no se puede abrir el primer archivo\n");
		return -1;
	}
	FILE* file2 = fopen(argv[2],"rt");
	if(!file2){
		fclose(file1);
		fprintf(stderr, "Error, no se puede abrir el segundo archivo\n");
		return -1;
	}	
	char* linea1 = NULL;
	char* linea2 = NULL;
	size_t capacidad = 0;
	ssize_t len1 = getline(&linea1, &capacidad, file1);
	ssize_t len2 = getline(&linea2, &capacidad, file2);
	while(len1 != -1 && len2 != -1){
		imprimir(linea1,len1);
		putchar('\t');
		imprimir(linea2,len2);
		putchar('\n');
		len1 = getline(&linea1, &capacidad, file1);
		len2 = getline(&linea2, &capacidad, file2);
	}
	free((void*)linea1);
	free((void*)linea2);
	fclose(file1);
	fclose(file2);
	if(len1 == -1 && len2 == -1)return 0;
	if(len1 != -1){
			fprintf(stderr, "Error, el primer archivo tiene mas lineas que el segundo\n");
			return -1;
	}
	fprintf(stderr, "Error, el segundo archivo tiene mas lineas que el primero\n");
	return -1;
}
	

