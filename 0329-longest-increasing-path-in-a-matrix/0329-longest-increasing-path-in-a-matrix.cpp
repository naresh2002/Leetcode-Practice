class Solution {
public:
    int dp[200][200];
    
    int solve (int i, int j, vector<vector<int>>& matrix, int prev) {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] <= prev) {
            return 0;
        }
        if (dp[i][j]) {
            return dp[i][j];
        }
        dp[i][j] = 1 + max({solve(i - 1, j, matrix, matrix[i][j]),
                            solve(i, j - 1, matrix, matrix[i][j]),
                            solve(i, j + 1, matrix, matrix[i][j]),
                            solve(i + 1, j, matrix, matrix[i][j])});
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, solve(i, j, matrix, -1));
            }
        }
        return ans;
    }
};