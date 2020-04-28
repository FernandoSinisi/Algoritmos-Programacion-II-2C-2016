#include<stdio.h>
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

void swap (int* x, int* y) {
	int aux=*x;
	*x=*y;
	*y=aux;
}

void seleccion(int vector[], int n) {
	int len=n;
	for(int i=0;i<len;i++){
		int pos_max=maximo(vector,n);
		swap(&vector[n-1],&vector[pos_max]);
		n--;
	}
}

int main(void){
	int vec1[]={1,2,3,8,6,8,9,15};
	int largo=8;
	for (int i=0;i<largo;i++){
		printf("%d",vec1[i]);
	}
	seleccion(vec1,largo);
	for (int i=0;i<largo;i++){
		printf("%d",vec1[i]);
	}
	return 0;
}
	
