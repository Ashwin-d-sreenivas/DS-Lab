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

struct poly *division(struct poly *p1,struct poly *p2)
{
	int i,j,k;
	struct poly *q;
	struct poly *r;
	q=malloc(sizeof(struct poly));
	r=malloc(sizeof(struct poly));
	q->n = p1->n;  
    	q->t = malloc(q->n * sizeof(struct term));
    	r->n = p1->n;
    	r->t = malloc(r->n * sizeof(struct term));
	i=j=k=0;
	for(int a=0;a<p1->n;a++)
	{
		r->t[a]=p1->t[a];
		}
	 while (r->t[i].exp >= p2->t[0].exp) {
        q->t[i].exp = r->t[i].exp - p2->t[0].exp;
        q->t[i].coef = r->t[i].coef / p2->t[0].coef;

        for (int j = 0; j < p2->n; j++) {
            r->t[i + j].coef -= q->t[i].coef * p2->t[j].coef;
        }

        i++;
    }

    
    k = 0;
    for (int j = 0; j < r->n; j++) {
        if (r->t[j].coef != 0) {
            r->t[k++] = r->t[j];
        }
    }
    r->n = k;

    printf("Quotient is:\n");
    display(*q);
    printf("Remainder is:\n");
    display(*r);
    
    return q;
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


