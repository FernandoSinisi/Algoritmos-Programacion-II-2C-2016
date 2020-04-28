#include<stdio.h>
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

int main(void){
	int vec1[]={1,2,3,2,8};
	int l1=5;
	int vec2[]={1,2,3,4};
	int l2=4;
	int mayor;
  	mayor=comparar(vec1,l1,vec2,l2);
	printf("%d",mayor);
	return 0;
}
