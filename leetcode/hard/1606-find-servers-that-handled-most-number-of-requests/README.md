# Find Servers That Handled Most Number of Requests

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Wish
Citadel
Apple
Cisco
Amazon

You have `k` servers numbered from `0` to `k-1` that are being used to handle multiple requests simultaneously. Each server has infinite computational capacity but  **cannot handle more than one request at a time**. The requests are assigned to servers according to a specific algorithm:

- The ith (0-indexed) request arrives.
- If all servers are busy, the request is dropped (not handled at all).
- If the (i % k)th server is available, assign the request to that server.
- Otherwise, assign the request to the next available server (wrapping around the list of servers and starting from 0 if necessary). For example, if the ith server is busy, try to assign the request to the (i+1)th server, then the (i+2)th server, and so on.

You are given a  **strictly increasing**  array `arrival` of positive integers, where `arrival[i]` represents the arrival time of the `ith` request, and another array `load`, where `load[i]` represents the load of the `ith` request (the time it takes to complete). Your goal is to find the  **busiest server(s)**. A server is considered  **busiest**  if it handled the most number of requests successfully among all the servers.

Return  *a list containing the IDs (0-indexed) of the  **busiest server(s)***. You may return the IDs in any order.

 

 **Example 1:** 

```
Input: k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3] 
Output: [1] 
Explanation: 
All of the servers start out available.
The first 3 requests are handled by the first 3 servers in order.
Request 3 comes in. Server 0 is busy, so it's assigned to the next available server, which is 1.
Request 4 comes in. It cannot be handled since all servers are busy, so it is dropped.
Servers 0 and 2 handled one request each, while server 1 handled two requests. Hence server 1 is the busiest server.

```

 **Example 2:** 

```
Input: k = 3, arrival = [1,2,3,4], load = [1,2,1,2]
Output: [0]
Explanation: 
The first 3 requests are handled by first 3 servers.
Request 3 comes in. It is handled by server 0 since the server is available.
Server 0 handled two requests, while servers 1 and 2 handled one request each. Hence server 0 is the busiest server.

```

 **Example 3:** 

```
Input: k = 3, arrival = [1,2,3], load = [10,12,11]
Output: [0,1,2]
Explanation: Each server handles a single request, so they are all considered the busiest.

```

 

 **Constraints:** 

- 1 <= k <= 105
- 1 <= arrival.length, load.length <= 105
- arrival.length == load.length
- 1 <= arrival[i], load[i] <= 109
- arrival is strictly increasing.

## Solution

**Language:** C++  
**Runtime:** 158 ms (beats 35.53%)  
**Memory:** 125.4 MB (beats 40.88%)  
**Submitted:** 2026-11-09T11:45:38.622Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/)