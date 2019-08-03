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


struct node* createNode(value);
struct node* insertNode(struct node* root, int data);
void inorder(struct node* root);
void preorder(struct node* node);
void postorder(struct node* node);
Student *create();
void print(int roll);
void print_all();
void add(Student *ptr);
void update(int rollno,Student *nstudent);
void Delete(int rollno);

