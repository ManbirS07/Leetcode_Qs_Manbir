class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();

        int i = 0;
        if(s1 == s2) return true;

        //what i did was simply store the frequency of all character in string 1
        //if i found a mismatch, i first checked does the mismatched character in string s2 occur in s1? if not it can never be reached via swap else i increased the cnt
        //at last, i checked if count = 2, i can swap the 2 indices hence return true

        unordered_map<char, int> mp, mp2;
        for(char ch: s1) {
            mp[ch]++;
        }

        for(char ch: s2) {
            mp2[ch]++;
        }
        if(mp != mp2) return false;

        int cnt = 0;
        while(i < n) {
            if(s1[i] != s2[i]) {
                if(mp.find(s2[i]) == mp.end()) return false;
                cnt++;
            }
            i++;
        }
        return cnt == 2;
    }
};