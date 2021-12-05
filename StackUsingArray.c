#include<stdio.h>
#include<conio.h>
int stack[100],i,j,ch,n,top_ele=-1;
void push();
void pop();
void display();
void top_ele();
void main()
{
    clrscr();
    printf("Enter the no of elements:");
    scanf("%d",&n);
    printf("\nOperations on stack");
    while(ch!=5)
    {
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.top_ele ELEMENT\n5.EXIT");
        printf("\nEnter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:{
                push();
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                top_ele();
                break;
            }
            case 5:{
                printf("\nExiting");
                break;
            }
            default:printf("Invalid Choice");
        }          
    };
getch();
}

void push()
{
    int val;
    if(top_ele==n-1)
        printf("\nOverflow");
    else
    {
        printf("\nEnter the element:");
        scanf("%d",&val);
        top_ele++;
        stack[top_ele]=val;
    }
 }
void pop()
 {
    if(top_ele==-1)
        printf("\nUnderflow");
    else
    {
        int val;
        val=stack[top_ele];
        top_ele--;
        printf("\nElement deleted");
    }
}
void display()
{
    printf("\nThe elements are:");
    for(i=top_ele;i>=0;i--)
    {
        printf("%d\t",stack[i]);
    }
    if(top_ele==-1)
        printf("\nStack is empty");
}
void top_ele()
{
     int val;
    if(top_ele==-1)
        printf("\nStack empty");
    else
    {
    val=stack[top_ele];
    printf("\nThe top_elemost element is: %d",val);
    }
}
