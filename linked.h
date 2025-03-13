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
