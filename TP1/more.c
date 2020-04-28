#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/* *****************************************************************
 *                    FUNCIONES AUXILIARES
 * *****************************************************************/

void imprimir(char* cadena,ssize_t len){
	for(int i = 0; i < len-1 ;i++){
		putchar(cadena[i]);
	}
	putchar('\n');
}

int validar_parametro(char* cadena){
	if(cadena[0]=='0' && strlen(cadena)==1) return 0;
	for(int i = 0; i < strlen(cadena)-1;i++){
		if(!isdigit(cadena[i]))return -1;
	}
	int numero = atoi(cadena);
	if (numero==0) return -1;
	return numero;
}
/* *****************************************************************
 *                    FUNCION PRINCIPAL
 * *****************************************************************/
		
int main(int argc, char* argv[]){
	if (argc != 3){
		fprintf(stderr, "Error, cantidad de parametros incorrecta\n");
		return -1;
	}
	FILE* file = fopen(argv[1],"r");
	if(!file){
		fprintf(stderr, "Error, no se puede abrir el archivo\n");
		return -1;
	}
	int cant_lineas = validar_parametro(argv[2]);
	if(cant_lineas == -1){
		fclose(file);
		fprintf(stderr, "Error, no se ingreso un parametro valido\n");
		return -1;
	}	
	char* linea = NULL;
	size_t capacidad = 0;
	int cont = 0;
	ssize_t len = 0;
	while(len != -1 && cont < cant_lineas){
		len = getline(&linea, &capacidad, file);
		imprimir(linea,len);
		cont++;
	}
	if(len==-1){
		fprintf(stderr, "Error, el archivo tiene menos lineas que las solicitadas\n");
		free((void*)linea);
		fclose(file);
		return -1;
	}
	printf("Presione enter para mostrar linea siguiente / presione * y luego enter para salir\n");
	char opcion[10];
	do{
		fgets(opcion,10,stdin);
		if(opcion[0] == '*' && opcion[1]=='\n'){
			break;
		}
		else if(opcion[0] == '\n'){
			len = getline(&linea, &capacidad, file);
			if(len==-1){
				printf("Se llego al final del archivo\n");
				break;
			}
			imprimir(linea,len);
		}
		else{
			printf("opcion no valida\n");
			printf("Presione enter para mostrar linea siguiente / presione * y luego enter para salir\n");
		}
	} while(true);
	free((void*)linea);
	fclose(file);
	return 0;
}


