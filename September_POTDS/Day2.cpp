/*
Given a binary tree and a budget. Assume you are at the root of the tree(level 1), 
you need to maximise the count of leaf nodes you can visit in your budget if the cost of visiting a leaf node is 
equal to the level of that leaf node.
*/

#include <iostream>
#include <queue>
using namespace std;

// Define the Node class (assuming it's defined elsewhere)
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
    int getCount(Node* root, int k) {
        queue<pair<Node*, int>> q;
        q.push({root, 1});
        int cnt = 0;

        while (!q.empty() && k > 0) {
            auto node = q.front().first;
            int level = q.front().second;
            q.pop();

            if (!node->left && !node->right) {
                if (level > k)
                    return cnt; // If the level exceeds k, return the count
                ++cnt; // Increment count for leaf node
                k -= level; // Reduce k by the current level
            } else {
                if (node->left)
                    q.push({node->left, level + 1}); // Enqueue left child with updated level
                if (node->right)
                    q.push({node->right, level + 1}); // Enqueue right child with updated level
            }
        }

        return cnt; // Return the count of leaf nodes within k levels
    }
};

int main() {
    // Create a sample binary tree (assuming you have one)
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution solution;

    int k = 2; // Define the value of k

    // Call the getCount function to get the count of leaf nodes within k levels
    int leafCount = solution.getCount(root, k);

    cout << "Number of leaf nodes within " << k << " levels: " << leafCount << endl;

    return 0;
}
