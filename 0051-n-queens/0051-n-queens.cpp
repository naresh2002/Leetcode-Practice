class Solution {
public:
    vector<vector<string>> ans;
    int row[10], col[10];
    int diag1[20], diag2[20];
    
    void solve (vector<string> &v, int cnt, int r, int n) {
        if (cnt == n) {
            ans.push_back(v);
            return;
        }
        for (int c = 0; c < n; c++) {
            if (!row[r] && !col[c] && !diag1[r - c + 10] && !diag2[r + c]) {
                v[r][c] = 'Q';
                row[r] = 1;
                col[c] = 1;
                diag1[r - c + 10] = 1;
                diag2[r + c] = 1;
                
                solve(v, cnt + 1, r + 1, n);
                
                v[r][c] = '.';
                row[r] = 0;
                col[c] = 0;
                diag1[r - c + 10] = 0;
                diag2[r + c] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> v;
        for (int i = 0; i < n; i++) {
            string s;
            for (int j = 0; j < n; j++) {
                s += '.';
            }
            v.push_back(s);
        }
        solve(v, 0, 0, n);
        return ans;
    }
};