#include<stdio.h>

int search(int key,int arr[100],int count);

void main()
{
	int key,array[100],n,i,res;
	
	printf("enter number of elements in the array:");
	scanf("%d",&n);
	
	printf("enter the elements in array in sorted order:");
	for(i=0;i<n;i++)
	{
		printf("element %d=",i+1);
		scanf("%d",&array[i]);
	}
	
	printf("enter number to be searched:");
	scanf("%d",&key);
	
	res=search(key,array,n);
	printf("closest element is %d",res);
}

int search(int key,int arr[100],int count)
{
	int f,l,mid,s=1000;
	int close;
	f=0;
	l=count-1;
	mid=(f+l)/2;
	
	while(f<=l)
	{
		if(arr[mid]==key)
		{
			s=mid;
			close=arr[mid];
			return close;
		}
		else if(arr[mid]<key)
		{	
			f=mid+1;
			mid=(f+l)/2;
		}
		else(arr[mid]>key);
		{
			l=mid-1;
			mid=(f+l)/2;
		}	
	}
	printf("%d",close);
	if(s==1000)
	{
		return close;
	}
}		
		
