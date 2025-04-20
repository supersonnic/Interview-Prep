
/**
 * This program defines a TreeNode class to represent nodes in a binary search tree.
 * It provides functions to insert elements into the BST and to perform an in-order
 * traversal of the tree, printing the elements in sorted order.
 *
 * Classes:
 * - TreeNode: Represents a node in the binary search tree, containing data and pointers
 *   to left and right child nodes.
 *
 * Functions:
 * - TreeNode::TreeNode(int d): Constructor to initialize a TreeNode with given data.
 * - TreeNode* BstInsert(TreeNode* current, int data): Recursively inserts a new node
 *   with the specified data into the BST, maintaining the BST property.
 * - void InOrder(TreeNode* node): Performs an in-order traversal of the BST, printing
 *   the data of each node in ascending order.
 *
 * Note:
 * Duplicate values are allowed in this implementation and are inserted into the left
 * subtree of the node with the same value.
 * 
 * Author: Shervin Oloumi
 * Date: 2023-10-01
 */
#include <iostream>

using namespace std;

class TreeNode {
public:
    TreeNode(int d) : data(d), left(nullptr), right(nullptr) {}

    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* BstInsert(TreeNode* current, int data) {
    if (!current) {
        return new TreeNode(data);
    }
    if (data <= current->data) {
        current->left = BstInsert(current->left, data);
    }
    else {
        current->right = BstInsert(current->right, data);
    }
    return current;
}

void InOrder(TreeNode* node) {
    if (node) {
        InOrder(node->left);
        cout << node->data << " ";
        InOrder(node->right);
    }
}

int main() {
    TreeNode* root = BstInsert(nullptr, 51);
    BstInsert(root, 59);
    BstInsert(root, 98);
    BstInsert(root, 13);
    BstInsert(root, 44);
    BstInsert(root, 25);
    BstInsert(root, 50);
    BstInsert(root, 51);

    InOrder(root);

    return 0;
}
