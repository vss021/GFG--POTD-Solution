#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int nthCatalanNumber(int N) {
    // Create a vector to store the Catalan numbers
    vector<int> catalan(N + 1, 0);

    // Base case: the 0th Catalan number is 1
    catalan[0] = 1;

    // Calculate Catalan numbers using dynamic programming
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            // Calculate the product of catalan[j] and catalan[i-j-1]
            int product = (1LL * catalan[j] * catalan[i - j - 1]) % MOD;
            // Add the product to catalan[i]
            catalan[i] = (catalan[i] + product) % MOD;
        }
    }

    return catalan[N];
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    // Calculate the Nth Catalan number
    int catalanN = nthCatalanNumber(N);

    // Print the result
    cout << "The " << N << "th Catalan number is: " << catalanN << endl;

    return 0;
}
