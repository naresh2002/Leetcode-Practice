class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int curr, int n, vector<int> &v, vector<int>& nums) {
        if (curr == n) {
            ans.push_back(v);
            return;
        }
        dfs(curr + 1, n, v, nums);
        v.push_back(nums[curr]);
        dfs(curr + 1, n, v, nums);
        v.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        dfs(0, n, v, nums);
        return ans;
    }
};