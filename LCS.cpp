#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    // Memoization solution for LCS
    int lcsMemoization(int x, int y, const string& s1, const string& s2, vector<vector<int>>& dp) {
        // Base case: If either string is empty, LCS is 0
        if (x == 0 || y == 0) {
            return 0;
        }

        // Check if the result is already calculated and stored in the dp array
        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        // If characters match, increment LCS length and move diagonally
        if (s1[x - 1] == s2[y - 1]) {
            dp[x][y] = 1 + lcsMemoization(x - 1, y - 1, s1, s2, dp);
        } else {
            // If characters don't match, consider maximum LCS without one character
            dp[x][y] = max(lcsMemoization(x - 1, y, s1, s2, dp), lcsMemoization(x, y - 1, s1, s2, dp));
        }

        return dp[x][y];
    }

    // Tabulation solution for LCS
    int lcsTabulation(int x, int y, const string& s1, const string& s2) {

        // Initialize a 2D DP table with all zeros
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));

        // Fill the DP table in a bottom-up manner
        for (int i = 1; i <= x; ++i) {
            for (int j = 1; j <= y; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    // If characters match, increment LCS length
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // If characters don't match, consider maximum LCS without one character
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // The value in the last cell represents the length of the LCS
        return dp[x][y];
    }
};

int main() {
    Solution solution;
    string s1, s2;

    // Get input strings from the user
    cout << "Enter the first string: ";
    cin >> s1;

    cout << "Enter the second string: ";
    cin >> s2;

    int x = s1.length();
    int y = s2.length();

    // Calculate LCS using Memoization and Tabulation
    int memoizationResult = solution.lcsMemoization(x, y, s1, s2, vector<vector<int>>(x + 1, vector<int>(y + 1, -1)));
    cout << "LCS using Memoization: " << memoizationResult << endl;

    int tabulationResult = solution.lcsTabulation(x, y, s1, s2);
    cout << "LCS using Tabulation: " << tabulationResult << endl;

    return 0;
}

