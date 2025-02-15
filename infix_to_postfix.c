#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100

char stack[MAX];
char infix[MAX];
char postfix[MAX];
int top=-1;

void push(char c);	
char pop(); 		
int isEmpty();		
void inToPost();   
int space(char c);
void print();		
int precedence(char c);
int post_eval(); 

void main(){
	printf("enter the infix expression:");
	gets(infix);
	
	inToPost();
	print();
	int result=post_eval();
	printf("result =%d",result);
	
}

void inToPost(){
	int i,j=0;
	char next;
	char symbol;
	
	for(i=0;i<strlen(infix);i++){
		symbol=infix[i];
		
		if(!space(symbol)){
			switch(symbol){
				case '(':
					push(symbol);
					break;
				
				case ')':
					while((next=pop())!='('){
						postfix[j++]=next;
						
					}
					break;
				
				case '+':
				case '-':
				case '*':
				case '/':
					while(!isEmpty() && precedence(stack[top])>=precedence(symbol)){
						postfix[j++]=pop();
					}
					push(symbol);
					break;
				
				default:
					postfix[j++]= symbol;
				}
			}
		}
	while(!isEmpty()){
		postfix[j++]=pop();
			}
	postfix[j]='\0';
}

int space(char c){
	
	if(c== ' ' || c=='\t'){
		return 1;
	}
	else{
		return 0;
	}
}
	
int precedence(char c){
	if(c=='+'|| c=='-'){
		return 1;
		}
	else if(c=='*'|| c=='/'){
		return 2;
	}
	else{
		return 0;
	}
}



int isEmpty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}


void push(char c){
	if(top==MAX-1){
		printf("stack overflow");
		return;
	}
	top++;
	stack[top]=c;
}



char pop(){
	char c=stack[top];
	top--;
	return c;
}


void print(){
	char c;
	int i=0;
	while(postfix[i]!='\0'){
		printf("%c",postfix[i]);
		i++;
	}
	printf("\n");
}	

int post_eval(){
	int i,a,b;
	
	for(i=0;i<strlen(postfix);i++){
		if(postfix[i]>='0' && postfix[i]<='9'){
			push(postfix[i]-'0');
		}
		else{
			a=pop();
			b=pop();
			switch(postfix[i]){
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
				}
			}
		}
	return pop();
}

								
