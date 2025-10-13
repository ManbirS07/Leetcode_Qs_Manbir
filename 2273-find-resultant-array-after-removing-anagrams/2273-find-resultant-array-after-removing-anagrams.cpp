class Solution {
public:
    bool checkAnagrams(string &a, string &b) {
        vector<int> v(26, 0), p(26, 0);

        for(char ch: a) {
            v[ch - 'a']++;
        }

        for(char ch: b) {
            p[ch - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(v[i] != p[i]) return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();

        vector<string> ans;
        ans.push_back(words[0]);

        for(int i = 1; i < n; i++) {
            if(checkAnagrams(words[i], words[i - 1])) continue;
            ans.push_back(words[i]);
        }
        return ans;
    }
};