#include<stdio.h>
#include<stdlib.h>
#define N 10

int n;
int arr[N];

void display(int k){
	(k==1) ? printf("Array: [") : printf("Sorted Array: [");
	for(int i=0;i<n;i++){
		printf("%d",arr[i]);
		if(i!=n-1) printf(", ");
	}
	printf("]\n\n");
}

void insert(){
	printf("Enter size of array: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("%d: ",i+1);
		scanf("%d",&arr[i]);
	}
}

void bubble_sort(){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
void insertion_sort(){
	for(int i=1;i<=n-1;i++){
		int temp=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>temp){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}

}
void selection_sort(){
	for(int i=0;i<=n-1;i++){
		int min=arr[i];
		int min_index=i;
		for(int j=i+1;j<=n-1;j++){
			if(arr[j]<min){
				min=arr[j];
				min_index=j;
			}
		}		
		int temp=arr[i];
		arr[i]=arr[min_index];
		arr[min_index]=temp;
	}
}
int main(){
	printf("SORTING\n\n");
	int choice;
	do{
		insert();
		display(1);
		printf("1.Bubble Sort\t2.Insertion Sort\t3.Selection Sort\nChoose a sorting algorithm: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: bubble_sort();
					display(2);
					break;
			case 2: insertion_sort();
					display(2);
					break;
			case 3: selection_sort();
					display(2);
					break;
			case 4: exit(0);
				break;
			default: printf("Enter a valid choice!");
		}
	}while(1);
return 0;
}
