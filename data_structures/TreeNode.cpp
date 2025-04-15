#include <iostream>
using namespace std;

class TreeNode {
public:
    TreeNode(int d, TreeNode* l, TreeNode* r) : data(d), left(l), right(r) {}

    int data;
    TreeNode* left;
    TreeNode* right;
};

void InOrder(TreeNode* node) {
    if (node) {
        InOrder(node->left);
        cout << node->data << " ";
        InOrder(node->right);
    }
}

void PreOrder(TreeNode* node) {
    if (node) {
        cout << node->data << " ";
        PreOrder(node->left);
        PreOrder(node->right);
    }
}

void PostOrder(TreeNode* node) {
    if (node) {
        PostOrder(node->left);
        PostOrder(node->right);
        cout << node->data << " ";
    }
}

int main() {
    TreeNode* root = new TreeNode(3, nullptr, nullptr);
    root->left = new TreeNode(1, nullptr, nullptr);
    root->right = new TreeNode(5, nullptr, nullptr);
    root->left->left = new TreeNode(0, nullptr, nullptr);
    root->left->right = new TreeNode(2, nullptr, nullptr);
    root->right->left = new TreeNode(4, nullptr, nullptr);
    root->right->right = new TreeNode(6, nullptr, nullptr);

    InOrder(root);
    cout << "\n";
    PreOrder(root);
    cout << "\n";
    PostOrder(root);

    return 0;
}
