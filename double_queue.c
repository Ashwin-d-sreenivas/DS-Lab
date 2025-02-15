#include<stdio.h>

int rear=0;
int front=-1;

void enQueueFront(int x,int size,int queue[]);
void enQueueBack(int x,int size,int queue[]);
void deQueueFront(int size,int queue[],int ch);
void deQueueBack(int size,int queue[],int ch);
void display(int size,int queue[],int ch);

void main(){
	int size;
	printf("enter the size of the queue");
	scanf("%d",&size);
	rear=size;
	int queue[size];
	int ch,x;
	while(1){
		printf("enter choice:1.enQueueFront/2.enQueueBack/3.deQueueFront/4.deQueueBack/5.Display/6.exit");
		scanf("%d",&ch);
		if(ch==1){
			printf("enter number to be added");
			scanf("%d",&x);
			enQueueFront(x,size,queue);
		}
		else if(ch==2){
			printf("enter number to be added");
			scanf("%d",&x);
			enQueueBack(x,size,queue);
		}
		else if(ch==3){
			deQueueFront(size,queue,ch);
		}
		else if(ch==4){
			deQueueBack(size,queue,ch);
		}
		else if(ch==5){
			display(size,queue,ch);
		}
		else{
			printf("closing");
			break;
		}
	}
}

int isEmpty(int ch,int size){
	if(ch==1){
		if(front==-1){
			return 1;
		}
	}
	else if(ch==2){
		if(rear==size){
			return 1;
		}
	}
	else if(ch==5){
		if(front==-1 && rear==size){
			return 1;
		}}
	else{
		return 0;
	}
}
int isFull(int size){
	if(front==rear-1){
		return 1;
	}
	else{
		return 0;
	}
}

void enQueueFront(int x,int size,int queue[]){
	if(isFull(size)==1){
		printf("queue full\n");
		return;
	}
	front++;
	queue[front]=x;
}

void enQueueBack(int x,int size,int queue[]){
	if(isFull(size)==1){
		printf("queue full");
		return;
	}
	rear--;
	queue[rear]=x;
}

void deQueueFront(int size,int queue[],int ch){
	if(isEmpty(ch,size)==1){
		printf("queue full");
		return;
	}
	front--;
}

void deQueueBack(int size,int queue[],int ch){
	if(isEmpty(ch,size)==1){
		printf("queue full");
		return;
	}
	rear++;
}

void display(int size,int queue[],int ch){
	if(isEmpty(ch,size)==1){
		printf("queue full");
		return;
	}
	for(int i=front+1;i<size;i++){
		printf("%d",queue[i]);
		printf("\t");
	}
	printf("\n");
}











		
