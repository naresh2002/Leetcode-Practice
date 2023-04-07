class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int tot = 0, prefSum = 0;
        for (auto x : nums) {
            tot += x;
        }
        for (int i = 0; i < n; i++) {
            if (prefSum == tot - prefSum - nums[i]) {
                return i;
            }
            prefSum += nums[i];
        }
        return -1;
    }
};