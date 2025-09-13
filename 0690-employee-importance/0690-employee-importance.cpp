/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int dfs(int id, unordered_map<int,Employee*>& adj) {
        Employee* emp = adj[id];  
        int ans = emp->importance;

        for(int &v: emp->subordinates) {
            ans += dfs(v, adj);
        }
        return ans;
    }
    int getImportance(vector<Employee*> employees, int id) {
        //dfs lagake jo bhi path explore kare uska sum return kardo
        unordered_map<int, Employee*> adj;
        for(auto& emp: employees) {
            adj[emp -> id] = emp;
        } 
        return dfs(id, adj);
    }
};