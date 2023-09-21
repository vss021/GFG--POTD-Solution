/*
Given a number N, find the first N Fibonacci numbers. The first two number of the series are 1 and 1.

Example 1:

Input:
N = 5
Output: 1 1 2 3 5
Example 2:

Input:
N = 7
Output: 1 1 2 3 5 8 13

*/


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // Brute force solution with memoization.
    vector<long long> printFibbMemoization(int n)
    {
        vector<long long> result;
        vector<long long> memo(n + 1, -1);
        for (int i = 0; i < n; i++)
        {
            result.push_back(fibonacciMemoization(i, memo));
        }
        return result;
    }

    // Tabulation (bottom-up) approach.
    vector<long long> printFibbTabulation(int n)
    {
        vector<long long> result;
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        result = dp;
        return result;
    }

    // Most optimized solution using mathematical formulas (Binet's Formula).
    vector<long long> printFibbOptimized(int n)
    {
        vector<long long> result;
        for (int i = 0; i < n; i++)
        {
            long double phi = (1 + sqrt(5)) / 2;
            long double psi = (1 - sqrt(5)) / 2;
            long long fib = round((pow(phi, i) - pow(psi, i)) / sqrt(5));
            result.push_back(fib);
        }
        return result;
    }

private:
    // Helper function for memoization.
    long long fibonacciMemoization(int n, vector<long long> &memo)
    {
        if (n <= 1)
        {
            return n;
        }
        if (memo[n] != -1)
        {
            return memo[n];
        }
        memo[n] = fibonacciMemoization(n - 1, memo) + fibonacciMemoization(n - 2, memo);
        return memo[n];
    }
};

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    Solution solution;

    // Brute force with memoization
    vector<long long> fibonacciNumbersMemo = solution.printFibbMemoization(n);
    cout << "Fibonacci numbers using memoization: ";
    for (long long num : fibonacciNumbersMemo)
    {
        cout << num << " ";
    }
    cout << endl;

    // Tabulation (bottom-up)
    vector<long long> fibonacciNumbersTabulation = solution.printFibbTabulation(n);
    cout << "Fibonacci numbers using tabulation: ";
    for (long long num : fibonacciNumbersTabulation)
    {
        cout << num << " ";
    }
    cout << endl;

    // Most optimized using mathematical formulas
    vector<long long> fibonacciNumbersOptimized = solution.printFibbOptimized(n);
    cout << "Fibonacci numbers using optimized formula: ";
    for (long long num : fibonacciNumbersOptimized)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
