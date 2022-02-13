class Solution {
public:
  vector<vector<int>> ans;
  
  void solve(int curr, int n, vector<int> &v, vector<int> &nums) {
    if (curr >= n) {
      ans.push_back(v);
      return;
    }
    v.push_back(nums[curr]);
    solve(curr + 1, n, v, nums);
    v.pop_back();
    solve(curr + 1, n, v, nums);
  }
  
  vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<int> v;
    solve(0, n, v, nums);
    return ans;
  }
};