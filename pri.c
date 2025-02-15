#include<stdio.h>
int size;
int front=-1;
int rear=-1;
struct PQ
{
int item;
int priority;
};
void display(struct PQ A[])
{
int i;
if(front==-1 && rear==-1)
{
printf("Queue is empty\n");
return;
}
else
{
for(i=front;i<=rear;i++)
printf("%d\t",A[i]);
printf("\n");
}
}
void enqueue(int x,int prio,struct PQ A[])
{
int i,loc;
if(front==0 && rear==size-1)
{
printf("Queue is full\n");
return;
}
else if(front==-1)
{

front=0;
rear=0;
A[rear].item=x;
A[rear].priority=prio;
}
else
{
if(rear==size-1)
{
for(i=front;i<=rear;i++)
A[i-1]=A[i];
front--;
rear--;
}
for(i=rear;i>=front;i--)
{
if(A[i].priority<prio)
{ break; }
}
loc=i+1;

for(i=rear;i>=loc;i--)
{
A[i+1]=A[i];
}
A[loc].item=x;
A[loc].priority=prio;
rear++;

}
}
void dequeue(struct PQ A[])
{
if(front==-1)

{
printf("Queue is Empty\n");
return;
}
else if(front==rear)
{
printf("deleted item is %d\n",A[front].item);
front=rear=-1;
}
else{
printf("deleted item is %d\n",A[front].item);
front++;
}
}
void main()
{

int num,pr;
printf("Enter size of queue\t");
scanf("%d",&size);
struct PQ A[size];
int choice;
while(1)
{
printf("1)Enqueue\n2)Dequeue\n3)Display\n4)Exit\n");
scanf("%d",&choice);

if(choice==1)
{
printf("Enter number:\t");
scanf("%d",&num);
printf("Enter priority\t");
scanf("%d",&pr);

enqueue(num,pr,A);

}
else if(choice==2)
{
dequeue(A);
}
else if(choice==3)
{
display(A);
}
else{
break;
}
}
}
