class Solution {
public:
    bool isPalindrome(string s) { //O(n)
        int i = 0, j = s.size() - 1;

        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(int i, int n, string s, vector<vector<string>>& ans, vector<string>& temp) {
        if(i == n) { //we have successfully performed the partitions only then we are able to reach at index n
            ans.push_back(temp);
            return;
        }

        for(int j = i; j < n; j++) {
            string subString = s.substr(i, j - i + 1);

            if(isPalindrome(subString)) { //this can be a valid partition
                temp.push_back(subString); //do
                // //agar remaining word yahi pe palindrome ban jaa rha h we can check, toh directly add it in temp and then add temp to ans to save a few recursion calls
                // string rem = s.substr(j + 1, n - j - 1);

                // if(isPalindrome(rem) && rem != "") {
                //     temp.push_back(rem); 
                //     ans.push_back(temp);

                //     temp.pop_back(); //2 baari kyuki maine word + remaining word dala h
                //     temp.pop_back();
                // }

                //do, explore, undo -> backtrack
                solve(j + 1, n, s, ans, temp);
                temp.pop_back(); //undo
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        //har valid partition ke liye ek alag temp vector banega
        //that vector would be added to the ans only when i == n i.e we have fully reached till the end
        //i'll use backtracking to remove from ans vector once recursion has been completed for a partition
        vector<string> temp;
        solve(0, n, s, ans, temp);
        return ans;
    }
};