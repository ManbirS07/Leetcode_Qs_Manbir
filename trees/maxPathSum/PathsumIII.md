# Path Sum III in a Binary Tree

This document explains the concept and approach to finding all paths in a binary tree that sum to a given target value.

## Intuition

The problem requires finding all paths in the binary tree that sum to the target value. Since paths can start and end at any node, a prefix sum approach can efficiently identify paths by tracking the cumulative sum of values from the root to the current node.

By using a prefix sum map, we can calculate how many sub-paths (up to the current node) have sums equal to `prefixSum - targetSum`. This allows us to count all valid paths ending at the current node.

## Approach

1. **Depth First Search (DFS)**:
   - Traverse the tree using a DFS approach.
   - Maintain a running prefix sum while traversing the tree.
   - Use an unordered map to store the frequency of prefix sums encountered so far.

2. **At Each Node**:
   - Check if the current prefix sum minus the target sum exists in the map. If it does, the frequency indicates the number of valid paths ending at the current node.
   - Update the prefix sum map with the current prefix sum.
   - Recursively traverse the left and right subtrees.
   - After traversing, decrement the frequency of the current prefix sum in the map to backtrack.

   ### While coming back from recursion(backtracking) we will remove the prefixSum corresponding to the node from where we are returning as we are not considering the node,so why to consider the contribution for the next nodes?

### Time Complexity

- **O(n)**: We explore every node exactly once.

### Space Complexity

- **O(n)**: Space for the prefix sum map.

## Example Code

```cpp
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
    void dfs(TreeNode* root,int targetSum,unordered_map<long long,long long>& mp,int &ans,long long prefixSum){
        if(!root)return;

        prefixSum += root->val;

        if(mp.find(prefixSum-targetSum)!=mp.end()){
            ans += mp[prefixSum-targetSum];
        }

        mp[prefixSum]++;

        dfs(root->left,targetSum,mp,ans,prefixSum);
        dfs(root->right,targetSum,mp,ans,prefixSum);

        mp[prefixSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        int ans=0;
        int prefixSum=0;
        unordered_map<long long,long long> mp;

        mp[0]=1;
        dfs(root,targetSum,mp,ans,0);

        return ans;
    }
};