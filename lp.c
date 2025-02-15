#include<stdio.h>
#include<stdlib.h>

void insert(int arr[],int val,int size){
	int i=0;
	int key=val%size;
	while(arr[key]!=0 && i<size){
		key=(key+1)%size;
		i++;
	}
	if(i==size){
		printf("full");
		return;
	}
	arr[key]=val;
}
void delete(int arr[],int val,int size){
	int i=0;
	int key=val%size;
	while(arr[key]!=val && i<size){
		key=(key+1)%size;
		i++;
	}
	if (i==size){
		printf("val not there");
		return;
	}
	arr[key]=0;
}
void display(int arr[],int size){
	for(int i=0;i<size;i++){
		if(arr[i]!=0){
			printf("%d",arr[i]);
		}
	}
}
	

void main(){
	int size;
	printf("enter size:");
	scanf("%d",&size);
	int arr[size];
	for(int i=0;i<size;i++){
		arr[i]=0;
	}
	
	int ch;
	while(1){
		printf("enter ch:");
		scanf("%d",&ch);
		if(ch==1){
			printf("enter val:");
			int val;
			scanf("%d",&val);
			insert(arr,val,size);
		}
		else if(ch==2){
			printf("enter val:");
			int val;
			scanf("%d",&val);
			delete(arr,val,size);
		}
		else if(ch==3){
			display(arr,size);
		}
		else{
			break;
		}
	}
}
