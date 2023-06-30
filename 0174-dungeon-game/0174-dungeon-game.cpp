class Solution {
public:
    
    bool isValid(int k, vector<vector<int>>& dungeon, vector<vector<int>> &minHealth) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!i && !j) {
                    minHealth[i][j] = (dungeon[i][j] < -k ? -1e9 : dungeon[i][j]);
                    continue;
                }
               int ans = -1e9;
                if (i && minHealth[i - 1][j] != -1e9)   ans = minHealth[i - 1][j];
                if (j && minHealth[i][j - 1] != -1e9) ans = max(ans, minHealth[i][j - 1]);
                minHealth[i][j] = max(int(-1e9), ans + dungeon[i][j]);
              if (minHealth[i][j] < -k) minHealth[i][j] = -1e9;
            }
        }
       
        return minHealth[n - 1][m - 1] >= -k;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        int l = 0, r = 1e9;
        int ans = r;
        vector<vector<int>> minHealth(n + 1, vector<int> (m + 1));
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isValid(mid, dungeon, minHealth)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans + 1;
    }
};