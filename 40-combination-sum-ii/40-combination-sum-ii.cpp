class Solution {
public:
    vector<vector<int>> ans;
    void dfs (int idx, int tot, vector<int> &v, vector<int> &candidates, int target) {
        if (tot == target) {
            ans.push_back(v);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (i != idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (tot + candidates[i] <= target) {
                v.push_back(candidates[i]);
                dfs(i + 1, tot + candidates[i], v, candidates, target);
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        dfs(0, 0, v, candidates, target);
        return ans;
    }
};