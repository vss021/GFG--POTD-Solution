/*
Given two numbers 'N' and 'S' , find the largest number that can be formed with 'N' digits and whose sum of digits should be equals to 'S'. Return -1 if it is not possible.

Example 1:

Input: N = 2, S = 9
Output: 90
Explaination: It is the biggest number 
with sum of digits equals to 9.
Example 2:

Input: N = 3, S = 20
Output: 992
Explaination: It is the biggest number 
with sum of digits equals to 20.

*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string findLargest(int N, int S) {
        if (S == 0 && N == 1) {
            return "0";  // Special case when N=1 and S=0, the only valid result is "0".
        }

        if (S < 1 || S > 9 * N) {
            return "-1"; // Not possible to create a string given the constraints.
        }

        string ans = "";

        int dig = 0;

        while (S) {
            if (S >= 9) {
                char d = '9';
                ans += d;
                S -= 9;
            } else {
                char d = (S + '0');
                ans += d;
                S = 0;
            }
        }

        if (N < ans.length()) {
            return "-1"; // Cannot create a string of length N.
        }

        if (N > ans.length()) {
            N -= ans.length();

            while (N != 0) {
                ans += '0';
                N--;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;

    int N, S;
    cin >> N >> S;

    string largestString = solution.findLargest(N, S);

    cout << largestString << endl;

    return 0;
}
