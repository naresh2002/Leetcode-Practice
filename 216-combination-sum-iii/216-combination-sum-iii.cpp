class Solution {
public:
    vector<vector<int>> ans;
    void dfs (int curr, int n, int k, vector<int> &v, int tot) {
        if (v.size() == k && tot == n) {
            ans.push_back(v);
            return;
        }
        for (int i = curr; i <= 9; i++) {
            if (tot + i > n) {
                continue;
            }
            v.push_back(i);
            dfs(i + 1, n, k, v, tot + i);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        if (n > k * 9) {
            return {};
        }
        vector<int> v;
        dfs(1, n, k, v, 0);
        return ans;        
    }
};