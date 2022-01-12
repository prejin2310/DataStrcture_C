// Program to Concatenate two Linked List.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

node *createList(int);
void displayList(node *);
void concatenateList(node *, int, node *, int);

void main()
{
	int n1,n2;
	node *head1, *head2;

	clrscr();

	printf("Enter Number of Nodes for List 1: ");
	scanf("%d",&n1);
	printf("Enter Number of Nodes for List 2: ");
	scanf("%d",&n2);

	head1=createList(n1);
	head2=createList(n2);
	displayList(head1);
	displayList(head2);
	concatenateList(head1,n1,head2,n2);

	getch();
}
node *createList(int n)
{
	node *head=NULL, *temp=NULL, *p=NULL;
	int i;

	printf("\n");

	for(i=0;i<n;i++)
	{
		temp=(node *)malloc(sizeof(node));
		printf("Enter Data for Node[%d]: ",i+1);
		scanf("%d",&temp->data);

		temp->next=NULL;

		if(head==NULL)
			head=temp;
		else
		{
			p=head;

			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=temp;
		}
	}
	return head;
}
void displayList(node *head)
{
	node *p;

	printf("\n");

	if(head==NULL)
		printf("\nList is Empty!");
	else
	{
		p=head;

		while(p!=NULL)
		{
			printf("[%d]=>",p->data);
			p=p->next;
		}
	}
}
void concatenateList(node *head1, int n1, node *head2, int n2)
{
	node *p;

	p=head1;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=head2;

	printf("\n\nList After Concatination:\n");

	displayList(head1);
}
