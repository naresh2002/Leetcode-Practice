class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        dp[0][1] = dp[1][0] = 0;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (!i || !j) {
                    if (i != 1 && j != 1) {
                        dp[i][j] = 1e6;
                    }
                }
                else {
                    int curr = grid[i - 1][j - 1];
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + curr;
                }
            }
        }
        return dp[m][n];
    }
};