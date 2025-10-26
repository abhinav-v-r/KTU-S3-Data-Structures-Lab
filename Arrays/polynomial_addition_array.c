//Polynomial Addition using Array
#include<stdio.h>
#include<stdlib.h>
#define N 5

typedef struct term{
	float coeff;
	int exp;
} Term;

Term p[N],q[N],r[N];
int np,nq,nr;

void input(int n){
	Term *poly = (n == 1) ? p : q;
	int terms;
	printf("\nEnter Polynomial %d\n",n);
	printf("Enter no. of terms: ");
	scanf("%d",&terms);
	
	// Bounds check
	if(terms > N) {
		printf("Error: Number of terms cannot exceed %d\n", N);
		return;
	}
	
	(n==1) ? (np=terms) : (nq=terms);
	printf("Enter the terms: \n");
	for(int i=0;i<terms;i++){
		printf("Term-%d\tCoeff: ",i+1);
		scanf("%f",&poly[i].coeff);
		printf("\tExp: ");
		scanf("%d",&poly[i].exp);
	}
	
}

void addition(){
	int i=0,j=0,k=0;
	while(i<np && j<nq){
		if(p[i].exp < q[j].exp){
			r[k].coeff=q[j].coeff;
			r[k].exp=q[j].exp;
			k++;j++;
		}		
		else if(p[i].exp > q[j].exp){
			r[k].coeff=p[i].coeff;
			r[k].exp=p[i].exp;
			k++;i++;
		}
		else if(p[i].exp == q[j].exp){
			r[k].coeff=p[i].coeff + q[j].coeff;
			r[k].exp=p[i].exp;
			k++;j++,i++;
		}			
	}
	//Residue Loop	
	while(i<np){
		r[k].coeff=p[i].coeff;
		r[k].exp=p[i].exp;
		k++;i++;
	}
	while(j<nq){
		r[k].coeff=q[j].coeff;
		r[k].exp=q[j].exp;
		k++;j++;
	}
nr=k;
display();
}

void display() {
    printf("Result: \n");
    for (int i = 0; i < nr; i++) {
        printf("%.0fx^%d", r[i].coeff, r[i].exp);
        if (i < nr - 1) printf(" + ");
    }
    printf("\n");
}

	

int main() {
	printf("Addition of Polynomials\n");
	input(1);
	input(2);
	addition();
}
