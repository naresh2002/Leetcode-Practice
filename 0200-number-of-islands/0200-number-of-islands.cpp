class Solution {
public:
    void solve (int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return;
        }
        grid[i][j] = '2';
        solve(i - 1, j, grid);
        solve(i + 1, j, grid);
        solve(i, j - 1, grid);
        solve(i, j + 1, grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    solve(i, j, grid);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};