/*prueba vector*/
#include<stdio.h>


void imprimir(const int v[], int s) {
for(int i = 0; i < s; i++){
	printf("%d\n", v[i]);
	}
}

int main(void){
	int vector[]={1,2,3,4};
	int largo=4;
	printf("%p\n%d\n",vector,vector[0]);
	imprimir(vector,largo);
	return 0;
}
