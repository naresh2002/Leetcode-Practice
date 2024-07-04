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
                vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                for (auto dir : dirs) {
                    int a = dir.first, b = dir.second;
                    if (x + a >= 0 && x + a < n &&
                       y + b >= 0 && y + b < m &&
                       grid[x + a][y + b] == 1) {
                        q.back().push_back({x + a, y + b});
                        grid[x + a][y + b] = 2;
                        newRotten++;
                    }
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