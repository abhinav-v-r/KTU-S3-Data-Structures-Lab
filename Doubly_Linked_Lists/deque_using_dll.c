#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next, *prev;
} Node;

Node *front,*rear;

void enqueue_front(){
	int item;
	Node *new;
	new=(Node*)malloc(sizeof(Node));
	printf("Enter item to be inserted: ");
	scanf("%d",&item);
	new->data=item;
    new->prev=NULL;
    printf("\n%d inserted at front\n\n",item);
    if(front==NULL && rear==NULL){
        new->next=NULL;
        front=rear=new;
        return;
    }
    new->next=front;
    front->prev=new;
    front=new;
}

void enqueue_rear(){
    int item;
	Node *new, *ptr;
	new=(Node*)malloc(sizeof(Node));
	printf("Enter item to be inserted: ");
	scanf("%d",&item);
	new->data=item;
    new->next=NULL;
    printf("\n%d inserted at rear\n\n",item);
    if(front==NULL && rear==NULL){
        new->next=NULL;
        front=rear=new;
        return;
    }
    new->prev=rear;
    rear->next=new;
    rear=new;
}

void dequeue_front(){
    Node *ptr;
    if(front==NULL && rear==NULL){
		printf("\nQueue is Empty\n\n 0");
		return;}
    int item = front->data;
    if(front==rear){
        front=rear=NULL;
    }
    else{
    ptr=front;
    (ptr->next)->prev=NULL;
    front=front->next;
    free(ptr);
    }
    printf("\n%d deleted from front\n\n",item);
}

void dequeue_rear(){
    Node *ptr;
    if(front==NULL && rear==NULL){
		printf("\nQueue is Empty\n\n");
		return;}
    int item = rear->data;
    if(front==rear){
        front=rear=NULL;
    }
    else{
        ptr=rear;
        (rear->prev)->next=NULL;
        rear=rear->prev;
        free(ptr);
    }
    printf("\n%d deleted from rear\n\n",item);
}

void display(){
	Node *ptr;
    if(front==NULL && rear==NULL){
		printf("\nQueue is Empty\n\n");
		return;}
	ptr=front;
	printf("\n");
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n\n");
}

int main(){
	int choice;
	do{
		printf("1.Enqueue at front \t 2.Enqueue at rear\t 3.Dequeue at front\t 4.Dequeue at rear\t 5.Display\t 6.EXIT\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				enqueue_front();
				break;
			case 2:
				enqueue_rear();
				break;
			case 3:
				dequeue_front();
				break;
			case 4:
				dequeue_rear();
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("Enter a valid choice\n");
		}
	} while(1);
return 0;
}
