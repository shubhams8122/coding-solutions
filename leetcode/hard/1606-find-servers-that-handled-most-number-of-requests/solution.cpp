#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }

        vector<int> requestCount(k, 0);
        int maxRequests = 0;

        for (int i = 0; i < arrival.size(); ++i) {
            long long currTime = arrival[i];
            long long duration = load[i];

            // Free up servers whose tasks have finished by the current arrival time
            while (!busy.empty() && busy.top().first <= currTime) {
                available.insert(busy.top().second);
                busy.pop();
            }

            // If no servers are available, drop the request
            if (available.empty()) {
                continue;
            }

            // Find the first available server >= (i % k)
            auto it = available.lower_bound(i % k);
            if (it == available.end()) {
                it = available.begin(); // Wrap around to 0
            }

            int serverId = *it;
            available.erase(it);

            busy.push({currTime + duration, serverId});
            requestCount[serverId]++;
            maxRequests = max(maxRequests, requestCount[serverId]);
        }

        // Collect all servers that handled the maximum number of requests
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (requestCount[i] == maxRequests) {
                result.push_back(i);
            }
        }

        return result;
    }
};