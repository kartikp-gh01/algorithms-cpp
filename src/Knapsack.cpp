/*
--------------------------------------------
Project : 0/1 Knapsack
Language: C++
Author   : Kartik Parasar

Description:
Implementation of 0/1 Knapsack using Dynamic Programming.

Time Complexity:
O(n * W)

Space Complexity:
O(n * W)
--------------------------------------------
*/

#include <iostream>
using namespace std;
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int weight[], int value[], int n, int capacity)
{
    int dp[100][100];

    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= capacity; w++)
        {
            if(i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if(weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}
int main()
{
    int n;

    cout << "Enter Number of Items: ";
    cin >> n;

    int weight[100], value[100];

    cout << "Enter Weight of Items:\n";

    for(int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter Value of Items:\n";

    for(int i = 0; i < n; i++)
        cin >> value[i];

    int capacity;

    cout << "Enter Capacity of Bag: ";
    cin >> capacity;

    cout << "\nMaximum Profit = "
         << knapsack(weight, value, n, capacity);

    return 0;
}