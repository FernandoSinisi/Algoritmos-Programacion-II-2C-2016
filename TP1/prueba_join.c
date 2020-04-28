#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strutil.c"

int main(){
	char* cadena = ",,,,,";
	char* cad3 = "8 9 *";
	char** lista = split(cadena,',');
	char** lista3 = split(cad3,' ');
	char* cad_join1 = join(lista3,' ');
	char* cad_join2 = join(lista,',');
	printf("join (%s)\n",cad_join1);
	printf("join (%s)\n",cad_join2);
	free_strv(lista);
	free_strv(lista3);
	free(cad_join1);
	free(cad_join2);
	return 0;
}	
