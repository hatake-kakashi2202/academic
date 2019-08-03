#include <stdio.h>
#include <stdlib.h>
#define CHAR_SIZE 26

struct Trie
{
    int isLeaf; 
    struct Trie* character[CHAR_SIZE];
};

typedef struct avltree
{
    int data;
    struct avltree *left,*right;
    int height;
}avltree;
 
avltree *avlinsert(avltree *,int);
avltree *avlDelete(avltree *,int);
void preorder(avltree *);
void inorder(avltree *);
void postorder(avltree *); 
int height( avltree *);
avltree *rotateright(avltree *);
avltree *rotateleft(avltree *);
avltree *rotateleftright(avltree *);
avltree *rotaterightleft(avltree *);
int BF(avltree *);
avltree *avlSearch(avltree*,int);

avltree * avlSearch(avltree *root, int key){ 
    while (root != NULL) 
    { 
        if (key > root->data) 
            root = root->right; 
  
        else if (key < root->data) 
            root = root->left; 
        else
            return 1; 
    } 
    return 0; 
} 

avltree * avlinsert(avltree *node,int key){
    if(node==NULL)
    {
        node=(avltree*)malloc(sizeof(avltree));
        node->data=key;
        node->left=NULL;
        node->right=NULL;
    }
    else
        if(key > node->data)    
        {
            node->right=avlinsert(node->right,key);
            if(BF(node)==-2)
                if(key>node->right->data)
                    node=rotateleft(node);
                else
                    node=rotaterightleft(node);
        }
        else
            if(key<node->data)
            {
                node->left=avlinsert(node->left,key);
                if(BF(node)==2)
                    if(key < node->left->data)
                        node=rotateright(node);
                    else
                        node=rotateleftright(node);
            }
        
        node->height=height(node);
        
        return(node);
}
 
avltree * avlDelete(avltree *node,int key){
    avltree *p;
    
    if(node==NULL)
    {
        return NULL;
    }
    else
        if(key > node->data)
        {
            node->right=avlDelete(node->right,key);
            if(BF(node)==2)
                if(BF(node->left)>=0)
                    node=rotateright(node);
                else
                    node=rotateleftright(node);
        }
        else
            if(key<node->data)
            {
                node->left=avlDelete(node->left,key);
                if(BF(node)==-2)
                    if(BF(node->right)<=0)
                        node=rotateleft(node);
                    else
                        node=rotaterightleft(node);
            }
            else
            {
                if(node->right!=NULL)
                {
                    p=node->right;
                    
                    while(p->left!= NULL)
                        p=p->left;
                    
                    node->data=p->data;
                    node->right=avlDelete(node->right,p->data);
                    
                    if(BF(node)==2)
                        if(BF(node->left)>=0)
                            node=rotateright(node);
                        else
                            node=rotateleftright(node);
                }
                else
                    return(node->left);
            }
    node->height=height(node);
    return(node);
}

int height(avltree *node){
    int lh,rh;
    if(node==NULL)
        return(0);
    
    if(node->left==NULL)
        lh=0;
    else
        lh=1+node->left->height;
        
    if(node->right==NULL)
        rh=0;
    else
        rh=1+node->right->height;
    
    if(lh>rh)
        return(lh);
    
    return(rh);
}

int BF(avltree *node)
{
    int lh,rh;
    if(node==NULL)
        return(0);
 
    if(node->left==NULL)
        lh=0;
    else
        lh=1+node->left->height;
 
    if(node->right==NULL)
        rh=0;
    else
        rh=1+node->right->height;
 
    return(lh-rh);
}
  
avltree * rotateright(avltree *key1){
    avltree *key2;
    key2=key1->left;
    key1->left=key2->right;
    key2->right=key1;
    key1->height=height(key1);
    key2->height=height(key2);
    return(key2);
}
 
avltree * rotateleft(avltree *key1)
{
    avltree *key2;
    key2=key1->right;
    key1->right=key2->left;
    key2->left=key1;
    key1->height=height(key1);
    key2->height=height(key2);
    
    return(key2);
}

 
 
avltree * rotateleftright(avltree *node)
{
    node->left=rotateleft(node->left);
    node=rotateright(node);
    
    return(node);
}
 
avltree * rotaterightleft(avltree *node)
{
    node->right=rotateright(node->right);
    node=rotateleft(node);
    return(node);
}
 

void preorder(avltree *node)
{
    if(node!=NULL)
    {
        printf("%d  ",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}
 
void inorder(avltree *node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%d  ",node->data);
        inorder(node->right);
    }
}

void postorder(avltree* node) 
{ 
     if (node == NULL) 
        return; 
     postorder(node->left); 
     postorder(node->right); 
     printf("%d  ",node->data);
} 

struct Trie* getNewTrieNode(){
    struct Trie* node = (struct Trie*)malloc(sizeof(struct Trie));
    node->isLeaf = 0;

    for (int i = 0; i < CHAR_SIZE; i++)
        node->character[i] = NULL;

    return node;
}

void trieinsert(struct Trie* *head, char* str){
    struct Trie* curr = *head;

    while (*str)
    {
        if (curr->character[*str - 'a'] == NULL)
            curr->character[*str - 'a'] = getNewTrieNode();

        curr = curr->character[*str - 'a'];
        str++;
    }
    curr->isLeaf = 1;
}

int triesearch(struct Trie* head, char* str){

    if (head == NULL)
        return 0;

    struct Trie* curr = head;
    while (*str)
    {
        curr = curr->character[*str - 'a'];
        if (curr == NULL)
            return 0;
        str++;
    }
    return curr->isLeaf;
}

int haveChildren(struct Trie* curr){
    for (int i = 0; i < CHAR_SIZE; i++)
        if (curr->character[i])
            return 1;   

    return 0;
}

int triedelete(struct Trie* *curr, char* str){
    if (*curr == NULL)
        return 0;
    if (*str)
    {
        if (*curr != NULL && (*curr)->character[*str - 'a'] != NULL && triedelete(&((*curr)->character[*str - 'a']), str + 1) && (*curr)->isLeaf == 0)
        {
            if (!haveChildren(*curr))
            {
                free(*curr);
                (*curr) = NULL;
                return 1;
            }
            else {
                return 0;
            }
        }
    }
    if (*str == '\0' && (*curr)->isLeaf)
    {
        if (!haveChildren(*curr))
        {
            free(*curr); 
            (*curr) = NULL;
            return 1;
        }
        else
        {
            (*curr)->isLeaf = 0;
            return 0;
        }
    }
    return 0;
}


int main(){
    struct Trie* head = getNewTrieNode();
    int choice;
    char character[100];
    avltree *root=NULL;
    int data;
    do{
    printf("enter your choice:\n\n(Trie tree):1)ADD_WORD   2)SEARCH_WORD    3)DELETE_WORD\n\n(AVL tree)4)INSERT   5)DELETE    6)FIND    7)PRINT_ALL_ORDERS\n\n      9)EXIT\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            scanf("%s",character);
            trieinsert(&head,character);
            break;
        case 2:
            scanf("%s",character);
            if(triesearch(head,character))
                printf("\nentered word is found in trie\n");
            else
                printf("\nentered word not found in trie\n");
            break;
        case 3:
            scanf("%s",character);
            if(triesearch(head,character)){
                triedelete(&head,character);
                printf("\nentered word is deleted from trie\n");
            }
            else
                printf("\nentered word is not found in trie\n");
            break;
        case 4:
            printf("\nEnter a data:");
            scanf("%d",&data);
            root=avlinsert(root,data);
            break;
        case 5:
            printf("\nEnter a data:");
            scanf("%d",&data);
            root=avlDelete(root,data);
            break;
        case 6:
            printf("\nEnter a data:");
            scanf("%d",&data);
            if(avlSearch(root,data))
                printf("\nfound in tree\n");
            else
                printf("\nnot found in tree\n");
            break;
        case 7:
            printf("\nPreorder sequence:\n");
            preorder(root);
            printf("\nInorder sequence:\n");
            inorder(root);
            printf("\nPostorder sequence:\n");
            postorder(root);
            printf("\n");
            break;  
        
    }
    }while(choice!=9);
    return 0;
}
