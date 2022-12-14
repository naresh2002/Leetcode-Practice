class Solution {
public:
    vector<vector<int>> ans;
    void dfs (int idx, int tot, vector<int> &v, vector<int> &candidates, int target) {
        if (tot == target) {
            ans.push_back(v);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (tot + candidates[i] <= target) {
                v.push_back(candidates[i]);
                dfs(i, tot + candidates[i], v, candidates, target); // Not i + 1 because we can choose 1 number multiple times
                v.pop_back();
            }
            else {
                break;
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        dfs(0, 0, v, candidates, target);
        return ans;
    }
};