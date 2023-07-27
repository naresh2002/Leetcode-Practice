class Solution {
public:
    // Here DAG is given so there will be no cycle
    vector<vector<int>> ans;
    void dfs(int curr, int n, vector<int>& v, vector<bool>& vis, vector<vector<int>>& graph) {
        if (curr == n - 1) {
            v.push_back(curr);
            ans.push_back(v);
            v.pop_back();
            return;
        }
        v.push_back(curr);
        for (auto x : graph[curr]) {
            if (!vis[x]) {
                dfs(x, n, v, vis, graph);
            }
        }
        v.pop_back();
        vis[curr] = false;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, false);
        vector<int> v;
        dfs(0, n, v, vis, graph);
        return ans;
    }
};