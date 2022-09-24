class Solution {
public:
    vector<vector<int>> ans;
    void dfs (vector<int> &v, vector<int> &perm, vector<bool> &vis) {
        if (perm.size() == v.size()) {
            ans.push_back(perm);
            return;
        }
        for (int i = 0; i < v.size(); i++) {
            if ((vis[i]) || (i && vis[i - 1] == false && v[i] == v[i - 1])) {
                continue;
            }
            vis[i] = true;
            perm.push_back(v[i]);
            dfs(v, perm, vis);
            perm.pop_back();
            vis[i] = false;
        }
    }  
    
    vector<vector<int>> permuteUnique(vector<int>& v) {
        vector<int> perm;
        vector<bool> vis(v.size(), false);
        sort(v.begin(), v.end());
        dfs(v, perm, vis);
        return ans;
    }
};