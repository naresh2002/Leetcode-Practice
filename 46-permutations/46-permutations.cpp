class Solution {
public:
    vector<vector<int>> ans;
    void dfs (vector<int> &v, vector<int> &perm, vector<bool> &vis) {
        if (perm.size() == v.size()) {
            ans.push_back(perm);
            return;
        }
        for (int i = 0; i < v.size(); i++) {
            if (!vis[i]) {
                vis[i] = true;
                perm.push_back(v[i]);
                dfs(v, perm, vis);
                perm.pop_back();
                vis[i] = false;
            }
        }
    }    
    
    vector<vector<int>> permute(vector<int>& v) {
        vector<int> perm;
        vector<bool> vis(v.size(), false);
        dfs(v, perm, vis);
        return ans;
    }
};