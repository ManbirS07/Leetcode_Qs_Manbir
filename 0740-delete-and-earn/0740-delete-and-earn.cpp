class Solution {
public:
    map<int,int> mp;
    unordered_map<int,int> dp; 

    int solve(auto it) {
        if(it == mp.end()) return 0;
        int num = it->first;

        if(dp.count(num)) return dp[num];

        auto nextIt = it; 
        ++nextIt;
        int skip = solve(nextIt);

        auto jumpIt = mp.upper_bound(num + 1); // first element >= num+2
        int take = num * it->second + solve(jumpIt);

        return dp[num] = max(skip, take);
    }

    int deleteAndEarn(vector<int>& nums) {
        for(int num: nums) mp[num]++;
        return solve(mp.begin());
    }
};
