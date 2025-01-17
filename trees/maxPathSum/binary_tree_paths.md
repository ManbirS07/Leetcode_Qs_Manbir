# Binary Tree Paths

This document explains the concept and approach to finding all root-to-leaf paths in a binary tree.

## Problem Statement

Given the root of a binary tree, return all root-to-leaf paths in the tree. A leaf is a node with no children.

## Approach

### Detailed Explanation

1. **Recursive Traversal**:
   - Use a recursive function to traverse the tree.
   - Maintain a string `ss` to store the current path from the root to the current node.

2. **Base Case**:
   - If the current node is `nullptr`, return.

3. **Leaf Node Check**:
   - If the current node is a leaf node (both left and right children are `nullptr`):
     - Append the current node's value to the path string `ss`.
     - Add the path string `ss` to the result list `ans`.
     - Return to backtrack.

4. **Recursive Calls**:
   - Append the current node's value to the path string `ss` followed by "->".
   - Recursively call the function for the left and right children of the current node.

### Time Complexity

- **O(n)**: We traverse each node exactly once.

### Space Complexity

- **O(h)**: The space required for the recursion stack, where `h` is the height of the tree.

## Example Code

```cpp
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void solve(TreeNode* root, vector<string> &ans, string ss) {
        if (root == nullptr) return;
        root->left == nullptr && root->right == nullptr ? ss += to_string(root->val) : ss += (to_string(root->val) + "->");
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(ss);
            return;
        }
        solve(root->left, ans, ss);
        solve(root->right, ans, ss);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string ss = "";
        solve(root, ans, ss);
        return ans;
    }
};