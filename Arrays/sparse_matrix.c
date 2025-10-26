//Sparse Matrix- Transpose and Addition

#include<stdio.h>
#include<stdlib.h>
#define N 100

typedef struct matrix{
	int row;
	int col;
	float value;
} Mat;

Mat a[N],b[N],c[N],trans[N];
int rows,cols,terms;

void display(Mat matrix[], int terms) {
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < terms; i++) {
        printf("%d\t%d\t%.0f\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
    printf("\n");
}

void input(int n) {
	Mat *matrix = (n == 1) ? a : b;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter number of non-zero elements: ");
    scanf("%d", &terms);

    if(terms >= N) {
        printf("Error: Number of terms cannot exceed %d\n", N-1);
        return;
    }

    matrix[0].row = rows;
    matrix[0].col = cols;
    matrix[0].value = terms;

    printf("Enter row, column, and value of non-zero elements:\n");
    for (int i = 1; i <= terms; i++) {
        printf("Element %d: ", i);
        scanf("%d %d %f", &matrix[i].row, &matrix[i].col, &matrix[i].value);
    }
    display(matrix, terms + 1);
}


void transpose(Mat z[]){ //Naive ALGORITHM
	trans[0].row=z[0].col;
	trans[0].col=z[0].row;
	trans[0].value=z[0].value;
	int currentb=1;
	for(int i=0;i<z[0].col;i++){
		for(int j=1;j<=z[0].value;j++){
			if(z[j].col==i){
				trans[currentb].row=z[j].col;
				trans[currentb].col=z[j].row;
				trans[currentb].value=z[j].value;
				currentb++;
			}
		}	
	}
printf("\nTranspose of the matrix : \n\n");
display(trans,z[0].value + 1);
}


void addition(){
	if(a[0].row != b[0].row || a[0].col != b[0].col){
		printf("Addition not Possible !\n");
		return;
	}
	c[0].row=a[0].row; c[0].col=a[0].col;
	int t1= a[0].value,t2=b[0].value;
	int i=1,j=1,k=1;
	while(i<=t1 && j<=t2){
//Case1		
		if(a[i].row==b[j].row && a[i].col==b[j].col){
			if(a[i].value + b[j].value ==0){
				i++;
				j++;
			}
			else{
				c[k].row= a[i].row;
				c[k].col=b[j].col;
				c[k].value=a[i].value + b[j].value;
				i++;j++;k++;
			}	
		}	
//Case2
		else if(a[i].row==b[j].row && a[i].col>b[j].col){
			c[k].row= b[j].row;
			c[k].col=b[j].col;
			c[k].value=b[j].value;
			j++;k++;	
		}
//Case 3
		else if(a[i].row==b[j].row && a[i].col<b[j].col){
			c[k].row= a[i].row;
			c[k].col=a[i].col;
			c[k].value=a[i].value;
			i++;k++;	
		}
//Case 4
		else if(a[i].row<b[j].row){
			c[k].row= a[i].row;
			c[k].col=a[i].col;
			c[k].value=a[i].value;
			i++;k++;	
		}
//Case 5
		else if(a[i].row>b[j].row){
			c[k].row= b[j].row;
			c[k].col=b[j].col;
			c[k].value=b[j].value;
			j++;k++;	
		}
	}
//Residue Loop
	while(i<=t1){
		c[k].row= a[i].row;
		c[k].col=a[i].col;
		c[k].value=a[i].value;
		i++;k++;
	}
	while(j<=t2){
		c[k].row= b[j].row;
		c[k].col=b[j].col;
		c[k].value=b[j].value;
		j++;k++;
	}
	c[0].value=k-1;
	printf("\nResult of Addition:\n");
	display(c,k);
}


int main() {
	int choice;
	do{
		printf("1.Addition \t2.Transpose\t3.EXIT\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Matrix 1: \n");
				input(1);
				printf("Matrix 2: \n");
				input(2);
				addition();
				break;
			case 2:
				printf("Matrix: \n");
				input(1);
				transpose(a);
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("Enter a valid choice!\n");
		}
	}while(1);	
return 0;
}
