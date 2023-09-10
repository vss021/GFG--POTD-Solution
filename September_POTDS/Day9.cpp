/*
Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
 Example 1:

Input:
      1
    /   \
   2     3
Output: 
1 2 3
Explanation:
The converted BST will be 
      2
    /   \
   1     3

Example 2:

Input:
          1
       /    \
     2       3
   /        
 4       
Output: 
1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1


*/

#include <iostream>
#include <vector>
#include <algorithm>

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
public:
    void Inorder(Node* root, vector<int>& v) {
        if (root == NULL)
            return;
        v.push_back(root->data);
        Inorder(root->left, v);
        Inorder(root->right, v);
    }

    Node* buildTree(vector<int>& v, int l, int r) {
        if (l > r) {
            return NULL; // Base case: no elements to build the tree
        }

        int mid = (l + r) / 2;
        Node* root = new Node(v[mid]); // Create a new Node
        root->left = buildTree(v, l, mid - 1);
        root->right = buildTree(v, mid + 1, r);
        return root;
    }

    Node* binaryTreeToBST(Node* root) {
        vector<int> v;
        Inorder(root, v);
        sort(begin(v), end(v));
        return buildTree(v, 0, v.size() - 1);
    }
};

// Function to print the inorder traversal of a BST
void printInorder(Node* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    // Create a sample binary tree
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    Solution solution;

    cout << "Inorder traversal of the original binary tree: ";
    printInorder(root);
    cout << endl;

    // Convert the binary tree to a BST
    Node* bstRoot = solution.binaryTreeToBST(root);

    cout << "Inorder traversal of the converted BST: ";
    printInorder(bstRoot);
    cout << endl;

    return 0;
}

/*
The provided code for converting a binary tree to a binary search tree (BST) is already quite efficient in terms of time complexity. However, there are a few minor optimizations and improvements you can make:

Avoid Sorting: Instead of sorting the values obtained from the inorder traversal, you can directly build the BST while doing the traversal without the need for sorting. This will save both time and space complexity.

Use a Balanced BST: While creating the BST, you can ensure that it's balanced by selecting the middle element as the root. This will guarantee that the BST is balanced, which is desirable for efficient search operations.

tc for sorting solution => O(NlogN)
sp => O(N) + O(H) => recursion + vector size
*/
