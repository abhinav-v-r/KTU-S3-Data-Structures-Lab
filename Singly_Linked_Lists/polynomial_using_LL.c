//Addition and Multiplication of Polynomials using Linked List

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	float coeff;
	int exp;
	struct node *link;
	} Node;

Node *poly1,*poly2,*sumresult,*prodresult;

Node* createnode(){
	Node *head=NULL,*ptr=head;
	int degree;
	printf("Enter degree of Polynomial: ");
	scanf("%d",&degree);
	for(int i=0;i<degree;i++){
		Node *new=(Node*)malloc(sizeof(Node));
		printf("Enter the terms(Coefficient and Exponent): \n");
		scanf("%f",&new->coeff);
		scanf("%d",&new->exp);
		new->link=NULL;	
		if (head==NULL)
			head=ptr=new;
		else{
			ptr->link=new;
			ptr=ptr->link;
		}
	}
return head;
}

void display(Node *head){
	Node *ptr;
	if(head==NULL){
		printf("\nEmpty List\n\n");
		return;
	}
	ptr=head;
	printf("\n");
	while(ptr->link!=NULL){
		printf("%.1fx^%d + ",ptr->coeff,ptr->exp);
		ptr=ptr->link;
	}
	printf("%.1fx^%d",ptr->coeff,ptr->exp);
	printf("\n\n");
}



void addition(){
	Node *i,*j,*k,*temp;
	i=poly1;
	j=poly2;
	while(i!=NULL && j!=NULL){
		Node *new=(Node*)malloc(sizeof(Node));
		if(i->exp>j->exp){
			new->coeff=i->coeff;
			new->exp=i->exp;
			i=i->link;
		}
		else if(i->exp<j->exp){
			new->coeff=j->coeff;
			new->exp=j->exp;
			j=j->link;
		}
		else{
			new->coeff=i->coeff + j->coeff;
			new->exp=i->exp;
			i=i->link;
			j=j->link;
		}
		
		if(sumresult==NULL)
			sumresult=k=new;
		else{
			k->link=new;
			k=new;
		}
	}
	while(i!=NULL){
		Node *new=(Node*)malloc(sizeof(Node));
		new->coeff=i->coeff;
		new->exp=i->exp;
		k->link=new;
		k=new;
		i=i->link;
	}
	while(j!=NULL){
		Node *new=(Node*)malloc(sizeof(Node));
		new->coeff=j->coeff;
		new->exp=j->exp;
		k->link=new;
		k=new;
		j=j->link;
	}		
display(sumresult);

}

void multiply(){
	Node *i,*j,*k,*temp;
	i=poly1;
	while(i!=NULL){
		j=poly2;
		while(j!=NULL){
			Node *new=(Node*)malloc(sizeof(Node));
			new->coeff=i->coeff*j->coeff;
			new->exp=i->exp+j->exp;
			new->link=NULL;
			temp=prodresult;
			int found=0;
			while(temp!=NULL){
				if(temp->exp==new->exp){
					temp->coeff+=new->coeff;
					found=1;
					break;
				}
				temp=temp->link;
			}
			if(!found){
				if(prodresult==NULL){
					prodresult=new;
					k=new;
				}
				else{
					k->link=new;
					k=new;
				}
			}
			j=j->link;
		}		
		i=i->link;
	}
}
int main(){
	int choice;
	do{
		printf("1.Create Polynomial\t2.Addition\t3.Multiplication\t5.EXIT\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			printf("1.1st Polynomial\t2.2nd Polynomial\n");
			scanf("%d",&choice);
			switch(choice){
				case 1:
					poly1=createnode();
					break;
				case 2:
					poly2=createnode();
					break;
			}
			break;
		case 2:
			addition();
			break;
		case 3:
			multiply();
			display(prodresult);
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("Enter a valid choice!");	
		}		
	}while(1);	
	
	
	
return 0;	
}
