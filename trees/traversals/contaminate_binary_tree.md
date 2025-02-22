Given a corrupted binary tree where all node values are initialized to-1, recover the tree such that:

The root node is set to0.
Left child =2 * parent + 1.
Right child =2 * parent + 2.
Implement a classFindElementswith the following methods:

Constructor:Recovers the tree by traversing and recalculating all node values.
find(target):Returnstrueif the target value is present in the recovered tree.
Approach Overview
Recovery:
Recursively set each node's value using the given rules.
Store all recovered values in a data structure (BitSet,set, etc.) for fast lookup.

Finding Values:
Directly check if a target exists in the recovered data structure.

Why This Approach?
Guaranteed Correctness:
The recovery rules ensure each node value is unique and correctly calculated.

Efficient Lookup:
UsingBitSetorsetallowsO(1)lookup time for thefindmethod.

Optimal Time Complexity:

Tree recovery takesO(n)time, wherenis the number of nodes in the tree.
Eachfindoperation takesO(1)time.
Complexity Analysis
Time Complexity:

O(n)for recovery (traverse all nodes once).
O(1)for eachfindoperation.
Space Complexity:

O(n)for storing all recovered node values.
📝 Code Implementations
🔵 Java Solution


class FindElements {
    BitSet recoveredValues;

    public FindElements(TreeNode root) {
        root.val = 0;
        recoveredValues = new BitSet();
        recoverTree(root);
    }

    private void recoverTree(TreeNode root) {
        if (root == null) return;
        recoveredValues.set(root.val);
        if (root.left != null) {
            root.left.val = 2 * root.val + 1;
            recoverTree(root.left);
        }
        if (root.right != null) {
            root.right.val = 2 * root.val + 2;
            recoverTree(root.right);
        }
    }

    public boolean find(int target) {
        return recoveredValues.get(target);
    }
}
🟢 C++ Solution

class FindElements {
    unordered_set<int> recoveredValues;

    void recoverTree(TreeNode* root) {
        if (!root) return;
        recoveredValues.insert(root->val);
        if (root->left) {
            root->left->val = 2 * root->val + 1;
            recoverTree(root->left);
        }
        if (root->right) {
            root->right->val = 2 * root->val + 2;
            recoverTree(root->right);
        }
    }

public:
    FindElements(TreeNode* root) {
        root->val = 0;
        recoverTree(root);
    }

    bool find(int target) {
        return recoveredValues.count(target);
    }
};