class Solution {
public:
    string reverseParentheses(string s) {
        //core cncept is same as minimum remove to make valid parenthesis
        //we store indices in stack of the opening ( and when we encounter an ), we take the latest index and reverse the string in btw

        //brute force -> now while maintaining answer(without extra last loop)
        int n = s.size();
        string ans = "";
        stack<int> st;

        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(ch == '(') {
                st.push(ans.length()); //not i because we are simulating for answer and we need to keep track of it's indices 
            } else if(ch == ')') {
                int idx = st.top();
                st.pop();
                reverse(ans.begin() + idx, ans.end()); //end isliye ki ye closing h toh puri kardo reverse answer jo banate jaa rha hu
            } else {
                ans += ch;
            }
        }
        return ans;
    }
};