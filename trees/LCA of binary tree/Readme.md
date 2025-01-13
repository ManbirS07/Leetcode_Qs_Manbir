# Lowest Common Ancestor (LCA) of a Binary Tree

This document explains the concept and approach to finding the Lowest Common Ancestor (LCA) of two nodes in a binary tree.

## Concept

The Lowest Common Ancestor (LCA) of two nodes `p` and `q` in a binary tree is defined as the lowest node that has both `p` and `q` as descendants (where we allow a node to be a descendant of itself).

## Approach

1. **Recursive Traversal**:
   - Use a recursive function to traverse the tree.
   - At each node, check if it is one of the target nodes (`p` or `q`).
   - Recursively search for `p` and `q` in the left and right subtrees.
   - If both subtrees return non-null values, the current node is the LCA.
   - If only one subtree returns a non-null value, propagate that value up the recursion stack.

### Time Complexity

- **O(n)**: We explore every node exactly once.

### Space Complexity

- **O(h)**: Space depends on the tree height for recursion.

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
    
    TreeNode* bfs(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if (root==nullptr) return nullptr;

        //we check ki kya hamara root p ya q ke barabar h
        //agar h toh ussi ko return kardo
        //This is for the node
        if(root==p || root==q) return root;

        //ab mai left aur right me dekhunga p ya q mile toh
        TreeNode* lh=bfs(root->left,p,q);
        TreeNode* rh=bfs(root->right,p,q);

        //yaha tak left aur right child ham traverse kar chuke h
        //ya toh hame ek side se nullptr aur ek side se p/q mila hoga
        //ya ek side se p ek side se q
        //in the latter case,we return the value of root kyuki wahi LCA h

        //This is when parent receives either p and q or null from it's children
        if(lh!=nullptr && rh!=nullptr) return root;

        if(lh!=nullptr) return lh;

        return rh;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root==nullptr) return nullptr;
        TreeNode* ans=bfs(root,p,q);
        return ans;
    }
};