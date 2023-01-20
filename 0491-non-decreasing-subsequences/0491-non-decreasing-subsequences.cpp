class Solution {
public:
    set<vector<int>> s;
    void allPossible (int curr, int n, vector<int> &v, vector<int> &nums) {
        if (curr == n) {
            if (v.size() >= 2) {
                s.insert(v);
            }
            return;
        }
        allPossible(curr + 1, n, v, nums);
        if (v.size() == 0 || nums[curr] >= v.back()) {
            v.push_back(nums[curr]);
            allPossible(curr + 1, n, v, nums);
            v.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        allPossible(0, n, v, nums);
        vector<vector<int>> ans;
        for (auto x : s) {
            ans.push_back(x);
        }
        return ans;
    }
};