class Solution {
public:
    int n, m;
    vector<vector<int>> solve(queue<vector<int>> &q, vector<vector<int>> &vis, vector<vector<int>>& heights) {
        vector<vector<int>> v;
        while (q.size()) {
            int x = q.front()[0];
            int y = q.front()[1];
            if (x + 1 < n && vis[x + 1][y] == 0 && heights[x + 1][y] >= heights[x][y]) {
                q.push({x + 1, y});
                vis[x + 1][y] = 1;
            }
            if (x - 1 >= 0 && vis[x - 1][y] == 0 && heights[x - 1][y] >= heights[x][y]) {
                q.push({x - 1, y});
                vis[x - 1][y] = 1;
            }
            if (y + 1 < m && vis[x][y + 1] == 0 && heights[x][y + 1] >= heights[x][y]) {
                q.push({x, y + 1});
                vis[x][y + 1] = 1;
            }
            if (y - 1 >= 0 && vis[x][y - 1] == 0 && heights[x][y - 1] >= heights[x][y]) {
                q.push({x, y - 1});
                vis[x][y - 1] = 1;
            }
            v.push_back(q.front());
            // cout << x << " " << y << " -> " << pacific.size() << endl;
            q.pop();
        }
        return v;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        queue<vector<int>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        // -------------------PACIFIC-------------------
        for (int i = 0; i < n; i++) {
            q.push({i, 0});
            vis[i][0] = 1;
        }
        for (int i = 1; i < m; i++) {   // i = 1 as [0,0] should not occur twice
            q.push({0, i});
            vis[0][i] = 1;
        }        
        vector<vector<int>> pacific = solve(q, vis, heights);
        // ----------------PACIFIC [END]----------------
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis[i][j] = 0;      // Reset vis to 0 [ERROR with memset for 2D vector]
            }
        }
        
        // -------------------ATLANTIC-------------------
        for (int i = 0; i < n; i++) {
            q.push({i, m - 1});
            vis[i][m - 1] = 1;
        }
        for (int i = 0; i < m - 1; i++) {   // i < m - 1 as [n - 1, m - 1] should not occur twice
            q.push({n - 1, i});
            vis[n - 1][i] = 1;
        }
        vector<vector<int>> atlantic = solve(q, vis, heights);
        // ----------------ATLANTIC [END]----------------
        
        
        vector<vector<int>> ans;
        map<vector<int>, int> m;
        for (auto x : pacific) {
            m[x]++;
        }
        for (auto x : atlantic) {
            if (m.count(x)) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};