#include <iostream>

using namespace std;

class bst
{
public:
    int info;
    bst *left,*right,*next;
};
bst *root=NULL;
void bst_creation(int data)
{
    bst *ptr=new bst ();
    ptr->info=data;
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->next=NULL;
    if(root==NULL) root=ptr;
    else
    {
        bst *srt;
        for(srt=root;;)
        {
            if(srt->info<ptr->info)
            {
                if(srt->right==NULL)
                {
                    srt->right=ptr;
                    break;
                }
                else
                    srt=srt->right;
            }
            else
            {
                if(srt->left==NULL)
                {
                    srt->left=ptr;
                    break;
                }
                else
                    srt=srt->left;
            }
        }
    }
}
bst *top=NULL;

void push_s(bst *srt)
{
    srt->next=top;
    top=srt;
}

bst* pop()
{
    bst *pt;
    if(top==NULL) return top;
    else
    {
        pt=top;
        top=top->next;
    }
    return pt;
}

void pre_order()
{
    bst *p;
    p=root;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        if(p->right!=NULL)
        {
            push_s(p->right);
        }
        if(p->left!=NULL)
        {
            p=p->left;
        }
        else
            p=pop();
    }
}

void in_order()
{
    bst *p;
    p=root;
    a: while(p!=NULL)
    {
        push_s(p);
        p=p->left;
    }
    p=pop();
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        if(p->right!=NULL)
        {
            p=p->right;
            goto a;
        }
        p=pop();
    }
}

int main()
{
    int item;
    cout<<"Enter the items"<<endl;
    while(1)
    {
        cin>>item;
        if(item==0) break;
        else
        {
            bst_creation(item);
        }
    }
    in_order();
    return 0;
}
