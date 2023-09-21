/**

A frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top of Nth step. As the answer will be large find the answer modulo 1000000007.

Example 1:

Input:
N = 1
Output: 1
Example 2:

Input:
N = 4
Output: 7
Explanation:Below are the 7 ways to reach
4
1 step + 1 step + 1 step + 1 step
1 step + 2 step + 1 step
2 step + 1 step + 1 step
1 step + 1 step + 2 step
2 step + 2 step
3 step + 1 step
1 step + 3 step

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long mod = 1000000007;

    long long countWays1(int n, vector<long long>& dp) {
        long long a = 0, b = 0, c = 0;

        if (n == 0) {
            return 1;
        }

        if (dp[n] != -1)
            return dp[n];

        if (n >= 1) {
            a = countWays1(n - 1, dp) % mod;
        }
        if (n >= 2) {
            b = countWays1(n - 2, dp) % mod;
        }
        if (n >= 3) {
            c = countWays1(n - 3, dp) % mod;
        }

        return dp[n] = (a + b + c) % mod;
    }

    long long countWays(int n) {
        vector<long long> dp(n + 1, -1);

        return countWays1(n, dp);
    }
};

int main() {
    Solution solution;

    // Example usage
    int n = 4;
    long long ways = solution.countWays(n);

    cout << "Number of ways frog can reach the top: " << ways << endl;

    return 0;
}
