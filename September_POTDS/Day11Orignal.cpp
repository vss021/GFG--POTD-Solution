/**
Lucky numbers are subset of integers. Rather than going into much theory, let us see the process of arriving at lucky numbers,
Take the set of integers
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,……
First, delete every second number, we get following reduced set.
1, 3, 5, 7, 9, 11, 13, 15, 17, 19,…………
Now, delete every third number, we get
1, 3, 7, 9, 13, 15, 19,….….
Continue this process indefinitely……
Any number that does NOT get deleted due to above process is called “lucky”.

You are given a number N, you need to tell whether the number is lucky or not. If the number is lucky return 1 otherwise 0.

Example 1:

Input:
N = 5
Output: 0
Explanation: 5 is not a lucky number 
as it gets deleted in the second 
iteration.
Example 2:

Input:
N = 19
Output: 1
Explanation: 19 is a lucky number because 
it does not get deleted throughout the process.
*/


#include <iostream>


#include <cmath>

class Solution {
public:
    bool isLucky(int n) {
        int divisor = 2;
        int temp = n;

        for (int i = 0; i < sqrt(n); i++) {
            if (temp % divisor == 0) {
                return false;
            }

            temp -= temp / divisor;
            divisor++;
        }

        return true;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    int n1 = 19; // Lucky number
    int n2 = 12; // Not a lucky number
    int n3 = 7;  // Lucky number
    int n4 = 5;  // Lucky number

    bool result1 = solution.isLucky(n1);
    bool result2 = solution.isLucky(n2);
    bool result3 = solution.isLucky(n3);
    bool result4 = solution.isLucky(n4);

    std::cout << n1 << " is a lucky number: " << result1 << std::endl;
    std::cout << n2 << " is a lucky number: " << result2 << std::endl;
    std::cout << n3 << " is a lucky number: " << result3 << std::endl;
    std::cout << n4 << " is a lucky number: " << result4 << std::endl;

    return 0;
}
