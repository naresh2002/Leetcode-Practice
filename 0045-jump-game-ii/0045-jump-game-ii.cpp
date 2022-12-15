class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 1e6);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 1; j <= nums[i]; j++) {
                dp[i] = min(dp[i], dp[i + j] + 1);
                if (i + j == n - 1) {
                    break;
                }
            }
        }
        return dp[0];
    }
};