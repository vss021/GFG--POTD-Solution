/*
Given an integer N. The task is to return the position of first set bit found from the right side in the binary representation of the number.
Note: If there is no set bit in the integer N, then return 0 from the function.  

Example 1:

Input: 
N = 18
Output: 
2
Explanation: 
Binary representation of 18 is 010010,the first set bit from the right side is at position 2.
Example 2:

Input: 
N = 12 
Output: 
3 
Explanation: 
Binary representation of  12 is 1100, the first set bit from the right side is at position 3.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    // Method 1: Using a Loop
    unsigned int getFirstSetBitLoop(int n) {
        int position = 1;
        while (n > 0) {
            if (n & 1) {
                return position;
            }
            n >>= 1;
            position++;
        }
        return 0; // Return 0 if no set bit is found.
    }

    // Method 2: Using Bit Manipulation
    unsigned int getFirstSetBitBitManipulation(int n) {
        if (n == 0) {
            return 0;
        }
        return log2(n & -n) + 1;
    }

    // Method 3: Using Brian Kernighan's Algorithm
    unsigned int getFirstSetBitBrianKernighan(int n) {
        if (n == 0) {
            return 0;
        }
        int position = 0;
        while (n) {
            n &= (n - 1);
            position++;
        }
        return position;
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter an integer: ";
    cin >> n;

    // Using Loop
    cout << "Position of first set bit (Loop): " << solution.getFirstSetBitLoop(n) << endl;

    // Using Bit Manipulation
    cout << "Position of first set bit (Bit Manipulation): " << solution.getFirstSetBitBitManipulation(n) << endl;

    // Using Brian Kernighan's Algorithm
    cout << "Position of first set bit (Brian Kernighan): " << solution.getFirstSetBitBrianKernighan(n) << endl;

    return 0;
}

