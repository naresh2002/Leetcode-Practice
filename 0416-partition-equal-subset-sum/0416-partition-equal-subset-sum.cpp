class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        int tot = 0;
        for (auto x : nums) {
            tot += x;
        }
        if (tot % 2) {
            return false;
        }
        tot /= 2;
        vector<bool> dp (tot  + 1, false);
        dp[0] = true;
        for (auto x : nums) {
            for (int i = tot; i >= x; i--) {
                dp[i] = dp[i] || dp[i - x];
            }
        }
        return dp[tot];
    }
};