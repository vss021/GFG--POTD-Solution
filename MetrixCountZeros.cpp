#include <iostream>
#include <vector>
using namespace std;

/*
Given a matrix of order nxm, composed of only 0's and 1's, 
find the number of 1's in the matrix that are surrounded by an even number (>0) of 0's. 
The surrounding of a cell in the matrix is defined as the elements above, below, on left, 
on right as well as the 4 diagonal elements around the cell of the matrix. Hence, 
the surrounding of any matrix elements is composed of 8 elements. Find the number of such 1's.

Example 1:

Input: 
matrix = {{1, 0, 0}, 
          {1, 1, 0}, 
          {0, 1, 0}}
Output: 
1
Explanation: 
1 that occurs in the 1st row and 1st column, has 3 surrounding elements 0,1 and 1. The occurrence of zero is odd. 
1 that occurs in 2nd row and 1st column has 5 surrounding elements 1,0,1,1 and 0. The occurrence of zero is even. 
1 that occurs in 2nd row and 2nd column has 8 surrounding elements. The occurrence of 0 is odd. 
Similarly, for the 1 that occurs in 3rd row and 2nd column, the occurrence of zero in it's 5 surrounding elements is odd. 
Hence, the output is 1.

*/

class Solution
{
public:
    // Function to count occurrences of '1' with even numbers of adjacent '0's in a matrix
    int Count(vector<vector<int>> &matrix)
    {
        int n = matrix.size();    // Get the number of rows in the matrix
        int m = matrix[0].size(); // Get the number of columns in the matrix
        int count = 0;            // Initialize a count variable to keep track of the result

        // Loop through each element in the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // If the element is '1', count adjacent '0's
                if (matrix[i][j] == 1)
                {
                    int z = countZeros(matrix, i, j); // Count adjacent '0's for this '1'
                    // If there are adjacent '0's and the count is even, increment count
                    if (z != 0 && z % 2 == 0)
                    {
                        count++;
                    }
                }
            }
        }

        return count; // Return the final count of '1's with even adjacent '0's
    }

private:
    // Function to count adjacent '0's around an element in the matrix
    int countZeros(vector<vector<int>> &matrix, int r, int c)
    {
        if (matrix[r][c] == 0)
        {
            return 0; // If the current element is '0', return 0
        }

        int n = matrix.size();    // Get the number of rows in the matrix
        int m = matrix[0].size(); // Get the number of columns in the matrix
        int zeros = 0;            // Initialize a variable to count adjacent '0's

        // Check adjacent elements for '0's
        if (r > 0 && c > 0)
        {
            if (matrix[r - 1][c - 1] == 0)
            {
                zeros++;
            }
        }
        if (r > 0)
        {
            if (matrix[r - 1][c] == 0)
            {
                zeros++;
            }
        }
        if (r > 0 && c < m - 1)
        {
            if (matrix[r - 1][c + 1] == 0)
            {
                zeros++;
            }
        }

        if (c > 0)
        {
            if (matrix[r][c - 1] == 0)
            {
                zeros++;
            }
        }
        if (c < m - 1)
        {
            if (matrix[r][c + 1] == 0)
            {
                zeros++;
            }
        }

        if (r < n - 1 && c > 0)
        {
            if (matrix[r + 1][c - 1] == 0)
            {
                zeros++;
            }
        }
        if (r < n - 1)
        {
            if (matrix[r + 1][c] == 0)
            {
                zeros++;
            }
        }
        if (r < n - 1 && c < m - 1)
        {
            if (matrix[r + 1][c + 1] == 0)
            {
                zeros++;
            }
        }

        return zeros; // Return the count of adjacent '0's
    }
};

int main()
{
    // Test the Solution class
    Solution solution;

    // Example matrix
    vector<vector<int>> matrix = {
        {1, 0, 0, 1},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 1}};

    int result = solution.Count(matrix);

    // Display the result
    cout << "Count of '1's with even adjacent '0's: " << result << endl;

    return 0;
}
