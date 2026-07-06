/*
--------------------------------------------
Project : Binary Search
Language: C++
Author   : Kartik Parashar

Description:
Implementation of Binary Search using Iterative Approach.

Time Complexity:
Best Case    : O(1)
Average Case : O(log n)
Worst Case   : O(log n)

Space Complexity:
O(1)
--------------------------------------------
*/

#include <iostream>
using namespace std;
// Time Complexity: O(log n)
// Space Complexity: O(1)

int binarySearch(int arr[], int size, int key)
{
    int left = 0;
    int right = size - 1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;

        if(arr[mid] == key)
            return mid;

        else if(arr[mid] < key)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}
int main()
{
    int n;

    cout << "Enter Size of Array: ";
    cin >> n;

    int arr[n];

    cout << "Enter Sorted Elements:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;

    cout << "Enter Element to Search: ";
    cin >> key;

    int result = binarySearch(arr, n, key);

    if(result != -1)
        cout << "Element Found at Index " << result << endl;
    else
        cout << "Element Not Found" << endl;

    return 0;
}