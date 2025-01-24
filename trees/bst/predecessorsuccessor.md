# Predecessor and Successor in Binary Search Tree

This document explains the concept and approach to finding the predecessor and successor of a given key in a Binary Search Tree (BST).

## Problem Statement

Given a Binary Search Tree (BST) and a key, find the predecessor and successor of the key in the BST. The predecessor of a node is the largest node that is smaller than the given key, and the successor of a node is the smallest node that is larger than the given key.

## Approach

1. **Successor**:
   - Initialize the successor as `-1`.
   - Traverse the tree starting from the root.
   - If the key is less than the current node's data, update the successor to the current node's data and move to the left child.
   - If the key is greater than or equal to the current node's data, move to the right child.

2. **Predecessor**:
   - Initialize the predecessor as `-1`.
   - Traverse the tree starting from the root.
   - If the key is less than or equal to the current node's data, move to the left child.
   - If the key is greater than the current node's data, update the predecessor to the current node's data and move to the right child.

3. **Result**:
   - Return a pair containing the predecessor and successor.

### Time Complexity

- **O(h)**: The time complexity is proportional to the height of the tree, where `h` is the height of the BST.

### Space Complexity

- **O(1)**: The space complexity is constant as no additional space is used other than a few variables.

## Example Code

```cpp
#include <utility>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

pair<int, int> predecessorSuccessor(TreeNode *root, int key) {
    int succ = -1;
    int pre = -1;
    pair<int, int> p;
    TreeNode* curr = root;

    // Find successor
    while (curr != nullptr) {
        if (key < curr->data) {
            succ = curr->data;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    // Find predecessor
    curr = root;
    while (curr != nullptr) {
        if (key <= curr->data) {
            curr = curr->left;
        } else {
            pre = curr->data;
            curr = curr->right;
        }
    }

    p.first = pre;
    p.second = succ;
    return p;
}