#include<stdio.h>

void main(){
	int n;
	printf("enter the number of elements in the array:\n");
	scanf("%d",&n);
	
	int arr[n];
	int min,temp,i,j;
	for(i=0;i<n;i++){
		printf("element %d:",i+1);
		scanf("%d",&arr[i]);
		}
	
	for(i=0;i<n;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
		
	}
	
	printf("sorted array:");
	for(i=0;i<n;i++){
		printf("%d \t",arr[i]);}
	printf("\n");
}
