class Solution {
public:

  int solve(int dp[], int curr, vector<int>& a, int n) {
    if (curr == 0) {
      return 1;
    }
    if (curr < 0) {
      return 0;
    }
    if (dp[curr] != -1) {
      return dp[curr];
    }
    dp[curr] = 0;
    for (int i = 0; i < n; i++) {
      if (curr  < a[i]) {
        break;
      }
      dp[curr] += solve(dp, curr - a[i], a, n);
    }
    return dp[curr];
  }
  
  int combinationSum4(vector<int>& a, int x) {
    sort(a.begin(), a.end());
    int n = a.size();
    int dp[3000];
    memset(dp, -1, sizeof dp);
    return solve(dp, x, a, n);
  }
};