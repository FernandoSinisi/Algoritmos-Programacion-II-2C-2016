#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testing.h"
#include "heap.h"
#include "heap_utils.h"
#define TAM 20
#define K 25

int comparar1 (const void* a, const void* b){
	char* dir_a = (char*)a;
	char* dir_b = (char*)b;
	if(*dir_a < *dir_b)return (int)-1;
	if(*dir_a == *dir_b)return (int)0;
	return (int)1;
}

void destruir_dato(void* dato){
	free(dato);
}

void prueba_top_k(){
	printf("\nComienza la prueba de top_k\n");
	void** arreglo = malloc(TAM*sizeof(void*));
	for(int i=0;i<TAM;i++){
		int* valor = malloc(sizeof(int));
		*valor = i;
		arreglo[i] = (void*)valor;
	}
	void** menores = top_k(K,arreglo,TAM,comparar);
	for(int i=0;i<K;i++){
		if(!menores[i])printf("NULL ");
		else printf("%d  ",*(int*)menores[i]);
	}
	printf("\n");
	for(int i=0;i<TAM;i++)free(arreglo[i]);
	free(arreglo);
	free(menores);
}

void prueba_actualizar_heap(){
	printf("\nComienza la prueba de actualizar prioridad\n");
	void** arreglo = malloc(TAM*sizeof(void*));
	for(int i=0;i<TAM;i++){
		int* valor = malloc(sizeof(int));
		*valor = i;
		arreglo[i] = (void*)valor;
	}
	
	heap_t* heap = heap_crear_arr(arreglo,TAM,comparar1);
	if(!heap)return;
	void** heapify = malloc(TAM*sizeof(void*));
	for(size_t i=0;i<TAM;i++)heapify[i] = heap_desencolar(heap);
	for(size_t i=0;i<TAM;i++)printf("%d ",*(int*)heapify[i]);
	printf("\n");
	 
	heap_t* ordenado = heap_crear_arr(heapify,TAM,comparar1);
	for(int i=TAM/2;i<TAM;i++){
		*(int*)heapify[i] = i/4;
		heap_actualizar_prioridad(heap,heapify[i]);
	}
	
	void** heapify2 = malloc(TAM*sizeof(void*));
	for(size_t i=0;i<TAM;i++)heapify2[i] = heap_desencolar(ordenado);
	for(size_t i=0;i<TAM;i++)printf("%d ",*(int*)heapify2[i]);
	printf("\n");
	
	for(size_t i=0;i<TAM;i++){
		free(heapify2[i]);
	}	
	heap_destruir(ordenado,NULL);
	heap_destruir(heap,NULL);
	free(heapify2);
	free(heapify);
	free(arreglo);	  	
}

int main()
{	prueba_top_k();
	prueba_actualizar_heap();
	return 0;
}

