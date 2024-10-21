class Solution {
public:
    // Topological Sort
    void dfs (int curr, vector<int>& v, vector<int>& ans, vector<bool>& vis, vector<int> adj[]) {
        if (vis[curr]) {
            return;
        }
        v.push_back(curr);
        vis[curr] = true;
        for (auto x : adj[curr]) {
            dfs(x, v, ans, vis, adj);
        }
        ans.push_back(v.back());
        v.pop_back();
    }
    
    // Cycle Detection
    bool isCyclic (int curr, vector<int>& color, vector<int> adj[]) {
        if (color[curr] == 1) {
            return false;
        }
        if (color[curr] == 2) {
            return true;
        }
        bool ans = true;
        color[curr]++;
        for (auto x : adj[curr]) {
            ans &= isCyclic(x, color, adj);
        }
        color[curr]++;
        return ans;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> adj[numCourses];
        vector<int> degree (numCourses, 0);
        for (auto p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        
        
        // 0 (initial color), 1 (intermidiate color), 2 (final color while backtracking)
        vector<int> color (numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (color[i] == 0) {
                if (!isCyclic(i, color, adj)) {
                    return {};
                }
            }
        }
        
        vector<bool> vis (numCourses, false);
        vector<int> v;
        vector<int> validOrder;
        
        for (int i = 0; i < numCourses; i++) {
            if (!degree[i]) {
                dfs(i, v, validOrder, vis, adj);
            }
        }
        reverse(validOrder.begin(), validOrder.end());
        return validOrder;
    }
};