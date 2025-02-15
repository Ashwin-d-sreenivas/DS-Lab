#include<stdio.h>
#include<stdlib.h>

struct term{
	int coef;
	int exp;
	};

struct poly{
	int n;
	struct term *t;
	};

void create(struct poly *p)
{
	int i;
	printf("enter number of non zero terms:\n");
	scanf("%d",&p->n);
	p->t=malloc(p->n*sizeof(struct term));
	printf("enter the coef and exp:\n");
	for(i=0;i<p->n;i++)
	{
		printf("enter term %d and its exp:",i+1);
		scanf("%d %d",&p->t[i].coef,&p->t[i].exp);
	}
}
void display(struct poly p)
{
			int i;
			printf("polynomial is:");
			for(i=0;i<p.n;i++)
			{
				if(i!=p.n-1){
					printf("%dx^%d+",p.t[i].coef,p.t[i].exp);}
				else{
					printf("%dx^%d\n",p.t[i].coef,p.t[i].exp);}
			}
}


struct poly *add(struct poly *p1,struct poly *p2)
{
	int i,j,k;
	struct poly *sum;
	sum=malloc(sizeof(struct poly));
	sum->t=malloc((p1->n+p2->n)*sizeof(struct term));
	
	i=j=k=0;
	
	while(i<p1->n && j<p2->n)
	{
		if(p1->t[i].exp>p2->t[j].exp)
		{
			sum->t[k]=p1->t[i];
			k++;i++;
		}
		else if(p2->t[j].exp>p1->t[i].exp)
		{
			sum->t[k]=p2->t[j];
			k++;j++;
		}
		else{
			sum->t[k].exp=p1->t[i].exp;
			sum->t[k].coef=p1->t[i].coef+p2->t[j].coef;
			i++;j++;k++;
		}
	}
		
		for(i;i<p1->n;i++)
		{
			sum->t[k]=p1->t[i];
			k++;
		}
		for(j;j<p2->n;j++)
		{
			sum->t[k]=p2->t[j];
			k++;
		}
		
		sum->n=k;
		return sum;
}


struct poly *multiply(struct poly *p1,struct poly *p2)
{
	int i,j,k;
	struct poly *prod;
	i=j=k=0;
	prod=malloc(sizeof(struct poly));
	prod->t=malloc((p1->n*p2->n)*sizeof(struct term));
	
	for(i;i<p1->n;i++)
	{
		for(j;j<p2->n;j++)
		{
			prod->t[k].coef=p1->t[i].coef*p2->t[j].coef;
			prod->t[k].exp=p1->t[i].exp+p2->t[j].exp;
			k++;
		}
	}
	prod->n=k;
	
	for(i=0;i<prod->n-1;i++)
	{
		for(j=i+1;j<prod->n;j++)
		{
			if(prod->t[i].exp==prod->t[j].exp)
			{
				prod->t[i].coef+=prod->t[j].coef;
				prod->t[j]=prod->t[prod->n-1];
				prod->n--;
				j--;
			}
		}
	}
	prod->t=realloc(prod->t,prod->n*sizeof(struct term));
	return prod;
}

struct poly *division(struct poly *p1,struct poly *p2)
{
	int i,j,k;
	struct poly *q;
	struct poly *r;
	q=malloc(sizeof(struct poly));
	r=malloc(sizeof(struct poly));
	if(p1->t[0].exp>=p2->t[0].exp)
	{
		q->t=malloc(p1->n*sizeof(struct term));
		r->t=malloc(p1->n*sizeof(struct term));
	}
	else{
		printf("q=0 , r=p2");
		return p2;
	}
	i=j=k=0;
	for(i;i<p1->n;i++)
	{
		for(j;j<p2->n;j++)
		{
			q->t[k].exp=p1->t[i].exp-p2->t[j].exp;
			q->t[k].coef=p1->t[i].coef/p2->t[j].coef;
			
		}
	}
	

void main()
{
	struct poly p1,p2,*p3,*p4,*p5;
	create(&p1);
	create(&p2);
	display(p1);
	display(p2);
	p3=add(&p1,&p2);
	display(*p3);
	p4=multiply(&p1,&p2);
	display(*p4);
	
	}















