#include<stdio.h>
#include<stdlib.h>

void addEdge(int **mat,int src,int des){
	mat[src][des]=1;
	mat[des][src]=1;
}
void delEdge(int **mat,int src,int des){
	mat[src][des]=0;
	mat[des][src]=0;
}
void comp(int **mat,int v){
	int inD[v]={0};
	int outD[v]={0};
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			if(mat[i][j]==1){
				inD[j]++;
				outD[i]++;
			}
		}
	}
	for(int k=0;k<v;k++){
		printf("num of in degrees and out degrees of %d=",k);
		printf("%d\t%d",inD[k],outD[k]);
		printf("\n");
	}
}
void bfs(int **mat,int start,int v){
	int visited[v]={0};
	int q[v],rear,front;
	rear=front=-1;
	
	visited[start]=1;
	rear++;
	q[rear]=start;
	while(front<rear){
		int current=q[++front];
		printf("%d",current);
		
		for(i=0;i<v;i++){
			if(mat[current][i]==1 && visited[i]!=1){
				q[++rear]=i;
				visited[i]=1;
			}
		}
	}
}
void dfsUtil(int **mat,int start,int v,int visited[]){
	visited[start]=1;
	printf("%d",start);
	for(int i=0;i<v;i++){
		if(mat[start][i]==1 && visited[i]==0){
			dfsUtil(mat,i,v,visited);
		}
	}
}
	

void dfs(int **mat,int start,int v){
	int visited[v]={0};
	dfsUtil(mat,start,v,visited);
}

void main(){
	int v;
	printf("ener number of vertices:");
	scanf("%d",&v);
	int mat[v][v]={0};
	int ch;
	int src,des;
	printf("insert choice:\n1.addEdge\n2.deleteEdge\n4.compute\n5.bfs\n6.dfs");
	while(1){
		printf("enter choice :");
		scanf("%d",&ch);
		if(ch==1){
			printf("enter source and destination:");
			scanf("%d%d",&src,&des);
			addEdge(*mat,src,des);
		}
		else if(ch==2){
			printf("enter source and destination:");
			scanf("%d%d",&src,&des);
			delEdge(*mat,src,des);
		}
		else if(ch==3){
			comp(*mat,v);
		}
		else if(ch==4){
			printf("enter start:");
			scanf("%d",&src);
			bfs(*mat,src,v);
		}
		else if(ch==5){
			printf("enter start:");
			scanf("%d",&src);
			dfs(*mat,src,v);
		}
		else{
			printf("closing");
			break;
		}
	}
}
		
		
		
		
		
		
