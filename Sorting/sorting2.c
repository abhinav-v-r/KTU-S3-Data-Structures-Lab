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

void quick_sort(int start, int end){
	if(start<end){
		int pivot=arr[start];
		int l=start,r=end;
		while(l<r){
			while(arr[l]<=pivot && l<=end) l++;
			while(arr[r]>pivot && l>=start) r--;
			if(l<r){
				int temp=arr[l];
				arr[l]=arr[r];
				arr[r]=temp;
			}
		}
		int temp=arr[r];
		arr[r]=arr[start];
		arr[start]=temp;
		quick_sort(start,r-1);
		quick_sort(r+1,end);
	}
	return;
}
void merge(int x[], int y[], int l, int m, int s) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= s) {
        if (x[i] < x[j]) {
            y[k++] = x[i++];
        } else {
            y[k++] = x[j++];
        }
    }
    if (i > m) {
        for (int t = j; t <= s; t++) {  
            y[k++] = x[t];
        }
    } else {
        for (int t = i; t <= m; t++) {
            y[k++] = x[t];
        }
    }
}

void mpass(int x[], int y[], int l) {
    int i = 0;
   while (i + 2 * l - 1 < n){
        merge(x, y, i, i + l - 1, (i + 2 * l - 1));
        i = i + 2 * l;
    }
    if (i + l - 1 < n) {
        merge(x, y, i, i + l - 1, n-1);
    } else {
       for (int t = i; t < n; t++) {
    			y[t] = x[t];
			}
    }
}

void merge_sort(int x[]) {
		int *y = (int*)malloc(n * sizeof(int));
    int l = 1;
    while (l < n) {
        mpass(x, y, l);
        l = 2 * l;
        mpass(y, x, l);
        l = 2 * l;
    }
}

void heapify(int i, int n){
	int largest=i;
	int l=2*i+1,r=2*i+2;
	if((l<=n-1) && (arr[l]>arr[largest])) largest=l;
	if((r<=n-1) && (arr[r]>arr[largest])) largest=r;
	if(largest!=i){
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		heapify(largest,n);
	}
}
void heap_sort(){
	for(int i = n/2 - 1; i >= 0; i--) {
  	  heapify(i, n);
	}
	for(int i=n-1;i>=1;i--){
		int temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		heapify(0,i);
	}
}


int main(){
	printf("SORTING\n\n");
	int choice;
	do{
		insert();
		display(1);
		printf("1.Quick Sort\t2.Merge Sort\t3.Heap Sort\t4.Exit\nChoose a sorting algorithm: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: quick_sort(0,n-1);
					display(2);
					break;
			case 2: merge_sort(arr);
					display(2);
					break;
			case 3: heap_sort();
					display(2);
					break;
			case 4:
					exit(0);
					break;
			default: printf("Enter a valid choice!");
		}
	}while(1);
return 0;
}
