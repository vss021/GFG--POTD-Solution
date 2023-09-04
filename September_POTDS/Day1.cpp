/*
problem

=>  Given a Binary Tree of size N, 
Print the corner nodes ie- the node at the leftmost and rightmost of each level.
*/

#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    void printCornerNodes(Node* root) {
        if (root == nullptr) {
            return; // Empty tree, nothing to print
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size(); // Number of nodes at this level

            for (int i = 0; i < n; i++) {
                Node* current = q.front();
                q.pop();

                // Print leftmost and rightmost nodes
                if (i == 0 || i == n - 1) {
                    cout << current->data << " ";
                }

                // Enqueue the left and right children, if they exist
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
        }
    }

    void printCorner(Node* root) {
        if (root == nullptr)
            return;

        printCornerNodes(root);
    }


    Node* buildTree() {
    int data;
    cout << "Enter data (or -1 for null): ";
    cin >> data;

    if (data == -1) {
        return nullptr; // Indicates a null node
    }

    Node* root = new Node(data);
    cout << "Enter left child of " << data << ": ";
    root->left = buildTree(); // Recursively build the left subtree
    cout << "Enter right child of " << data << ": ";
    root->right = buildTree(); // Recursively build the right subtree

    return root;
}

};

int main() {
    // Create a sample binary tree
    Node* root = buildTree()

    Solution solution;

    cout << "Corner Nodes: ";
    solution.printCorner(root);
    cout << endl;

    return 0;
}
