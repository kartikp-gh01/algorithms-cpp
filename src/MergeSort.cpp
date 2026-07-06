/*
--------------------------------------------
Project : Merge Sort
Language: C++
Author   : Kartik Parasar

Description:
Implementation of Merge Sort using Divide and Conquer approach.

Time Complexity:
Best Case    : O(n log n)
Average Case : O(n log n)
Worst Case   : O(n log n)

Space Complexity:
O(n)
--------------------------------------------
*/

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
// Time Complexity: O(n)
// Space Complexity: O(n)
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}
// Time Complexity: O(n log n)
// Space Complexity: O(log n)
void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);

        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
void display(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}
int main()
{
    int n;

    cout << "Enter Number of Elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter Elements:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nOriginal Array:\n";
    display(arr, n);

    auto start = high_resolution_clock::now();

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted Array:\n";
    display(arr, n);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);


    cout << "\nExecution Time: "
     << duration.count()
     << " microseconds" << endl;

    return 0;
}
