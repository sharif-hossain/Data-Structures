#include <iostream>

using namespace std;

int main()
{
    int a[50];
    int b,i,n,choose;
    cout<<"Array size:";
    cin>>n;

    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    while(1)
    {
        cout<<"Press:1 for push\nPress:2 for pop\n";
        cin>>choose;
        if(choose==1)
        {
            cin>>b;
            a[n]=b;
            n=n+1;
            for(i=0; i<n; i++)
            {
                cout<<" "<<a[i];
            }
        }
        if(choose==2)
        {

            for(i=0; i<n-1; i++)
            {
                a[i]=a[i+1];
            }
            n=n-1;
            for(i=0; i<n; i++)
            {
                cout<<" "<<a[i];
            }
        }
        if(choose==0)
            break;
        cout<<"\n";
    }

    return 0;
}

/*Sample Input : 5
               1 2 3 4 5
               1(for push)
               6

Sample Output :1 2 3 4 5 6

Sample Input : 5
               1 2 3 4 5
               2(for pop)

Sample Output : 2 3 4 5 */
