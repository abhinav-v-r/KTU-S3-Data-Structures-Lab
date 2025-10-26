#include <stdio.h>
#define MAX 50

int visited[MAX]={0},adj[MAX][MAX]={0};
int queue[MAX];
int front=-1,rear=-1;
void enqueue(int item){
 if(rear==MAX-1) printf("Queue is Full");
 else{
     if(front==-1) front=0;
     queue[++rear]=item;
     }
}

int dequeue(){
   int item;
   if(front==-1){ 
   	printf("Queue is Empty");
   	return -1; }
   else{ 
   item=queue[front];
   if(front==rear) front=rear=-1;
   else front++; }                                                                                        
   return item;	
}

void bfs_trav(int n,int v){
	printf("%d ",v);
	visited[v]=1;
	enqueue(v);
	while(front!=-1){
		v=dequeue();
		if(v==-1) break;
		for(int j=0;j<=n;j++){
			if(adj[v][j]==1 && visited[j]==0){
				printf("%d ",j);
				visited[j]=1;
				enqueue(j);
			}
		}
	}
	printf("\n");	
}

void main(){
	printf("BREADTH FIRST SEARCH\n\n");
	int n,choice,edge,v,a,b;
	printf("1.Directed\t2.Undirected\nEnter graph type: ");
	scanf("%d",&choice);
	printf("Enter no. of vertices: ");
	scanf("%d",&n);
	printf("Enter no. of edges: ");
	scanf("%d",&edge);
	printf("Enter the edges: \n");
	for(int i=0;i<edge;i++){
		scanf("%d",&a);
		(choice==1) ? printf("↓\n") : printf("│\n");
		scanf("%d",&b);
		printf("\n");
		if(choice==1) adj[a][b]=1;
		else if(choice==2) adj[a][b]=adj[b][a]=1;
	}
	printf("Enter starting vertex: ");
	scanf("%d",&v);
	printf("Displaying graph using BFS....\n");
	bfs_trav(n,v);	
}
