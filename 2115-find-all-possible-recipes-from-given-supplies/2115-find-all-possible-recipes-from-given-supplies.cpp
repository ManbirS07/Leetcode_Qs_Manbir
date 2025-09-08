class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();

        unordered_set<string> st;
        unordered_map<string, int> indegree;
        unordered_map<string, vector<string>> adj; //ingredient -> list of recipes -> kyuki finally toh hame ingredient ki dependency dekhni h kya padti h on the recipe

        //indegree = number of available ingredients initially
        for (int i = 0; i < n; i++) {
            indegree[recipes[i]] = ingredients[i].size();
            for (string ingredient : ingredients[i]) {
                adj[ingredient].push_back(recipes[i]);  //edge: ingredient -> recipe
            }
        }

        queue<string> q;
        vector<string> ans;

        for(string &s: supplies) { //we'll be playing with supplies only because this is what we have initially
            if(st.find(s) == st.end()) {
                q.push(s);
                st.insert(s);
            }
        }

        while (!q.empty()) {
            string item = q.front();
            q.pop();

            //it will be pushed into queue only if it's indegree becomes 0
            //this is only to check if the pushed item is a recipe or not
            if (indegree.find(item) != indegree.end()) {
                ans.push_back(item);
            }

            //reducing indegree of recipes depending on this item
            for (string &recipe : adj[item]) {
                indegree[recipe]--;
                if (indegree[recipe] == 0) {
                    q.push(recipe);
                }
            }
        }

        return ans;
    }
};
