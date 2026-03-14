class Solution {
public:
    typedef long long ll;
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll runningSum = 0, sum = 0;
        unordered_map<int, int> mp;

        int i = 0, j = 0;

        while(j < n) {
            runningSum += nums[j];
            mp[nums[j]]++;

            if(j - i + 1 == k) {
                if(mp.size() == k) sum = max(sum, runningSum);
                //shrink by one to shift the window
                runningSum -= nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }

            j++;
        } 
        return sum;
    }
};