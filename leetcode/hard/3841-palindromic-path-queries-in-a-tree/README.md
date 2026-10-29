# Palindromic Path Queries in a Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an undirected tree with `n` nodes labeled 0 to `n - 1`. This is represented by a 2D array `edges` of length `n - 1`, where `edges[i] = [ui, vi]` indicates an undirected edge between nodes `ui` and `vi`.

You are also given a string `s` of length `n` consisting of lowercase English letters, where `s[i]` represents the character assigned to node `i`.

You are also given a string array `queries`, where each `queries[i]` is either:

- "update ui c": Change the character at node ui to c. Formally, update s[ui] = c.
- "query ui vi": Determine whether the string formed by the characters on the unique path from ui to vi (inclusive) can be rearranged into a palindrome.

Return a boolean array `answer`, where `answer[j]` is `true` if the `jth` query of type `"query ui vi"​​​​​​​` can be rearranged into a  **palindrome**, and `false` otherwise.

 

 **Example 1:** 

 **Input:**  n = 3, edges = [[0,1],[1,2]], s = "aac", queries = ["query 0 2","update 1 b","query 0 2"]

 **Output:**  [true,false]

 **Explanation:** 

- "query 0 2": Path 0 → 1 → 2 gives "aac", which can be rearranged to form "aca", a palindrome. Thus, answer[0] = true.
- "update 1 b": Update node 1 to 'b', now s = "abc".
- "query 0 2": Path characters are "abc", which cannot be rearranged to form a palindrome. Thus, answer[1] = false.

Thus, `answer = [true, false]`.

 **Example 2:** 

 **Input:**  n = 4, edges = [[0,1],[0,2],[0,3]], s = "abca", queries = ["query 1 2","update 0 b","query 2 3","update 3 a","query 1 3"]

 **Output:**  [false,false,true]

 **Explanation:** 

- "query 1 2": Path 1 → 0 → 2 gives "bac", which cannot be rearranged to form a palindrome. Thus, answer[0] = false.
- "update 0 b": Update node 0 to 'b', now s = "bbca".
- "query 2 3": Path 2 → 0 → 3 gives "cba", which cannot be rearranged to form a palindrome. Thus, answer[1] = false.
- "update 3 a": Update node 3 to 'a', s = "bbca".
- "query 1 3": Path 1 → 0 → 3 gives "bba", which can be rearranged to form "bab", a palindrome. Thus, answer[2] = true.

Thus, `answer = [false, false, true]`.

 

 **Constraints:** 

- 1 <= n == s.length <= 5 * 104
- edges.length == n - 1
- edges[i] = [ui, vi]
- 0 <= ui, vi <= n - 1
- s consists of lowercase English letters.
- The input is generated such that edges represents a valid tree.
- 1 <= queries.length <= 5 * 104​​​​​​​queries[i] = "update ui c" or queries[i] = "query ui vi" 0 <= ui, vi <= n - 1 c is a lowercase English letter.

## Solution

**Language:** C++  
**Runtime:** 285 ms (beats 84.09%)  
**Memory:** 302.5 MB (beats 69.32%)  
**Submitted:** 2026-10-29T16:38:37.251Z  

```cpp
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos;
    vector<int> tree; // Segment tree storing bitmasks
    int cur_pos;

    // First DFS: compute subtree sizes, depths, parents, and heavy edges
    int dfs(int v, int p, int d) {
        int size = 1;
        int max_c_size = 0;
        parent[v] = p;
        depth[v] = d;
        for (int c : adj[v]) {
            if (c != p) {
                int c_size = dfs(c, v, d + 1);
                size += c_size;
                if (c_size > max_c_size) {
                    max_c_size = c_size;
                    heavy[v] = c;
                }
            }
        }
        return size;
    }

    // Second DFS: decompose tree into heavy chains
    void decompose(int v, int h) {
        head[v] = h;
        pos[v] = cur_pos++;
        if (heavy[v] != -1) {
            decompose(heavy[v], h);
        }
        for (int c : adj[v]) {
            if (c != parent[v] && c != heavy[v]) {
                decompose(c, c);
            }
        }
    }

    // Segment Tree point update
    void updateSegTree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) updateSegTree(2 * node, start, mid, idx, val);
        else updateSegTree(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    // Segment Tree range XOR query
    int querySegTree(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = start + (end - start) / 2;
        return querySegTree(2 * node, start, mid, l, r) ^ querySegTree(2 * node + 1, mid + 1, end, l, r);
    }

    // Query XOR mask along path between u and v
    int queryPath(int u, int v) {
        int res = 0;
        for (; head[u] != head[v]; v = parent[head[v]]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            res ^= querySegTree(1, 0, n - 1, pos[head[v]], pos[v]);
        }
        if (depth[u] > depth[v]) swap(u, v);
        res ^= querySegTree(1, 0, n - 1, pos[u], pos[v]);
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        tree.assign(4 * n, 0);
        cur_pos = 0;

        dfs(0, -1, 0);
        decompose(0, 0);

        // Build initial Segment Tree state
        for (int i = 0; i < n; ++i) {
            int mask = 1 << (s[i] - 'a');
            updateSegTree(1, 0, n - 1, pos[i], mask);
        }

        vector<bool> ans;
        for (const string& q : queries) {
            if (q[0] == 'u') { // "update u c"
                int u = 0;
                int i = 7;
                while (i < q.length() && q[i] != ' ') {
                    u = u * 10 + (q[i] - '0');
                    i++;
                }
                char c = q[i + 1];
                int mask = 1 << (c - 'a');
                updateSegTree(1, 0, n - 1, pos[u], mask);
            } else { // "query u v"
                int u = 0, v = 0;
                int i = 6;
                while (i < q.length() && q[i] != ' ') {
                    u = u * 10 + (q[i] - '0');
                    i++;
                }
                i++;
                while (i < q.length()) {
                    v = v * 10 + (q[i] - '0');
                    i++;
                }

                int mask = queryPath(u, v);
                // Valid palindrome if mask has at most 1 bit set
                bool can_be_palindrome = (mask == 0) || ((mask & (mask - 1)) == 0);
                ans.push_back(can_be_palindrome);
            }
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/palindromic-path-queries-in-a-tree/)