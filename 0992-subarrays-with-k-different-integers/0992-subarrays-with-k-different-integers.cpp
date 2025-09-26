class Solution {
public:
    int atmostk(vector<int>& nums, int k, unordered_map<int, int>& mp) {
        int i = 0, j = 0, n = nums.size();

        int ans = 0;
        while(j < n) {
            mp[nums[j]]++;
            while(mp.size() > k) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }

            ans += (j - i + 1);
            j++;
        }
        return ans;
    }
    int atmostkminusone(vector<int>& nums, int k, unordered_map<int, int>& mp2) {
        int i = 0, j = 0, n = nums.size();

        int cnt = 0;
        while(j < n) {
            mp2[nums[j]]++;
            while(mp2.size() > k - 1) { //<= k - 1 distinct integers only
                mp2[nums[i]]--;
                if(mp2[nums[i]] == 0) mp2.erase(nums[i]);
                i++;
            }
            cnt += (j - i + 1);
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //subarrays with exact k = subarrays with atmost(k) - atmost(k - 1)
        int n = nums.size();
        unordered_map<int, int> mp1, mp2;

        return atmostk(nums, k, mp1) - atmostkminusone(nums, k, mp2);
    }
};