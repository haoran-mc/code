#include<stdio.h>
void Sum(int a[],int num){
	int sum=0;
	for(int i=0;i<num;i++){
		sum+=a[i];
	}
	printf("Sum is %d\n",sum);
} 
