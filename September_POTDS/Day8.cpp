/*
Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

Example 1:

Input:
arr[] = {2, 5, 7}
start = 3, end = 30
Output:
2
Explanation:
Step 1: 3*2 = 6 % 100000 = 6 
Step 2: 6*5 = 30 % 100000 = 30
Example 2:

Input:
arr[] = {3, 4, 65}
start = 7, end = 66175
Output:
4
Explanation:
Step 1: 7*3 = 21 % 100000 = 21 
Step 2: 21*3 = 63 % 100000 = 63 
Step 3: 63*65 = 4095 % 100000 = 4095 
Step 4: 4095*65 = 266175 % 100000 = 66175
*/

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // Create an array 'steps' to store the minimum number of steps required
        // to reach each number from 'start'. Initialize all elements to a large value.
        vector<int> steps(100000, 1e8);
        
        // Create a queue 'q' for BFS and push 'start' into it.
        queue<int> q;
        q.push(start);
        
        // Initialize 'currSteps' to 0, which represents the current number of steps.
        int currSteps = 0;
        
        // Start the BFS loop until the queue is empty.
        while (!q.empty()) {
            // Get the number of elements at the current level of BFS.
            int Qsize = q.size();
            
            // Process all elements at the current level.
            for (int i = 0; i < Qsize; i++) {
                int num = q.front(); // Get the front element of the queue.
                q.pop(); // Remove the front element.
                
                // If 'num' is equal to 'end', we have reached the target.
                // Return the current number of steps.
                if (num == end)
                    return currSteps;
                
                // Try all possible choices for multiplication.
                for (int choice : arr) {
                    int newNum = (num * choice) % 100000; // Calculate the new number.
                    
                    // If taking this choice results in fewer steps to reach 'newNum',
                    // update the number of steps and push 'newNum' into the queue.
                    if (1 + currSteps < steps[newNum]) {
                        q.push(newNum);
                        steps[newNum] = 1 + currSteps;
                    }
                }
            }
            
            // Increment the number of steps to move to the next level of BFS.
            currSteps++;
        }
        
        // If we couldn't reach 'end', return -1 to indicate it's not possible.
        return -1;
    }
};

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Example input data
    vector<int> arr = {2, 3, 5};
    int start = 2;
    int end = 20;

    // Call the minimumMultiplications function
    int result = solution.minimumMultiplications(arr, start, end);

    // Display the result
    if (result != -1) {
        cout << "Minimum multiplications required: " << result << endl;
    } else {
        cout << "It's not possible to reach the 'end' value from 'start' with the given 'arr' choices." << endl;
    }

    return 0;
}

/*
 the time complexity is O(N*M), and 
 the space complexity is O(N), w
 here N represents the maximum number of steps required to reach the end value from the start value, 
 and M is the number of choices in the arr vector. The exact values of N and M will depend on the specific input data and can vary.*/
