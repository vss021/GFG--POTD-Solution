/*
    * Longest Increasing Subsequence 
    ans => [Breakdown] Recursion to DP to Binary Search

    Given an array of integers, find the length of the longest (strictly)
    increasing subsequence from the given array.

    Example 1:

    Input:
    N = 16
    A = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
    Output: 
    6
    Explanation:
    There are more than one LIS in this array. 
    One such Longest increasing subsequence is {0,2,6,9,13,15}.

    Example 2:

    Input:
    N = 6
    A[] = {5,8,3,7,9,1}
    Output: 
    3
    Explanation:
    There are more than one LIS in this array.  
    One such Longest increasing subsequence is {5,7,9}.
*/

#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    
    /*
    1. Recursion [TLE]
    The function first checks if the current index is valid. If it is not, it returns 0. 
    It then initializes a variable take to a very small negative value and calls itself 
    recursively with the previous index and the same previous index to calculate the result 
    if the current element is not included in the subsequence (notTake).

    If the previous index is equal to the size of the input vector, 
    it means that this is the first element being considered for inclusion in the subsequence.
    In this case,
    it updates the value of take as 1 plus the result of calling itself recursively with the previous
    index and the current index. If the previous index is not equal to the size of the input vector and the current element is smaller than the element at the previous index, it also updates the value of take as 1 plus the result of calling itself recursively with the previous index and the current index.
    Finally, it returns the maximum of take and notTake.

    The time complexity of this function is O(2^n), 
    where n is the length of the input vector, 
    because in the worst case, it needs to explore all possible subsequences of the input vector. 
    The space complexity is O(n), because it needs to store the recursive call stack.

    prevInd = n and ind = n - 1 (initially)
    */
    int BrutForceSolution(int ind, int prevInd, vector<int> &arr)
    {
        // Base case: If we have iterated through the entire array
        if (ind < 0)
        {
            return 0; // No more elements to consider, so the length is 0
        }
        
        int take = -1e8; // Initialize variable to store the length if we take the current element
        
        // Calculate the length if we do not take the current element
        int notTake = BrutForceSolution(ind - 1, prevInd, arr);
        
        // Check if we can take the current element
        if (prevInd == arr.size())
        {
            // If there's no previous element, we can take the current one
            take = 1 + BrutForceSolution(ind - 1, ind, arr);
        }
        else if (arr[ind] < arr.at(prevInd))
        {
            // If the current element is smaller than the previous one, we can take it
            take = 1 + BrutForceSolution(ind - 1, ind, arr);
        }
        
        // Return the maximum of taking or not taking the current element
        return max(take, notTake);
    }

    /*
    2. Memoization [TLE]
    Create a DP of size n * (n + 1) to store overlapping sub problems

    If the previous index is equal to the size of the input vector, it means that this is the first element being 
    considered for inclusion in the subsequence. 
    In this case, it updates the value of take as 1 plus the value 
    in the dp vector for the previous element and the current index. 
    If the previous index is not equal to the size of the input vector and the current element is smaller than the 
    element at the previous index, it also updates the value of take as 1 plus the value in the dp vector 
    for the previous element and the current index.
    Finally, it updates the value in the dp vector for the current element and previous index as the maximum 
    of take and notTake.

    The time complexity of this function is O(n^2), where n is the length of the input vector, b
    ecause it needs to fill all entries in the dp vector. 
    The space complexity is also O(n^2), because it needs to store the dp vector
    */

    int LongestIncreasingSubsequence_memoization(int ind, int prevInd, vector<int> &arr, vector<vector<int>> &dp)
    {
        // Base case: If we have iterated through the entire array
        if (ind < 0)
        {
            return 0; // No more elements to consider, so the length is 0
        }
        
        int take = -1e8;
        int notTake = LongestIncreasingSubsequence_memoization(ind - 1, prevInd, arr, dp);

        // Check if the value is already computed in the memoization table
        if (dp[ind][prevInd] != -1)
            return dp[ind][prevInd];
        
        if (prevInd == arr.size())
        {
            // If there's no previous element, we can take the current one
            take = 1 + LongestIncreasingSubsequence_memoization(ind - 1, ind, arr, dp);
        }
        else if (arr[ind] < arr.at(prevInd))
        {
            // If the current element is smaller than the previous one, we can take it
            take = 1 + LongestIncreasingSubsequence_memoization(ind - 1, ind, arr, dp);
        }

        // Store the computed value in the memoization table and return it
        return dp[ind][prevInd] = max(take, notTake);
    }

    /*
    3. Tabulation [TLE]
    The function creates a 2D vector dp to store the intermediate results and iterates through each element 
    in the input vector and each possible previous index. It initializes a variable take to a very small 
    negative value and calculates the result if the current element is not included in the subsequence (notTake) 
    as the value in the dp vector for the previous element and the same previous index.

    If the previous index is equal to the size of the input vector, it means that this is the first element 
    being considered for inclusion in the subsequence. In this case, it updates the value of take as 1 plus 
    the value in the dp vector for the previous element and the current index. If the previous index is not 
    equal to the size of the input vector and the current element is smaller than the element at the previous index, 
    it also updates the value of take as 1 plus the value in the dp vector for the previous element and the current 
    index.

    Finally, 
    it updates the value in the dp vector for the current element and previous index as the maximum of take and notTake.
    The time complexity of this function is O(n^2),
     where n is the length of the input vector, because it needs to fill all entries in the dp vector. 
     The space complexity is also O(n^2), because it needs to store the dp vector.
        */

    int TabulationSolution(int n, int nums[])
    {
        // Create a 2D DP table with (n + 1) rows and (n + 2) columns
        vector<vector<int>> dp(n + 1, vector<int>(n + 2));
        
        // Fill in the DP table using tabulation
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n + 1; j++)
            {
                int take = -1e8; // Initialize variable to store length if we take the current element
                int notTake = dp[i - 1][j]; // Length if we do not take the current element
                
                // Check if we can take the current element
                if (j - 1 == n)
                {
                    // If there's no next element, we can take the current one
                    take = 1 + dp[i - 1][i];
                }
                else if (nums[i - 1] < nums[j - 1])
                {
                    // If the current element is smaller than the next one, we can take it
                    take = 1 + dp[i - 1][i];
                }
                
                // Store the maximum of taking or not taking the current element in the DP table
                dp[i][j] = max(take, notTake);
            }
        }
        
        // Return the result stored in the last row and last column of the DP table
        return dp[n][n + 1];
    }
    /*
    4. Space optimization [2 rows] [TLE]
    Do we need the whole DP table or 2 rows of length n+2 will suffice?
    */

    int longestSubsequenceSO(int n, int nums[])
    {
        // Create two arrays to store the previous and current DP values
        vector<int> prev(n + 2), curr(n + 2);

        // Iterate through the array and calculate the longest increasing subsequence length
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n + 1; j++)
            {
                int take = -1e8; // Initialize variable to store length if we take the current element
                int notTake = prev[j]; // Length if we do not take the current element
                
                // Check if we can take the current element
                if (j - 1 == n)
                {
                    // If there's no next element, we can take the current one
                    take = 1 + prev[i];
                }
                else if (nums[i - 1] < nums[j - 1])
                {
                    // If the current element is smaller than the next one, we can take it
                    take = 1 + prev[i];
                }
                
                // Store the maximum of taking or not taking the current element in the current DP array
                curr[j] = max(take, notTake);
            }
            
            // Update the previous DP array with the values from the current DP array
            prev = curr;
        }
        
        // Return the result stored in the last column of the DP array
        return prev[n + 1];
    }

    /*
    5.  Binary Search Approach

    Here's an explanation of the approach step by step:

    1. Initialize a variable maxi to 1, which will keep track of the length of the longest increasing subsequence.

    2. Create an empty vector dp, which will store the elements of the increasing subsequence.

    3. Iterate through the input array a of length n.

    4. For each element a[i] in the input array:

    a. Use lower_bound to find the first element in the dp vector that is not less than a[i]. lower_bound returns an iterator pointing to the first element that is not less than the given value or the end() iterator if no such element is found.

    b. Check if the iterator it is at the end of the dp vector. If it is, it means that a[i] is greater than all elements in the current LIS. In this case, add a[i] to the end of the dp vector using emplace_back.

    c. If it is not at the end of the dp vector, get the index ind by subtracting dp.begin() from it. Update the element at index ind in the dp vector to a[i].

    d. Update the maxi variable with the maximum value between its current value and the size of the dp vector. This ensures that maxi always stores the length of the longest increasing subsequence encountered so far.

    After iterating through the entire input array, 
    return the value of maxi, which represents the length of the longest increasing subsequence.
    */

    int longestSubsequenceByBinarySearch(int n, int a[])
    {
        int maxi = 1; // Initialize a variable to store the length of the longest increasing subsequence.
        vector<int> dp; // Create an empty vector to store the elements of the increasing subsequence.

        // Iterate through the input array 'a' of length 'n'.
        for (int i = 0; i < n; i++)
        {
            // Use lower_bound to find the first element in the 'dp' vector that is not less than 'a[i]'.
            auto it = lower_bound(dp.begin(), dp.end(), a[i]);

            // If 'it' is at the end of the 'dp' vector, add 'a[i]' to the end.
            if (it == dp.end())
            {
                dp.emplace_back(a[i]);
            }
            else
            {
                // If 'it' is not at the end, calculate the index 'ind' by subtracting 'dp.begin()' from 'it'.
                int ind = it - dp.begin();
                
                // Update the element at index 'ind' with 'a[i]'.
                dp.at(ind) = a[i];
            }
            
            // Update 'maxi' with the maximum value between its current value and the size of 'dp'.
            maxi = max(maxi, (int)dp.size());
        }
        
        // Return the length of the longest increasing subsequence.
        return maxi;
    }





    int longestSubsequenceCommon(int n, int nums[], int approach)
    {
        if (approach == 1)
        {
            return BrutForceSolution(n - 1, n, vector<int>(nums, nums + n));
        }
        else if (approach == 2)
        {
            vector<vector<int>> dp(n, vector<int>(n + 1, -1));
            return LongestIncreasingSubsequence_memoization(n - 1, n, vector<int>(nums, nums + n), dp);
        }
        else if (approach == 3)
        {
            return TabulationSolution(n, nums);
        }
        else if (approach == 4)
        {
            return longestSubsequenceByBinarySearch(n, nums);
        }
        else
        {
            return -1; // Invalid approach
        }
    }
};

int main() {
    Solution solution;
    
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int a[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int approach;
    cout << "Choose an approach (1-BrutForce, 2-Memoization, 3-Tabulation, 4-BinarySearch): ";
    cin >> approach;
    
    int length = solution.longestSubsequenceCommon(n, a, approach);
    if (length != -1) {
        cout << "Length of the longest increasing subsequence: " << length << endl;
    } else {
        cout << "Invalid approach selected." << endl;
    }
    return 0;
}