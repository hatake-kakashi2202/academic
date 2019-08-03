#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
   {
       char fname[10];
       char lname[10];
       char rollno[12];
       float CGPA;
   }s[50];

void addstudent(void)
{
    int n,i=0,j=0,k=0;

   printf("No of students you want to add\n");
   scanf("%d",&n);
   if(n<=50)
   {
   for(k=0;k<n;)
   {
   scanf("%s",s[i].fname);
   scanf("%s",s[i].lname);
   scanf("%s",s[i].rollno);
   scanf("%f",&s[i].CGPA);
   int flag=0;
   for(j=0;j<i;j++)
   {
   if(strcmp(s[i].rollno,s[j].rollno)==0)
   {
       flag++;
       k++;
       if(k==n-1)
       {

           s[i].CGPA=-1;
       }

       printf("Already exists\n");
       break;

   }
   }

   if(flag==0)
   {
       i++;
       k++;
   }
   }
   }
   else
   {
       printf("More no of students than mentioned");
   }
   /*for(k=0;k<i;k++)
   {
   printf("%s ",s[k].fname);
   printf("%s ",s[k].lname);
   printf("%s ",s[k].rollno);
   printf("%f ",s[k].CGPA);
   }*/

}

void rno(void)
{
    char m[12];
    int flag=1,i;
   printf("Enter the roll no: ");
   scanf("%s",m);
   i=0;
   while(s[i].CGPA!='\0')
   {
   if(strcmp(s[i].rollno,m)==0)
   {
        printf("%s ",s[i].fname);
        printf("%s ",s[i].lname);
        printf("%s ",s[i].rollno);
        printf("%f ",s[i].CGPA);
        flag=0;
        break;

   }
   else
   {
       i++;
   }
   }
   if(flag!=0)
   {
       printf("No such student");
   }

}
void fname(void)
{
    printf("\n");
    char fn[12];
    int i,flag=1;
   printf("Enter the first name: ");
   scanf("%s",fn);
   i=0;
   while(s[i].CGPA!='\0')
   {
   if(strcmp(s[i].fname,fn)==0)
   {
        printf("%s ",s[i].fname);
        printf("%s ",s[i].lname);
        printf("%s ",s[i].rollno);
        printf("%f ",s[i].CGPA);
        i++;
        printf("\n");
        flag=0;


   }
   else
   {
       i++;
   }
   }
   if(flag!=0)
   {
       printf("No such student");
   }


}
void noofstudents(void)
{
   int i=0;
   while(s[i].CGPA!='\0'&&s[i].CGPA>0)
   {
       i++;
   }
   printf("No of students=%d",i);
}

int main()
{
    int choice;
    while(1)
    {
    printf("\nEnter the choice:");
    scanf("%d",&choice);

    switch(choice){
    case 1:
        addstudent();
        continue;
    case 2:
        rno();
        continue;
    case 3:
        fname();
        continue;
    case 4:
        noofstudents();
        continue;
    default:
        {
        exit;
        return 0;
        break;
        }

    }

    }
}
