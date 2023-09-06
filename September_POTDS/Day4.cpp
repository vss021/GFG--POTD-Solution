

/**
Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O' with 'X' that are surrounded by 'X'.

A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

Example 1:

Input: 
n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Explanation: 
Following the rule the above matrix is the resultant matrix. 
Example 2:

 

Input: 
n = 5, m = 4
mat = {{'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;

        int n = board.size();
        int m = board[0].size();

        // Step 1: Mark 'O' cells connected to the border as 'T'
        for (int i = 0; i < n; i++) {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }

        for (int j = 0; j < m; j++) {
            dfs(board, 0, j);
            dfs(board, n - 1, j);
        }

        // Step 2: Replace 'O' with 'X' and 'T' with 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }

private:
    // Depth-First Search (DFS) function
    void dfs(vector<vector<char>>& board, int i, int j) {
        int n = board.size();
        int m = board[0].size();

        // Base case: If out of bounds or not an 'O', return
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O') return;

        // Mark the current 'O' as 'T' (temporary)
        board[i][j] = 'T';

        // Recursively visit adjacent cells
        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }
};

// Helper function to print the matrix
void printMatrix(const vector<vector<char>>& matrix) {
    for (const vector<char>& row : matrix) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> mat1 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}
    };

    Solution solution;
    solution.solve(mat1);

    cout << "Output for mat1:" << endl;
    printMatrix(mat1);

    vector<vector<char>> mat2 = {
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}
    };

    solution.solve(mat2);

    cout << "\nOutput for mat2:" << endl;
    printMatrix(mat2);

    return 0;
}
/*
The time complexity of a Depth-First Search (DFS) algorithm applied to a graph or a grid depends on the structure of the graph or grid and the specific implementation. In the context of the provided solution for the matrix problem, the time complexity of the DFS is O(N * M), where N is the number of rows, and M is the number of columns in the matrix.

Here's why:

Initialization: In the DFS implementation, you typically start DFS from a specific node or set of nodes. In this case, you start DFS from 'O' cells along the border of the matrix. The number of such border cells is proportional to the number of rows and columns, i.e., O(N + M).

Traversal: During DFS, each cell is visited once. For each cell, you may explore up to four adjacent cells (above, below, left, and right). In the worst case, you may visit every cell in the matrix, resulting in a total of O(N * M) operations.

So, the overall time complexity of DFS in this context is O(N * M), where N is the number of rows, and M is the number of columns in the matrix. It's important to note that the time complexity of DFS can vary in different scenarios, such as when applied*/