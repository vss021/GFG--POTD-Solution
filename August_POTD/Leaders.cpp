#include <iostream>
#include <vector>
#include <algorithm> // For reverse
#include <climits>   // For INT_MIN

using namespace std;

class Solution {
public:
    vector<int> leaders(int a[], int n) {
        vector<int> ans;
        
        int mx = INT_MIN;
        
        for (int i = n - 1; i >= 0; i--) {
            if (mx <= a[i]) {
                ans.push_back(a[i]);
                mx = a[i];
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

int main() {
    Solution solution;

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int a[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> result = solution.leaders(a, n);

    cout << "Leaders in the array: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
