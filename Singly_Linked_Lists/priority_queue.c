#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int pt;
    char name[10];
    struct node *link;
} Node;

Node *front=NULL,*rear=NULL;

void enqueue(){
    Node *new;
    char data[10];
    new=(Node*)malloc(sizeof(Node));
    printf("Enter priority: ");
    scanf("%d",&new->pt);
    printf("Enter Name: ");
    scanf("%s",data);
    strcpy(new->name,data);
    printf("\n'%s' Entered\n\n",new->name);
    new->link=NULL;
    if(front==NULL) front=new;
    else rear->link=new;
    rear=new; 
}

void dequeue(){
    Node *prev=NULL, *curr=NULL;
    Node *best_prev=NULL,*best_curr=NULL;
    if(front==NULL){
        printf("\nNo customers in queue\n\n");
        return;
        }
    prev=NULL;
    curr=front;
    best_prev=NULL;
    best_curr=curr;
    while (curr!=NULL)
    {
        if(curr->pt < best_curr->pt){
            best_prev=prev;
            best_curr=curr;
        }
        prev=curr;
        curr=curr->link;
    }
    if(best_prev==NULL) front=front->link;
    else best_prev->link=best_curr->link;
    printf("\nRemoved '%s'\n\n",best_curr->name);
    free(best_curr);

}

void display(){
    Node *ptr;
    if(front==NULL){
        printf("\nNo customers in queue\n\n");
        return;
    }
    ptr=front;
    printf("\n");
    do{
        printf("%s(Priority:%d) \n",ptr->name,ptr->pt);
        ptr=ptr->link;
    }while(ptr!=rear->link);
    printf("\n\n");
}


int main(){
	int choice;
	do{
		printf("1.Add Members\t 2.Removed Members\t 3.Display\t 4.Exit\nEnter your choice: ");
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