#include <stdio.h>
#include <stdlib.h>

//insertion sort
void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    printf("\ninsertion sort\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
//swaps 2 inters (pass by reference
void swap(int *num1,int * num2){
    int temp=*num1;
    *num1=*num2
    *num2=temp;
}

//selection sort
void selection_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n-1;j++){
            if(arr[j]<arr[i])
                swap(&arr[j],&arr[i]);
        }
    }
    printf("\nselection sort\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

//bubble sort
void bubble_sort(int arr[],int n){
    for (int i = 0; i < n-1; i++)	 
        for (int j = 0; j < n-i-1; j++) 
		    if (arr[j] > arr[j+1]) 
			    swap(&arr[j], &arr[j+1]); 
    printf("\nbubble sort\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

//count_sort
int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 

void count_sort(int arr[], int n) 
{ 
    int output[n];
    int i, count[10] = {0}; 

    for (i = 0; i < n; i++) 
        count[arr[i]]++; 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[arr[i] ] - 1] = arr[i]; 
        count[arr[i]]--; 
    } 
    for (i = 0; i < n; i++) 
        arr[i] = output[i];

    printf("\ncount sort\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    } 
} 

//radix sort
void countSort(int arr[], int n, int exp) 
{ 
    int output[n];
    int i, count[10] = {0}; 
  
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
    for (i = n - 1; i >= 0; i--) { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
    for (i = 0; i < n; i++) 
        arr[i] = output[i];
} 
  
void radix_sort(int arr[], int n){ 
    int m = getMax(arr, n); 

    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(arr, n, exp); 

    printf("\nradix sort\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
 
//heap sort
void heapify(int arr[], int n, int i) 
{ 
    int largest = i;
    int l = 2*i + 1; 
    int r = 2*i + 2; 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
    if (largest != i) 
    { 
        swap(&arr[i], &arr[largest]); 
        heapify(arr, n, largest); 
    } 
} 
  
void heap_sort(int arr[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
    for (int i=n-1; i>=0; i--) 
    { 
        swap(&arr[0], &arr[i]); 
        heapify(arr, i, 0); 
    }

    printf("\nheap sort\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    } 
} 

//bst sort
typedef struct bst{
    int data;
    struct bst *left;
    struct bst *right;
}bst;
bst *root=NULL;

bst * create(int value){
    bst* new=(bst *)malloc(sizeof(bst));
    new->data=value;
    new->left=NULL;
    new->right=NULL;
    return new;
}

bst * insert(bst *node,int value){
    if(node==NULL)
    return create(value);
    if(value<node->data)
        node->left=insert(node->left,value);
    else if(value>node->data)
        node->right=insert(node->right,value);
    return node;
}
bst * findmin(bst*root){
    bst* temp = root; 
    while (temp && temp->left != NULL) 
        temp = temp->left; 
  
    return temp;
    
}

bst * delete(bst * root,int value){
    if(root==NULL)
        return root;
    if(root->data < value){
        root->right=delete(root->right,value);
    }
    else if(root->data > value){
        root->left=delete(root->left,value);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root=NULL;
        }
        else if(root->right==NULL){
            bst *temp = root->left; 
            free(root); 
            return temp;
        }
        else if(root->left==NULL){
            bst *temp = root->right; 
            free(root); 
            return temp;
        }
        else{
            bst * min=findmin(root->right);
            root->data=min->data;
            root->right=delete(root->right,min->data);
        }
    }
    return root;
        
}

void inorder(bst * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void bstsort(){
    root=insert(root,3);
    root=insert(root,1);
    root=insert(root,5);
    root=insert(root,0);
    root=insert(root,2);
    root=insert(root,4);
    root=insert(root,6);
    printf("\nbst sort\n");
    inorder(root);
    root=delete(root,0);
    root=delete(root,1);
    root=delete(root,6);
    root=delete(root,5);
    
    
    printf("\nbst after deleting the nodes with one or no child sorting is \n");
    inorder(root);
    root=delete(root,3);
    printf("\nbst after deleting the nodes with two children sorting is \n");
    inorder(root);

}
//randomised quick sort
int rand_partition(int arr[],int low,int high){
    int random=low+(rand()%(high-low));
    int pivot=arr[random];
    int i=low-1;
    
    swap(&arr[random],&arr[high]);
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
	    i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void rand_quicksort(int arr[],int low,int high){
    if(low<high){
        int part=rand_partition(arr,low,high);
        rand_quicksort(arr,low,part-1);
        rand_quicksort(arr,part+1,high);
    } 
}

//quick sort
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
	    i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int part=partition(arr,low,high);
        quicksort(arr,low,part-1);
        quicksort(arr,part+1,high);
    }
}

//merge sort
void merge(int arr[],int l,int mid,int r){
    int L[mid-l+1],R[r-mid],a=0,b=0,c=0;
    for(int i=0;i<mid-l+1;i++){
        L[i]=arr[l+i];
    }
    for(int j=0;j<r-mid;j++){
        R[j]=arr[mid+1+j];
    }
    while(a<mid-l+1 && b<r-mid){
        if(R[b]<L[a]){
            arr[l+c]=R[b];
            c++;
            b++;
        }
        else{
            arr[l+c]=L[a];
            a++;
            c++;
        }
    }
    while(a<mid-l+1){
        arr[l+c]=L[a];
        a++;
        c++;
    }
    while(b<r-mid){
        arr[l+c]=R[b];
        c++;
        b++;
    }    
}

void mergesort(int arr[],int l,int r){
    int mid=(l+r)/2;
    if(l<r){
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
    
}

//bucket sort
typedef struct bucket{
    int data;
    struct bucket * next;
}bucket;

bucket * output[25];
    

int maximum(int arr[],int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(max<arr[i])
            max=arr[i];
    }
    return max;
}

bucket * bucket_create(int value){
    bucket * temp=(bucket *)malloc(sizeof(bucket));
    temp->data=value;
    temp->next=NULL;
    return temp;
}

void insert_bucket(int value,int index){
    bucket * temp=bucket_create(value);
    if(output[index]->next==NULL){
        output[index]->next=temp;
    }
    else{
        bucket *last=(bucket *)malloc(sizeof(bucket));
        last=output[index]->next;
        while(last->next!=NULL)
            last=last->next;
        last->next=temp;
    }
    return;
}

void sort(int n){
    int swap;
    bucket *temp1,*temp2;
    for(int i=0;i<n;i++){
        for(temp1=output[i];temp1!=NULL;temp1=temp1->next){
            for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next){
                if(temp2->data<temp1->data){
                    swap=temp1->data;
                    temp1->data=temp2->data;
                    temp2->data=swap;
                }
            }
        }
    }
}

void bucketsort(){
    int n;
    int arr[6]={2,3,1,5,1,4};
    n=sizeof(arr)/sizeof(arr[0]);
    int max=maximum(arr,n);
    for(int i=0;i<50;i++){
        output[i]=(bucket *)malloc(sizeof(bucket));
        output[i]->next=NULL; 
    }
    for(int i=0;i<n;i++){
        int index=(arr[i]*n)/(max+1);
        insert_bucket(arr[i],index);   
    }
    int m=0;
    sort(n);
    for(int i=0;i<n;i++){
        bucket *temp=output[i];
        while(temp->next!=NULL){
            arr[m]=temp->next->data;
            temp=temp->next;
            m++;
            
        }
    }
    printf("\nbucket sort\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int n;
    int arr[6]={2,3,1,5,1,4};
    n=sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,n);
    selection_sort(arr,n);
    bubble_sort(arr,n);
    count_sort(arr,n);
    radix_sort(arr,n);
    heap_sort(arr,n);
    bstsort();
    quicksort(arr,0,n-1);
    rand_quicksort(arr,0,n-1);
    mergesort(arr,0,n-1);
    bucketsort();
}

// avl and trie
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

//red black tree insertion
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct rbtree{
    int data;
    struct rbtree* right;
    struct rbtree* left;
    struct rbtree* parent; 
    bool color;  //red=1 black=0
}Rbtree;


void LeftRotate(Rbtree **root,Rbtree *x){
    Rbtree *y = x->right;
    x->right = y->left;
    if (x->right != NULL)
        x->right->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        (*root) = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else    
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}
 
void rightRotate(Rbtree **root,Rbtree *y){
    Rbtree *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent =y->parent;
    if (x->parent == NULL)
        (*root) = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else y->parent->right = x;
    x->right = y;
    y->parent = x;
}

void tree_rotation(Rbtree **root,Rbtree *z)
{
    while (z != *root && z->parent->color == 1){
        Rbtree *y;
        if (z->parent == z->parent->parent->left)
            y = z->parent->parent->right;
        else
            y = z->parent->parent->left;
        if (y!=NULL && y->color == 1){
            y->color = 0;
            z->parent->color = 0;
            z->parent->parent->color = 1;
            z = z->parent->parent;
        }
        else{
            if (z->parent == z->parent->parent->left && z == z->parent->left){
                bool ch = z->parent->color ;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                rightRotate(root,z->parent->parent);
            }
            else if (z->parent == z->parent->parent->left && z == z->parent->right){
                bool ch = z->color ;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                LeftRotate(root,z->parent);
                rightRotate(root,z->parent);
            }
            else if (z->parent == z->parent->parent->right && z == z->parent->right){
                bool ch = z->parent->color ;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                LeftRotate(root,z->parent->parent);
            }
            else if (z->parent == z->parent->parent->right && z == z->parent->left){
                bool ch = z->color ;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                rightRotate(root,z->parent);
                LeftRotate(root,z->parent);
            }
        }
    }
    (*root)->color = 0; 
}

Rbtree * create(int value){
    Rbtree *rbtree=(Rbtree *)malloc(sizeof(Rbtree));
    rbtree->right=NULL;
    rbtree->left=NULL;
    rbtree->data=value;
    rbtree->parent=NULL;
    rbtree->color=1; // initially red
    return rbtree;
}

void insert(Rbtree **root,int value){
    Rbtree * temp=create(value);
    if(*root==NULL){
        temp->color=0; //black
        (*root)=temp;
    }
    else{
        Rbtree *temp2=NULL;
        Rbtree *temp1=(*root);
        while(temp1!=NULL){
            temp2=temp1;
            if(temp->data<temp1->data){
                temp1=temp1->left;
            }
            else{
                temp1=temp1->right;
            }
        }
        temp->parent=temp2;
        if(temp->data>temp2->data){
            temp2->right=temp;
        }
        else{
            temp2->left=temp;
        }
        temp->color=1;
        tree_rotation(root,temp);
    }
}

void inorder(Rbtree *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main(){
    Rbtree * root=NULL;
    insert(&root,35);
    insert(&root,25);
    insert(&root,45);
    insert(&root,10);
    insert(&root,20);
    insert(&root,40);
    insert(&root,30);
    insert(&root,50);
    printf("inorder Traversal Is : ");
    inorder(root);
    return 0;
}
