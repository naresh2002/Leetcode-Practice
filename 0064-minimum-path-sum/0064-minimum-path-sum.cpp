class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp (n + 1, vector<int> (m + 1));
        dp[0][1] = dp[1][0] = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (!i || !j) {
                    if (i != 1 && j != 1) {
                        dp[i][j] = 1e6;
                    }
                }
                else {
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};