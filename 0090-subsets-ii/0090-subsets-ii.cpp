class Solution {
public:
    set<vector<int>> s;
    void solve (int curr, int n, vector<int> &v, vector<int> &nums) {
        if (curr == n) {
            s.insert(v);
            return;
        }
        solve(curr + 1, n, v, nums);
        v.push_back(nums[curr]);
        solve(curr + 1, n, v, nums);
        v.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        int n = nums.size();
        solve(0, n, v, nums);
        vector<vector<int>> ans;
        for (auto x : s) {
            ans.push_back(x);
        }
        return ans;
    }
};