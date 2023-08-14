#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class MySolution
{
public:
    // Solution using Unordered Map - O(N) time and space
    vector<int> using_UnorderMap(vector<int> nums) 
    {
        vector<int> ans;
        
        unordered_map<int, int> freqMap;
        
        // Count the frequency of each element
        for(auto i : nums){
            freqMap[i]++;
        }
        
        // Identify the non-repeating elements
        for(auto i : freqMap){
            if(i.second == 1)
                ans.push_back(i.first);
        }
        return ans;
    }

    // Solution using Sorting - O(N log N) time and O(1) space
    vector<int> using_Sorting(vector<int> nums) 
    {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        
        // Traverse through the sorted array to find non-repeating elements
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == nums[i + 1]){
                i++;
            }
            else{
                ans.push_back(nums[i]);
            }
            if(ans.size() == 2){
                return ans;
            }
        }
        return ans;
    }

    // Solution using Bit Manipulation - O(N) time and O(1) space
    vector<int> Using_BitManipulation(vector<int> nums) 
    {
        vector<int> ans(2, 0);
        int w = 0;
        
        // Find XOR of all elements to get XOR of non-repeating elements
        for(int i = 0; i < nums.size(); i++){
            w = w ^ nums[i];
        }
        
        int x = w & -w;
        int y = 0;
        int z = 0;
        
        // Separate the elements based on their XOR with 'x'
        for(int i = 0; i < nums.size(); i++){
            if((x & nums[i]) == 0){
                y = y ^ nums[i];
            }
            else{
                z = z ^ nums[i];
            }
        }
        if(y < z){
            ans = {y, z};
        }
        else{
            ans = {z, y};
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        MySolution mySolution;

        // Uncomment one of the lines below to use the respective method

        // Method 1: Using Unordered Map
        // return mySolution.using_UnorderMap(nums);

        // Method 2: Using Sorting
        // return mySolution.using_Sorting(nums);

        // Method 3: Using Bit Manipulation
        return mySolution.Using_BitManipulation(nums);
    }
};

int main()
{
    Solution solution;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> result = solution.singleNumber(nums);

    cout << "Single non-repeating elements: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
