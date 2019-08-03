#include<stdio.h>
#include<stdlib.h>
struct student
{
    char firstname[20];
    char lastname[20];
    int rollno;
    int cgpa;
    struct student* ptr;
};
struct student *laststudent=NULL;
void onestudent(struct student *s)
{
     printf("Enter your first name:");
            scanf("%s",s->firstname);
            printf("Enter your last name:");
            scanf("%s",s->lastname);
            printf("Enter your roll no:");
            scanf("%d",&s->rollno);
            printf("Enter your CGPA:");
            scanf("%d",&s->cgpa);
            s->ptr=NULL;
}
void addstudent(struct student *s,struct student *laststudent)
{
if(laststudent==NULL)
        {
             printf("Enter your first name:");
            scanf("%s",s->firstname);
            printf("Enter your last name:");
            scanf("%s",s->lastname);
            printf("Enter your roll no:");
            scanf("%d",&s->rollno);
            printf("Enter your CGPA:");
            scanf("%d",&s->cgpa);
            laststudent=s;
            s->ptr=NULL;
        }
        else
        {
            laststudent->ptr=(struct student *)malloc(sizeof(struct student));
            laststudent=laststudent->ptr;
            printf("Enter your first name:");
            scanf("%s",laststudent->firstname);
            printf("Enter your last name:");
            scanf("%s",laststudent->lastname);
            printf("Enter your roll no:");
            scanf("%d",&laststudent->rollno);
            printf("Enter your CGPA:");
            scanf("%d",&laststudent->cgpa);


        }
}
void populate(struct student *pr1,struct student *pr2)
{

     pr1->ptr=pr2;
}
void printstruct(struct student *s)
{
     printf("%s\n",s->firstname);
     printf("%s\n",s->lastname);
     printf("%d\n",s->rollno);
     printf("%d\n",s->cgpa);
     if(s->ptr!=NULL)
     {
         printstruct(s->ptr);
     }
}
void morestudent(int *p,struct student *s)
{
    for(int i=0;i<*p;i++)
    {
       addstudent(s,laststudent);
       printstruct(s);
    //  printf("%s\n",s->firstname);
    //  printf("%s\n",s->lastname);
    //  printf("%d\n",s->rollno);
    //  printf("%d\n",s->cgpa);
    // s->ptr;

    }
}
int main()
{
    struct student *s1,*s2;
    int n;
    s1=( struct student *)malloc(sizeof(struct student));
    s2=( struct student *)malloc(sizeof(struct student));
    onestudent(s1);
    onestudent(s2);
    populate(s1,s2);
    printstruct(s1);
     printf("How many student details you want to enter:");
    scanf("%d",&n);
    morestudent(&n,s1);
 }

