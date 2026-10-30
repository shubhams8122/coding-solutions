#include <vector>
#include <queue>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Build adjacency list: adj[u] = list of {v, weight}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // dist[u][count] stores the shortest distance to reach node `u` 
        // with `count` consecutive identical characters ending at `u`.
        const int INF = 1e9 + 7;
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

        // Min-heap: tuple storing {distance, node, consecutive_count}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        // Base case: Start at node 0 with count 1
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();

            // If we found a shorter path to this state already, skip
            if (d > dist[u][count]) continue;

            // If we reached the target node, since it's Dijkstra, 
            // the first time we pop target n-1, it is guaranteed optimal.
            if (u == n - 1) return d;

            for (const auto& [v, weight] : adj[u]) {
                int next_count = (labels[u] == labels[v]) ? count + 1 : 1;

                // Skip if constraint is violated
                if (next_count > k) continue;

                // Relaxation step
                if (dist[u][count] + weight < dist[v][next_count]) {
                    dist[v][next_count] = dist[u][count] + weight;
                    pq.push({dist[v][next_count], v, next_count});
                }
            }
        }

        return -1;
    }
};