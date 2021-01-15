#include <iostream>

using namespace std;

int main()
{
    int a[30],n,c;
    cout << "Enter how many element add : ";
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    while(1)
    {
        int i;
        cout << "Enter 1 for push 2 for pop 0 for exit :";
        cin >> c;
        if(c==1)
        {
            cin >> i;
            a[n]=i;
            n+1;
            cout << "New array is " << "\n";
            for(int i=0; i<n; i++)
                cout << a[i];
            cout << "\n" ;
        }
        else if (c==2)
        {
            int j=0;
            cout << a[j];
            for(int i=1; i<n; i++)
            {
                a[j]=a[i];
                j++;
            }
            n-=1;
            cout << "New array is " << "\n";
            for(int i=0; i<n; i++)
                cout << a[i] ;
            cout << "\n";

        }
        else if(c==0)
            break;

    }
    return 0;
}
