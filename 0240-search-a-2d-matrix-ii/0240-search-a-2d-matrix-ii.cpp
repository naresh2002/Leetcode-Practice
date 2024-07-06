class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int x = 0, y = m - 1;
        while (1) {
            if (matrix[x][y] == 1LL * target) {
                return true;
            }
            else if (matrix[x][y] < 1LL * target) {
                x++;
            }
            else {
                y--;
            }
            if (y < 0 || x == n) {
                return false;
            }
        }
        return false;
    }
};