class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();

        int t = 0, f = 0;
        int i = 0, j = 0, len = 0;

        while(j < n) {
            answerKey[j] == 'T' ? t++ : f++;

            while(min(t, f) > k) {
                answerKey[i] == 'T' ? t--: f--;
                i++; 
            }

            len = max(len, j - i + 1);
            j++;
        }
        return len;
    }
};