#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* link;
} Node;

Node *front=NULL,*rear=NULL;

void enqueue(){
	Node *new;
	new=(Node*)malloc(sizeof(Node));
	int item;
	printf("Enter item to be inserted: ");
	scanf("%d",&item);
	new->data=item;
	printf("\n%d inserted\n\n",item);
	if(front==NULL)
		front=new;
	else
		rear->link=new;
	new->link=NULL;
	rear=new;
}

void dequeue(){
	Node *ptr;
	if(front==NULL){
		printf("\nQueue is empty\n\n");
		return;}
	ptr=front;
	printf("\n%d deleted\n\n",front->data);
	front=front->link;
	if(front==NULL)
		rear=NULL;
	free(ptr);
}

void display(){
	Node *ptr;
	if(front==NULL){
		printf("\nQueue is empty\n\n");
		return;}
		ptr=front;
		printf("\n");
		while(ptr!=NULL){
			printf("%d ",ptr->data);
			ptr=ptr->link;
		}
	printf("\n\n");	
}

int main(){
	int choice;
	do{
		printf("1.Enqueue\t2.Dequeue\t3.Display\t4.Exit\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: 
				enqueue();
				break;
			case 2:
				dequeue();
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
