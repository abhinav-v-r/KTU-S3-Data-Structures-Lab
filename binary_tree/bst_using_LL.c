#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *lc,*rc;
} Node;

Node *root=NULL;

void insert(){
	Node *p,*par;
	int key;
	int c;
	Node *new=(Node*)malloc(sizeof(Node));
	printf("Enter the Node: ");
	scanf("%d",&key);
	new->data=key;
	new->lc=new->rc=NULL;
	if(root==NULL){
		root=p=new;
		return;	
	}
	p=root;
	while(p!=NULL){
		if(p->data>key){
			par=p;
			p=p->lc;
        }
		else if(p->data<key){
			par=p;
			p=p->rc;
        }
		else{
			printf("Value already exists!");
			return;
		}
	}
	if(par->data>key) par->lc=new;
	else par->rc=new;

}

Node* inorder_succ(Node *p){
	Node *ptr;
	if(p->rc!=NULL) ptr=p->rc;
	while(ptr->lc!=NULL){ 
		ptr=ptr->lc;
}
	return ptr;
}

void delete(int key){
	int c;
	Node *p=root,*par=NULL;
	int found=0;
	while(p!=NULL){
		if(p->data>key){
			par=p;
			p=p->lc;
        }
		else if(p->data<key){
			par=p;
			p=p->rc;
        }
		else{
			found=1;
			break;
		}
	}
	if(p==NULL){
		printf("Node not exists!\n\n");
		return;	
	}
	if(p->lc==NULL && p->rc==NULL) c=1;
	else if(p->lc!=NULL && p->rc!=NULL) c=3;
	else c=2;
	
	if(c==1){
		if(p==par->lc) par->lc=NULL;
		else par->rc=NULL;
		free(p);
	}
	if(c==2){
		if(p==par->lc){
			if(p->lc==NULL) par->lc=p->rc;
			else par->lc=p->lc;
		}
		if(p==par->rc){
			if(p->lc==NULL) par->rc=p->rc;
			else par->rc=p->lc;
		}	
	free(p);	
	}
	if(c==3){
		Node *ptr=inorder_succ(p);
		int temp=ptr->data;
		delete(temp);
		p->data=temp;
	}
printf("%d deleted\n\n",key);
}





void inorder(Node *p){
	if(p!=NULL){
		inorder(p->lc);
		printf("%d ",p->data);
		inorder(p->rc);		
	}
	return;
}

void preorder(Node *p){
	if(p!=NULL){
		preorder(p->lc);
		preorder(p->rc);
		printf("%d ",p->data);		
	}
	return;
}


void postorder(Node *p){
	if(p!=NULL){
		printf("%d ",p->data);
		postorder(p->lc);
		postorder(p->rc);		
	}
	return;
}


int main(){
	int c,item;
	do{
		printf("\n1.Insert\n2.Delete\n3.Display\n4.EXIT\nEnter your choice: ");
		scanf("%d",&c);
		switch(c){
			case 1: insert();break;
			case 2: 
					printf("Enter the node to delete: ");
					scanf("%d",&item);				
					delete(item);
					break;
			case 3: printf("Inorder: ");
					inorder(root);
					printf("Preorder: ");
					preorder(root);
					printf("Postorder: ");
					postorder(root);
					break;
			case 4: exit(0);
			default: printf("Invalid choice!\n\n");	
		}	
	}while(1);
	
}
