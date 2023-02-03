class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        int a[n];     // a -> not robbing last house
        int b[n];     // b -> robbing last house
        
        a[0] = a[1] = nums[0];
        
        b[0] = 0;
        b[1] = nums[1];
        
        for (int i = 2; i < n; i++) {
            a[i] = max(a[i - 2] + nums[i], a[i - 1]);
            b[i] = max(b[i - 2] + nums[i], b[i - 1]);
        }
        return max(a[n - 2], b[n - 1]);
    }
};