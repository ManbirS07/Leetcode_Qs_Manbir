class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> res;

        for(int i = 0; i < n; i++) {
            //removing all invalid elements
            while(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            //removing all smaller elements
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i); //front me hamesha sabse bada element rahega
            //agar ye sabse bada element h in window, toh iske pehle deque empty hogyi hogi
            //warna iske aage bhi (front) me ek bada element present hoga

            if(i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};