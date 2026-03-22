/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int prefSum = 0;
    void revInorder(TreeNode* root) {
        if(root == nullptr) return;

        revInorder(root -> right);

        int rootVal = root -> val;
        root -> val += prefSum;
        prefSum += rootVal;

        revInorder(root -> left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        //reverse inorder -> start from right
        //at node, nodeval = nodeval + prefSum
        revInorder(root);
        return root;
    }
};