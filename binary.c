#include<stdio.h>

int search(int key,int arr[100],int count);

void main()
{
	int key,array[100],n,i,res;
	
	printf("enter number of elements in the array:");
	scanf("%d",&n);
	
	printf("enter the elements in array in sorted order: \n");
	for(i=0;i<n;i++)
	{
		printf("element %d=",i+1);
		scanf("%d",&array[i]);
	}
	
	printf("enter number to be searched:");
	scanf("%d",&key);
	
	res=search(key,array,n);
	if(res==-1)
	{
		printf("element not found \n");
		}
	else{
		printf(" element in position %d \n",res);
	}
}

int search(int key,int arr[100],int count)
{
	int f,l,mid;
	f=0;
	l=count-1;
	mid=(f+l)/2;
	
	while(f<=l)
	{
		if(arr[mid]==key)
		{
			return mid;
		}
		else if(arr[mid]<key)
		{	
			f=mid+1;
			mid=(f+l)/2;
		}
		else
		{
			l=mid-1;
			mid=(f+l)/2;
		}	
	}
	return -1;
	
}

		
		
		
		
		
		
		
		
		
		
		
		
