class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int curr, int k, vector<int> &v, int sum, int target) {
        if (sum == target && v.size() == k) {
            ans.push_back(v);
            return;
        }
        for (int i = curr; i <= 9; i++) {
            v.push_back(i);
            dfs(i + 1, k, v, sum + i, target);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        dfs(1, k, v, 0, n);
        return ans;
    }
};