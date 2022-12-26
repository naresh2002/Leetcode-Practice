class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, sum = nums[0];
        int ans = INT_MAX;
        while (r < n) {
            if (sum >= target) {
                // cout << l << " " << r << endl;
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l++;
            }
            else {
                r++;
                if (r < n) {
                    sum += nums[r];
                }
            }
        }
        if (ans == INT_MAX) {
            return 0;
        }
        return ans;
    }
};