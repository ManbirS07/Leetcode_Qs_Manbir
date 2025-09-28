class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        int n=tasks.size();
        for(int i=0;i<n;i++)
        {
            mp[tasks[i]]++;
        }

        int ans=0;
        for(auto &it:mp)
        {
            if(it.second==1) return -1;
            else
            {
                int grpsof3=(it.second/3);
                int rem=(it.second)%3;
                if(rem==1) ans+=(grpsof3+1);
                else 
                {
                    int grpsof2=rem/2;
                    ans+=(grpsof3+grpsof2);
                }
            }
        }
        return ans;
    }
};