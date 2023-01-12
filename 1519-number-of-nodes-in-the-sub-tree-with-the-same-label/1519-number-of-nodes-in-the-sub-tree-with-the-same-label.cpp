class Solution {
public:
    vector<int> dfs(int node, int parent, vector<vector<int>> &adj, string &labels, vector<int> & ans) {
        vector<int> cnt(26, 0);
        cnt[labels[node] - 'a']++;
        for (auto x : adj[node]) {
            if (x == parent) {
                continue;
            }
            vector<int> temp = dfs(x, node, adj, labels, ans);
            for (int i = 0; i < 26; i++) {
                cnt[i] += temp[i];
            }
        }
        ans[node] = cnt[labels[node] - 'a'];
        return cnt;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for (auto& x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int> ans(n, 0);
        dfs(0, -1, adj, labels, ans);

        return ans;
    }
};