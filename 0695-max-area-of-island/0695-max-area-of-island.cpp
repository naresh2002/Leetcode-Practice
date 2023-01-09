class Solution {
public:
    int island(vector<vector<int>>& grid, int i, int j, int n, int m, vector<vector<int>>& vis) {
        if (i < 0 || j < 0 || i == n || j == m || grid[i][j] == 0 || vis[i][j] == 1) {
            return 0;
        }
        vis[i][j] = 1;
        int ans = 1;
        ans += island(grid, i - 1, j, n, m, vis);
        ans += island(grid, i + 1, j, n, m, vis);
        ans += island(grid, i, j - 1, n, m, vis);
        ans += island(grid, i, j + 1, n, m, vis);
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis (n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    ans = max(ans, island(grid, i, j, n, m, vis));
                }
            }
        }
        return ans;
    }
};