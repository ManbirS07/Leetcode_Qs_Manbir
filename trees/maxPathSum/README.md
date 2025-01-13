# Maximum Path Sum in a Binary Tree

The problem is to find the maximum path sum in a binary tree. A path can start and end at any node, so the sum is maximized when considering paths that potentially combine both left and right child subtrees, plus the node itself.

## Concept

It is similar to finding the diameter, but here instead of the length of a U-shaped path, we have to return the value of the maximum path sum.

For each node, check the maximum sum from the left and right subtrees and add the node's own value. The sum of the left and right heights gives the maximum diameter of any node. Adding the value of the root to this sum gives the maximum path sum.

To the parent node, recursively call the left and right child, returning the maximum of `(left height, right height) + node value` to choose the maximum path.

## Approach

1. **Recursive Helper Function**:
   - Implement a helper function that computes the maximum path sum for any subtree.
   - At each node, calculate the maximum path sum including the node and its left and right subtrees.
   - Update the global maximum path sum if the current path sum is greater.
   -return the value of the node + max(left,right) so as to help the parent function to check for another path with the max sum

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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathDown(root, maxSum);
        return maxSum;
    }

    int maxPathDown(TreeNode* node, int &maxSum) {
        if (node == nullptr) return 0;
        int left = max(0, maxPathDown(node->left, maxSum));
        int right = max(0, maxPathDown(node->right, maxSum));
        maxSum = max(maxSum, left + right + node->val);
        return max(left, right) + node->val;
    }
};