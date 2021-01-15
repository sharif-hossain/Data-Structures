#include <iostream>

using namespace std;

int main()
{
    int i,n,t;
    cout<<"Enter number of elements: ";
    cin>>n;
    int a[n];
    cout<<"Enter elements: ";
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"After sorting: ";
    while (1)
    {
        for(i=n/2; i>=1; i--)
        {
            if(n%2!=0)
            {
                if(a[2*i-1]>a[2*i])
                {
                    if(a[i-1]>a[2*i])
                        swap(a[i-1],a[2*i]);
//                    k=a[i-1];
//                    a[i-1]=a[2*i];
//                    a[2*i]=k;
                }
                else
                {
                    if(a[i-1]>a[2*i-1])
                        swap(a[i-1],a[2*i-1]);
//                    k=a[i-1];
//                    a[i-1]=a[2*i-1];
//                    a[2*i-1]=k;
                }
            }
            else
            {
                if(a[i-1]>a[2*i-1])
                        swap(a[i-1],a[2*i-1]);
            }
        }

        cout<<a[0]<<" ";
        a[0]=a[n-1];
        n--;
        if(n==0)
            break;
    }
    return 0;
}
