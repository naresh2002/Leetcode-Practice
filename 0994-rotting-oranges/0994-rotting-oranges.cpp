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
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (1) {
            q.push_back({});
            int newRotten = 0;
            for (auto p : q.front()) {
                int x = p.first;
                int y = p.second;
                for (auto dir : dirs) {
                    int xx = x + dir.first;
                    int yy = y + dir.second;
                    if (xx >= 0 && yy >= 0 && xx < n && yy < m) {
                        if (grid[xx][yy] == 1) {
                            q.back().push_back({xx, yy});
                            grid[xx][yy] = 2;
                            newRotten++;
                            fresh--;
                        }
                    }
                }
            }
            q.pop_front();
            if (newRotten == 0) {
                break;
            }
            ans++;
        }
        if (fresh) {
            return -1;
        }
        return ans;
    }
};