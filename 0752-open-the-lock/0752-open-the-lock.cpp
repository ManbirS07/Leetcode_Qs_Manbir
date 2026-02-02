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
        //we can re-use the deadend set instead of a new visited set

        string start = "0000";
        if(deadend.find(start) != deadend.end()) return -1;

        queue<pair<string, int>> q;
        q.push({start, 0});
        deadend.insert(start);

        while(!q.empty()) {
            string currCombo = q.front().first;
            int ops = q.front().second;
            q.pop();

            if(currCombo == target) return ops;

            for(int i = 0; i < 4; i++) {
                char currChar = currCombo[i];
                string newCombo = currCombo;
                //ek baar try to rotate aage, and then peeche
                char next = nextChar(currChar);
                newCombo[i] = next;

                if(deadend.find(newCombo) == deadend.end()) {
                    q.push({newCombo, ops + 1});
                    deadend.insert(newCombo); //visited
                }

                char prev = prevChar(currChar);
                newCombo[i] = prev;

                if(deadend.find(newCombo) == deadend.end()) {
                    q.push({newCombo, ops + 1});
                    deadend.insert(newCombo); 
                }
            }
        }
        return -1;
    }
};