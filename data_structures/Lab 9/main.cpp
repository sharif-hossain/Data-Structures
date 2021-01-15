#include <iostream>

using namespace std;
int n;
void ascending(int n,int a[10])
{
    for(int i=1;i<n;i++)
    {
        int blank,value;
        value=a[i];
        blank=i;
        while(blank>0&&a[blank-1]>value)
        {
            a[blank]=a[blank-1];
            blank--;
        }
        a[blank]=value;
    }
    cout<<"Sorted array ascending :"<<endl;
    for(int i=0;i<n;i++) cout<<a[i] <<" ";
}

void deascending(int n,int a[10])
{
     for(int i=n-2;i>=0;i--)
    {
        int blank,value;
        value=a[i];
        blank=i;
        while(blank<n-1&&a[blank+1]>value)
        {
            a[blank]=a[blank+1];
            blank++;
        }
        a[blank]=value;
    }
    cout<<"Sorted array deascending :"<<endl;
    for(int i=0;i<n;i++) cout<<a[i] <<" ";
}

int main()
{
    cout<<"Enter the element numbers: "<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    ascending(n,a);cout<<endl;
    deascending(n,a);
    return 0;
}
