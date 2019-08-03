#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 50
typedef struct student
{
    char name[50];
    int rollno;
    float cgpa;
    struct student *next_student;
}Student;
Student *g_student_index[MAX_STUDENTS];
Student *head=NULL;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node *root=NULL;


int main()
{
    int choice,rollno;
    Student *ptr;
    do{
    printf("\n1:to create\n2:update student by rollno\n3:delete student by rollno\n4:print student by rollno\n5:print all students\n6:inorder\n7:postorder\n8:preorder\n9:exit\n");
    printf("\nPlease enter the solution to run: ");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        head=create();
        break;
    case 2:
        printf("enter the roll number:\n");
        scanf("%d",&rollno);
        ptr=create();
        update(rollno,ptr);
        break;
    case 3:
        printf("enter the the roll number:\n");
        scanf("%d",&rollno);
        Delete(rollno);
        break;
    case 4:
        printf("enter the roll number:\n");
        scanf("%d",&rollno);
        print(rollno);
        break;
    case 5:
        print_all();
        break;
    case 6:
        inorder(root);
        break;
    case 7:
        postorder(root);
        break;
    case 8:
        preorder(root);
        break;
    // case 9:
    //     printf("enter the roll number:\n");
    //     scanf("%d",&rollno);
    //     findstudent(rollno,root);
    //     break;
    }
 }while(choice!=9);
}
