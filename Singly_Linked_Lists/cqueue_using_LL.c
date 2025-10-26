#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}Node;

Node *front=NULL,*rear=NULL;

void enqueue(){
    Node *new;
    new=(Node*)malloc(sizeof(Node));
    int item;
	printf("Enter item to be inserted: "); 
	scanf("%d",&item);
    new->data=item;
    printf("\n%d inserted\n\n",item);
    if(front==NULL){
        front=rear=new;
        new->link=front;
    }
    else{
        rear->link=new;
        rear=new;
        rear->link=front;
    }
}

void dequeue(){
    Node *ptr;
    if(front==NULL){
        printf("\nQueue is Empty\n\n");
        return;
    }
    ptr=front;
    printf("\n%d deleted\n\n",front->data);
    if(front==rear){
        front=rear=NULL;
    }
    else{
        front=front->link;
        rear->link=front;
    }
    free(ptr);
}

void display(){
    Node *ptr;
    if(front==NULL){
        printf("\nQueue is Empty\n\n");
        return;
    }
    ptr=front;
    printf("\n");
    do{
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }while(ptr!=front);
    printf("\n\n");
}

int main(){
	int choice;
	do{
		printf("1.Enqueue\t 2.Dequeue\t 3.Display\t 4.Exit\nEnter your choice: ");
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
			default:
				printf("Enter a valid choice\n");
		}
	} while(1);
return 0;
}