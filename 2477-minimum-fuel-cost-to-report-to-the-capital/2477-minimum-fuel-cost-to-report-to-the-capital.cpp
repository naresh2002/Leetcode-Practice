class Solution {
public:
    long long ans;
    long long dfs(int node, int par, vector<vector<int>> &adj, int &seats) {
        int r = 1;  // r -> representatives
        for (auto x : adj[node]) {
            if (x != par) {
                r += dfs(x, node, adj, seats);
            }
        }
        if (node != 0) {
            ans += ((r + seats - 1) / seats);
        }
        return r;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        for (auto x : roads) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(0, -1, adj, seats);
        return ans;
    }
};