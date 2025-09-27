class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        //count of atleast k -> count of total subarrays - count of atmost k - 1 subarrays
        int n = s.size();
        int i = 0, j = 0;

        //we need to count subarrays where at most one character has frequency k - 1 i.e all others have frequency less than k
        unordered_map<char,int> mp;
        int ans = 0;
        while(j < n) {
            mp[s[j]]++;

            while(mp[s[i]] > k - 1) {
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            ans += (j - i + 1);
            j++;
        }

        int total = (n * (n + 1)/ 2);
        return total - ans;
    }
};