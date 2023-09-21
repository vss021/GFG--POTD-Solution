/*
Given an integer N and an integer D, rotate the binary representation of the integer N by D digits to the left as well as right and return the results in their decimal representation after each of the rotation.
Note: Integer N is stored using 16 bits. i.e. 12 will be stored as 0000000000001100.

Example 1:

Input:
N = 28, D = 2
Output:
112
7
Explanation: 
28 in Binary is: 0000000000011100
Rotating left by 2 positions, it becomes 0000000001110000 = 112 (in decimal).
Rotating right by 2 positions, it becomes 0000000000000111 = 7 (in decimal).
Example 2:

Input: 
N = 29, D = 2
Output: 
116
16391
Explanation: 
29 in Binary is: 0000000000011101
Rotating left by 2 positions, it becomes 0000000001110100 = 116 (in decimal).
Rotating right by 2 positions, it becomes 100000000000111 = 16391 (in decimal).

*/

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    // Function to perform left rotation and return decimal representation.
    int leftRotate(int n, int d) {
        bitset<16> binaryN(n);
        string binaryStr = binaryN.to_string();
        
        rotate(binaryStr.begin(), binaryStr.begin() + d, binaryStr.end());
        
        return bitset<16>(binaryStr).to_ulong();
    }

    // Function to perform right rotation and return decimal representation.
    int rightRotate(int n, int d) {
        bitset<16> binaryN(n);
        string binaryStr = binaryN.to_string();
        
        rotate(binaryStr.rbegin(), binaryStr.rbegin() + d, binaryStr.rend());
        
        return bitset<16>(binaryStr).to_ulong();
    }

    // Function to perform both left and right rotations.
    vector<int> rotate(int n, int d) {
        int leftResult = leftRotate(n, d);
        int rightResult = rightRotate(n, d);
        
        return {leftResult, rightResult};
    }
};

int main() {
    Solution solution;
    int N, D;

    cout << "Enter an integer N: ";
    cin >> N;
    cout << "Enter the number of rotations D: ";
    cin >> D;

    vector<int> results = solution.rotate(N, D);

    cout << "Left Rotation Result: " << results[0] << endl;
    cout << "Right Rotation Result: " << results[1] << endl;

    return 0;
}


