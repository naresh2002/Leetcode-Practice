class Solution {
public:
    vector<vector<int>> ans;
    vector<bool> vis;
    void dfs (int curr, int n, int k, vector<int> &v) {
        if (v.size() == k) {
            ans.push_back(v);
            return;
        }
        for (int i = curr; i <= n; i++) {
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            v.push_back(i);
            dfs(i + 1, n, k, v);
            vis[i] = false;
            v.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        vis.resize(n + 1, false);
        dfs(1, n, k, v);
        return ans;
    }
};