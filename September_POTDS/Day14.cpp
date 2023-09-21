
/*
Given an array arr[] of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

Note: Answer can be very large, so, output answer modulo 109+7

Example 1:

Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
       sum = 10
Output: 3
Explanation: {2, 3, 5}, {2, 8}, {10} are 
possible subsets.
Example 2:
Input: N = 5, arr[] = {1, 2, 3, 4, 5}
       sum = 10
Output: 3
Explanation: {1, 2, 3, 4}, {1, 4, 5}, 
{2, 3, 5} are possible subsets.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    // Recursive solution
    int perfectSumRecursive(int arr[], int n, int sum) {
        if (sum == 0) {
            return 1; // Only one way to achieve a sum of 0, which is not selecting any element.
        }
        if (n == 0) {
            return 0; // If there are no elements left, and the sum is not 0, it's not possible.
        }

        // Exclude the last element and count ways
        int excludeLast = perfectSumRecursive(arr, n - 1, sum);

        // Include the last element and count ways
        int includeLast = 0;
        if (arr[n - 1] <= sum) {
            includeLast = perfectSumRecursive(arr, n - 1, sum - arr[n - 1]);
        }

        // Total ways are the sum of ways with and without including the last element
        return excludeLast + includeLast;
    }

    // DP solution
    int perfectSumDP(int arr[], int n, int sum) {
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1; // There's always one way to achieve a sum of 0.
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j]; // Exclude the current element
                if (arr[i - 1] <= j) {
                    dp[i][j] += dp[i - 1][j - arr[i - 1]]; // Include the current element
                }
            }
        }

        return dp[n][sum];
    }

    int perfectSum(int arr[], int n, int sum) {
        // Your code goes here
        long long m=1e9+7;
        int dp[n+1][sum+1];
        
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i==0)dp[i][j]=0;
                if(j==0)dp[i][j]=1;
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]]%m+dp[i-1][j]%m;
                }
                else{
                    dp[i][j]=dp[i-1][j]%m;
                }
            }
            
        }
        return dp[n][sum]%m;
    }
};

int main() {
    Solution solution;

    // Example usage
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 10;

    int waysRecursive = solution.perfectSumRecursive(arr, n, sum);
    int waysDP = solution.perfectSumDP(arr, n, sum);
    int ways = solution.perfectSum(arr, n, sum);

    cout << "Number of ways to achieve the sum (Recursive): " << waysRecursive << endl;
    cout << "Number of ways to achieve the sum (DP): " << waysDP << endl;
    cout << "Number of ways to achieve the sum: " << ways << endl;

    return 0;
}
