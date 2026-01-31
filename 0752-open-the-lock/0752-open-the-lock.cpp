class Solution {
public:
    char nextChar(char ch) {
        if (ch == '9')
            return '0';
        return ch + 1;
    }

    char prevChar(char ch) {
        if (ch == '0')
            return '9';
        return ch - 1;
    }

    //without creating extra temp string 
    int openLock(vector<string>& deadends, string target) {
        // same as genetic mutation question
        // for each lock, we have to try all combinations with cost of each
        // combination as 1 if at any stage, the string becomes one from
        // deadends, we don't explore it furthur
        unordered_set<string> deadend(begin(deadends), end(deadends));
        unordered_set<string> visited;

        queue<pair<string, int>> q;
        string start = "0000";
        if(deadend.find(start) != deadend.end()) return -1;

        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            string s = q.front().first;
            int turns = q.front().second;
            q.pop();

            if (s == target)
                return turns;

            for (int i = 0; i < 4; i++) {
                // ek baar aage rotate, ek baari peeche rotate
                char currChar = s[i];
                char forwardChar = (currChar == '9' ? '0' : currChar + 1);
                s[i] = forwardChar;

                if (visited.find(s) == visited.end() &&
                    deadend.find(s) == deadend.end()) {
                    q.push({s, turns + 1});
                    visited.insert(s);
                }

                char previousChar = (currChar == '0' ? '9' : currChar - 1);
                s[i] = previousChar;

                if (visited.find(s) == visited.end() &&
                    deadend.find(s) == deadend.end()) {
                    q.push({s, turns + 1});
                    visited.insert(s);
                }

                s[i] = currChar; 
            }
        }
        return -1;
    }
};