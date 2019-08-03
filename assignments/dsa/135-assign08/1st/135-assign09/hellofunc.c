#include <stdlib.h>
#include <stdio.h>
#include "hellomake.h"
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

struct node* createNode(value){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
  
  
struct node* insertNode(struct node* root, int data)
{
    if (root == NULL) 
        return createNode(data);

    if (data < root->data)
        root->left  = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);   
    return root;
}

void inorder(struct node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ->", root->data);
    inorder(root->right);
}

void preorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
     printf("%d ->", node->data);   
     preorder(node->left);   
     preorder(node->right); 
}   

void postorder(struct node* node) 
{ 
     if (node == NULL) 
        return; 
     postorder(node->left); 
     postorder(node->right); 
     printf("%d ->", node->data); 
} 

// void findstudent(int roll,struct node *root){
//     if(roll==root->rollno)
//     printf("%s %d %f",root->name,root->rollno,root->cgpa);
//     else{
//         if(roll<root->rollno)
//             findstudent(roll,root->left);
//         else
//             findstudent(roll,root->right);
//     }
// }

Student *create()
{
        Student *temp;
        temp=(Student*)malloc(sizeof(Student));
        printf ("Enter your name roll no and cgpa respectively:\n");
        scanf ("%s %d %d", temp->name,&temp->rollno,&temp->cgpa);
        root = insertNode(root, temp->rollno);
        temp->next_student=NULL;
        return temp;
}

void print(int roll)
{
    Student *s1=NULL;
    s1=(Student*)malloc(sizeof(Student));
    if(head == NULL)
    {
        printf("No Elements");
    }
    s1 = head;
        while(s1->rollno != roll)
        {
            s1 = s1->next_student;
        }
    printf("\nname:%s\n",s1->name);
    printf("roll number:%d\n",s1->rollno);
    printf("cgpa:%0.1f\n",s1->cgpa);
}

void print_all()
{
    Student *temp;
    temp=head;
    while(temp!=NULL)
    {
    printf("\nname:%s\n",temp->name);
    printf("roll number:%d\n",temp->rollno);
    printf("cgpa:%0.1f\n",temp->cgpa);
    temp=temp->next_student;
    }
    free( temp );
}
void add(Student *ptr)
{
    Student *s1=NULL;
    s1=(Student*)malloc(sizeof(Student));
    if(head == NULL)
    {
        head = ptr;
    }
    else
    {
        s1  = head;
        while(s1->next_student != NULL)
        {
            s1 = s1->next_student;
        }
        s1->next_student = ptr;
    }
}
void update(int rollno,Student *nstudent)
{
    Student *s1=NULL,*temp=NULL;
    s1=(Student*)malloc(sizeof(Student));
    temp=(Student*)malloc(sizeof(Student));
    if(head == NULL)
    {
        printf("No Elements");
    }
    if(head->rollno==rollno)
        {
            temp=head->next_student;
            head=nstudent;
            head->next_student=temp;
            return;
        }
    s1 = head;
        while(s1->rollno == rollno)
        {
            s1 = s1->next_student;
        }
    temp=s1->next_student;
    s1->next_student=nstudent;
    nstudent=temp->next_student;
    free( temp );
}
void Delete(int rollno)
{
    Student *s1=NULL,*temp=NULL;
    s1=(Student*)malloc(sizeof(Student));
    temp=(Student*)malloc(sizeof(Student));
    if(head == NULL)
    {
        printf("No Elements");
    }
    if(head->rollno==rollno)
        {
            temp=head;
            head=head->next_student;
            free(temp);
            return;
        }
    s1  = head;
        while(s1->rollno == rollno)
        {
            s1 = s1->next_student;
        }
    if( s1->next_student != NULL )
    {
       temp = s1->next_student;
       s1->next_student = temp->next_student;
       free( temp );
    }
}

