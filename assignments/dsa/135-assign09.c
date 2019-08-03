#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct linked_list* node_ptr;
struct linked_list
{
    char name[20];
    int roll;
    float cgpa;
    node_ptr next;
};
node_ptr head = NULL;
typedef struct tree* tree_node;
struct tree
{
    node_ptr data;
    tree_node left;
    tree_node right;
};
node_ptr addStudent(char *input_name,int input_roll,float input_cgpa)
{
    node_ptr new_node = (node_ptr)malloc(sizeof(struct linked_list));
    strcpy(new_node->name,input_name);
    new_node->roll = input_roll;
    new_node->cgpa = input_cgpa;
    new_node->next = NULL;
    if(head == NULL)
    {
        head = new_node;
        return new_node;
    }
    node_ptr temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    return new_node;
}
void deleteStudentByRollNo(int input_roll)
{
    node_ptr temporary = head;
    node_ptr previous = NULL;
    if(input_roll == head->roll)
    {
        head = head->next;
        free(temporary);
        return;
    }
    while(temporary != NULL &&temporary->roll != input_roll)
    {
        previous = temporary;
        temporary = temporary->next;
    }
    if(temporary->roll == input_roll)
    {
        previous->next = temporary->next;
        free(temporary);
    }
    else if(temporary == NULL)
    {
        printf("ROLL NO DOESN'T EXIST\n");
        return;
    }

}
void updateStudentByRollNo(int input_roll,tree_node input)
{
    node_ptr temporary = head;
    while(temporary->roll!=input_roll && temporary!=NULL)
    {
        temporary = temporary->next;
    }
    if(temporary->roll == input_roll)
    {
        printf("Enter the New name\n");
        scanf("%s",temporary->name);
        printf("Enter the New rollno\n");
        scanf("%d",&temporary->roll);
        printf("Enter the New CGPA\n");
        scanf("%f",&temporary->cgpa);

        input->data->cgpa = temporary->cgpa;
        input->data->roll = temporary->roll;
        strcpy(input->data->name,temporary->name);
    }
    else if(temporary == NULL)
    {
        printf("ROLL NO DOESN'T EXIST\n");
        return;
    }
}
void printStudentByRollNo(int input_roll)
{
    node_ptr temporary = head;
    while(temporary->roll!=input_roll && temporary!=NULL)
    {
        temporary = temporary->next;
    }
    if(temporary->roll == input_roll)
    {
        printf("Name : %s ROLL : %d CGPA : %f\n",temporary->name,temporary->roll,temporary->cgpa);
    }
    else if(temporary == NULL)
    {
        printf("ROLL NO DOESN'T EXIST\n");
        return;
    }
}
void printAllStudents()
{
    node_ptr temporary = head;
    while(temporary != NULL)
    {
        printf("Name : %s ROLL : %d CGPA : %f\n",temporary->name,temporary->roll,temporary->cgpa);
        temporary = temporary->next;
    }
}
tree_node create_node_tree(node_ptr input_ptr)
{
    tree_node new_node = (tree_node)malloc(sizeof(struct tree));
    new_node->data = input_ptr;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
tree_node createBST(tree_node root,node_ptr input_data)
{
    if(root == NULL)
        root = create_node_tree(input_data);
    else if(input_data->roll <= root->data->roll)
        root->left = createBST(root->left,input_data);
    else if(input_data->roll > root->data->roll)
        root->right = createBST(root->right,input_data);

    return root;
}
void printBST(tree_node root)
{
    if(root == NULL)
        return;
    printBST(root->left);
    printf("NAME : %s ROLL : %d CGPA : %f\n",root->data->name,root->data->roll,root->data->cgpa);
    printBST(root->right);
}
tree_node minValueNode(tree_node root)
{
    while(root != NULL)
    {
        root = root->left;
    }
    return root;
}

tree_node deleteNode(tree_node root, int key)
{

    if (root == NULL) return root;


    if (key < root->data->roll)
        root->left = deleteNode(root->left, key);

    else if (key > root->data->roll)
        root->right = deleteNode(root->right, key);

    else
    {

        if (root->left == NULL)
        {
            tree_node temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            tree_node temp = root->left;
            free(root);
            return temp;
        }
        tree_node temp = minValueNode(root->right);

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data->roll);
    }
    return root;
}
tree_node findStudentByRollNo(tree_node root,int input_roll)
{
    if(root==NULL || root->data->roll == input_roll)
        return root;
    if(input_roll <= root->data->roll)
        return findStudentByRollNo(root->left,input_roll);
    else
        return findStudentByRollNo(root->right,input_roll);

}
int main()
{
    int choice,dummy_i,search_roll;
    char input_name[20];
    float dummy_f;
    node_ptr temp;
    tree_node root = NULL;
    tree_node dummy_t;

    do
    {
        printf("\n 1)ADD-STUDENT 2)UPDATE-STUDENT 3)DELETE-STUDENT 4)PRINT-BY-ROLL 5)PRINT-ALL 6)FIND-BY-ROLL(BST) 7)EXIT\nenter your choice -  ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1 :
        {
            printf("ENTER THE DETAILS\n");
            scanf("%s",input_name);
            scanf("%d",&dummy_i);
            scanf("%f",&dummy_f);
            temp = addStudent(input_name,dummy_i,dummy_f);
            root = createBST(root,temp);
        }
        break;
        case 2 :
        {
            printf("ENTER THE ROLL\n");
            scanf("%d",&search_roll);
            dummy_t = findStudentByRollNo(root,search_roll);
            updateStudentByRollNo(search_roll,dummy_t);


        }
        break;
        case 3:
        {
            printf("ENTER THE ROLL\n");
            scanf("%d",&search_roll);
            deleteStudentByRollNo(search_roll);
            root = deleteNode(root,search_roll);

        }
        break;
        case 4 :
        {
            printf("ENTER THE ROLL\n");
            scanf("%d",&search_roll);
            printStudentByRollNo(search_roll);
        }
        break;
        case 5 :
        {
            printAllStudents();
            printf("\n\nSORTED ORDER(inorder tree traversal)\n\n");
            printBST(root);
        }
        break;
        case 6 :
            {
                printf("ENTER THE ROLL\n");
                scanf("%d",&search_roll);
                dummy_t = findStudentByRollNo(root,search_roll);
                if(dummy_t == NULL)
                    printf("NOT FOUND\n");
                else
                    printf("NAME : %s ROLL : %d CGPA %f\n",dummy_t->data->name,dummy_t->data->roll,dummy_t->data->cgpa);
            }
            break;

        }
    }while(choice!=7);
    return 0;
}