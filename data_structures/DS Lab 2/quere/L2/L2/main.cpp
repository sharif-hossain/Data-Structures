#include <iostream>

using namespace std;

int main()
{
    int a[30],c,n;

    cout << "Enter how many element you want to add in array : " ;
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> a[i];

    while(1)
    {
        int i;
        cout << "Enter 1 for push 2 for pop 0 for exit" << "\n";
        cin >> c;

        if(c==1)
        {
            cout << "Enter the element to push " << "\n";
            cin >> i;

            a[n]=i;
            n+=1;

            cout << "New array is " << "\n";

            for(int i=0; i<n; i++)
                cout << a[i];

            cout << "\n" ;
        }

        else if(c==2)
        {
            cout << a[n-1] << "\n";
            n-=1;

            cout << "New array is " << "\n";

            for(int i=0; i<n; i++)
                cout << a[i];

            cout << "\n" ;
        }

        else if(c==0)
            break;
    }

    return 0;
}

/* Sample Input : 5
                  1 2 3 4 5
                  1(for push)
                  7
Sample Output :1 2 3 4 5 7

Sample Input : 5
               1 2 3 4 5
               2(for pop)

Sample Output :1 2 3 4
