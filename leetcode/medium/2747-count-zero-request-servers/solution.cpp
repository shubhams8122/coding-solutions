class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        
        // Store queries with their original indices: {query_time, index}
        vector<pair<int, int>> sorted_queries(m);
        for (int i = 0; i < m; ++i) {
            sorted_queries[i] = {queries[i], i};
        }
        
        // Sort queries in ascending order
        sort(sorted_queries.begin(), sorted_queries.end());
        
        // Sort logs based on time: {time, server_id}
        // Note: logs[i] is [server_id, time], so we reorder to {time, server_id} for sorting
        vector<pair<int, int>> sorted_logs;
        for (const auto& log : logs) {
            sorted_logs.push_back({log[1], log[0]});
        }
        sort(sorted_logs.begin(), sorted_logs.end());
        
        int l = 0, r = 0;
        int num_logs = sorted_logs.size();
        unordered_map<int, int> server_freq;
        
        for (int i = 0; i < m; ++i) {
            int q_time = sorted_queries[i].first;
            int q_idx = sorted_queries[i].second;
            
            int window_start = q_time - x;
            int window_end = q_time;
            
            // Expand right pointer to include all logs up to window_end
            while (r < num_logs && sorted_logs[r].first <= window_end) {
                server_freq[sorted_logs[r].second]++;
                r++;
            }
            
            // Shrink left pointer to remove logs older than window_start
            while (l < num_logs && sorted_logs[l].first < window_start) {
                server_freq[sorted_logs[l].second]--;
                if (server_freq[sorted_logs[l].second] == 0) {
                    server_freq.erase(sorted_logs[l].second);
                }
                l++;
            }
            
            // Servers with zero requests = total servers (n) - servers with at least one request (server_freq.size())
            ans[q_idx] = n - server_freq.size();
        }
        
        return ans;
    }
};