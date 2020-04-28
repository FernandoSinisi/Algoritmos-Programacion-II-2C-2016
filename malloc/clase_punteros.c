
#include <stdio.h>
#include <stdlib.h>

void no_incrementar(int punt){
    punt += 1;
}

void incrementar(int *punt){
    *punt += 1;
}

int main(void) {
    // Pido memoria para un entero 
	int *puntero = (int *) malloc(1 * sizeof(int));

    if (puntero == NULL){ // chequeo el puntero
        printf("FALLO (me quede sin memoria)\n");
        return 1;
    }

	*puntero = 38 ;

	printf("Valor de puntero: %p\n", puntero);

	incrementar(puntero); // ahora vale 39
    no_incrementar(*puntero); // sigue valiendo 39

	int valor;
	valor = *puntero; // Obtengo el valor guardado en puntero.

	printf("Valor de valor: %d\n", valor); 
	printf("Valor de contenido del puntero: %d\n", *puntero); 
	
    free(puntero); // INCAPIE AQUI! siempre liberar la memoria que pedimos!
	return 0;
}

