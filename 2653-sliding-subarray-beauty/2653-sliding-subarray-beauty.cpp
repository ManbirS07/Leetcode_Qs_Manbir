class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        // can't use a monotonic queue or deque here as they are efficient in
        // only finding the smallest or largest -> xth smallest ke liye nikalne
        // padenge from front and back -> wrong

        // since range of nums is less, we can maintain frequency of each -ve
        // element as we are interested in only -ve numbers

        int n = nums.size();
        vector<int> res;
        vector<int> freq(51, 0);

        int i = 0, j = 0;
        while (j < n) {
            if (nums[j] < 0)
                freq[nums[j] + 50]++;

            if (j - i + 1 == k) {
                int cnt = 0;

                for (int l = 0; l <= 50; l++) {
                    cnt += freq[l];

                    if (cnt >= x) {
                        res.push_back(l - 50);
                        break;
                    }
                }

                if (cnt < x)
                    res.push_back(0);
                if (nums[i] < 0) freq[nums[i] + 50]--;
                i++;
            }
            j++;
        }
        return res;
    }
};