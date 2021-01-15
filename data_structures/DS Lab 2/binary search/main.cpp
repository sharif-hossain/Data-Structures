#include <iostream>

using namespace std;
int a[100],n,i;

int search(int value)
{
    int beg=0,end=n,loc=0;
    int i,mid=(beg+end)/2;
    for(i=0;beg<=end && mid!=value;i++)
    {
        if(value<mid)
        {
            end=mid-1;
        }
        else
        {
            beg=mid+1;
        }
        mid=(beg+end)/2;
    }
    if(mid==value)
    {
        return mid;
    }
    else
    return loc;

}
int main()
{
    int j,value,loc;
    cout<<"Enter the size of array:";
    cin>>n;
    for(i=0; i<n; i++)
{
    cin>>a[i];
}
    cout<<"Value=";
    cin>>value;
    loc=search(value);
    if(loc==0)
        cout<<"Not found";
    else{
    cout<<loc;
    }
    return 0;
}
