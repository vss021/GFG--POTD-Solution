/**
Given a non-negative integer N. The task is to check if N is a power of 2. More formally, check if N can be expressed as 2x for some integer x.

Example 1:

Input: 
N = 8
Output: 
YES
Explanation:
8 is equal to 2 raised to 3 (23 = 8).
Example 2:

Input: 
N = 98
Output: 
NO
Explanation: 
98 cannot be obtained by any power of 2.
*/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    // Method 1: Bit Manipulation (Using Brian Kernighan's Algorithm)
    bool isPowerofTwoBitManipulation(long long n) {
        if (n <= 0)
            return false;
        return (n & (n - 1)) == 0;
    }

    // Method 2: Using Logarithm
    bool isPowerofTwoLogarithm(long long n) {
        if (n <= 0)
            return false;
        double logValue = log2(n);
        return logValue == floor(logValue);
    }

    // Method 3: Iterative Approach
    bool isPowerofTwoIterative(long long n) {
        if (n <= 0)
            return false;
        while (n > 1) {
            if (n % 2 != 0)
                return false;
            n /= 2;
        }
        return true;
    }
};

int main() {
    Solution solution;
    long long n;

    cout << "Enter a non-negative integer: ";
    cin >> n;

    if (solution.isPowerofTwoBitManipulation(n))
        cout << n << " is a power of 2 using Bit Manipulation." << endl;
    else
        cout << n << " is not a power of 2 using Bit Manipulation." << endl;

    if (solution.isPowerofTwoLogarithm(n))
        cout << n << " is a power of 2 using Logarithm." << endl;
    else
        cout << n << " is not a power of 2 using Logarithm." << endl;

    if (solution.isPowerofTwoIterative(n))
        cout << n << " is a power of 2 using Iterative Approach." << endl;
    else
        cout << n << " is not a power of 2 using Iterative Approach." << endl;

    return 0;
}
