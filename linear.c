#include<stdio.h>

int linear(int key,int array[100],int num);

void main()
{
	int key,arr[100],res,i,j,n;
	printf("enter number of elements:");
	scanf("%d",&n);
	
	printf("enter the array \n");
	for(i=0;i<n;i++)
	{
		printf("element %d=",i+1);
		scanf("%d",&arr[i]);
	}
		
	printf("enter number to be searched:");
	scanf("%d",&key);
	res=linear(key,arr,n);
	
	if(res==-1)
	{
		printf("element not found \n");
	}
	else
	{
		printf("element in position %d \n",res);
	}
}


int linear(int key,int array[100],int num)
{
	int j,found=-1;
	for(j=0;j<num;j++)
	{
		if(array[j]==key)
		{
			return j;
			}
	}
	
	if(found==-1)
	{
		return found;
	}
}
