class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        vector<int> endTime(n), res;
        vector<int> requests(k, 0);
        for(int i = 0; i < n; i++) {
            endTime[i] = arrival[i] + load[i];
        }

        set<int> availableServers;
        for(int i = 0; i < k; i++) availableServers.insert(i);
        //initially all servers can take the request

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //earliest time a server can take the request along with the serverID
        for(int i = 0; i < n; i++) {
            int reqStart = arrival[i];
            int reqEnd = endTime[i];

            //checking all servers that got free before arrival of this request
            while(!pq.empty() && pq.top().first <= reqStart) {
                availableServers.insert(pq.top().second);
                pq.pop();
            }

            if(availableServers.empty()) continue; //request dropped

            //if the (i % k)th server is free, I'll assign this request to that one,
            //else to the one that is available the earliest
            int reqdServer = (i % k);
            if(availableServers.find(reqdServer) != availableServers.end()) {
                //assign the request to this server
                pq.push({reqEnd, reqdServer});
                availableServers.erase(reqdServer);
                requests[reqdServer]++;
            } else {
                //The Q specifically says that try to allocate to i + 1, i + 2th and so on
                //mtlb just iske baad wala jo free h sabse pehla usse assign
                //upper_bound
                auto nextServerIdx = availableServers.upper_bound(reqdServer); 
                if(nextServerIdx != availableServers.end()) {
                    int nextServerId = *nextServerIdx;
                    pq.push({reqEnd, nextServerId});
                    availableServers.erase(nextServerId);
                    requests[nextServerId]++;
                } else {
                    //use the first available server
                    int firstFreeServer = *availableServers.begin();
                    pq.push({reqEnd, firstFreeServer});
                    availableServers.erase(firstFreeServer);
                    requests[firstFreeServer]++;
                }
            }
        }

        int serverWithMaxReqs = -1, maxRequests = -1;
        for(int i = 0; i < k; i++) {
            if(requests[i] > maxRequests) {
                maxRequests = requests[i];
                serverWithMaxReqs = i;
            }
        }

        for(int i = 0; i < k; i++) {
            if(requests[i] == maxRequests) {
                res.push_back(i);
            }
        }
        return res;
    }
};