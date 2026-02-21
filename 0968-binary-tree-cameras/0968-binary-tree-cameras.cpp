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
private:
    int cameras = 0;
public:
    int solve(TreeNode* root) {
        if(root == nullptr) return 1;

        int left = solve(root -> left);
        int right = solve(root -> right);

        if(left == -1 || right == -1) {
            cameras++;
            return 0; //yaha pe camera lagana padega
        }

        if(left == 0 || right == 0) {
            //it means this node is already covered
            return 1;
        }

        return -1; //the only case where both left and right se 1 aayga
        //it means I need a camera now, will ask my parent to place a camera
    }
    int minCameraCover(TreeNode* root) {
        //1 -> I am covered and I dont need a camera
        //0 -> I myself have a camera
        //-1 -> I need a camera asap
        int minCameras = solve(root);
        if(minCameras == -1) return 1 + cameras; //root ko khudko chahiye ek camera -> when uske both children already covered and dono pe hi no camera
        return cameras;
    }
};