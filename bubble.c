#include<stdio.h>
void main()
{
	int n,j,k,temp;
	printf("enter no of elements:");
	scanf("%d",&n);
	int array[n];
	for(int i=0;i<n;i+=1)
		{
		printf("enter array numbers:");
		scanf("%d",&array[i]);
		}
	for(int i=0;i<n;i++)
	{
		for(j=0;j<n-1;j+=2)
		{
			if(array[j]>array[j+1]){
			temp=array[j];
			array[j]=array[j+1];
			array[j+1]=temp;}
		}
		for(k=1;k<n-1;k+=2)
		{
			if(array[k]>array[k+1]){
			temp=array[k];
			array[k]=array[k+1];
			array[k+1]=temp;}
		}
	}
	printf("array rearranged to:");
	for(int i=0;i<n;i+=1)
	{
		printf("%d",array[i]);
	}
}
