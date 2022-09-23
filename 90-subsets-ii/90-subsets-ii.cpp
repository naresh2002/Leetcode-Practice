class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> ss;
    void solve (int curr, int n, vector<int> v, vector<int> nums) {
        if (curr == n) {
            ss.insert(v);
            return;
        }
        solve(curr + 1, n, v, nums);
        v.push_back(nums[curr]);
        solve(curr + 1, n, v, nums);
    }
        
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(0, nums.size(), {}, nums);
        for (auto x : ss) {
            ans.push_back(x);
        }
        return ans;
    }
};