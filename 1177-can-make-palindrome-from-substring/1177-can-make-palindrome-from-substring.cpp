class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<bool> res;
        vector<vector<int>> pref(n); //pref[i] stores freq of each char till now (till ith character)
        //for making palindrome, even freq wale dont matter
        //but the character for odd frequency should just be 1
        //so I'll try ki kya mai odd frequency wale characters ko sirf ek character with odd freq bana skta?

        vector<int> freq(26, 0);
        for(int i = 0; i < n; i++) {
            int currChar = s[i] - 'a';
            freq[currChar]++;
            pref[i] = freq;
        }

        for(auto q: queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];

            vector<int> currFreq(26);
            if(l == 0) currFreq = pref[r];
            else {
                for(int i = 0; i < 26; i++) {
                    currFreq[i] = pref[r][i] - pref[l - 1][i];
                }
            }

            int oddCnt = 0;
            for(int i = 0; i < 26; i++) {
                if(currFreq[i] % 2 != 0) oddCnt++;
            } 
            
            int ops = (oddCnt / 2); //jaise 4 h with odd frequency, toh I need value of k = 2 to replace to make them even atlest
            bool queryRes = (ops <= k) ? true: false;
            res.push_back(queryRes);
        }
        return res;
    }
};