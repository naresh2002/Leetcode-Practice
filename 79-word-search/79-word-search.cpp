class Solution {
public:
    int vis[10][10];
    int n, m;
    
    bool solve (vector<vector<char>>& v, int r, int c, string s, int curr) {
        if (r < 0 || r >= n || c < 0 || c >= m || v[r][c] != s[curr] || vis[r][c]) {
            return false;
        }
        if (curr == s.size() - 1) {
            return true;
        }
        vis[r][c] = 1;
        bool L = solve(v, r, c - 1, s, curr + 1);
        bool R = solve(v, r, c + 1, s, curr + 1);
        bool U = solve(v, r - 1, c, s, curr + 1);
        bool D = solve(v, r + 1, c, s, curr + 1);
        vis[r][c] = 0;
        return L | R | U | D;
    }
    
    bool exist(vector<vector<char>>& v, string s) {
        n = v.size();
        m = v[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (solve(v, i, j, s, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};