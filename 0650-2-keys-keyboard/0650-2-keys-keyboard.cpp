class Solution {
public:
    int dp[1001][1001];
    int solve(int n, int curr, int clip) {
        if(curr == n) return 0;
        if(curr > n) return 1e9; //zyada bhi nhi chalega
        if(dp[curr][clip] != -1) return dp[curr][clip];

        int ans = 1e9;

        if(clip != curr) { //baar baar copy karenge toh infinite recursion -> we should copy only when it is useful
            ans = min(ans, 1 + solve(n, curr, curr));
        }

        //we paste only if clipboard has something
        if(clip > 0) {
            ans = min(ans, 1 + solve(n, curr + clip, clip));
        }

        return dp[curr][clip] = ans;
    }

    int minSteps(int n) {
        if(n == 1) return 0; 
        memset(dp, -1, sizeof(dp));
        return solve(n, 1, 0);
    }
};
