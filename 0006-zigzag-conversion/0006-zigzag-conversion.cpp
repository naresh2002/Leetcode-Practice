class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int n = s.size();
        vector<vector<char>> v (numRows, vector<char>(n, '0'));
        int r = 0, c = 0;
        char dir;   // Direction
        for (int i = 0; i < n; i++) {
            v[r][c] = s[i];
            if (r == 0) {
                dir = 'D';  // Down
            }
            if (r == numRows - 1) {
                dir = 'Z';   // Zig-Zag
            }
            if (dir == 'D') {
                r++;
            }
            if (dir == 'Z') {
                r--;
                c++;
            }
        }
        string ans;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] != '0') {
                    ans += v[i][j];
                }
            }
        }
        return ans;
    }
};