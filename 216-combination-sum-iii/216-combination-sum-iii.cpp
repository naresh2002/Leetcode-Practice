class Solution {
public:
    vector<vector<int>> ans;
    vector<bool> vis;
    void dfs (int curr, int n, int k, vector<int> &v, int tot) {
        if (v.size() == k && tot == n) {
            ans.push_back(v);
            return;
        }
        for (int i = curr; i <= 9; i++) {
            if (tot + i > n || vis[i]) {
                continue;
            }
            vis[i] = true;
            v.push_back(i);
            dfs(i + 1, n, k, v, tot + i);
            vis[i] = false;
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        if (n > k * 9) {
            return {};
        }
        vector<int> v;
        vis.resize(10, false);
        dfs(1, n, k, v, 0);
        return ans;        
    }
};