#include<stdio.h>
#include<stdlib.h>

struct terms{
	int coef;
	int exp;
	};

struct poly{
	int n;
	struct terms *term;};

void create(struct poly *p)
{
	int i;
	printf("enter number of terms:");
	scanf("%d",&p->n);
	p->term=malloc(p->n*sizeof(struct terms));
	
	printf("enter the term in the form of coef exp:\n");
	for(i=0;i<p->n;i++)
	{
		printf("enter term %d:\n",i+1);
		scanf("%d %d",&p->term[i].coef,&p->term[i].exp);
	}
	
}

void display(struct poly p)
{
	int i;
	printf("polynomial is:\n");
	for(i=0;i<p.n;i++)
	{
		if(i!=p.n-1)
		{
			printf("%dx^%d+",p.term[i].coef,p.term[i].exp);
			}
		else{
			printf("%dx^%d",p.term[i].coef,p.term[i].exp);
		}
	}
	printf("\n");
}

struct poly *add(struct poly *p1,struct poly *p2)
{
	int i,j,k;
	struct poly *sum;
	sum=malloc(sizeof(struct poly));
	sum->term=malloc((p1->n+p2->n)*sizeof(struct terms));
	i=j=k=0;
	while(i<p1->n && j<p2->n)
	{
		if(p1->term[i].exp>p2->term[j].exp)
		{
			sum->term[k]=p1->term[i];
			i++;k++;
		}
		else if(p2->term[j].exp>p1->term[i].exp)
		{
			sum->term[k]=p2->term[j];
			j++;k++;
		}
		else{
			sum->term[k].exp=p1->term[i].exp;
			sum->term[k].coef=p1->term[i].coef+p2->term[j].coef;
			i++;j++;k++;
			}
	}
	for(i;i<p1->n;i++)
	{
		sum->term[k]=p1->term[i];
		k++;
	}
	for(j;j<p2->n;j++)
	{
		sum->term[k]=p2->term[j];
		k++;
	}
	sum->n=k;
	
	return sum;
}

struct poly *multiply(struct poly* p1,struct poly *p2)
{
	int i,j,k;
	i=j=k=0;
	struct poly *prod;
	
	prod=malloc(sizeof(struct poly));
	prod->term=malloc(p1->n*p2->n*sizeof(struct terms));
	for(i=0;i<p1->n;i++)
	{
		for(j=0;j<p2->n;j++)
		{
			prod->term[k].coef=p1->term[i].coef*p2->term[j].coef;
			prod->term[k].exp=p1->term[i].exp+p2->term[j].exp;
			k++;
		}
	}
	prod->n=k;
	for(i=0;i<prod->n;i++)
	{
		for(j=i+1;j<prod->n;j++)
		{
			if(prod->term[i].exp==prod->term[j].exp)
			{
				prod->term[i].coef+=prod->term[j].coef;
				prod->term[j]=prod->term[prod->n-1];
				prod->n--;
				j--;
			}
		}
	}
	
	prod->term=realloc(prod->term,prod->n*sizeof(struct terms));
	return prod;
}

void main()
{
	struct poly p1,p2,*p3,*p4;
	create(&p1);
	create(&p2);
	display(p1);
	display(p2);
	p3=add(&p1,&p2);
	printf("added :");
	display(*p3);
	printf("multiplied");
	p4=multiply(&p1,&p2);
	display(*p4);
}

