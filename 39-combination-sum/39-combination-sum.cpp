class Solution {
public:
  vector<vector<int>> ans;
  void solve(int curr, int n, int sum, vector<int> v, vector<int> candidates, int target) {
    if (curr >= n) {
      if (sum == target) {
        ans.push_back(v);
      }
      return;
    }
    if (sum > target) {
      return;
    }
    v.push_back(candidates[curr]);
    solve(curr, n, sum + candidates[curr], v, candidates, target);
    v.pop_back();
    solve(curr + 1, n, sum, v, candidates, target);    
  }
  
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int n = candidates.size();
    vector<int> v;
    solve(0, n, 0, v, candidates, target);
    return ans;
  }
};