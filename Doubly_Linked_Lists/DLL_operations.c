#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *prev,*next;
} Node;

Node *head;

void insert_at_beg(){
	int item;
	Node *new;
	new=(Node*)malloc(sizeof(Node));
	printf("Enter item to be inserted: ");
	scanf("%d",&item);
	new->data=item;
    new->prev=NULL;
	printf("\n%d inserted at beginning\n\n",item);
    if(head==NULL){
        new->next=NULL;
        head=new;
        return;
    }
	new->next=head;
	head->prev=new;
    head=new;		
}

void insert_at_end(){
	int item;
	Node *new, *ptr;
	new=(Node*)malloc(sizeof(Node));
	printf("Enter item to be inserted: ");
	scanf("%d",&item);
	new->data=item;
    new->next=NULL;
	printf("\n%d inserted at end\n\n",item);
	if(head==NULL){
		new->prev=NULL;
		head=new;
		return;		
	}
	ptr=head;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=new;
    new->prev=ptr;
}


void insert_in_bw(){
	int item,key;
	Node *new, *ptr;
	new=(Node*)malloc(sizeof(Node));
	printf("Enter item to be inserted: ");
	scanf("%d",&item);
	new->data=item;
	if(head==NULL){
		new->next=new->prev=head;
		head=new;
		printf("\n%d inserted\n\n",item);
		return;		
	}
	printf("Enter the key: ");
	scanf("%d",&key);
	ptr=head;
	while((ptr != NULL) && (ptr->data != key)){
		ptr=ptr->next;
	}
	if (ptr!=NULL){
		new->next=ptr->next;
        ptr->next=new;
        new->prev=ptr;
        (ptr->next)->prev=new;
		printf("\n%d inserted after %d\n\n",item,key);
	}
	else{
		printf("\nKey not found\n\n");
		free(new);
    }
}

void del_frm_beg(){
	Node *ptr;
	if(head==NULL){
		printf("\nEmpty List\n");
		return;}
	ptr=head;
	printf("\n%d deleted from beginning\n\n",ptr->data);
	head=head->next;
    if(head != NULL)
        head->prev=NULL;
	free(ptr);
}

void del_frm_end() {
    Node *ptr;
    if (head == NULL) {
        printf("\nEmpty List\n\n");
        return;
    }
    if (head->next == NULL) {
        printf("\n%d deleted from end\n\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;

    printf("\n%d deleted from end\n\n", ptr->data);
    ptr->prev->next = NULL;
    free(ptr);
}


void del_in_bw(){
	int key;
	Node *ptr;
	if(head==NULL){
		printf("\nEmpty List\n\n");
		return;}
	printf("Enter the key: ");
	scanf("%d",&key);
	ptr=head;
	while((ptr != NULL) && (ptr->data != key))
		ptr=ptr->next;
    if(ptr == NULL){
        printf("\nKey not found\n\n");
        return;
    }  
    if(ptr == head){
        head = ptr->next;
        if(head != NULL)
            head->prev = NULL;
    }
    else{
        (ptr->prev)->next = ptr->next;
    }
    if(ptr->next != NULL){
        (ptr->next)->prev = ptr->prev;
    }
    
    printf("\n%d deleted\n\n", ptr->data);
    free(ptr);
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
		ptr=ptr->next;
	}
	printf("\n\n");
}
int main(){
	int choice;
	do{
		printf("DLL Operations\n1.Insertion\t2.Deletion\t3.Display\t4.EXIT\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\n1.Insert at beginning\t2.Insert at end\t3.Insert in between\nEnter your choice: ");
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
				printf("\n1.Delete from beginning\t2.Delete from end\t3.Delete in between\nEnter your choice: ");
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
