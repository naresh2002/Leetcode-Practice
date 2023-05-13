class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l = 0, r = matrix[0].size() - 1;
        int u = 0, d = matrix.size() - 1;
        int k = 0;
        vector<int> ans;
        
        while (l <= r && u <= d) {
            if (k == 0) {
                for (int j = l; j <= r; j++) {
                    ans.push_back(matrix[u][j]);
                }
                u++;
                k++;
            }
            else if (k == 1) {
                for (int i = u; i <= d; i++) {
                    ans.push_back(matrix[i][r]);
                }
                r--;
                k++;
            }
            else if (k == 2) {
                for (int j = r; j >= l; j--) {
                    ans.push_back(matrix[d][j]);
                }
                d--;
                k++;
            }
            else {
                for (int i = d; i >= u; i--) {
                    ans.push_back(matrix[i][l]);
                }
                l++;
                k = 0;
            }
        }
        return ans;
    }
};