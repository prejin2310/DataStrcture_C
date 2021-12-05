#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *link;
};
typedef struct Node Node;
Node *getnode();

void main()
{
    Node *first;
    int choice, item, pos, n,ser;
    clrscr();
    InitializeLList(&first);
    printf("\nHow many nodes you want to create: ");
    scanf("%d", &n);
    LListCreate(&first, n);
    while (1)
    {
	printf("\n1.Insert at First: ");
	printf("\n2.Insert at Last: ");
	printf("\n3.Insertion at any specific location: ");
	printf("\n4.Deletion from First: ");
	printf("\n5.Deletion from Last: ");
	printf("\n6.Deletion from any specific location: ");
	printf("\n7. Display");
	printf("\n8. Exit");
	printf("\nEnter your choice: ");
	scanf("%d",&choice);
	switch (choice)
	{
	    case 1:
		printf("\nEnter the item: ");
		    scanf("%d",&item);
		    InsertLListFirst(&first,item);
		    break;

	    case 2:printf("\nEnter the item: ");
		    scanf("%d",&item);
		    InsertLListLast(&first,item);
		    break;
	    case 3:
		printf("\nEnter the item: ");
		    scanf("%d",&item);
		    printf("\nEnter the node number where you want to insert the item: ");
		    scanf("%d",&pos);
		    InsertLListAtAny (&first,item,pos);
		    break;
	    case 4:
		DeleteLListFirst(&first);
	            break;
            case 5:
                DeleteLListLast(&first);
	            break;
            case 6:
                printf("\nEnter the node number you want to delete: ");
	            scanf("%d",&pos);
	            DeleteLListAny (&first,pos);
	            break;
            case 7:
                TraverseLList(first);
	            break;
            case 8: 
                exit(0);

        }
    }
}
InitializeLList(Node **first)
{
    (*first)=NULL;
}

LListCreate(Node **f, int n)
{
    Node *temp, *current;
    int i, item;
    for(i=1; i<=n; i++)
    {
        printf("Enter the data field of Node :");
        scanf("%d", &item);
        temp = getnode();
        temp->data = item;
        temp->link = NULL;
        if (*f == NULL)
            *f = temp;
        else
            current->link = temp;
        current = temp;
    }
}
TraverseLList(Node *first)
{
    printf("\nStart => ");
    while (first != NULL)
    {
        printf("%d -> ",first->data);
        first=first->link;
    }
    printf("End\n");
}
InsertLListFirst (Node **first, int item)
{
    Node *temp;
    temp=getnode();
    if (temp==NULL)
    {
        printf("\nUnable to create a new node. ");
        return;
    }
    temp->data=item;
    temp->link=(*first);
    (*first)=temp;
}

InsertLListLast(Node **first,int item)
{
    Node *temp, *current;
    temp=getnode();
    if (temp==NULL)
    {
        printf("\nUnable to create a new node. ");
        return;
    }
    temp->data=item;
    temp->link=NULL;
    if(* first==NULL)
        (*first)=temp;
    else
    {
        current=(*first);
        while (current->link!=NULL)
            current= current->link;
        current->link=temp;
    }
}

InsertLListAtAny(Node **first,int item,int pos)
{
    Node *current,*previous,*temp;
    int i;
    temp=getnode();
    if (temp==NULL)
    {
        printf("\nUnable to create a new node. ");
        return;
    }
    if((*first==NULL)||(pos== 1))
    {
        temp->data=item;
        temp->link=(*first);
        (*first)=temp;
        return;
    }
    current= (*first)->link;
    previous= (*first);
    i=1;
    while(current!= NULL)
    {
        if((i+1) == pos)
            break;
        else
        {
            previous=current;
            current= current->link;
            i++;
        }
    }
    temp->data = item;
    temp->link = current;
    previous->link = temp;
}

DeleteLListFirst(Node **first)
{
    Node *current;
    int item;
    if (*first==NULL)
    {
        printf("\nList is empty. ");
        return;
    }
    current = (*first);
    item= current ->data;
    (*first) = (*first)->link;
    freenode(current);
    printf("\nDeleted item = %d", item);
}


DeleteLListLast(Node **first)
{
    Node *current, *previous;
    int item;
    if (*first == NULL)
    {
        printf("\nList is empty. ");
        return;
    }
    current = (*first);
    previous=NULL;
    if ((*first)->link == NULL)
        (*first) = (*first)->link;
    else
    {
        while (current->link != NULL)
        {
            previous= current;
            current= current->link;
        }
        previous->link = current->link;
    }
    item=current->data;
    freenode(current);
    printf("\nDeleted item = %d", item);
}

DeleteLListAny (Node **first, int pos)
{  
    Node *current, *previous;
    int item, i;
    if (*first == NULL)
    {
        printf("\nList is empty. ");
        return;
    }
    if(pos == 1)
    {
        current = (*first);
        item=current->data;
        (*first)= (*first)->link;
        freenode(current);
        printf("\nDeleted item = %d", item);
        return;
    }
    current = (*first)->link;
    previous=(*first);
    i=2;
    while (current != NULL)
    {
        if(i == pos)
        {
            previous->link = current->link;
            item= current->data;
            freenode(current);
            printf("\nDeleted item = %d",item);
        }
        else
        {
            previous = current;
            current = current->link;
        }
        i++;
    }
}

Search(Node *first,int item)
{
    int temp=1,flag=0;
    if(first==NULL)
    {
        printf("List is empty");
        return;
    }
    while(first!=NULL)
    {
        if(first -> data == item)
        {
            flag=1;
            break;
        }
        else
            first = first ->link;
            temp++;
    }
        if(flag==1)
            printf("item found at position : %d",temp);
        else
            printf("item not found");
}

Node *getnode()
{
  Node *p;
  p = (Node *)malloc(sizeof(Node));
  return (p);
}

freenode(Node *p)
{
  free(p);
}
