#include <stdio.h>
#include <stdlib.h>
#include "grades.h"
#define SIZE 7

int main(){
	float array[SIZE];
	int number,i,j;
	printf("number of students\n");
	scanf("%d",&number);
	printf("enter the grades of students\n");
	for(i=0;i<number;i++){
		scanf("%f",&array[i]);
	}
	printf("minimum=%.2f\n",minimum(array,number));
	printf("maximum=%.2f\n",maximum(array,number));
	printf("rec_add=%.2f\n",rec_add(array,number));
	float sum=iterative_add(array,number);
	printf("iterative_add=%.2f\n",sum);
	printf("average=%.2f",average(sum,number));
	return 0;
}
