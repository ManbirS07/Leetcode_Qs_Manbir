class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int wordLen = words[0].size();
        int windowSizeReqd = words.size() * wordLen;

        unordered_map<string, int> wordFreq;
        vector<int> indices;

        for (string word : words) {
            wordFreq[word]++;
        }

        for (int k = 0; k < wordLen; k++) { //try starting from each index
            unordered_map<string, int> currWindowFreq;
            int i = k, j = k - 1; //words mai k se hi lena chalu karunga

            while (j + wordLen < n) {
                string currWord = s.substr(j + 1, wordLen);
                currWindowFreq[currWord]++;
                j += wordLen;

                if (j - i + 1 == windowSizeReqd) {
                    if (currWindowFreq == wordFreq) {
                        indices.push_back(i);
                    }

                    string wordToErase = s.substr(i, wordLen);
                    currWindowFreq[wordToErase]--;
                    if (currWindowFreq[wordToErase] == 0) currWindowFreq.erase(wordToErase);
                    i += wordLen;
                }
            }
        }
        return indices;
    }
};