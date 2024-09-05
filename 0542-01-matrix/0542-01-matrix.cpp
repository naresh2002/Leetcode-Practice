class Solution {
public:
    // vector<vector<int>> dp (10000, vector<int> (10000, -1));
    int n, m;
    bool isValidIdx(int r, int c) {
        if (r < 0 || r >= n || c < 0 || c >= m) {
            return false;
        }
        return true;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                }
                else {
                    mat[i][j] = n * m;
                }
            }
        }
        
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for (auto [x, y] : dirs) {
                int new_row = row + x;
                int new_col = col + y;
                if (isValidIdx(new_row, new_col) && mat[new_row][new_col] > mat[row][col] + 1) {
                    q.push({new_row, new_col});
                    mat[new_row][new_col] = mat[row][col] + 1;;
                }
            }
        }
        
        return mat;
    }
};