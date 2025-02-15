#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *link;
};

struct Node* create(int value){
	struct Node *newNode=(struct Node*) malloc(sizeof(struct Node));
	newNode->data=value;
	newNode->link=NULL;
	return newNode;
}

void eF(struct Node* *head,int data){
	struct Node* newNode=create(data);
	newNode->link=*head;
	*head=newNode;
}

void eB(struct Node **head,int data){
	struct Node* newNode=create(data);
	struct Node *temp=*head;
	if(temp==NULL){
		*head=newNode;
		return;
	}
	while(temp->link!=NULL){
		temp=temp->link;
	}
	temp->link=newNode;
}

void eBW(struct Node **head,int data,int key){
	struct Node *newNode=create(data);
	struct Node *temp=*head;
	while(temp!=NULL && temp->data!=key){
		temp=temp->link;
	}
	if(temp==NULL){
		printf("element not found");
		return;
	}
	newNode->link=temp->link;
	temp->link=newNode;
	if(temp==NULL){
		printf("element not found");
		return;
	}
}

void dF(struct Node **head){
	if(*head==NULL){
		printf("empty list");
		return;
	}
	*head=(*head)->link;
}

void dB(struct Node **head){
	if(*head==NULL){
		printf("empty list");
		return;
	}
	struct Node *temp=*head;
	struct Node *prev=*head;
	
	while(temp->link!=NULL){
		prev=temp;
		temp=temp->link;
	}
	prev->link=NULL;
}

void dBW(struct Node **head,int key){
	if(*head==NULL){
		printf("empty list");
		return;
	}
	if((*head)->data==key){
		*head=(*head)->link;
	}
	struct Node *temp=*head;
	struct Node *prev=*head;
	while(temp!=NULL && temp->data!=key){
		prev=temp;
		temp=temp->link;
	}
	if(temp==NULL){
		printf("element not");
		return;
	}
	prev->link=temp->link;
}

void display(struct Node *head){
	struct Node *temp=head;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->link;
	}
}


void main(){
	struct Node *head=NULL;
	int ch,num,key;
	printf("enter choice:\n 1.entryFront\n2.back\n3.between\n4.deleteFront\n5.back\n6.between\n7.display\n8.exit");
	while(1){
		printf("enter choice:");
		scanf("%d",&ch);
		
		if(ch==1){
			printf("enter num:");
			scanf("%d",&num);
			eF(&head,num);
		}
		else if(ch==2){
			printf("enter num:");
			scanf("%d",&num);
			eB(&head,num);}
		else if(ch==3){
			printf("enter num:");
			scanf("%d",&num);
			printf("enter key:");
			scanf("%d",&key);
			eBW(&head,num,key);
			}
		else if(ch==4){
			dF(&head);
		}
		else if(ch==5){
			dB(&head);
		}
		else if(ch==6){
			printf("enter key:");
			scanf("%d",&key);
			dBW(&head,key);
		}
		else if(ch==7){
			display(head);
		}
		else{
			break;
		}
	}
}
			
			
			
			
			
			
			
			
			
			
			
			
			
			
