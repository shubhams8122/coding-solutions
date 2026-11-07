class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        
        // Min-heap for free servers: stores {weight, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeServers;
        
        // Min-heap for busy servers: stores {free_time, weight, index}
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> busyServers;
        
        for (int i = 0; i < n; ++i) {
            freeServers.push({servers[i], i});
        }
        
        vector<int> ans(m);
        long long currentTime = 0;
        
        for (int j = 0; j < m; ++j) {
            currentTime = max(currentTime, (long long)j);
            
            // If there are no free servers, jump time to when the next server becomes free
            if (freeServers.empty()) {
                currentTime = max(currentTime, get<0>(busyServers.top()));
            }
            
            // Free all servers that become available by current time
            while (!busyServers.empty() && get<0>(busyServers.top()) <= currentTime) {
                auto [freeTime, weight, index] = busyServers.top();
                busyServers.pop();
                freeServers.push({weight, index});
            }
            
            // Assign the task to the best available server
            auto [weight, index] = freeServers.top();
            freeServers.pop();
            
            ans[j] = index;
            busyServers.push({currentTime + tasks[j], weight, index});
        }
        
        return ans;
    }
};