#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
struct dbms{
  char firstname[30];
  char lastname[30];
  unsigned long id;
  float cgpa;
};
struct dbms record[50];

int main(){
    int i,j,k,l;
    int choice;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s %s %lu %f",&record[i].firstname,&record[i].lastname,&record[i].id,&record[i].cgpa);        
    }
     for(i=0;i<n;i++){
         printf("%s %s %lu %0.2f\n",record[i].firstname,record[i].lastname,record[i].id,record[i].cgpa);        
     }

        addstudent(n,record);
        findstudent(n,record);
        findstudents(n,record);
        totalstudents(n,record);
}
  
void addstudent(int n,struct dbms record[]){
  printf("enter your id or add your details\n");
    int i;
    unsigned long id;
 scanf("%lu",&id);
    for(i=0;i<n;i++)
        if(record[i].id==id)
        {
            printf("you are already in the list");
            break;
        }
        else{
        printf("your details are going to added\n");
        scanf("%s %s %lu %f",&record[n+1].firstname,&record[n+1].lastname,&record[n+1].id,&record[n+1].cgpa);
        printf("%s %s %lu %0.2f\n",record[n+1].firstname,record[n+1].lastname,record[n+1].id,record[n+1].cgpa);      
        }
        n++;
}

void findstudent(int n,struct dbms record[]){
  printf("your id to show your details\n");
  unsigned long id;
  int i;
 scanf("%lu",&id);
    for(i=0;i<=n;i++){
        if(record[i].id==id)
        printf("%s %s %lu %0.2f\n",record[i].firstname,record[i].lastname,record[i].id,record[i].cgpa);      
    }
}

void findstudents(int n,struct dbms record[]){
  printf("you are in the third function\n");
    int i,j,k,l;
    unsigned long id;
    char firstname[30];
    scanf("%s",&firstname);
    scanf("%lu",&id);
    for(int j=0;j<n;j++){
        if(strcmp(record[j].firstname,firstname)==0)
        if(strcmp(record[j].id,id)==0)
        printf("%s %s %lu %0.2f\n",record[j].firstname,record[i].lastname,record[i].id,record[i].cgpa);      
    }    
}

void totalstudents(int n,struct dbms record[]){
  printf("you are in the total students function\n");
  printf("%d",n);
}