#include <stdio.h>
#include <stdlib.h>
 
typedef struct node{
   struct node* left;
   struct node* right;
   int data;
}Node;
 
//Preparing the queue
#define MAX_NUM 10
Node* queue[MAX_NUM];
int first=0;
int last=0;
void enqueue(Node*);
Node* dequeue(void);
 
//Function prototype declaration
Node* new_node(int);
Node* insert_tree(int, Node*);
Node* search_tree(int, Node*);
void traverse_pre_order(Node*);
void traverse_in_order(Node*);
void traverse_post_order(Node*);
void traverse_level_order(Node*);
void free_tree(Node*);
 
void main(void)
{
   int x;
   Node* p;
   Node* root=NULL;
 
   printf("\n=Input data=\n");
   while(1){
      printf("Enter integer (Enter -1 to end) : ");
      scanf("%d",&x);
      if(x==-1)break;
      else root=insert_tree(x,root);
   }
 
   printf("\n\n=Display all data=");
   printf("\ntraverse pre order\n");
   traverse_pre_order(root);
   printf("\ntraverse in order\n");
   traverse_in_order(root);
   printf("\ntraverse post order\n");
   traverse_post_order(root);
   printf("\ntraverse_level_order\n");
   traverse_level_order(root);
    
   printf("\n\n=Search data=\n");
   while(1){
      printf("Search target value (Enter -1 to end) : ");
      scanf("%d",&x);
      if(x==-1)break;
      p=search_tree(x,root);
      if(p!=NULL) printf("Found\n");
      else printf("Not found\n");
   }
 
   free_tree(root);
}

Node* new_node(int x)
{
   Node* p;
   p=(Node*)malloc(sizeof(Node));
   p->data = x;
   p->left = NULL;
   p->right=NULL;
   return p;
}

Node* insert_tree(int x, Node* root)
{
   if(root==NULL) return new_node(x);
   if(x < root->data) root->left=insert_tree(x,root->left);
   else root->right=insert_tree(x,root->right);
   return root;
}

Node* search_tree(int x, Node* root)
{
   if(root==NULL) return NULL;
   if(x == root->data) return root;
   if(x < root->data) return search_tree(x,root->left);
   else return search_tree(x,root->right);
}

void traverse_pre_order(Node* root)
{
   if(root==NULL)return;
   printf("%d\t",root->data);
   traverse_pre_order(root->left);
   traverse_pre_order(root->right);
}

void traverse_in_order(Node* root)
{
   if(root==NULL)return;
   traverse_in_order(root->left);
   printf("%d\t",root->data);
   traverse_in_order(root->right);
}

void traverse_post_order(Node* root)
{
   if(root==NULL)return;
   traverse_post_order(root->left);
   traverse_post_order(root->right);
   printf("%d\t",root->data);
}

void free_tree(Node* root)
{
   if(root==NULL)return;
   free_tree(root->left);
   free_tree(root->right);
   free(root);
}

void traverse_level_order(Node* root)
{
    int x;
    Node* p;
    enqueue(root);
    while(1){
        p=dequeue();
        if(p==NULL)return;
        printf("%d\t",p->data);
        if(p->left!=NULL) enqueue(p->left);
        if(p->right!=NULL) enqueue(p->right);
    }
}

#define MAX_NUM 10
Node* queue[MAX_NUM];
//int first=0;
//int last=0;
 
void enqueue(Node* data)
{
   if( (last+1)%MAX_NUM == first ){
      printf("Queue is full and cannot be added\n");
      return;
   }
   queue[last]=data;
   last=(last+1)%MAX_NUM;
   return;
}
 
Node* dequeue(void)
{
   Node* ret;
   if(first==last){
      //printf("No data in queue\n");
      return NULL;
   }
   ret=queue[first];
   first=(first+1)%MAX_NUM;
   return ret;
}
