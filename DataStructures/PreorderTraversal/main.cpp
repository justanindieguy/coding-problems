#include <iostream>
#include "tree_node.h"

using namespace std;

void preorderTraversal(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(7);
    p->left->left = new TreeNode(2);
    p->left->right = new TreeNode(6);
    p->left->right->left = new TreeNode(5);
    p->left->right->right = new TreeNode(11);
    p->right = new TreeNode(9);
    p->right->right = new TreeNode(9);
    p->right->right->left = new TreeNode(5);

    preorderTraversal(p);
    cout << endl;

    return 0;
}
