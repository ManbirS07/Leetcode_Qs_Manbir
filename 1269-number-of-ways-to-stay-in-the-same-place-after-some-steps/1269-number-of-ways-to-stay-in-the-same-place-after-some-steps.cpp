class Solution {
public:
    typedef long long ll;
    int mod = 1e9 + 7;
    int numWays(int steps, int len) {
        int maxPos = min(steps, len);
        vector<vector<ll>> dp(steps + 1, vector<ll>(maxPos + 1, 0));
        //dp[step][position] -> ways to reach position using step steps
        dp[0][0] = 1;
        // dp[1][0] = 1; //at position 0 with one step -> stay
        // dp[1][1] = 1; //at position 1 with one step -> stay

        for(int step = 1; step <= steps; step++) { //har step me mai position ke saath 3 changes kar skta hu
            for(int i = 0; i < maxPos; i++) {
                ll ways = 0;
                //moving left
                if (i > 0) ways = (ways + dp[step - 1][i - 1]) % mod;
                //moving right
                if (i < maxPos) ways = (ways + dp[step - 1][i + 1]) % mod;
                //ye esse kaam kar rha h ki left right ko ulta kar dia h
                //DP is not simulating forward moves.

                // Instead, we’re asking:
                // “How many ways could I have arrived at pos at step t?”

                // So we look at all possible previous positions that could land us here in 1 move:

                // If you were at pos before → stay.

                // If you were at pos-1 before → moved right into pos.

                // If you were at pos+1 before → moved left into pos.

                // That’s why we check pos+1.

                //So checking pos+1 is just saying:
                // Maybe I was at the right side before, and I moved left to arrive here.”
                ways = (ways + dp[step - 1][i]) % mod;

                dp[step][i] = ways;
            }
        }
        return dp[steps][0];   
    }
};