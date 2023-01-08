class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size(), s1 = (target + sum) / 2;
        if (target > sum || (target + sum) % 2 || s1 < 0) {
            return 0;
        }
        
        vector<int> dp(s1 + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = s1; j >= nums[i]; j--) {
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[s1];
    }
    
/*
    S1 - S2 = target;
    S1 + S2 = sum(v);
    Adding Above Two :
    => 2(S1) = target + sum(v)
*/
};