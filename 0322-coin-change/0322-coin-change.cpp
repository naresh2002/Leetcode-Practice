class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // sort(coins.begin(), coins.end(), greater<int>());
        vector<int> dp(amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            dp[i] = INT_MAX - 1;
            for (auto x : coins) {
                if (i - x >= 0) {
                    dp[i] = min(dp[i], dp[i - x] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX - 1) {
            return -1;
        }
        return dp[amount];
    }
};