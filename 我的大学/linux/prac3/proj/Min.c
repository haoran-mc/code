#include<stdio.h>
void Min(int a[],int num){
	int min=a[0];
	for(int i=0;i<num;i++){
		if(a[i]<min){
			min=a[i];
		}
	}
	printf("minimum is %d\n",min);
} 
