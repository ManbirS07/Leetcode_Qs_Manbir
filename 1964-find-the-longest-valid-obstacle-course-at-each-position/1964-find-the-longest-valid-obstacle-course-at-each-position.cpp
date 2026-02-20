class Solution {
public:
    // Lis at each index
    // dp me state hoga ki dp[i] -> length of LIS ending at i
    // jaise 1,2,3,2 me in a map I'll store
    // 1 -> 1, means length of longest LIS ending at 1 is 1
    // for 2, I'll check largest vales <= 2, jo iss case me h 1
    // so dp[2] would be 1 + dp[1] = 2
    // in case of duplicates, obviously value would get increased each time so
    // store the new value (since <=)

    // dp should stay monotonic
    // keys as well as values should always remain increasing
    // like 4 -> LIS = 4
    //      5 -> LIS = 3 breaks
    // if obstacle val = 6, it should take the one with 4 not 5 right
    // so, after computing 4 with LIS 4, we see 5 with a smaller value and erase
    // it and any more values also greater than 4 with smaller LIS to maintain
    // increasing nature

    // Cleaning rule

    // After inserting obstacle:

    // remove all future keys where:
    // value > obstacle AND dp[value] <= dp[obstacle]

    // This keeps:
    // as value increases → LIS strictly increases
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n, 1);
        map<int, int> dp;

        for (int i = 0; i < n; i++) {
            int obstacle = obstacles[i];

            auto it = dp.upper_bound(obstacle);
            int best = 1;

            if (it != dp.begin()) {
                --it;
                best = 1 + it->second;
            }

            dp[obstacle] = max(dp[obstacle], best);

            ans[i] = dp[obstacle];

            // cleaning all those values jinki value haa badi h but LIS chota h
            auto it2 = dp.upper_bound(obstacle);

            while (it2 != dp.end() && it2->second <= dp[obstacle]) {
                it2 = dp.erase(it2);
            }
        }
        return ans;
    }
};