class Solution {
public:
    int solve(int idx, char prev, string& s) {
        int n = s.size();
        if (idx >= n)
            return 0;
        char curr = s[idx];

        int flip = 1e9, skip = 1e9;
        // if i saw 1, cant flip it to 0 anyway
        if (s[idx] == '1') {
            if (prev == '0') {
                flip = min(flip, 1 + solve(idx + 1, '0', s));
                skip = min(skip, solve(idx + 1, '1', s));
            } else {
                // cant flip here
                skip = min(skip, solve(idx + 1, '1', s));
            }
        } else {
            if (prev == '0') {
                // 00
                flip = min(flip, 1 + solve(idx + 1, '1', s));
                skip = min(skip, solve(idx + 1, '0', s));
            } else {
                // 10, flip hi karna padega
                flip = min(flip, 1 + solve(idx + 1, '1', s));
            }
        }
        return min(flip, skip);
    }
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        // solve(0, '0', s); // monotonic hone ke liye 0 se hi start hona chahiye sequence
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // base case
        for (int i = 0; i < 2; i++) {
            dp[n][i] = 0;
        }

        for (int i = n - 1; i >= 0; i--) {
            char curr = s[i];
            for (int prev = 0; prev < 2; prev++) {
                int flip = 1e9, skip = 1e9;
  
                if (curr == '1') {
                    if (prev == 0) {
                        flip = min(flip, 1 + dp[i + 1][0]);
                        skip = min(skip, dp[i + 1][1]);
                    } else {
                        skip = min(skip, dp[i + 1][1]);
                    }
                } 


                else {
                    if (prev == 0) {
                        // 00
                        flip = min(flip, 1 + dp[i + 1][1]);
                        skip = min(skip, dp[i + 1][0]);
                    } else {
                        // 10, flip hi karna padega
                        flip = min(flip, 1 + dp[i + 1][1]);
                    }
                }
                dp[i][prev] = min(flip, skip);
            }
        }
        return dp[0][0];
    }
};