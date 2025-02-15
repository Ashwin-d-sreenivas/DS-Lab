#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *Lchild,*Rchild;
};

struct Node *createNode(int val){
	struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
	newNode->data=val;
	newNode->Lchild=newNode->Rchild=NULL;
	return newNode;
}

void Node *insert(struct Node **root,int val){
	if(*root==NULL){
		*root=createNode(val);
		return;
	}
	if(val<(*root->data)){
		*root->Lchild=insert((*root->Lchild),val);
	}
	else if(val > *root->data){
		root->Rchild=insert((*root->Rchild),val);
	}
	return;
}

struct Node *search(struct Node **root,int val){
	if(*root==NULL || *root->data==val){
		return;
	}
	if(*root->data < val){
		return search(*root->Rchild,val);
	}
	return search(*root->Lchild,val);
}

struct Node *minvalue(struct Node **root){
	if(*root==NULL){
		return ;
	}
	while(*root->Lchild!=NULL){
		return minvalue(*root->Lchild);
	}
	return;
}

struct Node *delete(struct Node **root,int val){
	if(*root==NULL){
		return;
	}
	if(*root->data > val){
		*root->Lchild=delete(*root->Lchild,val);
	}
	else if(*root->data < val){
		*root->Rchild=delete(*root->Rchild,val);
	}
	else{
		if(*root->Lchild==NULL && *root->Rchild==NULL){
			free(root);
			return NULL;
		}
		else if(*root->Lchild==NULL || root->Rchild==NULL){
			struct Node *temp;
			if(root->Lchild==NULL){
				temp=root->Rchild;
			}
			else{
				temp=root->Lchild;
			}
			free(root);
			return temp;
		}
		else{
			struct Node *temp=minvalue(root->Rchild);
			root->data=temp->data;
			root->Rchild=delete(root->Rchild,temp->data);
		}
	}
	return root;
}
			
void preorder(struct Node *root){
	if(root!=NULL){
		printf("%d",root->data);
		preorder(root->Lchild);
		preorder(root->Rchild);
	}
}

void inorder(struct Node *root){
	if(root!=NULL){
		inorder(root->Lchild);
		printf("%d",root->data);
		inorder(root->Rchild);
	}
}

void postorder(struct Node *root){
	if(root!=NULL){
		postorder(root->Lchild);
		postorder(root->Rchild);
		printf("%d",root->data);
	}
}

void main(){
	struct Node *root=NULL;
	int ch,val;
	printf("1.insert\n2.search\n3.delete\n4.preorder\n5.inorder\n6.postorder\nother to exit");
	while(1){
		printf("enter choice");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("enter value to insert");
				scanf("%d",&val);
				insert(&root,val);
				break;
			case 2:
				printf("enter value to search");
				scanf("%d",&val);
				if(search(&root,val)!=NULL){
					printf("found");
				}
				else{
					printf("not found");
				}
				break;
			case 3:
				printf("enter value to delete");
				scanf("%d",&val);
				root=delete(&root,val);
				break;
			case 4:
				preorder(root);
				break;
			case 5:
				inorder(root);
				break;
			case 6:
				postorder(root);
				break;
			default:
				printf("exiting");
				exit(0);
		}
	}
}
