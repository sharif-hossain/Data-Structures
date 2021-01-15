#include <iostream>

using namespace std;

void insertionSort(int arr[], int n)
{
    for( int i = 0 ; i < n ; i++ )
    {
        int temp = arr[ i ];
        int hole = i;

        while(  hole > 0  && temp < arr[hole - 1])
        {
            arr[ hole ] = arr[ hole - 1];
            // hole = hole - 1;
            hole --;
        }
        // moving current element to its  correct position.
        arr[ hole ] = temp;
    }
}
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

    insertionSort(arr, n);

    cout << "\nSorted data " ;


    for(int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
    return 0;
}
