class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = -1e6;
        int best = -1e6;
        for (int i = 0; i < nums.size(); i++) {
            maxSum = max(nums[i], maxSum + nums[i]);
            best = max(best, maxSum);
        }
        return best;
    }
};