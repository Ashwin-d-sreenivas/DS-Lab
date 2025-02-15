#include<stdio.h>

void main()
{
	int n,t;
	int poly1[100],poly2[100];
	
	printf("enter the highest degree:\n");
	scanf("%d",&n);
	int i;
	printf("enter the constants in a order such that the constant of the least power of variable comes first\n");
	for(i=0;i<=n;i++)
	{
		printf("enter term %d:",i);
		scanf("%d",&poly1[i]);
	}
	
	printf("enter the highest degree for poly2:\n");
	scanf("%d",&t);
	int j;
	printf("enter the constants in a order such that the constant of the least power of variable comes first\n");
	for(j=0;j<=t;j++)
	{
		printf("enter term %d:",j);
		scanf("%d",&poly2[j]);
	}
	
	int k;
	int poly_add[100];
	int tot;
	if(n>=t)
	{
		tot=n;
		for(k=0;k<=tot;k++)
		{	
			poly_add[k]=poly1[k];}
		
		for(k=0;k<=t;k++)
		{	
			poly_add[k]+=poly2[k];}
	}
	else{
		tot=t;
		for(k=0;k<=tot;k++)
		{
			poly_add[k]=poly2[k];}
		for(k=0;k<n;k++)
		{
			poly_add[k]+=poly1[k];}
	}
	
	printf("summation gives:\n");
	for(k=0;k<=tot;k++)
	{
		printf("%d\n",poly_add[k]);
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
