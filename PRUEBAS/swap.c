#include <stdio.h>
void swap (int* x, int* y) {
	int aux=*x;
	*x=*y;
	*y=aux;
}
int main(void){
	int x=4;
	int y=3;
	swap(&x,&y);
	printf("%d %d",x,y);
	return 0;
}


