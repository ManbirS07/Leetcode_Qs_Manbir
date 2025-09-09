class Solution {
public:
    int find(int i, vector<int>& parent) {
        if(parent[i] == i) return i;

        return parent[i] = find(parent[i], parent);
    }
    bool equationsPossible(vector<string>& equations) {
        //I'll go on creating sets where each element equals to one another
        //If i find out that there is a ! in the expression, and still parent of both elements is same, it means they need to be equal but equations hi wo nhi di toh false

        int n = equations.size();

        vector<int> parent(26);
        vector<int> rank(26, 0);
        for(string &s: equations) {
        for(int i = 0; i < 26; i++) {
            parent[s[0] - 'a'] = s[0] - 'a';
            parent[s[3] - 'a'] = s[3] - 'a';
        }
    }
        for(string &s: equations) {
            int first = s[0] - 'a';
            int second = s[3] - 'a';

            int parent1 = find(first, parent);
            int parent2 = find(second, parent);

            if(s[1] == '!') {
                if(parent1 == parent2) return false;
            } else {
                if(rank[parent1] > rank[parent2]) parent[parent2] = parent1; // new parent

                else if(rank[parent2 > rank[parent1]]) parent[parent1] = parent2;

                else {
                    parent[parent2] = parent1;
                    rank[parent1]++;
                }
            }
        }
        return true;
    }
};