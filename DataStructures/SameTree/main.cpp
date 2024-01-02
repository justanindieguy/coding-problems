#include <iostream>
#include "tree_node.h"

using namespace std;

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
    {
        return true;
    }

    if (!p || !q || p->val != q->val)
    {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    if (isSameTree(p, q))
    {
        cout << "Same!" << endl;
    }
    else
    {
        cout << "NOT the same!" << endl;
    }

    return 0;
}
