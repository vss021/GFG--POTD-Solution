#include <iostream>
#include <vector>

using namespace std;

vector<int> findSubarrayWithSum(const vector<int>& a, int s) {
    int n = a.size();
    int i = 0, j = 0; // Initialize two pointers i and j to the beginning of the array.
    int sum = 0;      // Initialize a variable to keep track of the current sum.

    while (i < n && j <= n) {
        if (sum < s) {
            sum += a[j];
            j++;
        } else if (sum > s) {
            sum -= a[i];
            i++;
        } else {
            // If the current sum is equal to s, we found a subarray.
            // Return the indices (i+1) and j.
            return {i + 1, j};
        }
    }

    // If no subarray is found, return an empty vector or an appropriate value to indicate that.
    return {};
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int s = 10;
    vector<int> result = findSubarrayWithSum(a, s);

    if (!result.empty()) {
        cout << "Subarray with sum " << s << " found at indices: " << result[0] << " to " << result[1] - 1 << endl;
    } else {
        cout << "No subarray found with the given sum." << endl;
    }

    return 0;
}
