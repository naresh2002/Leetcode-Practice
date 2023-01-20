class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int curr, int n, vector<int> &v, vector<int> &candidates, int sum, int target) {
        if (sum == target) {
            ans.push_back(v);
            return;
        }
        for (int i = curr; i < n; i++) {
            if (i != curr && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (sum + candidates[i] <= target) {
                v.push_back(candidates[i]);
                dfs(i + 1, n, v, candidates, sum + candidates[i], target);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        vector<int> v;
        dfs(0, n, v, candidates, 0, target);
        return ans;
    }
};