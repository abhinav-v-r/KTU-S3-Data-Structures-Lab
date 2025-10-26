#include <stdio.h>
#define MAX 50

int visited[MAX]={0}, adj[MAX][MAX]={0};
int stack[MAX];
int top=-1;

void push(int item){	
	if(top==MAX-1)
		printf("Stack Overflow\n\n");
	else{
		top++;
		stack[top]=item;
	}
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n\n");
        return -1; }
    else {
        int item = stack[top];
        top--;
        return item;
    }
}


void dfs_trav(int n, int v) {
    int pop_v;
    push(v);
    while (top != -1) {
        pop_v = pop();
		if (pop_v == -1) break;
        if (visited[pop_v] == 0) { 
            printf("%d ", pop_v);
            visited[pop_v] = 1;
            for (int j = n-1; j >= 0; j--) {
                if (adj[pop_v][j] == 1 && visited[j] == 0) {
                    push(j);
                }
            }
        }
    }
    printf("\n");
}

void main(){
	printf("DEPTH FIRST SEARCH\n\n");
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
	printf("Displaying graph using DFS....\n");
	dfs_trav(n,v);	
}
