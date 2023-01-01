class Solution {
public:
    int vec[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    
    int countLiveNeighbours(vector<vector<int>>& board, int i, int j, int n, int m) {
        int cnt = 0;
        for (int k = 0; k < 8; k++) {
            int x = i + vec[k][0];
            int y = j + vec[k][1];
            if (x >= 0 && y >= 0 && x < n && y < m) {
                if (board[x][y] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    //  0 -> -1   &&   1 -> 2
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> temp = board;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int k = countLiveNeighbours(temp, i, j, n, m);
                if (k < 2 && temp[i][j] == 1) {
                    board[i][j] = 0;
                }
                else if ((k == 2 || k == 3) && temp[i][j] == 1) {
                    continue;
                }
                else if (k > 3 && temp[i][j] == 1) {
                    board[i][j] = 0;
                }
                else if (k == 3 && temp[i][j] == 0) {
                    board[i][j] = 1;
                }
            }
        }
    }
};