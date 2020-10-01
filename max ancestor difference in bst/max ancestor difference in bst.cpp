#include <iostream>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
	}
};

// Helper function to find maximum difference between a node and its
// descendants in a binary tree
int maxDifference(Node* root, int &diff)
{
    // base case: if tree is empty, return infinity
    if (root == nullptr)
        return INT_MAX;

    // recur for left and right subtree
    int left = maxDifference(root->left, diff);
    int right = maxDifference(root->right, diff);

    // find maximum difference between current node and its descendants
    int d = root->data - min(left, right);

    // update the maximum difference found so far if required
    diff = max(diff, d);

    // in order for difference to be maximum, the function should return
    // minimum value among all nodes in sub-tree rooted at it
    return min(min(left, right), root->data);
}

// Find maximum difference between a node and its descendants in a binary tree
int maxDifference(Node *root)
{
    int diff = INT_MIN;
    maxDifference(root, diff);

    return diff;
}

int main()
{
    Node* root = nullptr;

    root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->right->left = new Node(2);
    root->right->right = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(7);

    cout << maxDifference(root);

    return 0;
}
