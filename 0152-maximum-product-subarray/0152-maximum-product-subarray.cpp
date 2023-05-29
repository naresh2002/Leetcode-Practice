class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currMin = nums[0];
        int currMax = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            int temp = min({nums[i], currMin * nums[i], currMax * nums[i]});
            currMax = max({nums[i], currMin * nums[i], currMax * nums[i]});
            currMin = temp;
            ans = max(ans, currMax);
        }
        return ans;
    }
};