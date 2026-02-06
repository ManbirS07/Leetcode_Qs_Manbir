class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int maxLen = 0;

        int minEle = *min_element(begin(nums), end(nums));
        int maxEle = *max_element(begin(nums), end(nums));
        int minIdx = -1, maxIdx = -1;
        while(j < n) {
            if(nums[j] == minEle) {
                minIdx = j;
            }

            if(nums[j] == maxEle) {
                maxIdx = j;
            }

            while(minIdx != -1 && maxIdx != -1 && nums[i] != minEle && nums[i] != maxEle) {
                i++;
                maxLen = j - i + 1;
            }

            if(minIdx != -1 && maxIdx != -1) break;

            j++;
        }
        cout << maxLen << " " << i << " " << j;
        return min({n - i + 1, j + 1, n - maxLen + 2}); //right me h dono values, left me h dono values, beech me h dono values
    }
};