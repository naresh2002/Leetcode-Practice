class Solution {
public:
  int longestCommonSubsequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (!i || !j) {
          dp[i][j] = 0;
          continue;
        }
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        }
        else {
          dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
      }
    }
    return dp[n][m];
  }
};