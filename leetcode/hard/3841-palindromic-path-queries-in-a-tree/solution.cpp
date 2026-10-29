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