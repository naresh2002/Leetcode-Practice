class Solution {
public:
    bool passageAvailable(int k, vector<vector<int>> &minHealth, int n, int m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (minHealth[i - 1][j] < -k && minHealth[i][j - 1] < -k) {
                    minHealth[i][j] = -1e8;
                }
            }
        }
        if (minHealth[n][m] < -k) {
            return false;
        }
        return true;
    }
    
    bool isValid(int k, vector<vector<int>>& dungeon, vector<vector<int>> &minHealth) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (!i || !j) {
                    if (i != 1) {
                        minHealth[i][j] = -1e8;
                    }
                }
                else {
                    int up = minHealth[i - 1][j];
                    int left = minHealth[i][j - 1];
                    minHealth[i][j] = max(up, left) + dungeon[i - 1][j - 1];
                    if (minHealth[i][j] < -k) {
                        minHealth[i][j] = -1e8;
                    }
                }
            }
        }
        return minHealth[n][m] >= -k;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        int l = 0, r = 4e7;
        int ans = r;
        vector<vector<int>> minHealth(n + 1, vector<int> (m + 1));
        minHealth[1][0] = 0;
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