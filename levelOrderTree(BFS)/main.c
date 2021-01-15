#include <stdio.h>
#include <stdlib.h>
#define n 100

struct BstNode* queue[n];
int front=-1,rear=-1;

void Enqueue();
void Dequeue();
struct BstNode* first();
int isEmpty();
struct BstNode* insert();
struct BstNode* NewNode();
void LevelOrder();

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct BstNode{
	int data;
	struct BstNode* right;
	struct BstNode* left;
};

void Enqueue(struct BstNode* x){
	if(front==-1&&rear==-1){
		front=rear=0;
	}else if((rear+1)%n==front){
		printf("Memory Full\n");exit(1);
	}else{
		rear = (rear+1)%n;
	}
	queue[rear] = x;
}
void Dequeue(){
	if(front==-1&&rear==-1)return;
	if(front==0&&rear==0){
		front=rear=-1;
	}else{
		front = (front+1)%n;
	}
}
struct BstNode* first(){
	return queue[front];
}
int isEmpty(){
	if(front==-1&&rear==-1) return 1;
	return 0;
}

int main(){
	struct BstNode* root = NULL;

	root = insert(root,3);
	root = insert(root,6);
	root = insert(root,1);
	root = insert(root,9);
	root = insert(root,11);
	root = insert(root,8);
	root = insert(root,10);
	root = insert(root,19);
	root = insert(root,5);
	LevelOrder(root);

	return 0;
}
struct BstNode* insert(struct BstNode* root,int data){
	if(root==NULL){
		root = NewNode(data);
	}else if(data<=root->data){
		root->left = insert(root->left,data);
	}else if(data>root->data){
		root->right = insert(root->right,data);
	}
	return root;

}
struct BstNode* NewNode(int data){
	struct BstNode* temp = (struct BstNode*)malloc(sizeof(struct BstNode));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
void LevelOrder(struct BstNode* root){
	if(root==NULL) return;
	Enqueue(root);
	while(!isEmpty()){
		struct BstNode* current = first();
		printf("%d ",current->data);
		if(current->left!=NULL) Enqueue(current->left);
		if(current->right!=NULL) Enqueue(current->right);
		Dequeue();
	}
}
