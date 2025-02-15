#include<stdio.h>

int rear=-1;
int front=-1;

void enQueue(int x,int size,int queue[]);
void deQueue();
void display(int size,int queue[]);

void main(){
	int size;
	printf("enter the size of the queue:");
	scanf("%d",&size);
	int queue[size];
	int ch;
	while(1){
		printf("enter choice:1.enQueue/2.deQueue/3.display/4.exit:");
		scanf("%d",&ch);
		
		if(ch==1){
			printf("enter number:");
			int x;
			scanf("%d",&x);
			enQueue(x,size,queue);
		}
		else if(ch==2){
			deQueue();
		}
		else if(ch==3){
			display(size,queue);
		}
		else{
			printf("closing");
			printf("\n");
			break;}
	}
}

void enQueue(int x,int size,int queue[]){
	if(rear==size-1){
		printf("queue full\n");
		return;
	}
	rear++;
	queue[rear]=x;
	return;
}

void deQueue(){
	if(rear==front){
		printf("queue empty\n");
		return;
	}
	front++;
}

void display(int size,int queue[]){
	for(int i=front+1;i<size;i++){
		printf("%d",queue[i]);
		printf("\t");
	}
	printf("\n");
}



	
