#include<stdio.h>
#include<iostream>
//#include<conio.h>
#include<process.h>
#include<ctype.h>
using namespace std;

struct  t_node
{
    char ch;
    t_node *left,*right,*next;
};


typedef t_node *treeNode;
treeNode root,TOP,stack[1000];

void push(treeNode ptr)
{
    treeNode p;
    if(TOP==NULL)
        TOP=ptr;
    else
    {
        for(p=TOP; p->next!=NULL; p=p->next)
            ;

        p->next=ptr;
    }
}


treeNode get()
{
    treeNode p;
    if(TOP==NULL)
    {
        cout<<"tree is empty:\n";
        //getch();
        //exit(1);
        return NULL;
    }
    p=TOP;
    TOP=TOP->next;
    return p;
}

void tree_make()
{
    treeNode p,dat;
    char c;
    cout<<"Enter root of tree\n";
    cin>>c;

    c=toupper(c);
    if(c=='0')
    {
        cout<<"tree is empty\n";
        //getch();
        //exit(1);
        return;
    }
    p=new t_node;
    p->ch=c;
    p->right=NULL;
    p->left=NULL;
    p->next=NULL;
    if(root==NULL)
        root=p;
    push(p);
    while(TOP!=NULL)
    {
        char aa;
        dat=get();
        cout<<" Enter left of "<<dat->ch<<": ";
        cin>>aa;
        if(aa!='0')
        {
            aa=toupper(aa);
            p=new t_node;
            if(p==NULL)
            {
                printf("\n Memory not available");
                //exit(0);
                return;
            }
            p->left=NULL;
            p->right=NULL;
            p->next=NULL;
            p->ch=aa;
            push(p);
            dat->left=p;

        }

        cout<<" Enter right of "<<dat->ch<<": ";
        cin>>aa;
        if(aa!='0')
        {
            aa=toupper(aa);
            p=new t_node;
            if(p==NULL)
            {
                printf("\n Memory not available");
                //exit(0);
                return;
            }
            p->left=NULL;
            p->right=NULL;
            p->next=NULL;
            p->ch=aa;
            push(p);
            dat->right=p;
        }

    }

}
treeNode empty()
{
    return TOP;
}

void push_s(treeNode pt)
{
    //treeNode p;
    pt->next=TOP;
    TOP=pt;
}

treeNode pop()
{
    treeNode pt,pev;
    if(TOP==NULL)
        return TOP;
    else
    {
        pt=TOP;
        TOP=TOP->next;
    }
    return pt;
}



void preorder_t()
{

    cout<<"After preorder traverse"<<endl<<endl;
    treeNode ptr;
    ptr=root;
    while(ptr!=NULL)

    {
        cout<<"   "<<ptr->ch;
        if(ptr->right!=NULL)
            push_s(ptr->right);

        if(ptr->left!=NULL)
            ptr=ptr->left;
        else
            ptr=pop();

    }

}


int main()
{
    //clrscr();
    tree_make();
    int choice;
    cout<<"Enter 1 for preorder traverse :";
    cout<<"\nEnter 2 for inorder traverse :";
    cout<<"\nEnter 3 for postorder traverse :";

    cin>>choice;

    if(choice==1)
    {
        preorder_t();
    }

    return 0;

    //getch();

}
