class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();

        vector<int> mainFreq(128, 0);
        vector<int> freq(128, 0);

        for(char ch: t) {
            freq[ch - 'A']++;
        }

        int i = 0, j = 0;
        int minLen = INT_MAX, startIdx = -1;

        while(j < n) {
            mainFreq[s[j] - 'A']++;

            while(true) {
                bool flag = true;
                //checking if all characters of t are present so I can trim
                for(int k = 0; k < 128; k++) {
                    if(mainFreq[k] < freq[k]) {
                        flag = false;
                        break;
                    }
                }

                if(!flag) break;
                //else start trimming
                if(j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    startIdx = i;
                }

                mainFreq[s[i] - 'A']--;
                i++;
            }

            j++;
        }
        return startIdx == -1 ? "" : s.substr(startIdx, minLen);
    }
};