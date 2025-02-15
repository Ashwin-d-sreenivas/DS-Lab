#include<stdio.h>
#include<stdlib.h>

struct term{
	float coef;
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
		scanf("%f %d",&p->t[i].coef,&p->t[i].exp);
	}
}
void display(struct poly p)
{
			int i;
			printf("polynomial is:");
			for(i=0;i<p.n;i++)
			{
				if(i!=p.n-1){
					printf("%fx^%d+",p.t[i].coef,p.t[i].exp);}
				else{
					printf("%fx^%d\n",p.t[i].coef,p.t[i].exp);}
			}
}

void division(struct poly *p1,struct poly *p2)
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
		printf("quotient=0 , remainder=p2");
		display(*p2);
	}
	i=j=k=0;
	
	for(int a=0;a<p1->n;a++)
	{
		r->t[a]=p1->t[a];
		}
	r->n=p1->n;
	
	while(r->t[0].exp>=p2->t[0].exp)
	{
		q->t[i].exp=r->t[0].exp-p2->t[0].exp;
		q->t[i].coef=r->t[0].coef/p2->t[0].coef;
		
		
		for(j=0;j<=p2->n;j++)
		{
			r->t[j].coef=r->t[j].coef-q->t[0].coef*p2->t[j].coef;;}
		
		
		while(r->t[0].coef==0)
		{
			for(k=0;k<sizeof(r->t)-1;k++)
			{
				r->t[k].coef=r->t[k+1].coef;
				r->t[k].exp=r->t[k+1].exp;
			}
			r->t[k].coef=0;
			r->t[k].exp=0;
			
		}
		
	}
	
	printf("quo is:");
	display(*q);
	printf("rem is");
	display(*r);
	
}	
			
	
	
	
void main()
{
	struct poly p1,p2,*p3;
	create(&p1);
	create(&p2);
	display(p1);
	display(p2);
	division(&p1,&p2);

	
	}
