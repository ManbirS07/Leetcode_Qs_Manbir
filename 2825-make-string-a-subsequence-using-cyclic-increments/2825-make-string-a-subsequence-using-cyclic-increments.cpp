class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();

        //like edit distance
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(str1[i] == str2[j]) {
                i++;
                j++;
            } else {
                char ch = str1[i] == 'z' ? 'a': str1[i] + 1;
                if(str2[j] == ch) {
                    i++;
                    j++;
                } else {
                    i++;
                }
            }
        }

        return j == m;
    }
};