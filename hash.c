#include <stdio.h>
#include <stdlib.h>
 
#define TABLE_SIZE 11
#define SUCCESS 0
#define FAILURE 1
#define EMPTY 0
#define DELETED -1

typedef struct record{
   long int tel;
   char name[32];
}Record;

Record Table[TABLE_SIZE];

int hash(long int key){
   return key%TABLE_SIZE;
}

int rehash(int bucket){
   return (bucket+1)%TABLE_SIZE;
}

int add_hashtable(Record new_data)
{
   int bucket,k;
   long int  key,data;
 
   key=new_data.tel;
   bucket=hash(key);
   for(k=0;k<TABLE_SIZE;k++){
      data=Table[bucket].tel;
      if( data==EMPTY || data==DELETED){
         Table[bucket]=new_data;
         printf(" Added \n");
         return SUCCESS;
      }
      bucket=rehash(bucket);
   }
   printf(" Could not add ");
   return FAILURE;
}

int search_hashtable(long int key)
{
   int bucket,k;
   long int data;
 
   bucket=hash(key);
   for(k=1;k<TABLE_SIZE;k++){
      data=Table[bucket].tel;
      if(data==key){
         printf(" %s's phone number \n",Table[bucket].name);
         return SUCCESS;
      }
      if(data==EMPTY) break;
      bucket=rehash(bucket);
   }
   printf(" Not found \n");
   return FAILURE;
}

int delete_hashtable(long int key)
{
   int bucket,k;
   long int data;
 
   bucket=hash(key);
   for(k=0;k<TABLE_SIZE;k++){
      data=Table[bucket].tel;
      if(data==key){
         Table[bucket].tel=DELETED;
         printf(" Deleted \n");
         return SUCCESS;
      }
      if( data==EMPTY ) break;
      bucket=rehash(bucket);
   }
   printf(" Not found \n");
   return FAILURE;
}

void main(void)
{
   Record new_data;
   int i,menu,rc;
   long int  key;
 
   for(i=0;i<TABLE_SIZE;i++)Table[i].tel=EMPTY;
 
   while(1){
      printf("\nRegister 1  Delete 2  Search 3  Display 4\nMenue number : ");      scanf("%d",&menu);
      switch(menu){
         case 1:
            printf("\n=Register data=\n");
            while(1){
               printf("Phone number (Registration ends with -1) : ");
               scanf("%ld",&new_data.tel);
               if(new_data.tel==-1) break;
               printf("Name : ");
               scanf("%s",new_data.name);
               rc=add_hashtable(new_data);
               if(rc==FAILURE) break;
            }
            break;
         case 2:
            printf("\n=Delete data=\n");
            while(1){
               printf("Phone number (Deletion ends with -1) : ");
               scanf("%ld",&key);
               if(key==-1)break;
               delete_hashtable(key);
            }
            break;
         case 3:
            printf("\n=Search data=\n");
            while(1){
               printf(" Phone number (Searching ends with -1) : ");
               scanf("%ld",&key);
               if(key==-1)break;
               search_hashtable(key);
            }
            break;
         case 4:
            printf("\n=Display data=\n");
            for(i=0 ; i<TABLE_SIZE ; i++){
               if(Table[i].tel==EMPTY || Table[i].tel==DELETED) continue;
               printf("%d\t%ld\t%s\n",i,Table[i].tel,Table[i].name);
            }
            break;
         default:
            return;
      }
   }
   return;
}
