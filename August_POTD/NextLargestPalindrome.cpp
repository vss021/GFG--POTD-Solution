#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to check if all digits are 9
    bool isallnine(int s[], int n) {
        for (int i = 0; i < n; ++i) {
            if (s[i] != 9) return false;
        }
        return true;
    }

    // Function to check if a number is less than another represented by an array
    bool isless(int s[], int len) {
        int i = (len - 1) / 2, j = len / 2;
        while (i >= 0) {
            if (s[i] < s[j]) return true;
            else if (s[i] > s[j]) return false;
            --i, ++j;
        }
        return true;
    }

    // Function to generate the next palindrome number
    vector<int> generateNextPalindrome(int s[], int n) {
        if (isallnine(s, n)) {
            vector<int> ans(n + 1, 0);
            ans[0] = ans[n] = 1;
            return ans;
        }

        vector<int> ans(s, s + n);
        int i = (n - 1) / 2, j = n / 2, carry = isless(s, n);
        while (i >= 0) {
            if (carry) {
                if (ans[i] == 9) ans[i] = 0;
                else ans[i]++, carry = 0;
            }
            ans[j++] = ans[i--];
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Example input: {1, 2, 3, 4}
    int input[] = {1, 2, 3, 4};
    int n = sizeof(input) / sizeof(input[0]);

    // Generate the next palindrome
    vector<int> nextPalindrome = solution.generateNextPalindrome(input, n);

    // Print the input array
    cout << "Input Array: ";
    for (int i = 0; i < n; ++i) {
        cout << input[i] << " ";
    }
    cout << endl;

    // Print the next palindrome
    cout << "Next Palindrome: ";
    for (int digit : nextPalindrome) {
        cout << digit;
    }
    cout << endl;

    return 0;
}
