class Solution {
public:
    void dfs(vector<vector<int>> &image, int old, int color, int r, int c) {
        if (r < 0 || r >= image.size()) {
            return;
        }
        if (c < 0 || c >= image[0].size()) {
            return;
        }
        if (image[r][c] == color || image[r][c] != old) {
            return;
        }
        image[r][c] = color;
        dfs(image, old, color, r - 1, c);
        dfs(image, old, color, r, c - 1);
        dfs(image, old, color, r, c + 1);
        dfs(image, old, color, r + 1, c);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old = image[sr][sc];
        dfs(image, old, color, sr, sc);
        return image;
    }
};