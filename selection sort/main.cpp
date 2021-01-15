#include <iostream>

using namespace std;

void seclectionSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int minimum = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minimum])
            {
                minimum = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minimum];
        arr[minimum] = temp;
    }
}

/*void printAray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
       cout << endl;
} */


int main()
{
    int n;
    cout << "enter number of data to sorted: " ;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
    {
        cout << "enter element " << i+1 << " : ";
        cin >> arr[i];
    }

    seclectionSort(arr, n);

    cout << "\nSorted data " ;

    // printAray(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
    return 0;
}
