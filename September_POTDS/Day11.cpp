/*
Given a BST and a key K. If K is not present in the BST, Insert a new Node with a value equal to K into the BST. If K is already present in the BST, don't modify the BST.

Example 1:

Input:
     2
   /   \   1     3
K = 4
Output: 
1 2 3 4
Explanation: 
After inserting the node 4
Inorder traversal will be 1 2 3 4.
Example 2:

Input:
        2
      /   \
     1     3
             \
              6
K = 4
Output: 
1 2 3 4 6
Explanation: 
After inserting the node 4
Inorder traversal of the above tree will be 1 2 3 4 6.

*/

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
public:
    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            Node* newNode = new Node(data);
            return newNode;
        }

        if (node->data > data) {
            node->left = insert(node->left, data);
        } else if (node->data < data) {
            node->right = insert(node->right, data);
        }

        return node;
    }
};

// Function to print the inorder traversal of a BST
void printInorder(Node* root) {
    if (root == nullptr)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    Solution solution;
    Node* root = nullptr; // Initialize an empty BST

    // Insert elements into the BST
    root = solution.insert(root, 50);
    root = solution.insert(root, 30);
    root = solution.insert(root, 70);
    root = solution.insert(root, 20);
    root = solution.insert(root, 40);
    root = solution.insert(root, 60);
    root = solution.insert(root, 80);

    // Print the inorder traversal to verify the insertion
    cout << "Inorder traversal of the BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}

/*

Time Complexity: O(Height of the BST). 
Auxiliary Space: O(Height of the BST).
*/