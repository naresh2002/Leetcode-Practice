class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &hasApple) {
        int totalTime = 0, childTime = 0;
        for (auto x : adj[node]) {
            if (x == parent) {
                continue;
            }
            childTime = dfs(x, node, adj, hasApple);
            if (childTime || hasApple[x]) {
                totalTime += (childTime + 2);
            }
        }
        return totalTime;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        return dfs(0, -1, adj, hasApple);
    }
};