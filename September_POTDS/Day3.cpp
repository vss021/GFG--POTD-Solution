/*
Given two Binary Trees. Check whether they are Isomorphic or not.

Note: 
Two trees are called isomorphic if one can be obtained from another by a series of flips, i.e. 
by swapping left and right children of several nodes. Any number of nodes at any level can have their children swapped. 
Two empty trees are isomorphic. For example, the following two trees are isomorphic with the following sub-trees flipped:
 2 and 3, NULL and 6, 7 and 8.
*/

#include <iostream>
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
    bool isIsomorphic(Node* root1, Node* root2) {
        if (root1 == NULL && root2 == NULL)
            return true;

        if (root1 == NULL || root2 == NULL)
            return false;

        if (root1->data != root2->data)
            return false;

        bool first = (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right));
        bool second = (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left));

        return (first || second);
    }
};

int main() {
    // Create two sample binary trees
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    Node* root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);
    root2->right->left = new Node(5);
    root2->right->right = new Node(4);

    Solution solution;

    // Check if the trees are isomorphic and print the result
    if (solution.isIsomorphic(root1, root2))
        cout << "The trees are isomorphic." << endl;
    else
        cout << "The trees are not isomorphic." << endl;

    return 0;
}
