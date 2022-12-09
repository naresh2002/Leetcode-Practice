class Solution {
public:
    int dp[200][200];
    
    int uniquePaths(int x, int y) {
        if (x == 1 && y == 1) {
            return 1;
        }
        if (x == 0 || y == 0) {
            return 0;
        }
        if (dp[x][y]) {
            return dp[x][y];
        }
        dp[x][y] = uniquePaths(x - 1, y) + uniquePaths(x, y - 1);
        return dp[x][y];
    }
};