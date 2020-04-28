#include "tp0.h"

/* ******************************************************************
 *                     FUNCIONES A COMPLETAR
 * *****************************************************************/

/* swap() intercambia dos valores enteros.
 */
void swap (int* x, int* y) {
	int aux=*x;
	*x=*y;
	*y=aux;
}


/* maximo() busca el mayor elemento del arreglo y devuelve su posicion.
 * Si el vector es de largo 0, devuelve -1.
 */
int maximo(int vector[], int n) {
	if (n==0){
		return -1;
	}
	int pos_may=0;
	for (int i=0;i<n;i++){
		if (vector[i]>vector[pos_may]){
			pos_may=i;
		}
	}
	return pos_may;
}

/* La función comparar recibe dos vectores y sus respectivas longitudes
 * y devuelve -1 si el primer vector es menor que el segundo; 0 si son
 * iguales; y 1 si el segundo es menor.
 *
 * Un vector es menor a otro cuando al compararlos elemento a elemento,
 * el primer elemento en el que difieren no existe o es menor.
 */
int comparar(int vector1[], int n1, int vector2[], int n2) {
	int len;
	if (n1<n2){
		len=n1;
	}
	else{
		len=n2;
	}
	for(int i=0;i<len;i++){
		if(vector1[i]>vector2[i]){
			return 1;
		}
		else if(vector1[i]<vector2[i]){
			return -1;
		}
		else{
			continue;
		}
	}
	if (n1==n2){
		return 0;
	}
	else if(n1<n2){
		return -1;
	}
	else{
		return 1;
	}
}

/* selection_sort() ordena el arreglo recibido mediante el algoritmo de
 * selección.
 */
void seleccion(int vector[], int n) {
	int len=n;
	for(int i=0;i<len;i++){
		int pos_max=maximo(vector,n);
		swap(&vector[n-1],&vector[pos_max]);
		n--;
	}
}

