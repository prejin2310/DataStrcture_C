#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
struct node *head;
void display();
void binsert();
void findElem();

void  main()
{
 int choice=0;
 clrscr();
 do{
  printf("\n 1. Insert \n");
  printf("2. Display \n");
  printf("3. Search \n");
  printf("4. Exit \n Enter your Choice: ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
      binsert();
      break;
   case 2:
      display();
      break;
   case 3:
      findElem();
      break;
   case 4:
      exit(0);
      break;
   default: printf("Invalid Choice");
   }
   }while(choice!=4);
  getch();
 }

 void binsert()
 {
  int item;
  struct node *ptr;
  ptr=(struct node *)malloc(sizeof(struct node));
  if(ptr==NULL)
    printf("Overflow");
  else{
   printf("Enter the Data :");
   scanf("%d",&item);
   ptr->data=item;
   ptr->next=head;
   head=ptr;
   }
}

void display()
{
 struct node *ptr;
 ptr=head;
 if(ptr==NULL)
   printf("Nothing to print");
 else{
  printf("Printing Elements");
  while(ptr!=NULL)
  {
   printf("%d ->",ptr->data);
   ptr=ptr->next;
   }
  }
}
void findElem()
{
 struct node *ptr;
 int item,i=0,flag=0;
 ptr=head;
 if(ptr==NULL)
  printf("Empty List");
 else
 {
  printf("Enter the data to be search :");
  scanf("%d",&item);
  while(ptr!=NULL)
  {
   if(ptr->data==item)
   {
   printf("\n Item found at position %d",i+1);
   flag=0;
   }else{
    flag=1;
   }
   i++;
   ptr=ptr->next;
   }
  if(flag==1)
  {
  printf("Item not found \n");
  }
 }

}

