#include <stdio.h>
void Avg(int a[],int num){
	float avg=0;
	int sum=0;
	for(int i=0;i<num;i++){
		sum+=a[i];
	}
	avg=(float)sum/(float)num;
    printf("Average: %f\n", avg);
} 
