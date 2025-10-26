#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;

void enqueue(){
	int item;
	if (rear==N-1) //if stack is full
		printf("Queue Full\n");
	else{
		printf("Enter item to be inserted: ");
		scanf("%d",&item);
		rear++;
		queue[rear]=item;
		printf("%d inserted\n",item);
		if (front==-1) //inserting first element
		front=front+1;
		}
	
}

void dequeue(){
	int item;
	if (front==-1 && rear==-1)
		printf("Queue Empty\n");
	else{
		item=queue[front];
		printf("%d deleted\n",item);
		front++;
	}
	if (front>rear){
			front=-1;
			rear=-1;
	}
}

void display(){
	if (front==-1)
		printf("Queue Empty\n");
	else{
		for(int i=front;i<=rear;i++)
			printf("%d ",queue[i]);
	}
	printf("\n");		
}
int main(){
	int choice;
	do{
		printf("Enter your choice: \n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
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
