#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* link;
} Node;

Node *head;


void insert_at_beg(){
	int item;
	Node *new;
	new=(Node*)malloc(sizeof(Node));
	printf("Enter item to be inserted: ");
	scanf("%d",&item);
	new->data=item;
	printf("\n%d inserted at beginning\n\n",item);
	new->link=head;
	head=new;		
}
void insert_at_end(){
	int item;
	Node *new, *ptr;
	new=(Node*)malloc(sizeof(Node));
	printf("Enter item to be inserted: ");
	scanf("%d",&item);
	new->data=item;
	new->link=NULL;
	printf("\n%d inserted at end\n\n",item);
	if(head==NULL){
		new->link=head;
		head=new;
		return;		
	}
	ptr=head;
	while(ptr->link!=NULL){
		ptr=ptr->link;
	}
	ptr->link=new;
}
void insert_in_bw(){
	int item,key;
	Node *new, *ptr;
	new=(Node*)malloc(sizeof(Node));
	printf("Enter item to be inserted: ");
	scanf("%d",&item);
	new->data=item;
	printf("\n%d inserted\n\n",item);
	if(head==NULL){
		new->link=head;
		head=new;
		return;		
	}
	printf("Enter the key: ");
	scanf("%d",&key);
	ptr=head;
	while((ptr->data != key) && (ptr->link!=NULL)){
		ptr=ptr->link;
	}
	if (ptr->link!=NULL){
		new->link=ptr->link;
		ptr->link=new;
		printf("\n%d inserted after %d\n\n",item,key);
	}
	else{
		printf("\nKey not found\n\n");
    }
}
void del_frm_beg(){
	Node *ptr;
	if(head==NULL){
		printf("\nEmpty List\n");
		return;}
	ptr=head;
	printf("\n%d deleted from beginning\n\n",ptr->data);
	head=head->link;
	free(ptr);
}
void del_frm_end(){
	Node *ptr,*prev;
	if(head==NULL){
		printf("\nEmpty List\n\n");
		return;}
	prev=NULL;
	ptr=head;
	while(ptr->link!=NULL){
		prev=ptr;
		ptr=ptr->link;}
	printf("\n%d deleted from end\n\n",ptr->data);
	prev->link==NULL;
	free(ptr);
}
void del_in_bw(){
	int key;
	Node *ptr,*prev;
	if(head==NULL){
		printf("\nEmpty List\n\n");
		return;}
	printf("Enter the key: ");
	scanf("%d",&key);
	prev=NULL;
	ptr=head;
	while((ptr->data!=key) && (ptr->link!=NULL)){
		prev=ptr;
		ptr=ptr->link;
	}
	if(ptr->link!=NULL){
		printf("\n%d deleted\n\n",ptr->data);
		prev->link=ptr->link;
		free(ptr);
	}else{
		printf("\nKey not found\n\n");		
	}
}
void display(){
	Node *ptr;
	if(head==NULL){
		printf("\nEmpty List\n\n");
		return;}
	ptr=head;
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
		printf("SLL Operations\n1.Insertion\t2.Deletion\t3.Display\t4.EXIT\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("1.Insert at beginning\t2.Insert at end\t3.Insert in between\nEnter your choice: ");
				scanf("%d",&choice);
				switch(choice){
					case 1:
						insert_at_beg();
						break;
					case 2:
						insert_at_end();
						break;
					case 3:
						insert_in_bw();
						break;
					default:
						printf("Enter a valid choice\n");
				}
				break;	
			case 2:
				printf("1.Delete from beginning\t2.Delete from end\t3.Delete in between\nEnter your choice: ");
					scanf("%d",&choice);
					switch(choice){
						case 1:
							del_frm_beg();
							break;
						case 2:
							del_frm_end();
							break;
						case 3:
							del_in_bw();
							break;
						default:
							printf("Enter a valid choice\n");
					}
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
