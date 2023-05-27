class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0;
        int ans = nums[0];
        for (auto x : nums) {
            curr = max(x, curr + x);
            ans = max(ans, curr);
        }
        return ans;
    }
};