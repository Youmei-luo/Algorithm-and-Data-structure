#include <stdio.h>
#include <stdlib.h>
 
typedef struct node{
   struct node* next;
   int data;
}Node;
 
// A function that creates a node whose arguments are members. And returns a pointer to that node
Node* add_node(Node* next, int data)
{
    Node* p;
    p = (Node*)malloc(sizeof(Node));
    p->next = next;
    p->data = data;
    return p;
}
 
void main(void)
{
   Node* head=NULL;
   Node* p;
   Node* q;
   int data;
   int flg;
 
   while(1){
      printf("Input integer value (Exit with 0):");
      scanf("%d",&data);
      if(data==0) break;
      head=add_node(head,data);
   }
 
   printf("\n=Input data=\n");
   for(p=head;p!=NULL;p=p->next)printf("%d\n",p->data);
 
   printf("=Search data=");
   while(1){
      flg=0;
      printf("\nSerch data (Exit with 0):");
      scanf("%d",&data);
      if(data==0)break;
      if(head->data==data){
         printf("##Found##"); flg=1;
         continue;
      }
      for(p=head;p->next!=NULL;p=p->next){
         q=p->next;
         if(q->data==data){
            printf("##Found##"); flg=1;
            p->next = q->next;
            q->next = head;
            head = q;
            break;
         }
      }
      if(flg==0) printf("##Not found##");
   }
 
   printf("\n=Input data=\n");
   for(p=head;p!=NULL;p=p->next) printf("%d\n",p->data);
 
   while(head!=NULL){
      p=head->next;
      free(head);
      head=p;
   }
   return;
}
