#include <iostream>

using namespace std;

int BinarySearch(int arr[], int n, int x)
{
    int low = 0, high = n - 1;

    while(low <= high)
    {
        int mid = low + (high - low)/2; // (low+high)/2
        if(x == arr[mid])
        {
            return mid;
        }
        else if(x < arr[mid])
        {
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return - 1;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter the array elements:\n";
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }

    int value;

    cout << "Enter a value to find: " << endl;

    cin >> value;
    int result = BinarySearch(arr, n, value);

    if(result >= 0)
    {
        cout << "The number " << arr[result] << " was found at the element with index " << result << endl;
    }
    else
    {
        cout << "The number " << value << " was not found." << endl;
    }
    return 0;
}
