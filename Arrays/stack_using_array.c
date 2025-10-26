#include<stdio.h>
#include<stdlib.h>
#define N 5
int stack[N];
int top=-1;
void push(){
	int item;
	if (top==N-1) //if stack is full
		printf("Stack Overflow\n");
	else{
		printf("Enter item to be inserted: ");
		scanf("%d",&item); 
		top++;
		stack[top]=item;
		printf("%d inserted\n",item);
	}
}
void pop(){
	int item;
	if (top==-1) //if stack is empty
		printf("Stack Underflow\n");
	else{
		item=stack[top];
		printf("%d Deleted\n",item);
		top--;
	}
}
void display(){
	if (top==-1) //if stack is empty
		printf("Stack Empty\n");
	else{
		for(int i=top;i>=0;i--)
			printf("%d ",stack[i]);
	}
	printf("\n");
}
			
int main(){
	int choice;
	do{
		printf("Enter your choice: \n1.Push\n2.Pop\n3.Display\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: 
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Enter a valid choice\n");
		}
	}while(1);
			
return 0;
}
