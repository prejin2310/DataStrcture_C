#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};

struct Node* top = NULL;
struct Node* temp,*current;
int count = 0;

void display()
{
	temp = top;
	if(count == 0)
	{
		printf("\nStack is Empty!\n");
		return;
	}
	else
	{
		printf("\nThere are currently %d items:-\n", count);
		while(temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}	
		printf("\n");
	}
}

void push(int el)
{
	if(top == NULL)
	{
		top = (struct Node*) malloc(sizeof(struct Node*));
		top->data = el;
		top->next = NULL;
	}
	else
	{
		temp = (struct Node*) malloc(sizeof(struct Node*));
		temp->next = top;
		temp->data = el;
		top = temp;
	}
	count++;
	display();
}

void pop()
{
	temp = top;
	if(top == NULL)
	{
		printf("\nStack is empty!\n");
		exit(1);
	}
	else
		temp = temp->next;
	
	printf("\nItem to be removed is %d.", top->data);
	free(top);
	top = temp;
	count--;
	display();
}

void search()
{
   int item,flag=0;
  printf("Enter search element");
		   scanf("%d",&item);
            if(top==NULL)
                printf("stack underflow\n");
            else
            {
                temp=top;
                while(temp!=NULL) 
                {
                    if(temp->data==item)
					{
						flag=1;
						break;
					}
					else{
						temp=temp->next;
					}
                }
				if(flag==1)
				{
					printf("\nElement %d found\n", item);
				}
				else{
					printf("\n %d Element not found\n", item);
				}
            }
}

int main()
{
	int choice;
	int el;
	while(1)
	{
		printf("\n1.Push\n2.Pop\n3.Display\n4.Search \n5.Exit Choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("\nElement to be inserted: ");
				scanf("%d", &el);
				push(el);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
      case 4:
				search();
				break;
      case 5:
            exit(0);
        default:printf("\n invalid input");		
		}
	}
	return 0;
}
