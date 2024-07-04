class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int fresh = 0;
        deque<vector<pair<int, int>>> q;
        q.push_back({});
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.front().push_back({i, j});
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        int ans = 0;
        while (1) {
            int newRotten = 0;
            q.push_back({});
            for (auto f : q.front()) {
                int x = f.first, y = f.second;
                if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                    q.back().push_back({x - 1, y});
                    grid[x - 1][y] = 2;
                    newRotten++;
                }
                if (x + 1 < n && grid[x + 1][y] == 1) {
                    q.back().push_back({x + 1, y});
                    grid[x + 1][y] = 2;
                    newRotten++;
                }
                if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                    q.back().push_back({x, y - 1});
                    grid[x][y - 1] = 2;
                    newRotten++;
                }
                if (y + 1 < m &&grid[x][y + 1] == 1) {
                    q.back().push_back({x, y + 1});
                    grid[x][y + 1] = 2;
                    newRotten++;
                }
            }
            fresh -= newRotten;
            if (newRotten == 0) {
                break;
            }
            q.pop_front();
            ans++;
        }
        if (fresh) {
            return -1;
        }
        return ans;
    }
};