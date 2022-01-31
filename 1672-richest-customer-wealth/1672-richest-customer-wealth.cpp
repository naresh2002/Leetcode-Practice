class Solution {
public:
  int maximumWealth(vector<vector<int>>& v) {
    int n = v.size(), m = v[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < m; j++) {
        v[i][j] += v[i][j - 1];
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, v[i][m - 1]);
    }
    return ans;
  }
};