class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();

        unordered_map<int, int> mp;
        for(int t: time) {
            t = t % 60;
            mp[t]++; //storing {rem, count}
        }

        long long ans = 0;
        for(auto &it: mp) {
            if(it.first > 30) continue; //only this first 30 with it's complement to avoid double counting

            else if(it.first == 30 || it.first == 0)  {
            int val = it.second;
            ans += (1LL * val * (val - 1)) / 2; //total pairs khud ke saath = n * (n - 1) / 2
            }

            else {
                int first = it.first;
                int freq = it.second;

                if(mp.find(60 - first) != mp.end()) {
                    ans += (mp[60 - first] * freq); //jaise 20, 40, 40 h toh number of pairs = 1 * 2 = 2
                }
            }
        }
        return ans;
    }
};