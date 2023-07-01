class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1)); // [ZEROS][ONES]
        dp[0][0] = 0;
        for (auto x : strs) {
            int zeros = count(x.begin(), x.end(), '0');
            int ones = x.size() - zeros;
            vector<vector<int>> temp = dp;
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    if (i - zeros >= 0 && j - ones >= 0) {
                        temp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                    }
                }
            }
            dp = temp;
        }
        return dp[m][n];
    }
};