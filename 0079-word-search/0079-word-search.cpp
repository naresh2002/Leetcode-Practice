class Solution {
public:
    bool vis[10][10];
    int n, m;
    
    bool dfs(int i, int j, vector<vector<char>>& board, int curr, string &word) {
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || board[i][j] != word[curr]) {
            return false;
        }
        if (curr == word.size() - 1) {
            return true;
        }
        
        vis[i][j] = true;
        bool ans = dfs(i, j + 1, board, curr + 1, word) |
            dfs(i, j - 1, board, curr + 1, word) |
            dfs(i + 1, j, board, curr + 1, word) |
            dfs(i - 1, j, board, curr + 1, word);
        vis[i][j] = false;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, board, 0, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};