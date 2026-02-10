class Solution {
public:
    int solve(int idx, vector<int>& startTime, vector<int>& endTime,
              vector<int>& profit, int n) {
        if (idx >= n)
            return 0;

        int currStartTime = startTime[idx];
        int currEndTime = endTime[idx];
        int currProfit = profit[idx];

        int skipJob = solve(idx + 1, startTime, endTime, profit, n);
        int doJob = currProfit;

        // finding next possible job i.e job whose startTime >= endTime of
        // current job
        auto it = lower_bound(begin(startTime), end(startTime), currEndTime);
        if (it != startTime.end()) {
            int nextJobIdx = it - startTime.begin();
            doJob += solve(nextJobIdx, startTime, endTime, profit, n);
        }
        return max(doJob, skipJob);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // dp with binary search
        int n = startTime.size();
        vector<vector<int>> jobs;

        for(int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        //sorting by startTime
        sort(jobs.begin(), jobs.end());

        vector<int> starts;
        for(auto &j : jobs) starts.push_back(j[0]);

        vector<int> dp(n + 1, 0);

        // base case
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            int currStartTime = jobs[i][0];
            int currEndTime = jobs[i][1];
            int currProfit = jobs[i][2];

            int skipJob = dp[i + 1];
            int doJob = currProfit;

            // finding next possible job i.e job whose startTime >= endTime of
            // current job
            auto it = lower_bound(begin(starts), end(starts), currEndTime);
            if (it != starts.end()) {
                int nextJobIdx = it - starts.begin();
                doJob += dp[nextJobIdx];
            }
            dp[i] = max(doJob, skipJob);
        }

        return dp[0];
    }
};