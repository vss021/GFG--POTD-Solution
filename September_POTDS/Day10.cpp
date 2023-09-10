/*
Given a Binary Search Tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

Example 1:

Input:
      4
    /   \
   2     9
k = 2 
Output: 4
Example 2:

Input:
       9
        \ 
          10
K = 1
Output: 10 */

#include <iostream>

using namespace std;

// Definition of the Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Definition of the Solution class
class Solution {
private:
    void solve(Node* root, int& k, int& ans) {
        if (root == nullptr || k == 0)
            return;

        // Traverse the right subtree first
        solve(root->right, k, ans);

        k--;
        if (k == 0) {
            ans = root->data;
            return;
        }

        // Then, traverse the left subtree
        solve(root->left, k, ans);
    }

public:
    int kthLargest(Node* root, int K) {
        int ans = 0;
        solve(root, K, ans);
        return ans;
    }
};

int main() {
    // Create a sample BST
    Node* root = new Node(20);
    root->left = new Node(15);
    root->right = new Node(25);
    root->left->left = new Node(10);
    root->left->right = new Node(18);

    Solution solution;

    int K = 3; // Find the 3rd largest element

    int result = solution.kthLargest(root, K);

    cout << "The " << K << "th largest element in the BST is: " << result << endl;

    return 0;
}

/*

Time Complexity: O(N).
Auxiliary Space: O(H) where H is max recursion stack of height H at a given time.

*/