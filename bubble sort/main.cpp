#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n-1 ; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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

    bubbleSort(arr, n);

    cout << "\nSorted data " ;

    // printAray(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
    return 0;
}
