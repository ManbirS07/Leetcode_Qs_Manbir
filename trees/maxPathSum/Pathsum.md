# Path Sum in a Binary Tree

This document explains the concept and approach to finding all root-to-leaf paths in a binary tree where each path's sum equals a given target sum.

## Concept

The goal is to find all paths from the root to leaf nodes where the sum of the node values in each path equals the target sum. This involves traversing the tree and keeping track of the current path and its sum.

We will maintain a vector to store the nodes as we traverse and a sum variable to keep adding the values
When we reach a leaf node,we will check if the sum==targetsum
If yes,we will add the vector containing all nodes to the vector ans
If not,we will remove the value of leaf node from sum and vector and return to go to another child
and then check the sum (backtrack)

## Approach

1. **Recursive Traversal**:
   - Use a recursive helper function to traverse the tree.
   - Maintain a running sum and a temporary list to store the current path.
   - At each node, add the node's value to the running sum and the current path.
   - If a leaf node is reached and the running sum equals the target sum, add the current path to the result list.
   - Backtrack by removing the current node's value from the running sum and the current path.

### Time Complexity

- **O(n)**: We explore every node exactly once.

### Space Complexity

- **O(h)**: Space depends on the tree height for recursion.

## Example Code

```cpp
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> ans;
    void solve(TreeNode* root, int &sum, vector<int>& temp, int &targetSum) {
        if (root == nullptr) return;
        sum += root->val;
        temp.push_back(root->val);

        // Checking target sum at leaf nodes
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == targetSum) ans.push_back(temp);
            temp.pop_back();
            sum -= root->val;
            return;
        }

        solve(root->left, sum, temp, targetSum);
        solve(root->right, sum, temp, targetSum);

        sum -= root->val;
        temp.pop_back();
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int> temp;
        solve(root, sum, temp, targetSum);
        return ans;
    }
};



Dry Run Example
Consider the following binary tree and target sum of 22:
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1

Steps
Start at the root (5):

Current path: [5]
Current sum: 5
Move to the left child (4):

Current path: [5, 4]
Current sum: 9
Move to the left child (11):

Current path: [5, 4, 11]
Current sum: 20
Move to the left child (7):

Current path: [5, 4, 11, 7]
Current sum: 27 (not a leaf, backtrack and remove 7 from array)
Move to the right child (2):

Current path: [5, 4, 11, 2]
Current sum: 22 (leaf node, path found)
Backtrack and explore the right subtree of the root (8):

Continue similar steps...