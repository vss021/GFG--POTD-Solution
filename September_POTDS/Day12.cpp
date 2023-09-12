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
