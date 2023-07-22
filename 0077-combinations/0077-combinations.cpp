class Solution {
public:
    vector<vector<int>> ans;
    void dfs (int curr, int n, int k, vector<int> &v) {
        if (v.size() == k) {
            ans.push_back(v);
            return;
        }
        for (int i = curr; i <= n; i++) {
            v.push_back(i);
            dfs(i + 1, n, k, v);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        dfs(1, n, k, v);
        return ans;
    }
};