class Solution {
public:
    //dp[i] = longest length of obstacle course ending at val[i]
    //LIS -> with concept of cleaning up
    //jaise 2 pe end hone wale pe longest obstacle ke length 
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        map<int, int> dp;
        vector<int> ans(n, 1);

        //try to extend each sequence 
        //finding 1 + smallest value <= x
        for(int i = 0; i < n; i++) {
            int obstacle = obstacles[i];
            auto it = dp.upper_bound(obstacle);
            int best = 1;

            if(it == dp.begin()) {
                dp[obstacle] = 1;
            } else {
                --it;
                int nearest = it -> second;
                best = 1 + nearest; 
            }

            dp[obstacle] = max(dp[obstacle], best);
            ans[i] = dp[obstacle];
            //aage agar koi element h jiski value badi h but LIS chota, it removes monotonicity
            auto it2 = dp.upper_bound(obstacle);
            while(it2 != dp.end() && it2 -> second <= dp[obstacle]) {
                it2 = dp.erase(it2);
            }
        }
        return ans;
    }
};