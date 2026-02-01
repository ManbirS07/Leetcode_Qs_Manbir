class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        //0 means difference is positive, 1 means diff negative
        //O(n) -> greedy

        int pos = 1, neg = 1, res = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                pos = max(pos, 1 + neg);
            } else if(nums[i] < nums[i - 1]) {
                neg = max(neg, 1 + pos);
            }
            res = max({res, pos, neg});
        }
        return res;
    }
};