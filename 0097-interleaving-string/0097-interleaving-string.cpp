class Solution {
public:
    // https://leetcode.com/problems/interleaving-string/discuss/1247459/Easy-Understanding-Recursion-and-Memoization-%2B-Iterative
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if (n + m != s3.size()) {
            return false;
        }
        vector<vector<bool>> dp(n + 1, vector<bool> (m + 1, false));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                }
                else if (i == 0) {
                    if (s2[j - 1] == s3[j - 1]) {
                        dp[i][j] = dp[i][j - 1];
                    }
                }
                else if (j == 0) {
                    if (s1[i - 1] == s3[i - 1]) {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
                else if (s1[i - 1] == s3[i + j - 1] && s2[j - 1] != s3[i + j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                }
                else if (s1[i - 1] != s3[i + j - 1] && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j - 1];
                }
                else if (s1[i - 1] == s3[i + j - 1] && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = (dp[i - 1][j] | dp[i][j - 1]);   // '|' or '||' both works here
                }
            }
        }
        return dp[n][m];
    }
};