class Solution {
public:
    typedef long long ll;
    int minRemoval(vector<int>& nums, int k) {
        //sliding window 
        int n = nums.size();
        if(n == 1) return 0; //always valid, no elements to remove

        int maxLen = 0;
        int i = 0, j = 1;

        sort(begin(nums), end(nums));
        while(j < n) {
            while(ll(nums[j]) > (1LL * nums[i] * k)) {
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return n - maxLen; //maxLen is the maximum length of a valid window, baaki remove karne padenge
    }
};