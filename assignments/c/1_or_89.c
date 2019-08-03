

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(){
int i=0,num=0,sum=0,m=0,count=0,sumsqr=0,n=0,j=0,k=0;
char name[100];
int number[10000];

printf("Please enter your name:\n");
gets(name);

while(name[i] != '\0')
{
sum = sum + name[i];
i++;
}
num = sum % 9;
if(num == 0)
printf("%s,your lucky number is = 9 \n", name);
else
printf("%s,your lucky number is = %d \n", name, num);

printf("%s,you belong to %d-kind\n\n\n\n", name, kind(num));

printf("Please enter a number: \n");
scanf("%d",&n);

kind(n);

for(j=1;j<=n;++j){
if(kind(j)==1)
{
number[k]=j;
k++;
count++;
}
}

printf("Following %d numbers are inbetween 1 and %d end in 1 kind\n",count,n);
for(m=0;m<k;m++){
printf("%d ",number[m]);
}
}

int kind(int num){
int sumsqr=0,x;
while(num!=0 )
{
sumsqr+=((num%10)*(num%10));
num=num/10;
}
if (sumsqr==1)
return (sumsqr);
else if(sumsqr==89)
return (sumsqr);
else
kind(sumsqr);
}


