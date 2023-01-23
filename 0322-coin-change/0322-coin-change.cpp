class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; i++) {
            dp[i] = 1e5;
            for (auto x : coins) {
                if (i - x >= 0) {
                    dp[i] = min(dp[i], dp[i - x] + 1);
                }
                else {
                    break;
                }
            }
        }
        if (dp[amount] == 1e5) {
            return -1;
        }
        return dp[amount];
    }
};