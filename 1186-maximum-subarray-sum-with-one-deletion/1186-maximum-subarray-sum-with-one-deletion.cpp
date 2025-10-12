class Solution {
public:
    int maximumSum(vector<int>& arr) {
        //modified kadane
        //dp with 2 states -> either directly extend or delete and modify
        int n = arr.size(), ans = INT_MIN;

        //dp[i][flag] -> stores max sum ending at index i anf flag tells has 2 states 0 and 1
        //1 if we have deleted a sum till now, we cant delete one more and 0 means we can delete the sum
        if(n == 1) return arr[0];
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = arr[0];
        dp[0][1] = 0; 
        //dp[i][0]: max subarray sum ending at i without any deletion
       // dp[i][1]: max subarray sum ending at i with one deletion already done
        for(int i = 1; i < n; i++) {
            dp[i][0] = max(arr[i], dp[i - 1][0] + arr[i]); //classic kadane start or extend
            //for dp[i][1], either I can delete this or extend it
            dp[i][1] = max(dp[i - 1][1] + arr[i], dp[i - 1][0]); //pehla is extend, doosra is delete kardia
            //agar isko delete kar rha hu toh pura sum carry hoga till prev index with no deletion as deletion yaha hui h i.e dp[i - 1][0];
            ans = max({ans, dp[i][0], dp[i][1]});
        }
        return ans;
    }
};