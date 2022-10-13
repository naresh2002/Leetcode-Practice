class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int l = 0, maxlen = 0;
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof dp);        
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= n; i++) {
                if (i == j) {
                    dp[i][j] = 1;
                }
                if (j > i) {
                    if (s[i - 1] == s[j - 1] && dp[i + 1][j - 1] == j - i - 1) {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }
                if (dp[i][j] > maxlen) {
                    l = i - 1;
                    maxlen = dp[i][j];
                }
            }
        }
        return s.substr(l, maxlen);
    }
};