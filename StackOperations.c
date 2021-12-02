#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top=-1;
int max=100;

int isEmpty(){
	if(top<=-1){
		return 1;
	}
	else{
		return 0;
	}
}

int isFull(){
	if(top>=max){
		return 1;
	}
	else{
		return 0;	
	}
}

void push(){
	int value;
	if(isFull()){
		printf("Stack is full\n");
	}
	else{
		printf("Enter push item : ");
		scanf("%d",&value);
		top=top+1;
		stack[top]=value;
		printf("\n%d pushed to stack",value);
	}
}

void pop(){
	if(isEmpty()){
		printf("stack is empty");
	}
	else{
		printf("%d is poped out : ",stack[top]);
		top=top-1;
	}
}

void display(){
	int i;
	if(!isEmpty()){
	for(i=0;i<=top;i++){
		printf(" %d \n",stack[i]);
	}
	}
	else{
		printf("stack is empty");
	}
}

void s_top(){
	if(!isEmpty()){
		printf("top element is : %d",stack[top]);
	}
	else{
		printf("stack is empty");
	}
}

void main() {
	int opt;
	clrscr();
	while(1){
		printf("\n\n");
		printf("1)PUSH\n");
		printf("2)POP\n");
		printf("3)STACK TOP\n");
		printf("4)DISPLAY\n");
		printf("5)QUIET \n");
		printf("choose your option : ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				s_top();
				break;
			case 4:
				display();
				break;
			case 5:
				exit(1);
			default:
			printf("\nInvalid Operation! Try Again... \n");
		}
	}
	getch();
}
