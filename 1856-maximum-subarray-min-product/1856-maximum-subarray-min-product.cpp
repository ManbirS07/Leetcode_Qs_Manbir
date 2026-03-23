class Solution {
public:
    int mod = 1e9 + 7;
    int maxSumMinProduct(vector<int>& nums) {
        // monotonic stack me count contribution of each element
        int n = nums.size();
        vector<long long> prefSum(n, 0);
        prefSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

        stack<int> st;
        vector<int> left(n, -1), right(n, n);

        // next smaller element on left
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] <= nums[st.top()]) {
                st.pop();
            }

            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        // re-using the stack
        while (!st.empty())
            st.pop();

        // next smaller element on right
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] < nums[st.top()]) {
                st.pop();
            }

            if (st.empty())
                right[i] = n; // no smaller element on the right
            else
                right[i] = st.top();

            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int l = left[i] + 1;
            int r = right[i] - 1;

            long long sum = prefSum[r] - (l > 0 ? prefSum[l - 1] : 0);
            ans = max(ans, sum * nums[i]);
        }
        return ans % mod;
    }
};