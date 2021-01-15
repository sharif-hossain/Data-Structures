#include <iostream>

using namespace std;

class tree
{public:
    char a;
    tree *left,*right,*next;
};
tree *root,*top;

void push(tree *ptr)
{
    tree *p;
    if(top==NULL) top=ptr; ///this will execute once
    else
    {
        for(p=top;p->next!=NULL;p=p->next);
        p->next=ptr;
    }
}

tree get()
{
    tree *p;
    if(top!=NULL) /// not empty
    {
        p=top;
        top=top->next;
    }
    return *p;
}

void make_tree()
{
    tree *p,*dat;
    char c;cin>>c;///root
    c=toupper(c);
    p=new tree();
    p->left=NULL;
    p->right=NULL;
    p->next=NULL;
    p->a=c;
    if(root==NULL) root=p;
    push(p);/// assigns the top and it will be executed once

    while(top!=NULL)
    {
        char c;
        *dat=get(); /// returns top and updates top to it's next
        cout<<"Enter left of "<< dat->a <<endl;
        cin>>c;
        if(c!='0')
        {
            c=toupper(c);
            p=new tree();
            p->left=NULL;
            p->right=NULL;
            p->next=NULL;
            p->a=c;
            push(p); ///sets top's next to this p
            dat->left=p;
        }
        cout<<"Enter right of "<<dat->a<<endl;
        cin>>c;
        if(c!='0')
        {
            c=toupper(c);
            p=new tree();
            p->left=NULL;
            p->right=NULL;
            p->next=NULL;
            p->a=c;
            push(p); /// sets top's next's next to this p
            dat->right=p;
        }
    }
}

void inorder()
{
    tree *ptr=root;
    while(ptr!=NULL)
    {
        tree *pt1=ptr,*pt2;
        ptr=ptr->next;
        if(ptr->right!=NULL){
        ptr->next=ptr->right;
        pt2=ptr->next;
        pt2->next=pt1;
        }

    }
    ptr=root;
    while(ptr!=NULL)
    {
        cout<<ptr->a<<endl;
    }

}

int main()
{
    make_tree();
    inorder();
    return 0;
}
