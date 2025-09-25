class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        //pehle 2 element ko agle wale ke equal bana do
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int target = nums[2];
        nums[0] = target, nums[1] = target;
        
        return nums[n - 1] - nums[1];
    }
};