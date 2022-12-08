class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned int dp[2022] = {0};
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= target; i++) {
            if (dp[i]) {
                for (auto x : nums) {
                    if (x + i > target) {
                        break;
                    }
                    dp[i + x] += dp[i];
                }
            }
        }
        return dp[target];
    }
};