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
    vector<vector<int>>ans;
    void solve(TreeNode* root,int &sum,vector<int>&temp,int &targetSum)
    {
        if(root==nullptr) return;
        sum+=root->val;
        temp.push_back(root->val);
       

        //Checking target sum at leaf nodes
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==targetSum) ans.push_back(temp);
            temp.pop_back();
            sum-=root->val;
            return;
        }

        solve(root->left,sum,temp,targetSum);
        solve(root->right,sum,temp,targetSum);
    
        sum-=root->val;
        temp.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int> temp;
        solve(root,sum,temp,targetSum);
        return ans;
    }
};