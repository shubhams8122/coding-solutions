# Find Subtree Sizes After Changes

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a tree rooted at node 0 that consists of `n` nodes numbered from `0` to `n - 1`. The tree is represented by an array `parent` of size `n`, where `parent[i]` is the parent of node `i`. Since node 0 is the root, `parent[0] == -1`.

You are also given a string `s` of length `n`, where `s[i]` is the character assigned to node `i`.

We make the following changes on the tree  **one**  time  **simultaneously**  for all nodes `x` from `1` to `n - 1`:

- Find the closest node y to node x such that y is an ancestor of x, and s[x] == s[y].
- If node y does not exist, do nothing.
- Otherwise, remove the edge between x and its current parent and make node y the new parent of x by adding an edge between them.

Return an array `answer` of size `n` where `answer[i]` is the  **size**  of the subtree rooted at node `i` in the  **final**  tree.

 

Original
C++
 **Example 1:** 

 **Input:**  parent = [-1,0,0,1,1,1], s = "abaabc"

 **Output:**  [6,3,1,1,1,1]

 **Explanation:** 

The parent of node 3 will change from node 1 to node 0.

 **Example 2:** 

 **Input:**  parent = [-1,0,4,0,1], s = "abbba"

 **Output:**  [5,2,1,1,1]

 **Explanation:** 

The following changes will happen at the same time:

- The parent of node 4 will change from node 1 to node 0.
- The parent of node 2 will change from node 4 to node 1.

 

 **Constraints:** 

- n == parent.length == s.length
- 1 <= n <= 105
- 0 <= parent[i] <= n - 1 for all i >= 1.
- parent[0] == -1
- parent represents a valid tree.
- s consists only of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 429 ms (beats 56.96%)  
**Memory:** 280.2 MB (beats 58.23%)  
**Submitted:** 2026-11-21T09:15:15.875Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/find-subtree-sizes-after-changes/)