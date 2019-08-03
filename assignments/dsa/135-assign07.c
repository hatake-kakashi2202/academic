#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#define SIZE 50

int rec_add(int array[],int number){
	if(number<=0)
		return 0;
	else
		return(rec_add(array,number-1)+array[number-1]);
}


int loops(int array[],int number){
	int sum1=0;
	printf("\n\nmethod-1 using loops\n");
    struct timespec start, finish; 
    clock_gettime(CLOCK_REALTIME, &start); 
	for(int k=0;k<number;k++){
		sum1=sum1+array[k];
	}
    int i,j;
    for (i=0,j=0; i<100000000; i++) { j+=i*i; }     

    clock_gettime(CLOCK_REALTIME, &finish); 

    long seconds = finish.tv_sec - start.tv_sec; 
    long ns = finish.tv_nsec - start.tv_nsec; 
    
    if (start.tv_nsec > finish.tv_nsec) { // clock underflow 
	--seconds; 
	ns += 1000000000; 
    } 
    printf("seconds without ns: %ld\n", seconds); 
    printf("nanoseconds: %ld\n", ns); 
    printf("total seconds: %e\n", (double)seconds + (double)ns/(double)1000000000); 
	printf("sum=%d\n",sum1);
}


int recursion(int array[],int number){
	printf("\n\nmethod-2 using recursion\n");
	int sum2=0;
    struct timespec start, finish; 
    clock_gettime(CLOCK_REALTIME, &start);
    sum2=rec_add(array,number);
	 int i,j;
    for (i=0,j=0; i<100000000; i++) { j+=i*i; }     

    clock_gettime(CLOCK_REALTIME, &finish); 

    long seconds = finish.tv_sec - start.tv_sec; 
    long ns = finish.tv_nsec - start.tv_nsec; 
    
    if (start.tv_nsec > finish.tv_nsec) { // clock underflow 
	--seconds; 
	ns += 1000000000; 
    } 
    printf("seconds without ns: %ld\n", seconds); 
    printf("nanoseconds: %ld\n", ns); 
    printf("total seconds: %e\n", (double)seconds + (double)ns/(double)1000000000); 
	printf("sum=%d\n",sum2);
}


int gauss(int array[],int number){
	int k;
	printf("\n\nmethod-3 using gauss technique\n");
	int sum4=0;
	int copy[SIZE];
    struct timespec start, finish; 
    clock_gettime(CLOCK_REALTIME, &start);	for(k=0;k<number;k++){
		copy[k]=array[number-k-1];
	}
	for(k=0;k<number;k++){
		sum4=sum4+array[k]+copy[k];
	}
 	int i,j;
    for (i=0,j=0; i<100000000; i++) { j+=i*i; }     

    clock_gettime(CLOCK_REALTIME, &finish); 

    long seconds = finish.tv_sec - start.tv_sec; 
    long ns = finish.tv_nsec - start.tv_nsec; 
    
    if (start.tv_nsec > finish.tv_nsec) { // clock underflow 
	--seconds; 
	ns += 1000000000; 
    } 
    printf("seconds without ns: %ld\n", seconds); 
    printf("nanoseconds: %ld\n", ns); 
    printf("total seconds: %e\n", (double)seconds + (double)ns/(double)1000000000); 
	printf("sum=%d\n",sum4/2);

}


int formula(int array[],int number){
	printf("\n\nmethod-4 using formula");
	int sum3=0;
    struct timespec start, finish; 
    clock_gettime(CLOCK_REALTIME, &start);	sum3=number*(number+1)/2;
	 int i,j;
    for (i=0,j=0; i<100000000; i++) { j+=i*i; }     

    clock_gettime(CLOCK_REALTIME, &finish); 

    long seconds = finish.tv_sec - start.tv_sec; 
    long ns = finish.tv_nsec - start.tv_nsec; 
    
    if (start.tv_nsec > finish.tv_nsec) { // clock underflow 
	--seconds; 
	ns += 1000000000; 
    } 
    printf("seconds without ns: %ld\n", seconds); 
    printf("nanoseconds: %ld\n", ns); 
    printf("total seconds: %e\n", (double)seconds + (double)ns/(double)1000000000); 
	printf("\nsum(prints correctly if given input is in order)=%d\n",sum3);
}


int pointer(int array[],int number){
	printf("\n\nmethod-5 using multiple pointers");
	int sum5=0;
    struct timespec start, finish; 
    clock_gettime(CLOCK_REALTIME, &start);    int l=number-1;
    int k=0;
   	if(number%2==0){
   		while(k<l){
   			sum5=sum5+array[l]+array[k];
   			l--;
   			k++;
   		}
   	}
   	if(number%2!=0){
   		while(k!=l){
   			sum5=sum5+array[l]+array[k];
   			l--;
   			k++;
  		}
  		sum5=sum5+array[number/2];
   	}
	 int i,j;
    for (i=0,j=0; i<100000000; i++) { j+=i*i; }     

    clock_gettime(CLOCK_REALTIME, &finish); 

    long seconds = finish.tv_sec - start.tv_sec; 
    long ns = finish.tv_nsec - start.tv_nsec; 
    
    if (start.tv_nsec > finish.tv_nsec) { // clock underflow 
	--seconds; 
	ns += 1000000000; 
    } 
    printf("seconds without ns: %ld\n", seconds); 
    printf("nanoseconds: %ld\n", ns); 
    printf("total seconds: %e\n", (double)seconds + (double)ns/(double)1000000000); 
	printf("\nsum=%d\n",sum5);	
}





int main(int argc, char *argv[]){
	int i,j,k,l,m,sum1=0,number=0;
	int array[SIZE];
	printf("enter number of elements you want to scan:\n");
	scanf("%d",&number);
	for(i=0;i<number;i++){
		scanf("%d",&array[i]);
	}
	// number=atoi(argv[1]);
	// for(i=0;i<number;i++){
	// 	array[i]=atoi(argv[i+2]);
	// }
	// for(i=0;i<number;i++){
	// 	printf("%d ",array[i]);
	// }
	loops(array,number);
	recursion(array,number);
	gauss(array,number);
	formula(array,number);
	pointer(array,number);
	int num=atoi(argv[1]);
	printf("\n\n");
	int c; 
	int lower=atoi(argv[2]);
	int upper=atoi(argv[3]);
    for (c = 0; c < atoi(argv[1]); c++) { 
        int num = (rand()%(upper - lower + 1))+lower; 
        printf("%d ", num); 
    } 
}

