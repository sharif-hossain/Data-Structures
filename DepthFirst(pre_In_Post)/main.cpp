#include <iostream>
#include<queue> //#include <bits/stdc++.h>
using namespace std;

struct node{
 char data;
 node* left;
 node* right;
};

//node* root = NULL;
 node* newNode(char x)
 {
     node* temp = new node();
     temp -> data = x;
     temp -> left = temp -> right = NULL;
     return temp;
 }

 node* Insert(node* root, char data)
 {
     if(root == NULL)
     {
         root = newNode(data);
       //  return root;
     }
     else if(data <= root->data)
     {
         root -> left = Insert(root -> left, data);
     }
     else{
        root -> right = Insert(root -> right, data);
     }
     return root;
 }

 void Preorder(node* root)
 {
     if(root == NULL)
     {
         return;
     }
     cout << root -> data << " ";
     Preorder(root-> left);
     Preorder(root->right);
 }
 void Inorder(node* root)
 {
     if(root == NULL)
     {
         return;
     }
     Inorder(root->left);
     cout << root->data << " ";
     Inorder(root->right);
 }
 void Postorder(node* root)
 {
     if(root == NULL)
     {
         return;
     }
     Postorder(root->left);
     Postorder(root->right);
     cout << root->data << " ";
 }

 // level order root

 void LevelOrder(node *root) {
	if(root == NULL) return;
	queue<node*> Q;
	Q.push(root);
	//while there is at least one discovered node
	while(!Q.empty()) {
		node* current = Q.front();
		Q.pop(); // removing the element at front
		cout<<current->data<<" ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
	}
}

 bool Search(node* root, char data)
 {
     if(root == NULL)
     {
         return false;
     }
     else if(root -> data == data)
     {
         return true;
     }
     else if(data <= root-> data)
     {
         return Search(root -> left, data);
     }
     else
     {
         return Search(root -> right, data);
     }
 }

 void Print(node* root)
 {

     if(root != NULL)
     {
         Print(root -> left);
         cout << root -> data << " ";
         Print(root -> right);
     }
 }

int main()
{
    /*Code To Test the logic
	  Creating an example tree
                F
			   /  \
			  D    J
			 / \   / \
			B   E  G  K
		   / \      \
		   A  C      I
		             /
		             H
    */

    node* root = NULL;

    root = Insert(root, 'F');
    root = Insert(root, 'D');
    root = Insert(root, 'B');
    root = Insert(root, 'A');
    root = Insert(root, 'C');
    root = Insert(root, 'E');
    root = Insert(root, 'J');
    root = Insert(root, 'G');
    root = Insert(root, 'I');
    root = Insert(root, 'H');
    root = Insert(root, 'K');

    cout << "current tree : " << endl;
    Print(root);

    cout << "\nPreOrder: ";
    Preorder(root);
    cout << "\n";

    cout << "\nInOrder: ";
    Inorder(root);
    cout << "\n";

    cout << "\nPostOrder: ";
    Postorder(root);
    cout << "\n";

    cout << "\nLevel Order(Breadth first): ";
    LevelOrder(root);
    cout << "\n";
    // search
    char num;
    cout << "\nEnter number to be searched\n";
    cin >> num;

    if(Search(root, num) ==  true)
    {
        cout << "Found" ;
    }
    else{
        cout << "Not found";
    }
    return 0;
}
