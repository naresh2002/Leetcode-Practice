class Solution {
public:
    bool check(int r, int c, int len, vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        n = min(n, r + len);
        m = min(m, c + len);
        for (int i = r; i < n; i++) {
            for (int j = c; j < m; j++) {
                if (matrix[i][j] == '0') {
                    return false;
                }
            }
        }
        // if (len > 1) {
        //     cout << r << " " << c << " " << len << endl;
        // }
        return true;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] != '1') {
                    continue;
                }
                // cout << i << " " << j << endl;
                for (int diag = 1; i + diag <= n && j + diag <= m; diag++) {
                    if (diag > ans) {
                        if (check(i, j, diag, matrix)) {
                            ans = max(ans, diag);
                        }
                        else {
                            break;
                        }
                    }
                }
            }
        }
        ans *= ans;
        return ans;
    }
};