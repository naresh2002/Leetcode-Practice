class Solution {
public:
    vector<vector<int>> ans;
    void solve (int curr, int n, vector<int>& v, vector<int>& nums) {
        if (curr == n) {
            ans.push_back(v);
            return;
        }
        solve(curr + 1, n, v, nums);
        v.push_back(nums[curr]);
        solve(curr + 1, n, v, nums);
        v.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        solve(0, nums.size(), v, nums);
        return ans;
    }
};