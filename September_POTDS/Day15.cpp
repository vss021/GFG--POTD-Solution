/*
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explanation: This array can never be 
partitioned into two such parts.
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Brute Force Solution (Top-down / Recursive)
    bool canPartitionBruteForce(int arr[], int N, int sum) {
        if (sum % 2 != 0) {
            return false; // If the sum is odd, it's not possible to partition into equal subsets.
        }

        return subsetSum(arr, N, sum / 2, 0);
    }

    bool subsetSum(int arr[], int N, int targetSum, int currentIndex) {
        if (targetSum == 0) {
            return true; // Found a subset that sums up to the targetSum.
        }

        if (currentIndex == N || targetSum < 0) {
            return false; // Reached the end of the array or exceeded the targetSum.
        }

        // Include the current element in the subset.
        bool includeCurrent = subsetSum(arr, N, targetSum - arr[currentIndex], currentIndex + 1);

        // Exclude the current element from the subset.
        bool excludeCurrent = subsetSum(arr, N, targetSum, currentIndex + 1);

        return includeCurrent || excludeCurrent;
    }

    // Dynamic Programming Solution (Bottom-up)
    bool canPartitionDP(int arr[], int N, int sum) {
        if (sum % 2 != 0) {
            return false; // If the sum is odd, it's not possible to partition into equal subsets.
        }

        sum /= 2;
        vector<vector<bool>> dp(N + 1, vector<bool>(sum + 1, false));

        // Base case: An empty subset can always have a sum of 0.
        for (int i = 0; i <= N; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[N][sum];
    }

    // Most Optimized Solution (Bottom-up)
    int equalPartition(int N, int arr[]) {
        int S = 0;
        for (int i = 0; i < N; i++) {
            S += arr[i];
        }
        if (S % 2 == 0) {
            S /= 2;
            vector<int> dp(S + 1, 0);
            dp[0] = 1;
            for (int i = 0; i < N; i++) {
                for (int j = S; j >= 0; j--) {
                    if (j - arr[i] >= 0) {
                        dp[j] |= dp[j - arr[i]];
                    }
                }
            }
            return dp[S];
        } else {
            return 0;
        }
    }
};

int main() {
    Solution solution;

    // Example usage
    int arr[] = {1, 5, 11, 5};
    int N = sizeof(arr) / sizeof(arr[0]);

    bool canPartitionBrute = solution.canPartitionBruteForce(arr, N, 2 * 11);
    bool canPartitionDP = solution.canPartitionDP(arr, N, 2 * 11);
    int canPartitionOptimized = solution.equalPartition(N, arr);

    cout << "Can partition (Brute Force): " << canPartitionBrute << endl;
    cout << "Can partition (DP): " << canPartitionDP << endl;
    cout << "Can partition (Optimized): " << canPartitionOptimized << endl;

    return 0;
}

