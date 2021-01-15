#include <bits/stdc++.h>

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
    bst *ptr=new bst();
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
                else srt=srt->right;
            }
            else
            {
                if(srt->left==NULL)
                {
                    srt->left=ptr;
                    break;
                }
                else srt=srt->left;
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


void in_order()
{
    bst *p=root;
a:
    while(p!=NULL)
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

void deleteing(int a)
{
    bst *srt=root,*tmp;
    while(1)
    {
        if(a>srt->info)
        {
            tmp=srt;
            srt=srt->right;
        }
        else if(a<srt->info)
        {
            tmp=srt;
            srt=srt->left;
        }
        else if(a==srt->info)
        {
            if(srt->left==NULL && srt->right==NULL)
            {
                if(a>tmp->info)
                {
                    tmp->right=NULL;
                    break;
                }
                else if(a<tmp->info)
                {
                    tmp->left=NULL;
                    break;
                }
            }
            else if(srt->left!=NULL && srt->right!=NULL)
            {
                if(a>tmp->info)
                {
                    bst *tmp2=srt->right;
                    tmp->right=srt->right;
                    tmp2->right=srt->right;
                    (tmp2->left)->right=tmp2->right;
                    break;
                }
                else
                {
                    bst *tmp2=srt->right;
                    tmp->left=srt->right;
                    tmp2->left=srt->left;
                    (tmp2->right)->left=tmp2->left;
                    break;
                }
            }
            else
            {
                if(srt->right!=NULL)
                {
                    if(a>tmp->info)
                    {
                        tmp->right=srt->right;
                        break;
                    }
                    else
                    {
                        tmp->left=srt->right;
                        break;
                    }
                }
                else if(srt->left!=NULL)
                {
                    if(a>tmp->info)
                    {
                        tmp->right=srt->right;
                        break;
                    }
                    else
                    {
                        tmp->left=srt->right;
                        break;
                    }
                }
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    int item;
    cout<<"Enter the items"<<endl;
    while(1)
    {
        cin>>item;
        if(item==0) break;
        else
            bst_creation(item);
    }
     in_order();
    cout<<"Now Enter an item to delete it !"<<endl;
    int a;
    cin>>a;
    deleteing(a);
    in_order();
    return 0;
}
