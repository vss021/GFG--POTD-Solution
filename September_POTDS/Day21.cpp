/*
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. ith house has a[i] amount of money present in it.

Example 1:

Input:
n = 5
a[] = {6,5,5,7,4}
Output: 
15
Explanation: 
Maximum amount he can get by looting 1st, 3rd and 5th house. Which is 6+5+4=15.
Example 2:

Input:
n = 3
a[] = {1,5,3}
Output: 
5
Explanation: 
Loot only 2nd house and get maximum amount of 5.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Function to find the maximum money the thief can get using recursion.
    int Recursion(int arr[], int n, int index)
    {
        // Base case
        if (index >= n) {
            return 0;
        }

        // Taking the current house
        int taking = arr[index] + Recursion(arr, n, index + 2);

        // Not taking the current house
        int notTaking = Recursion(arr, n, index + 1);

        return max(taking, notTaking);
    }

    // Function to find the maximum money the thief can get using recursion with memoization.
    int RecursionMemo(int arr[], int n, int index, vector<int> &dp)
    {
        // Base case
        if (index >= n) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        // Taking the current house
        int taking = arr[index] + RecursionMemo(arr, n, index + 2, dp);

        // Not taking the current house
        int notTaking = RecursionMemo(arr, n, index + 1, dp);

        return dp[index] = max(taking, notTaking);
    }

    // Function to find the maximum money the thief can get using tabulation.
    int Tabulation(int arr[], int n)
    {
        vector<int> dp(n + 1, 0);
        dp[1] = arr[0];

        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + arr[i - 1]);
        }

        return dp[n];
    }

    // Function to find the maximum money the thief can get in the most optimized way.
    int MostOptimized(int arr[], int n)
    {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return arr[0];
        }

        int prev2 = arr[0]; // Represents the maximum money if the thief chooses the first house.
        int prev1 = max(arr[0], arr[1]); // Represents the maximum money if the thief chooses either the first or second house.

        for (int i = 2; i < n; i++) {
            int current = max(prev1, prev2 + arr[i]); // Choose either the current house or skip it.
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }

    // Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        return MostOptimized(arr, n);
    }
};

int main() {
    int n;
    cout << "Enter the number of houses: ";
    cin >> n;

    int arr[n];
    cout << "Enter the values of money in each house: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution solution;

    // Using Recursion
    int maxSumRecursion = solution.Recursion(arr, n, 0);
    cout << "Maximum money using Recursion: " << maxSumRecursion << endl;

    // Using Recursion with Memoization
    vector<int> dp(n, -1);
    int maxSumRecursionMemo = solution.RecursionMemo(arr, n, 0, dp);
    cout << "Maximum money using Recursion with Memoization: " << maxSumRecursionMemo << endl;

    // Using Tabulation
    int maxSumTabulation = solution.Tabulation(arr, n);
    cout << "Maximum money using Tabulation: " << maxSumTabulation << endl;

    // Using Most Optimized Approach
    int maxSumMostOptimized = solution.MostOptimized(arr, n);
    cout << "Maximum money using Most Optimized Approach: " << maxSumMostOptimized << endl;

    return 0;
}
