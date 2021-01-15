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
    bst *ptr=new bst();
    ptr->info=data;
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->next=NULL;
    if(root==NULL) root=ptr;
    else
    {
        bst *srt;
        srt=root;
        while(1)
        {
            if(ptr->info<=srt->info)
            {
                if(srt->left==NULL)
                {
                    srt->left=ptr;
                    break;
                }
                else srt=srt->left;
            }
            else
            {
                if(srt->right==NULL)
                {
                    srt->right=ptr;
                    break;
                }
                else srt=srt->right;
            }
        }
    }
}

void deleteing(int data)
{
    bst *srt=root,*tmp;
    while(1)
    {
        if(srt==NULL)
        {
            cout<<"Not Found !"<<endl;
            break;
        }
        else if(data<=srt->info)
        {
            tmp=srt;
            srt=srt->left;
            if(srt->info==data)
            {
                if(srt->left==NULL&&srt->right==NULL)
                {
                    tmp->left=NULL;
                    break;
                }
                else if(srt->left!=NULL&&srt->right==NULL)
                {
                    tmp->left=srt->left;
                    break;
                }
                else if(srt->left==NULL&&srt->right!=NULL)
                {
                    tmp->left=srt->right;
                    break;
                }
                else if(srt->left!=NULL&&srt->right!=NULL)
                {
                    tmp->left=srt->right;
                }
            }
        }
        else if(data>srt->info)
        {
            tmp=srt;
            srt=srt->right;
            if(srt->info==data)
            {
                if(srt->left==NULL&&srt->right==NULL)
                {
                    tmp->right=NULL;
                    break;
                }
                else if(srt->left!=NULL&&srt->right==NULL)
                {
                    tmp->right=srt->left;
                    break;
                }
                else if(srt->left==NULL&&srt->right!=NULL)
                {
                    tmp->right=srt->right;
                    break;
                }
                else if(srt->left!=NULL&&srt->right!=NULL)
                {
                    tmp->right=srt->right;
                }
            }
        }
    }
}

int main()
{
    int item;
    cout<<"Enter the items number of bst : "<<endl;
    while(1)
    {
        cin>>item;
        if(item==0) break;
        else
        {
            bst_creation(item);
        }
    }
    cout<<"Now Enter an item to Delete it!"<<endl;
    cin>>item;
    deleteing(item);
    return 0;
}
