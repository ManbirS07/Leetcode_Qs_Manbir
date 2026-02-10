class Solution {
public:
    typedef long long ll;
    ll mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<ll>> vec;
        for(int i = 0; i < n; i++) {
            vec.push_back({ll(efficiency[i]), ll(speed[i])});
        }

        sort(begin(vec), end(vec), greater());
        priority_queue<int, vector<int>, greater<>> pq;

        ll sum = 0, res = -1;
        for(int i = 0; i < k - 1; i++) {
            int currSpeed = vec[i][1];
            int minEff = vec[i][0];

            sum += currSpeed;
            res = max(res, sum * minEff); //atmost k wala case
            //waise k maintain karne me hi fayda h kyuki sum hamesha badega hi toh elements toh saare lo
            //aur descending order me jaa rhe toh efficiency dec hi hogi
            pq.push(currSpeed);
        }

        for(int i = k - 1; i < n; i++) {
            ll minEff = vec[i][0]; //trying for each efficiency to be min
            ll currSpeed = vec[i][1];

            sum += currSpeed;
            pq.push(currSpeed);

            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            res = max(res, minEff * sum);
        }
        return res % mod;
    }
};