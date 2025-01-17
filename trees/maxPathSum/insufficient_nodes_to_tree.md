# Insufficient Nodes in Root to Leaf Paths

This document explains the concept and approach to removing insufficient nodes in root-to-leaf paths in a binary tree.

## Problem Statement

Given a binary tree and an integer `limit`, remove all insufficient nodes in root-to-leaf paths. A node is considered insufficient if the sum of the values from the root to that node is less than `limit`.

## Approach

### Detailed Explanation

1. **Recursive Traversal**:
   - Use a recursive function to traverse the tree.
   - Maintain a running sum of the values from the root to the current node.

2. **Base Case**:
   - If the current node is `nullptr`, return `nullptr`.

3. **Leaf Node Check**:
   - If the current node is a leaf node (both left and right children are `nullptr`):
     - Check if the running sum including the current node's value is less than the `limit`.
     - If it is, return `nullptr` to remove the node.
     - Otherwise, return the current node.

4. **Recursive Calls**:
   - Recursively call the function for the left and right children of the current node.
   - Update the left and right children of the current node based on the results of the recursive calls.

5. **Post-Recursive Check**:
   - After the recursive calls, if both left and right children of the current node are `nullptr`, return `nullptr` to remove the node.
   - Otherwise, return the current node.

### Time Complexity

- **O(n)**: We traverse each node exactly once.

### Space Complexity

- **O(h)**: The space required for the recursion stack, where `h` is the height of the tree.

## Example Code

```cpp
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit, int sum = 0) {
        if (root == nullptr) {
            return nullptr;
        }
        sum += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (sum < limit) {
                return nullptr;
            }
            return root;
        }
        root->left = sufficientSubset(root->left, limit, sum);
        root->right = sufficientSubset(root->right, limit, sum);
        if (root->left == nullptr && root->right == nullptr) {
            return nullptr;
        }
        return root;
    }
};

## Dry Run
Consider the following binary tree and limit value:

      1
     / \
    2   3
   /   / \
  4   5   6

  Steps
Start at the root (1):

Current sum: 1
Move to the left child (2):

Current sum: 3
Move to the left child (4):

Current sum: 7 (leaf node)
Since 7 >= limit, keep the node.
Move to the right child (3):

Current sum: 4
Move to the left child (5):

Current sum: 9 (leaf node)
Since 9 >= limit, keep the node.
Move to the right child (6):

Current sum: 10 (leaf node)
Since 10 >= limit, keep the node.
Return to the root and update the tree structure based on the results of the recursive calls.