#include<stdio.h>

int top1=-1;
int top2=-1;

int isEmpty();
int isFull(int size);
void push(int x,int st1[]);
int pop(int st[],int top);
void display(int st1[]);

void main(){
	int size;
	printf("enter the size of the queue:");
	scanf("%d",&size);
	int st1[size],st2[size];
	int ch,x,top;
	
	while(1){
		printf("enter choice:1.enqueue/2.dequeue/3.display/any other number to exit:");
		scanf("%d",&ch);
		
		if(ch==1){
			if(isFull(size)){
				printf("queue full");
				continue;
			}
			
			printf("enter number to put inside queue:");
			scanf("%d",&x);
			push(x,st1);
		}
		
		else if(ch==2){
			if(isEmpty()){
				printf("no elements");
				continue;}
				
			while(top1!=-1){
				top=1;			//top to be changed here is top1
				st2[++top2]=pop(st1,top);
			}
			top=2;
			pop(st2,top);
			while(top2!=-1){
				top=2;			//top to be changed her is top2
				st1[++top1]=pop(st2,top);
			}
		}
		
		else if(ch==3){
			display(st1);
		}
		
		else{
			printf("closing!!!\n");
			break;
		}
	}
}	

int isEmpty(){
	if(top1==-1){
		return 1;
	}
	else{
		return 0;
	}
}

int isFull(int size){
	if(top1==size-1){
		return 1;
	}
	else{
		return 0;
	}
}

void push(int x,int st1[]){
	st1[++top1]=x;
}

int pop(int st[],int top){
	if(top==1){
		return st[top1--];
	}
	else if(top==2){
		return st[top2--];
	}
}

void display(int st1[]){
	for(int i=0;i<=top1;i++){
		printf("%d\t",st1[i]);
	}
	printf("\n");
}












