#include<stdio.h>
#include<stdlib.h>
#define MAX_STUDENTS 50

typedef struct Student{
  char name[20];
  int rollno;
  int cgpa;
  struct Student *next;
} Student;
Student *g_student;
Student *g_student_index[MAX_STUDENTS];
int count;
Student *create (){
  Student *temp;
  temp = (Student *) malloc (sizeof (Student));
  printf ("Enter your name roll no and cgpa respectively:\n");
  scanf ("%s %d %d", temp->name,&temp->rollno,&temp->cgpa);
  temp->next = NULL;
  return (temp);
}

void print(Student * printing){
  printf ("%s ", printing->name);
  printf ("%d ", printing->rollno);
  printf ("%d\n", printing->cgpa);
}

void print_from (Student * printingfrom){
  print (printingfrom);
  if (printingfrom->next != NULL){
      print_from (printingfrom->next);
   }
}

void print_all(){
  print_from (g_student);
}

void add(Student * add){
  Student *student1;
  student1 = create ();
  if (g_student == NULL){
      g_student = student1;
  }
  else{
      Student *student2;
      student2 = g_student;
      while (student2->next != NULL){
      student2 = student2->next;
      }
      student2->next = student1;
  }
}

void update(int location, Student *update){
  if (location > count){
      printf ("there is no location.");
      printf ("current no of indices are :%d", count);
  }
  else{
      Student *student1;
      int i;
      student1 = g_student;
      while (i < location - 2){
      student1 = student1->next;
      i++;
      }
      update = student1;
      student1 = update;
      print_all ();
  }
}

void insert(int loc1, Student *in){
  if (loc1 > count){
      printf ("there is no location.");
  }
  else{
      Student *student1, *student2;
      int i;
      student1 = g_student;
      while (i < loc1){
      student1 = student1->next;
      i++;
      }
      student2 = create ();
      student2->next = student1->next;
      student1->next = student2;
      count++;
      print_all ();
   }
}

void delete_det(int loc2){
  Student *temp2;
  Student *student1, *student2;
  if (loc2 > count){
      printf ("there is no location.");
      printf ("current no of indices are :%d", count);
  }
  else if (loc2 == 1){
      temp2 = g_student;
      g_student = temp2->next;
      temp2->next = NULL;
      free (temp2);
      count--;
  }
  else{
      int i = 1;
      student1 = g_student;
      while (i < loc2 - 1){
     student1 = student1->next;
     i++;
     }
      student2 = student1->next;
      student1->next = student2->next;
      student2->next = NULL;
      free (student2);
      count--;
      print_all ();
  }
}

Student *get(int index)
{
  Student *temp3, *student1;
  if (index > count){
      printf ("there is no location.");
      printf ("current no of indices are :%d", count);
  }
  else{
      student1 = g_student;
      int i = 1;
      while (i < index){
      student1 = student1->next;
      i++;
      }
      temp3 = student1->next;
      return temp3;
  }
}

void add_to_index(Student *student)
{
    g_student_index[count]=student;
    count++;
}

void Print_by_index()
{
    for(int i=0;i<count;i++)
    {
        print(g_student_index[i]);
    }
}

void search(int roll1)
{
    int low=0;
    int high=count-1;
    int middle =(high+low)/2;
    while (low<= high) {
      if (g_student_index[middle]->rollno < roll1)
         low = middle + 1;
      else if (g_student_index[middle]->rollno == roll1) {
         print(g_student_index[middle]);
         break;
      }
      else
         low = middle - 1;

      middle = (high + low)/2;
   }
}

void update_index()
{
    int i,j;
    Student *temp;
    for(i=0;i<count;i++)
    {
        for(j=i+1;j<count;j++)
            if(g_student_index[j]->rollno < g_student_index[i]->rollno)
        {
            temp=g_student_index[j];
            g_student_index[j]=g_student_index[i];
            g_student_index[i]=temp;
        }
    }
}

void delete_from_index(Student *student)
{
    int i,j;
    for(i=0;;i++)
    {
        if(g_student_index[i]==student);
        break;
    }
    for(j=i;j<MAX_STUDENTS;j++)
    {
        g_student_index[j]=g_student_index[j+1];
    }
}

int main(){
  Student *student, *student1, *student2;
  int index, index2, index3, index4;
  int choice;
  printf("1:to create\n2:enter index and replace\n3:to insert\n4:to delete\n5:student details\n");
  scanf("%d",&choice);
  switch(choice){
  case 1:{ 
  printf ("How many students you want to enter:");
  scanf ("%d", &count);
  for (int i = 0; i < count; i++){
      add (student);
    }
  }
  case 2:{
   printf("students details entered\n");
  print_all (g_student);
  }
  case 3:{
  printf ("please enter the index to replace out of %d: ", count);
  scanf ("%d", &index);
  if (index > count){
      printf ("there is no location.");
      printf ("current no of indices are : %d", count);
  }
  else{
      Student *student3;
      Student *student4;
      int i;
      student3 = g_student;
      while (i < index - 2){
      student3 = student3->next;
      i++;
      }
      student4 = student3;
      student4 = create ();
      student3 = student4;
      update (index, student4);
    }
   }
   case 4:{
   printf ("enter the index to insert out of %d: ", count);
   scanf ("%d", &index2);
   insert (index2, g_student);
   }
   case 5:{
   printf ("enter the index to delete within %d: ", count);
   scanf ("%d", &index3);
   delete_det (index3);
   }
   case 6:{
   printf ("please enter the index for student details within %d: ", count);
   scanf ("%d", &index4);
   student1 = get(index4-1);
   print(student1);
   }
   case 7:
     update_index();
   case 8:{
     int roll1;
     printf("Please enter a roll number of student : \n");
     scanf("%d",&roll1);
     search(roll1);
   }
   case 9:
     Print_by_index();
      break;
 }
}
