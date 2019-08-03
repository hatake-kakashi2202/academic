#include "grades.h"
#define SIZE 7

float minimum(float arr[],int number){
	float min = arr[0];
	int i;
    for(i=1; i<number; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    return (min);
}

float maximum(float arr[],int number){
    int i;
    float max = arr[0];
    for(i=1; i<number; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
	}
    return (max);
}

float rec_add(float array[],int number){
	if(number<=0)
		return 0;
	else
		return(rec_add(array,number-1)+array[number-1]);
}

float iterative_add(float array[],int number){
	int k;
	float sum1=0;
	for(k=0;k<number;k++){
		sum1=sum1+array[k];
	}
	return sum1;
}

float average(float sum,int number){
	float sum1,num1;
    num1=(float)number;
    sum1=sum/num1;
    return (sum1);
}
