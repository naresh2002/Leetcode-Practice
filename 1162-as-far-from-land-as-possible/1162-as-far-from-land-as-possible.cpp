class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // For checking from UP and LEFT
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    grid[i][j] = 0;
                }
                else {
                    grid[i][j] = 1e5;
                    if (i > 0) {
                        grid[i][j] = min(grid[i][j], grid[i - 1][j] + 1);
                    }
                    if (j > 0) {
                        grid[i][j] = min(grid[i][j], grid[i][j - 1] + 1);
                    }
                }
            }
        }
        
        int ans = INT_MIN;
        
        // For checking from DOWN and RIGHT
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i < n - 1) {
                    grid[i][j] = min(grid[i][j], grid[i + 1][j] + 1);
                }
                if (j < n - 1) {
                    grid[i][j] = min(grid[i][j], grid[i][j + 1] + 1);
                }
                ans = max(ans, grid[i][j]);
            }
        }
        
        if (ans == 0 || ans == 1e5) {
            return -1;
        }
        return ans;
    }
};