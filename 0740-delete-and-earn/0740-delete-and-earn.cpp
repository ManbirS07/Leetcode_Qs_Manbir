class Solution {
public:
    map<int, int> mp;
    unordered_map<int, int> dp;
    int solve(auto it) {
        if(it == mp.end()) return 0;

        if(dp.count(it->first)) return dp[it->first];
        int take = 0, skip = 0;
        skip = solve(next(it));

        int element = (*it).first;
        int freq = (*it).second;
        //jaise 3 pe hu, toh next I can go to 5 or higher, i.e first element >= nums[i] + 2 ya first element > nums[i] + 1
        auto idx = mp.upper_bound(element + 1);
        take = element * freq + solve(idx);
        return dp[element] = max(take, skip);
    }
    int deleteAndEarn(vector<int>& nums) {
        //isme esse h jaise
        //if I delete 2, i would also have to delete 3 so next i would explore 4
        //If i delete 3, i would have skipped till here in one choice and then I cannot explore 4
        for(int x: nums) {
            mp[x]++; //I dont care about duplicates, on deleting an element I will get it's freq * deleted element points, basically we can't take consecutive elements so we would have needed a sorted array without duplicates hence we take a map
        }
        int n = nums.size();
        return solve(mp.begin());
    }
};