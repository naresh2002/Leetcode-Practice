class Solution {
public:
    bool solve (int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& board, int pos, string& word) {
        if (pos == word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || vis[i][j]) {
            return false;
        }
        bool ans = false;
        pair<int, int> dirs[] = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };
        if (board[i][j] == word[pos]) {
            vis[i][j] = true;
            for (auto dir : dirs) {
                ans = ans || solve(i + dir.first, j + dir.second, vis, board, pos + 1, word);
            }
            vis[i][j] = false;
        }
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis (n + 1, vector<bool> (m + 1, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(i, j, vis, board, 0, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};