# Children Sum Property in a Binary Tree

This document explains the concept and approach to ensuring the Children Sum Property in a binary tree.

## Concept

The Children Sum Property states that for every node in a binary tree, the node's value should be equal to the sum of its children's values. 
If a node does not have children, it is considered to have a value of 0.

## Intuition

While going down, increase the children values so we make sure to never fall short,
then all we have to do is sum both children and replace it in parent.

1. **Adjust Children's Values**:
   - If both children's sum is less than the parent's value, make the children's values equal to the parent's value.
   - If both children's values sum is greater than or equal to the parent's value, make the parent's value equal to the children's sum.

2. **Recursive Traversal**:
   - Use Depth-First Search (DFS) to traverse the tree.
   - When coming back up the tree, take the sum of the children and replace it in the parent.

3. **Base Case**:
   - If we reach a null node, just return.

## Approach

1. Traverse the tree using DFS.
2. Adjust the children's values while going down the tree to ensure we never fall short.
3. Sum both children and replace it in the parent when coming back up the tree.

## Example Code

```cpp
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void childrenSumProperty(TreeNode* root) {
        if (root == nullptr) return;

        int childSum = 0;
        if (root->left) childSum += root->left->val;
        if (root->right) childSum += root->right->val;

        //if sum of children greater than that of root,make value of root equal to childsum
        if(childSum>=root->val) root->val=childSum;

        //if sum of children less than root,make the value of children equal to that of parent
       else {
            if (root->left) root->left->val = root->val;
            if (root->right) root->right->val = root->val;
        }

        childrenSumProperty(root->left);
        childrenSumProperty(root->right);

        int totalSum = 0;
        if (root->left) totalSum += root->left->val;
        if (root->right) totalSum += root->right->val;

        if (root->left || root->right) root->val = totalSum;
    }
};