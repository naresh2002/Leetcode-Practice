class Solution {
public:
    int coinChange(vector<int>& c, int x) {
        if (x == 0) {
            return 0;
        }
        sort(c.begin(), c.end());
        int n = c.size();
        int dp[x + 1];
        for (int i = 0; i <= x; i++) {
            dp[i] = INT_MAX - 10;
        }
        for (int i = 0; i <= x; i++) {
            for (auto x : c) {
                if (i - x < 0) {
                    break;
                }
                if (x == i) {
                    dp[i] = 1;
                    break;
                }
                dp[i] = min(dp[i], dp[i - x] + 1);
            }
        }
        if (dp[x] == INT_MAX - 10) {
            return -1;
        }
        return dp[x];
    }
};