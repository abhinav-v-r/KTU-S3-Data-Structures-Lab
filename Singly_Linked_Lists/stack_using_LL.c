#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* link;
} Node;

Node *top;

void push(){
	Node *new;
	new=(Node*)malloc(sizeof(Node));
	int item;
	printf("Enter item to be inserted: ");
	scanf("%d",&item);
	new->data=item;
	new->link=top;
	printf("\n%d inserted\n\n",item);
	top=new;
}

void pop(){
	Node *ptr;
	if(top==NULL){
		printf("\nStack is empty\n\n");
		return;}
	ptr=top;
	printf("\n%d deleted\n\n",ptr->data);
	top=top->link;
	free(ptr);
}

void display(){
	if(top==NULL){
		printf("\nStack is empty\n\n");
		return;}
	Node *ptr;
	ptr=top;
	printf("\n");
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}printf("\n\n");
}

int main(){
	int choice;
	do{
		printf("1.Push\t2.Pop\t3.Display\t4.Exit\nEnter your choice: ");
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
