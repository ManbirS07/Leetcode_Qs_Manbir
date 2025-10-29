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

            if(isPalindrome(subString)) { //this can be a valid partition //(n)
                temp.push_back(subString); //do
                solve(j + 1, n, s, ans, temp);
                temp.pop_back(); //undo
            }
        }
    }
    vector<vector<string>> partition(string s) { //This is a backtracking problem where we decide at each position whether to "cut" the string or not -> 2^n
        //loop runs for total n time and O(n) to check palindrome
        //hence tc -> O(n2 * 2^n)

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