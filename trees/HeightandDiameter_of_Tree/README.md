# Finding the Depth of a Binary Tree

This document explains how to find the depth of a binary tree using two methods: recursion and level order traversal.

## Level Order Traversal

For level order traversal, we can count the number of levels. We traverse through the levels and track the depth by counting the number of levels traversed. At each level, we pop the nodes and push their left and right children, incrementing the depth counter as we explore.

### Time Complexity

- **O(N)** where N is the number of nodes in the binary tree. This complexity arises from visiting each node exactly once during the traversal to determine the maximum depth.

## Using Recursion

Let's have faith in recursion and assume that we are already given the maximum depth of the root's left and right subtrees by recursion. 
To find the maximum depth of this binary tree, we will take the maximum of the two depths given to us by recursion and add 1 to that to consider the current level (i.e., the root's level) into our depth.

### Base Case

If we are at a leaf node as the root, then its left and right subtrees will have 0 depth, and consequently, this leaf node will have a maximum depth of 1.

### Time Complexity

- **O(N)** as we are traversing all the nodes of the tree.

### Space Complexity

- **O(height of the tree)** for the recursive stack.

## Example Code

### Level Order Traversal
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
    int maxDepth(TreeNode* root) {
        int depth=0;
        queue<TreeNode*> q;
        if(root==nullptr) return 0;
        q.push(root);

        while(!q.empty())
        {
            vector<int> level;
            for(int i=0;i<q.size();i++)
            {
                root=q.front();
                q.pop();
                level.push_back(root->val);

                //This loop will run for size of queue each time,so after every loop,
                //The queue would contain left and right children of the root
                if(root->left!=nullptr) q.push(root->left);
                if(root->right!=nullptr) q.push(root->right);
            }
            depth++;
        }
        return depth;
    }
};

### Using Recursion
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
};