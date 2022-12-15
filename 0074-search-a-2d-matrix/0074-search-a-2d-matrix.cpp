class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (target > matrix[n - 1][m - 1]) {
            return false;
        }
        int row = 0, col = m - 1;
        while (1) {
            if (row < 0 || col < 0 || (target > matrix[row][col] && col < m - 1)) {
                return false;
            }
            if (target == matrix[row][col]) {
                return true;
            }
            if (target > matrix[row][col]) {
                row++;
            }
            if (target < matrix[row][col]) {
                col--;
            }
        }
        return false;
    }
};