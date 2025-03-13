#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *link;
 };
 struct Node *head=NULL,*baby,*ptr,*kill,*prew;
 
 struct Node *getNode(int item)
 {
   ptr=(struct Node*)malloc(sizeof(struct Node));
   ptr->data=item;
   ptr->link=NULL;
   return (ptr);
  }
 int isempty()
 {
  if(head==NULL)
  {
   return 1;
  }
  else
   {
     return 0;
   }
 }
 
 void traverse()
 {
   if (isempty())
   {
   printf("list is empty");
   }
   
   else
   {
    ptr=head;
    while(ptr !=NULL)
    {
      printf("%d -> ",ptr->data);
      ptr=ptr->link;
    }
    if(ptr ==NULL)
    {
      printf("NULL");
      }
    }
 }
 void insertfront(int item)
 {
  baby=getNode(item);
  baby->link=head;
  head=baby;
  printf("item inserted\n");
 }
 void search(int key)
 {
   int flag=0;
   ptr=head;
   while(ptr!=NULL)
   {
     if(ptr->data == key)
     {
       flag=1;
      printf("key is founded int list\n");
      
      break;
     }
     else
     {
       ptr=ptr->link;
     }
   }
   if (flag==0)
   {
     printf("key is not found in list\n");
     }
  }
  
void insertEnd(int item)
{
  if (isempty())
  {
   insertfront(item);
  }
  else
  {
    baby=getNode(item);
    ptr=head;
   while(ptr->link!=NULL)
   {
     ptr=ptr->link;
   }
   ptr->link=baby;
 }
 }
 int deletefront()
 {
 int item;
   if (isempty())
   {
     printf("list is empty");
     return -1;
   }
   else
   {
   kill=head;
   item=kill->data;
   head=kill->link;
   free(kill);
   return(item);
   }
 }
 void insertafterkey(int key,int item)
 {
   int found=0;
   baby=getNode(item);
   ptr=head;
   while(ptr!=NULL)
   {
    if(ptr->data==key)
    {
      found=1;
      baby->link=ptr->link;
      ptr->link=baby;
      printf("item is inserted");
      break;
    }
    else
    {
     ptr=ptr->link;
    }
   
   }
   if(found==0)
   {
     printf("key not found,insertion failed\n");
     free(baby);
   }
  
 }
 int deleteany(int key)
 {
   int found,item;
   if(isempty())
   {
     printf("list empty");
      return -1;
    }
    else if(head->link==NULL)
    {
      item=deletefront();
      return item;
    }
    else
    {
      found=0;
      
      ptr=head;
     while(ptr !=NULL)
     {
     if( ptr->data==key)
     {
       found=1;
       item=ptr->data;
       prew->link=ptr;
       free(ptr);
       return item;
       break;
     }
     else
     {
       prew=ptr;
       ptr=ptr->link;
     }
    }
    if(found==0)
    {
     printf("key not found\n");
    }
   }
   }
int deleteEnd()
{
  int item;
  if(isempty())
  {
    printf("list empty");
     return -1;
  }
  else if(head->link==NULL)
  {
    item=deletefront();
    return item;
  }
  else
  {
   ptr=head;
   while (ptr ->link!=NULL)
   {
     prew=ptr;
    ptr=ptr->link;
   }
   item=ptr->data;
   prew->link=NULL;
   free(ptr);
   return (item);
   }
  }
 int main()
 {
    int ch,item,key,x,z;
   while(1)
   {
   printf("\n******************");
   printf("\n1.Insertfront \n2.Traverse\n3.search\n4.InsertEnd\n5.deletefront\n6.Insertany\n7.deleteAny\n8.deleteEnd\n9.Exit\n");
   printf("******************\n");
   printf("choose no:");
   
   scanf("%d",&ch);
   
   switch(ch)
   {
    case 1:
    printf("Enter the item front insertion:");
    scanf("%d",&item);
    insertfront(item);
    break;
    case 2:
      traverse();
     break;
    case 3:
      printf("Enter the search key:");
    scanf("%d",&key);
      search(key);
        break;
    case 4:
      printf("Enter the item end insertion:");
    scanf("%d",&item);
    insertEnd(item);
    break;
    case 5:
       x=deletefront();
       if(x!=-1)
       {
      printf("delete front=%d",x);
      }
      break;
    case 6:
    printf("Enter the insertion key:");
    scanf("%d",&key);
    printf("Enter the item any insertion:");
    scanf("%d",&item);
    insertafterkey(key,item);
       break;
    case 7:
       printf("Enter the insertion key:");
       scanf("%d",&key);
       z=deleteany(key);
       if(z!=-1)
       {
      printf("delete any=%d",z);
      }
      break;
    case 8:
       x=deleteEnd();
       if(x!=-1)
       {
      printf("delete End=%d",x);
      }
      break;
    case 9:
      printf("Exited....!\n");
       exit(0);
 
   }
   }
  }  