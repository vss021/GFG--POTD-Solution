#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
private:
    // Function to find the first occurrence of x in a sorted array
    int firstOcc(int arr[], int n, int x)
    {
        int low = 0, high = n - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = (low + high) >> 1;

            if (arr[mid] == x)
            {
                ans = mid;
                high = mid - 1;
            }
            else if (arr[mid] < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }

    // Function to find the last occurrence of x in a sorted array
    int lastOcc(int arr[], int n, int x)
    {
        int low = 0, high = n - 1;
        int ans;
        while (low <= high)
        {
            int mid = (low + high) >> 1;

            if (arr[mid] == x)
            {
                ans = mid;
                low = mid + 1;
            }
            else if (arr[mid] > x)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

    int countOccurrences(const vector<int> &arr, int x)
    {
        // Use lower_bound to find the first occurrence of x
        int start = lower_bound(arr.begin(), arr.end(), x);

        // Use upper_bound to find the first element greater than x
        int end = upper_bound(arr.begin(), arr.end(), x);

        // The number of occurrences is the difference between start and end iterators
        return distance(start, end);
    }

public:
    // Function to count the number of occurrences of x in a sorted array
    int count(int arr[], int n, int x)
    {
        int ind1 = firstOcc(arr, n, x), ind2 = 0;
        if (ind1 == -1)
        {
            return 0;
        }
        else
        {
            ind2 = lastOcc(arr, n, x);
        }

        return ind2 - ind1 + 1;
    }
};

int main()
{
    Solution solution;

    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the sorted array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cout << "Enter the element to count occurrences: ";
    cin >> x;

    int result = solution.count(arr, n, x);
    cout << "The number of occurrences of " << x << " is: " << result << endl;

    return 0;
}
