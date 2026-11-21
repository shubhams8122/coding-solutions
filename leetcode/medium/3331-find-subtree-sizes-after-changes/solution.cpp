#include <vector>
#include <string>
#include <array>

using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = static_cast<int>(parent.size());
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> new_parent = parent;
        array<int, 26> last_seen;
        last_seen.fill(-1);

        // Pass 1: Find closest ancestor with the same character in the original tree
        auto reassign_dfs = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            if (u != 0 && last_seen[c] != -1) {
                new_parent[u] = last_seen[c];
            }

            int prev = last_seen[c];
            last_seen[c] = u;

            for (int v : adj[u]) {
                self(self, v);
            }

            last_seen[c] = prev; // Backtrack so siblings don't see this branch
        };

        reassign_dfs(reassign_dfs, 0);

        // Build final tree from updated parents
        vector<vector<int>> final_adj(n);
        for (int i = 1; i < n; ++i) {
            final_adj[new_parent[i]].push_back(i);
        }

        // Pass 2: Compute subtree sizes in the final tree
        vector<int> ans(n, 1);
        auto size_dfs = [&](auto& self, int u) -> int {
            int total = 1;
            for (int v : final_adj[u]) {
                total += self(self, v);
            }
            return ans[u] = total;
        };

        size_dfs(size_dfs, 0);
        return ans;
    }
};