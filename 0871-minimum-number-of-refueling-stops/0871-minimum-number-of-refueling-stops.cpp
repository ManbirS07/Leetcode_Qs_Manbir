class Solution {
public:
    typedef unsigned long long ull;
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<vector<ull>> dp(n+1, vector<ull>(n+1, 0));
        //dp[i][j] -> max distance reached if i used j stops out of i
        //if j = 0, it means i didnt use any fuelstop so the max i canr each is startfuel only
        for(int i = 0; i <= n; i++) {
            dp[i][0] = startFuel;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                //i dont refuel here
                dp[i][j] = dp[i-1][j];

                //i refill here but only if i can reach this station -> j - 1 because abhi refill nhi kiya h maine yaha
                if(dp[i-1][j-1] >= stations[i-1][0]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + stations[i-1][1]); //ith station rep by i - 1
                }
            }
        }

         //After i end up with all stations,i need to  check which t[n][j] was best for reaching target
        //best means, minimum j used by me to reach target
        for(int j = 0; j<n+1; j++) {
            if(dp[n][j] >= target)
                return j;
        }
        
        //You could never reach target, so return -1
        return -1;
    }
};