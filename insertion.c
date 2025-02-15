#include<stdio.h>

void main(){
	int n;
	printf("enter the number of elements in the array:\n");
	scanf("%d",&n);
	
	int arr[n];
	int key,i,j;
	for(i=0;i<n;i++){
		printf("element %d:",i+1);
		scanf("%d",&arr[i]);
	}
	
	for(i=1;i<n;i++){
		j=i-1;
		key=arr[i];
		while(arr[j]>key && j>=0){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
		}
		
	printf("sorted array:");
	for(i=0;i<n;i++){
		printf("%d \t",arr[i]);}
	printf("\n");
}

