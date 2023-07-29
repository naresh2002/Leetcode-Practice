class Solution {
public:
    //      FOR UNDERSTANDING USING DIAGRAM
    // https://leetcode.com/problems/is-graph-bipartite/discuss/1065709/C%2B%2B-or-DFS-or-O(n)-8ms-Beats-100-or-Explanation
    bool dfs(int curr, int n, vector<bool> &vis, int c, vector<int> &col, vector<vector<int>> &graph) {
        if (curr == n) {
            return true;
        }
        if (vis[curr]) {
            if (col[curr] != c) {   // Here c is expected color
                return false;
            }
            return true;
        }
        vis[curr] = true;
        col[curr] = c;
        bool ans = true;
        for (auto x : graph[curr]) {
            ans = ans & dfs(x, n, vis, c ^ 1, col, graph);
        }
        return ans;
    }
    
    // Can be colored with only 2 colors and where adjacent color is different
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, false);
        vector<int> col(n, -1);
        for (int i = 0; i < n; i++) {
            if (vis[i] == false && dfs(i, n, vis, 0, col, graph) == false) {
                return false;
            }
        }
        return true;
    }
};