class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        vector<pair<int, int>> cells(n * n + 1);
        int label = 1;
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[label++] = {row, column};
            }
            reverse(columns.begin(), columns.end());
        }
        vector<int> dist(n * n + 1, -1);
        queue<int> q;
        dist[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
                auto [row, column] = cells[next];
                int destination = board[row][column] != -1 ? board[row][column] : next;
                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }
        return dist[n * n];
    }
};

/*
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m; j++) {
                swap(board[i][j], board[n - i - 1][j]);
            }
        }
        
        map<int, vector<int>> ma;
        int temp = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ma[temp++].push_back(i);
                ma[temp++].push_back(j);
            }
        }
        
        temp = 1;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = 1e5;
                if (i == 0 && j == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                
                for (int k = 1; k <= 6; k++) {
                    if (temp - k > 0) {
                        int x = ma[temp - k][0];
                        int y = ma[temp - k][1];
                        dp[i][j] = min(dp[i][j], dp[x][y] + 1);
                    }
                }
                
                if (board[i][j] != -1) {
                    int x = ma[board[i][j]][0];
                    int y = ma[board[i][j]][1];
                    if (dp[x][y] == -1) {
                        dp[x][y] = dp[i][j];
                    }
                    else {
                        dp[x][y] = min(dp[x][y], dp[i][j]);
                    }
                }
                temp++;
            }
        }
        return dp[n - 1][m - 1];
    }
};
*/