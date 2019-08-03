#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TOTAL_STUDENTS 4
typedef struct student{
	char Student_name[10];
	int rollno;
	float cgpa;
	struct student* next;
	struct student* favorite_student;
}Student;
Student *g_students[TOTAL_STUDENTS];
void populate_student_details(){
int i;
	for(i=0;i<TOTAL_STUDENTS;i++){
		g_students[i]=(Student *)malloc(sizeof(Student));
		printf("enter student details student name,rollno and cgpa respectively:  ");
		scanf("%s %d %f",(g_students[i]->Student_name),&(g_students[i]->rollno),&(g_students[i]->cgpa));
		g_students[i]->favorite_student=NULL;
	}
	for(i=0;i<TOTAL_STUDENTS;i++){
		printf("entered student details student name,rollno and cgpa respectively:  ");
		printf("\n%s %d %.2f\n",(g_students[i]->Student_name),(g_students[i]->rollno),(g_students[i]->cgpa));
	}
}
int find_index(int roll_no){
	int i;
	for(i=0;i<TOTAL_STUDENTS;i++){
		if((g_students[i]->rollno)==roll_no){
			return i;
			break;
		}
	}
}
void make_favorite_student(int roll1,int roll2){
	int index1=find_index(roll1);
	int index2=find_index(roll2);
	g_students[index1]->favorite_student=g_students[index2];
	printf("%d %f",g_students[index1]->favorite_student->rollno,g_students[index1]->favorite_student->cgpa);
}
void print_fav_chain(Student *sptr){
	if(sptr!=NULL){
		printf("%s %d %f",sptr->Student_name,sptr->rollno,sptr->cgpa);
		print_fav_chain(sptr->favorite_student);
	}
}
void print_from_student(){
	int roll_no;
	scanf("%d",&roll_no);
	int j=find_index(roll_no);
	print_fav_chain(g_students[j]);
}
int main(){
	int choice;
	int roll_no,i,roll1,roll2;
    printf("\nPlease enter the solution to run: ");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        populate_student_details();
    case 2:
		printf("enter rollno");
		scanf("%d",&roll_no);
		printf("%d ",find_index(roll_no));
    case 3:
		printf("enter rollno1 & rollno2");
		scanf("%d %d",&roll1,&roll2);
		make_favorite_student(roll1,roll2);
		make_favorite_student(2,3);
		make_favorite_student(3,4);
    case 4:
        print_fav_chain(g_students[0]);
        print_from_student();
    default:
    	break;
    }	
}