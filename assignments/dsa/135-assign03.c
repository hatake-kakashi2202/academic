#include <stdio.h>
#include <stdlib.h>

void solution1(void){
    int number=1;
    int result=1;
   printf("Enter the value of number you want to find factorial\n");
    scanf("%d",&number);
    findfactorialToN(number, &result);    
    printf("\n%d",result);

}

void findfactorialToN(int n, int *product)
{
    if (n == 0)
        *product *= 1;
    else
    {
        *product *= n;
        findfactorialToN(n - 1, product);
     }
}

void solution2(void){
   int array[30];
   int i;
   long int sum=1;
   int *ptr;

   printf("\nsum of first 100 fibnaci numbers\n");
   for(i=2;i<20;i++){
      array[0]=0;
      array[1]=1;
      array[i]=array[i-1]+array[i-2];
   }

   for(i=0;i<20;i++) 
   {
      printf("%d ",array[i]);
   }

   ptr = array;

   for(i=0;i<20;i++) 
   {
      sum = sum + *ptr;
      ptr++;
   }

   printf("\nThe sum is: %ld",sum);
}

void solution3(void){
   int i, number, sum = 0;
   int *array;
 
      printf("Enter the size of the array\n");
      scanf("%d", &number);
 
      array = (int *) malloc(number * sizeof(int));
   for (i = 0; i < number; i++) 
        {
      scanf("%d", array + i);
   }
   for (i = 0; i < number; i++)
   {
      sum = sum + *(array + i);
   }
 
   printf("Sum of all elements in array = %d\n", sum);
}

void solution4(void){
   int x, y;
   printf("Enter the value of x and y\n");
   scanf("%d%d",&x,&y);
   swap(&x, &y);
   printf("After Swapping\nx = %d\ny = %d\n", x, y);
   return 0;
}

void swap(int *a, int *b)
{
   int t;
 
   t  = *b;
   *b = *a;
   *a = t;
}




int main()
{
    int choice;
    printf("\nPlease enter the solution to run: ");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        solution1();
        break;
    case 2:
        solution2();
        break;
    case 3:
        solution3();
        break;
    case 4:
        solution4();
        break;
    default:
        solution1();
        solution2();
        solution3();
        solution4();
    }
}


