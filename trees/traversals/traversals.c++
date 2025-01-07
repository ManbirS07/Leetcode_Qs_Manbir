//iterative preorder
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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        if(root==nullptr) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            root=st.top();
            st.pop();
            ans.push_back(root->val);

            if(root->right!=nullptr) st.push(root->right);
            if(root->left!=nullptr) st.push(root->left);
        }
        return ans;

    }
};

//iterative inorder
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;

        stack<TreeNode*>st;
        while(root || !st.empty())
        {
            while(root!=nullptr)
            {
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            ans.push_back(root->val);
            root=root->right;
        }
        return ans;
    }
};

//level order
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        //sabse pehle make an array of ans
        vector<vector<int>>ans;
        if(root==nullptr) return ans;
        //start by initialising the queue to store nodes
        queue <TreeNode*> q;
        q.push(root);
        //for every iteration till queue is not empty,make a list and add elements of queue in that
        //before popping, add children of node in the queue

        //size of q is dynamic every-time and 
        //the for loop is running for every level i.e putting the value of parent nodes
        //in temp vector and then enqueeing children of each level
        while(!q.empty())
        {
            vector<int> temp;
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);

                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};