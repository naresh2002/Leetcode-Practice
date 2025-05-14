class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0, best = nums[0];
        for (auto x : nums) {
            curr = max(x, curr + x);
            best = max(curr, best);
        }
        return best;
    }
};