class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        stack<int> st;

        vector<int> visited(26, 0);
        vector<int> lastSeen(26, -1);

        for(int i = 0; i < n; i++) {
            lastSeen[s[i] - 'a'] = i;
        }
        
        int startChar = s[0] - 'a';
        st.push(startChar);
        visited[startChar] = 1;

        for(int i = 1; i < n; i++) {
            int currChar = s[i] - 'a';
            if(visited[currChar] == 1) continue;
            
            while(!st.empty() && st.top() > currChar) {
                if(lastSeen[st.top()] < i) break;

                visited[st.top()] = 0;
                st.pop();
            }

            visited[currChar] = 1;
            st.push(currChar);
        }

        string res = "";
        while(!st.empty()) {
            res += st.top() + 'a';
            st.pop();
        }

        reverse(begin(res), end(res));
        return res;
    }
};