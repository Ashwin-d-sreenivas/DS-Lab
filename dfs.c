#include<stdio.h>
#include<stdlib.h>

struct Node{
	int vertex;
	struct Node *next;
};

struct Adjlist{
	struct Node *head;
};

struct Graph{
	int v;
	struct Adjlist *array;};
	

struct Node *createNode(int v){
	struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
	newnode->vertex=v;
	newnode->next=NULL;
	return newnode;
}
struct Graph *createG(int v){
	struct Graph *graph=(struct Graph *)malloc(sizeof(struct Graph));
	graph->v=v;
	graph->array=(struct Adjlist *)malloc(v*sizeof(struct Adjlist));
	
	for(int i=0;i<v;i++){
		graph->array[i].head=NULL;
	}
	return graph;
}

void insert(struct Graph *graph,int src,int des){
	struct Node *newnode=createNode(des);
	newnode->next=graph->array[src].head;
	graph->array[src].head=newnode;
}

void delete(struct Graph *graph,int src,int des){
	struct Node *temp=graph->array[src].head;
	struct Node *cur=graph->array[src].head;
	if(temp==NULL){
		printf("no edge ");
		return;
	}
	while(temp!=NULL && temp->vertex!=des){
		cur=temp;
		temp=temp->next;
	}
	if(temp==NULL){
		printf("des no edge:");
		return;
	}
	cur->next=temp->next;
}

void search(struct Graph *graph,int src,int des){
	struct Node *temp=graph->array[src].head;
	while(temp!=NULL){
		if(temp->vertex==des){
			printf("found");
			return;
		}
		temp=temp->next;
	}
	printf("not");
	
}

void BFS(struct Graph *graph,int start,int v){
	int visited[v];
	int q[v],rear,front;
	rear=front=0;
	
	for(int i=0;i<v;i++){
		visited[i]=0;
	}
	visited[start]=1;
	q[rear++]=start;
	
	while(front<rear){
		int current=q[front++];
		printf("%d",current);
		struct Node *temp=graph->array[current].head;
		while(temp!=NULL){
			int ver=temp->vertex;
			if(visited[ver]!=1){
				visited[ver]=1;
				q[rear++]=ver;
			}
			temp=temp->next;
		}
	}
}

void DFSUtil(struct Graph *graph,int start,int v,int visited[]){
	visited[start]=1;
	printf("%d",start);
	
	struct Node *temp=graph->array[start].head;
	while(temp!=NULL){
		int ver=temp->vertex;
		if(visited[ver]==0){
			DFSUtil(graph,ver,v,visited);
		}
		temp=temp->next;
	}
}

void DFS(struct Graph *graph,int start,int v){
	int visited[v];
	for(int i=0;i<v;i++){
		visited[i]=0;
	}
	DFSUtil(graph,start,v,visited);
}

void main(){
	int v;
	printf("enter v:");
	scanf("%d",&v);
	struct Graph *graph=createG(v);
	
	int ch,src,des;
	printf("1.InsertEdge\n2.DeleteEdge\n3/SearchEdge\n4.BFS\n5.DFS\n6.EXIT");
	
	while(1){
		printf("enter ch:");
		scanf("%d",&ch);
		if(ch==1){
			printf("enter source and destnation:");
			scanf("%d %d",&src,&des);
			insert(graph,src,des);
		}
		else if(ch==2){
			printf("enter source and destnation:");
			scanf("%d %d",&src,&des);
			delete(graph,src,des);
		}
		else if(ch==3){
			printf("enter source and destnation:");
			scanf("%d %d",&src,&des);
			search(graph,src,des);
		}
		else if(ch==4){
			printf("enter start:");
			scanf("%d",&src);
			BFS(graph,src,v);
		}
		else if(ch==5){
			printf("enter start:");
			scanf("%d",&src);
			DFS(graph,src,v);
		}
		else{
			printf("closing\n");
			break;
		}
	}
}
			

