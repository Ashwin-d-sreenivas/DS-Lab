#include<stdio.h>

int top=-1;

int is_empty();
int is_full(int size);
void push(int x,int stack[],int size);
void pop(int stack[],int size);
void display(int stack[],int size);

void main(){
	int size;
	printf("enter size of the stack:");
	scanf("%d",&size);
	int stack[size];
	
	int choice;
	while(1){
		printf("enter your choice: 1.push/2.pop/3.display/any other integer to close the program:\n");
		scanf("%d",&choice);
		if(choice==1){
			int x;
			printf("enter element to be pushed:");
			scanf("%d",&x);
			push(x,stack,size);
			}
		else if(choice==2){
			pop(stack,size);
			}
		else if(choice==3){
			display(stack,size);
			}
		else{
			printf("closing!!!");
			break;
		}
	}
}

int is_empty(){
	if(top==-1){
		return -1;
		}
	else{
		return 1;
		}
}

int is_full(int size){
	if(top==size-1){
		return -1;
	}
	else{
		return 1;
		}
}

void push(int x,int stack[],int size){
	
	if(is_full(size)==-1){
		printf("stack overflow\n");
		return;
	}
	stack[++top]=x;
	return;
}

void pop(int stack[],int size){
	if(is_empty()==-1){
		printf("stack underflow\n");
		return;
	}

	printf("popped element is:%d\n",stack[top--]);
	}

void display(int stack[],int size){
	if(is_empty()==-1){
		printf("stack underflow\n");
		return ;
	}
	
	printf("stack from top to bottom is\n");
	for(int i=top;i>=0;i--){
		printf("%d\t",stack[i]);}
	printf("\n");
	return;}	
	
	
	
	
