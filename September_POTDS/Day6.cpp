
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

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minimumMultiplications(vector<int>& arr, int start, int end) {
    vector<int> steps(100000, 1e8);  // Initialize an array to store minimum steps for each value.
    queue<int> q;
    q.push(start);
    int currSteps = 0;

    while (!q.empty()) {
        int Qsize = q.size();

        // Process all elements in the current BFS level.
        for (int i = 0; i < Qsize; i++) {
            int num = q.front();
            q.pop();

            if (num == end) {
                return currSteps;  // We've reached the target 'end'.
            }

            for (int choice : arr) {
                int newNum = (num * choice) % 100000;

                // If taking this step results in fewer steps to reach 'newNum', update it.
                if (1 + currSteps < steps[newNum]) {
                    q.push(newNum);
                    steps[newNum] = 1 + currSteps;
                }
            }
        }

        currSteps++;  // Move to the next BFS level.
    }

    return -1;  // If 'end' is not reachable.
}

int main() {
    vector<int> arr = {2, 3, 7, 11};
    int start = 2;
    int end = 162;

    int result = minimumMultiplications(arr, start, end);

    if (result != -1) {
        cout << "Minimum steps: " << result << endl;
    } else {
        cout << "Not possible to reach end." << endl;
    }

    return 0;
}
