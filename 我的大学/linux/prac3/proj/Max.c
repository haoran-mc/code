#include<stdio.h>
void Max(int a[],int num){
	int max=a[0];
	for(int i=0;i<num;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	printf("maximum is %d\n",max);
} 
