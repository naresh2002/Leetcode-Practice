class Solution {
public:
    vector<vector<int>> ans;
    void dfs (vector<int> &nums, vector<int> &v, vector<bool> &visited) {
        if (v.size() == nums.size()) {
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] || (i && visited[i - 1] == false && nums[i - 1] == nums[i])) {
                continue;
            }
            visited[i] = true;
            v.push_back(nums[i]);
            dfs(nums, v, visited);
            v.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> v;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, v, visited);
        return ans;
    }
};