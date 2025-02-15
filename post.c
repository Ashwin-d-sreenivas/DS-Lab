#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
char infix[MAX],postfix[MAX],stack[MAX];
int top=-1;

void push(char c)
{
	if(top==MAX-1)
	{
 	printf("stack overflow");
 	return;
 	}
 	stack[++top]=c;
	
}
char pop(){
	char c;
	if(top==-1)
	{
		printf("stack underflow");
		return -1;
	}
	else
	{
		c=stack[top];
		top--;
		return c;
	}
}
int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int precedence(char symbol){
	switch(symbol)
	{
		case '^':
			return 3;
		case '/':
			return 2;
		case '*':
			return 2;
		case '+':
			return 1;
		case '-':
			return 1;
		default:
			return 0;
	}
}
void print()
{
	int i=0;
	printf("postfix expression:\n");
	while(postfix[i]!='\0')
	{
		printf("%c",postfix[i]);
		i++;
	}
	printf("\n");
	
}


void toPostfix()
{
	int i,j=0;
	char symbol,next;
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		switch(symbol)
		{
			case '(':
				push(symbol);
				break;
			case ')':
				while((next=pop())!='(')
				{
					postfix[j++]=next;
				}
				break;
			case '+':
			case '-':
			case '/':
			case '*':
			case '^':
				while(!(isEmpty()) && precedence(stack[top])>=precedence(symbol)){
				postfix[j++]=pop();
				push(symbol);}
				break;
			default :
			postfix[j++]=symbol; 
}}
	while(!isEmpty()){
		postfix[j++]=pop();  
	}
	postfix[j]='\0';
	
}
int post_eval()
{
	int i;
	int a,b;
	for(i=0;i<strlen(postfix);i++)
	{
		if(postfix[i]>='0' && postfix[i]<='9')
	{
	push(postfix[i]-'0');
	}
	else{
		a=pop();
		b=pop();
		switch (postfix[i])
    {
    case '+':
     push(b+a);
     break;
    case '-':
     push(b-a);
     break;
    case '*':
     push(b*a);
     break;
    case '/':
     push(b/a);
     break;
    case '^':
     push(pow(b,a));
     break;
    }
   }
  }
  return pop();
}

int main()
{
	 printf("Enter infix expression\n");
	 scanf("%s",infix);
	 toPostfix();
	 print();
	 int result=post_eval();
	 printf("Result obtained after postfix evaluation\t");
	 printf("%d\n",result);
	 return 0;
}
	

