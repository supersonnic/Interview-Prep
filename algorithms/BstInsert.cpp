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
