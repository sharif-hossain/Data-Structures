#include <iostream>

using namespace std;

struct node{
 int data;
 node* left;
 node* right;
};

//node* root = NULL;
 node* newNode(int x)
 {
     node* temp = new node();
     temp -> data = x;
     temp -> left = temp -> right = NULL;
     return temp;
 }

 node* Insert(node* root, int data)
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

 bool Search(node* root, int data)
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
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */

    node* root = NULL;

    root = Insert(root, 50);
    root = Insert(root, 30);
    root = Insert(root, 20);
    root = Insert(root, 40);
    root = Insert(root, 70);
    root = Insert(root, 60);
    root = Insert(root, 80);

    cout << "current tree : " << endl;
    Print(root);
    int num;
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
