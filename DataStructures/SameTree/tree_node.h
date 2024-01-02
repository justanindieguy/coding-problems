#include <iostream>

#if !defined(TREE_NODE_H)
#define TREE_NODE_H

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left = NULL;
    TreeNode *right = NULL;

    TreeNode(int val) { this->val = val; };
};

#endif // TREE_NODE_H
