/*
Given a number N, check if a number is perfect or not. A number is said to be perfect if sum of all its factors excluding the number itself is equal to the number. Return 1 if the number is Perfect otherwise return 0.

Example 1:

Input:
N = 6
Output:
1 
Explanation:
Factors of 6 are 1, 2, 3 and 6.
Excluding 6 their sum is 6 which
is equal to N itself. So, it's a
Perfect Number.
Example 2:

Input:
N = 10
Output:
0
Explanation:
Factors of 10 are 1, 2, 5 and 10.
Excluding 10 their sum is 8 which
is not equal to N itself. So, it's
not a Perfect Number.
*/

#include <iostream>
#include <cmath>

class Solution {
public:
    int isPerfectNumber(long long N) {
        if (N <= 1) {
            return 0;
        }

        long long sum = 1;

        for (int i = 2; i <= sqrt(N); i++) {
            if (N % i == 0) {
                sum += i;
                sum += (N / i);
            }
        }

        if (sum == N) {
            return 1;
        }

        return 0;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    long long N1 = 28; // Perfect number
    long long N2 = 6;  // Perfect number
    long long N3 = 12; // Not a perfect number

    int result1 = solution.isPerfectNumber(N1);
    int result2 = solution.isPerfectNumber(N2);
    int result3 = solution.isPerfectNumber(N3);

    std::cout << "Is " << N1 << " a perfect number? " << result1 << std::endl;
    std::cout << "Is " << N2 << " a perfect number? " << result2 << std::endl;
    std::cout << "Is " << N3 << " a perfect number? " << result3 << std::endl;

    return 0;
}
