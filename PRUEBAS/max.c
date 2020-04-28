#include <stdio.h>
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

int main(void){
	int vector[]={1,2,3,4,5,8,15,5};
	int largo=8;
	int pos=maximo(vector,largo);
	printf("%d",pos);
	return 0;
}
