class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e5;
        int curr_max = -1e5;
        for (auto x : nums) {
            curr_max = max(x, curr_max + x);
            ans = max(ans, curr_max);
        }
        return ans;
    }
};