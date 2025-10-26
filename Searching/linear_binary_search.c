#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int arr[MAX];

void read_elements(int n){
	printf("Enter elements: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);}
	printf("Array: [");
	for(int i=0;i<n;i++){
		printf("%d",arr[i]);
		if(i!=n-1) printf(",");
	}
	printf("]\n");
}

void sort_arr(int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;}
		}
	}
}


void linear_search(int x,int n){
		printf("Searching %d using linear search...\n",x);
		int i,found=0;
		for(i=0;i<n-1;i++){
			if(arr[i]==x){
				found=1;
				break;
			}
		}
		if(found) printf("Element found at index %d\n",i);
		else printf("Element not found\n");		
}

void binary_search(int x, int n){
	sort_arr(n);
	printf("Searching %d using binary search...\n",x);
	int found=0,beg=0,end=n-1,mid;
	while(beg<=end && !found){
		mid=(beg+end)/2;
		if(x<arr[mid]) end=mid-1;
		else if(x>arr[mid]) beg=mid+1;
		else found=1;
	}
	if(found){
	printf("Sorted Array: [");
	for(int i=0;i<n;i++){
		printf("%d",arr[i]);
		if(i!=n-1) printf(",");
	}
	printf("]\n");
	printf("Element found at index %d in sorted array\n",mid);}
	else printf("Element not found\n");		
}

int main(){
	int n,choice,key;
	printf("SEARCHING\n\n");
	printf("Enter no. of elements in array: ");
	scanf("%d",&n);
	read_elements(n);
	do{
	printf("\n1.Linear Search\t2.Binary Search\t3.EXIT\nEnter the type of search to perform: ");
	scanf("%d",&choice);
	if(choice==1 || choice==2){
		printf("Enter the key: ");
		scanf("%d",&key);
		if(choice==1) linear_search(key,n);
		else if(choice==2) binary_search(key,n);}
	else if(choice==3) exit(0);
	else printf("Invalid choice!");
	}while(1);
return 0;
}
