class Solution {
public:
    int solve(int i, string s, int n) {
        if(i >= n) return 1; //valid partition

        int ans = 0, num = 0;
        for(int j = i; j < n; j++) {
            num = (num * 10) + s[j] - '0';

            if(num > 26) break; //not valid
            ans += solve(j + 1, s, n);
        }
        return ans;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        dp[n] = 1;
        for(int i = n - 1; i >= 0; i--) { //O(n)
            int ans = 0, num = 0;

            if(s[i] == '0') continue; //0 se start hone wala koi bhi mapping not valid

    //Since valid numbers are only 1 to 26, the number formed can have at most 2 digits.
    //So from any index i:
    //j = i → 1-digit number 
    //j = i+1 → 2-digit number maybe 
    //j = i+2 → number ≥ 100 so break immediately

    //Therefore inner loop runs at most 2 iterations.
            for(int j = i; j < n; j++) {
                num = (num * 10) + s[j] - '0';

                if(num > 26) break;
                ans += dp[j + 1];
            }

            dp[i] = ans;
        }
        return dp[0];
    }
};